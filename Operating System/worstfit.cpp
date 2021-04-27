#include<bits/stdc++.h> 
using namespace std; 

void worstFit(int b_size[], int m, int p_size[], int n) 
{ 

     int allocation[n]; 

    memset(allocate, -1, sizeof(allocate)); 
  
    for (int i=0; i<n; i++) 
    { 
        int wstIdx = -1; 
        for (int j=0; j<m; j++) 
        { 

   
            if (b_size[j] >= p_size[i]) 
            { 
                if (wstIdx == -1) 
                    wstIdx = j; 
                else if (b_size[wstIdx] < b_size[j]) 
                    wstIdx = j; 
            } 
        } 
  
        if (wstIdx != -1) 
        { 
        
            allocate[i] = wstIdx; 
 
            B_size[wstIdx] -= p_size[i]; 
        } 
    } 

  
   
    cout << "\nProcess Number \tProcess Size\tBlock Number\n"; 
    for (int i = 0; i < n; i++) 
    { 
 
        cout << "   " << i+1 << "\t\t" << p_size[i] << "\t\t"; 

   
        if (allocate[i] != -1) 

   
            cout<< allocate[i] + 1; 


        else
   
            cout << "Not Allocated"; 
        cout << endl; 
    } 
} 
   
int main() 
{ 
    int blockSize[] = {100, 500, 200, 300, 600}; 
    int processSize[] = {212, 417, 112, 426}; 
    int m = sizeof(blockSize)/sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);

    worstFit(b_size, m, processSize, n);

    return 0 ; 
}