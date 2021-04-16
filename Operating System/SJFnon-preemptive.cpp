#include <bits/stdc++.h> 
using namespace std; 



void findWaitingTime(int arrivaltime[], int bursttime[], int size,
                     int wt[])
{ 
	int rt[size]; 
	
	for (int i = 0; i < size; i++) 
		rt[i] = bursttime[i]; 

	int complete = 0, t = 0, minm = INT_MAX; 
	int shortest = 0, finish_time; 
	bool check = false; 

	while (complete != size) { 

	
		for (int j = 0; j < size; j++) { 
			if ((arrivaltime[j] <= t) && 
			(rt[j] < minm) && rt[j] > 0) { 
				minm = rt[j]; 
				shortest = j; 
				check = true; 
			} 
		} 

		if (check == false) { 
			t++; 
			continue; 
		} 

	
		rt[shortest]--; 

		
		minm = rt[shortest]; 
		if (minm == 0) 
			minm = INT_MAX; 

		if (rt[shortest] == 0) { 
     		complete++; 
			check = false; 

				finish_time = t + 1; 

		
			wt[shortest] = finish_time - 
						bursttime[shortest] - 
						arrivaltime[shortest]; 

			if (wt[shortest] < 0) 
				wt[shortest] = 0; 
		} 

		t++; 
	} 
}

void findavgTime(int arrivaltime[], int bursttime[], int size)
{ 
	int wt[size], total_wt = 0;
	findWaitingTime(arrivaltime,bursttime,size, wt); 
	cout << "Processes "
		<< " Burst time "
		<< " Waiting time"<<endl;
	
	for (int i = 0; i <size; i++) { 
		total_wt = total_wt + wt[i]; 
		cout << " " << i+1 << "\t\t"
			<< bursttime[i] << "\t\t " << wt[i]<< endl; 
	} 

	cout << "\nAverage waiting time = "
		<< (float)total_wt / (float)size; 

} 

int main() 
{ 

    int size;
    cout<<"Enter the number of processes: ";
    cin>>size;

    int arrivaltime[size];

    cout<<"Enter the arrival times: ";
    for (int i = 0; i < size; i++)
    {
        cin >>arrivaltime[i];
    }

    int bursttime[size];
    
    cout<<"Enter the burst times: ";
    for (int i = 0; i < size; i++)
    {
        cin >>bursttime[i];
    }

	findavgTime(arrivaltime,bursttime,size); 
	return 0; 
} 
