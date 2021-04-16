#include <bits/stdc++.h>
using namespace std;

void findWaitingTime(int n,
                     int bt[], int wt[])
{
    wt[0] = 0;
    for (int i = 1; i < n; i++)
        wt[i] = bt[i - 1] + wt[i - 1];
}

void findavgTime(int n, int bt[])
{
    int wt[n], total_wt = 0;

    findWaitingTime(n, bt, wt);

    cout << "Processes "
         << " Burst time "
         << " Waiting time "<<endl;

 for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        cout << " " << i + 1 << "\t\t" << bt[i] << "\t "
             << wt[i] << endl;
    }

    cout << "Average waiting time = "
         << (float)total_wt / (float)n;   
}

int main()
{
  
    int size;
    cout<<"Enter the number of processes: ";
    cin>>size;
          
   int bursttimes[size];
   cout<<"Enter burst times: ";
   for (int i = 0; i < size; i++)
   {
       cin >> bursttimes[i];
   }

   findavgTime(size, bursttimes);
   cout<<endl;
   return 0;
}
