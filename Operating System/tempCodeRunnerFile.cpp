#include <iostream>
using namespace std;
int main()
{
    int n, i, j, TEMP, TEMP1, TEMP2, TEMP3, TEMP4;
    float WTSUM = 0, TATSUM = 0;
    int bt[10], at[10], P[10], ct[10], tat[10], wt[10], pt[10];
    cout << "Enter the no of  processes:";
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cout << "\nEnter the Process id,Arrival Time,Burst Time,Priority of processes:";
        cin >> P[i] >> at[i] >> bt[i] >> pt[i];
    }
    ct[0] = 0;
    if (bt[1] >= at[n])
    {
        ct[1] = bt[1] + at[1];
        tat[1] = ct[1] - at[1];
        wt[1] = tat[1] - bt[1];
        WTSUM = wt[1];
        TATSUM = tat[1];
        for (i = 2; i <= n; i++)
        {
            for (j = i + 1; j <= n; j++)
            {
                if (pt[j] < pt[i])
                {
                    TEMP4 = pt[i];
                    pt[i] = pt[j];
                    pt[j] = TEMP4;
                    TEMP1 = bt[i];
                    bt[i] = bt[j];
                    bt[j] = TEMP1;
                    TEMP2 = at[i];
                    at[i] = at[j];
                    at[j] = TEMP2;
                    TEMP3 = P[i];
                    P[i] = P[j];
                    P[j] = TEMP3;
                }
            }
            if (ct[i - 1] < at[i])
            {
                TEMP = at[i] - ct[i - 1];
                ct[i] = ct[i - 1] + bt[i] + TEMP;
                TEMP1 = bt[i];
            }
            else
            {
                ct[i] = ct[i - 1] + bt[i];
            }
            tat[i] = ct[i] - at[i];
            wt[i] = tat[i] - bt[i];
            WTSUM = WTSUM + wt[i] + wt[1];
            TATSUM = TATSUM + tat[i] + tat[1];
        }
    }
    if (at[n] == 0)
    {
        ct[0] = 0;
        for (i = 1; i <= n; i++)
        {
            for (j = i + 1; j <= n; j++)
            {
                if (pt[j] < pt[i])
                {
                    TEMP4 = pt[i];
                    pt[i] = pt[j];
                    pt[j] = TEMP4;
                    TEMP1 = bt[i];
                    bt[i] = bt[j];
                    bt[j] = TEMP1;
                    TEMP2 = at[i];
                    at[i] = at[j];
                    at[j] = TEMP2;
                }
            }
            if (ct[i - 1] < at[i])
            {

                TEMP = at[i] - ct[i - 1];
                ct[i] = ct[i - 1] + bt[i] + TEMP;
                TEMP1 = bt[i];
            }
            else
            {
                ct[i] = ct[i - 1] + bt[i];
            }
            tat[i] = ct[i] - at[i];
            wt[i] = tat[i] - bt[i];
            WTSUM = WTSUM + wt[i];
            TATSUM = TATSUM + tat[i];
        }
    }
    cout << endl;
    cout << "Process\t\tBurst Time\tArrival Time\tPriority Time\tWaiting Time\n";
    for (i = 1; i <= n; i++)
    {
        cout << P[i] << "\t\t" << bt[i] << "\t\t" << at[i] << "\t\t" << pt[i] << "\t\t" << wt[i] << "\n";
    }
    cout << "Average waiting time:" << (float)WTSUM / (float)n;
    cout << endl;
    cout << "Gantt chart:\n";
    cout << "| ";
    for (i = 1; i <= n; i++)
        cout << P[i] << " | ";
    cout << "\n";
    cout << 0;
    for (i = 1; i <= n; i++)
        cout << "  " << ct[i];
    cout << endl;
    return 0;
}