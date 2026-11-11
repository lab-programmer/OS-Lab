
#include <stdio.h>

struct process {
    int pid, bt, pr, wt, tat;
};

void input(struct process p[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;

        printf("Enter burst time for P%d: ", i + 1);
        scanf("%d", &p[i].bt);

        printf("Enter priority for P%d: ", i + 1);
        scanf("%d", &p[i].pr);
    }
}

void priority(struct process p[], int n) {
    int i, j, min;
    int totalwt = 0, totaltat = 0;
    float avgwt, avgtat;
    struct process temp;

    // Sort according to priority
    for (i = 0; i < n - 1; i++) {
        min = i;

        for (j = i + 1; j < n; j++) {
            if (p[j].pr < p[min].pr) {
                min = j;
            }
        }

        temp = p[i];
        p[i] = p[min];
        p[min] = temp;
    }

    // Calculate WT and TAT
    p[0].wt = 0;
    p[0].tat = p[0].bt;

    for (i = 1; i < n; i++) {
        p[i].wt = p[i - 1].tat;
        p[i].tat = p[i].wt + p[i].bt;
    }

    printf("\nPID\tPR\tBT\tWT\tTAT\n");

    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].pr, p[i].bt,
               p[i].wt, p[i].tat);

        totalwt += p[i].wt;
        totaltat += p[i].tat;
    }

    avgwt = (float)totalwt / n;
    avgtat = (float)totaltat / n;

    printf("\nTotal WT = %d", totalwt);
    printf("\nAverage WT = %.2f", avgwt);
    printf("\nTotal TAT = %d", totaltat);
    printf("\nAverage TAT = %.2f\n", avgtat);
}

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    if (n <= 0) return 0;

    struct process p[n];

    input(p, n);
    priority(p, n);

    return 0;
}
