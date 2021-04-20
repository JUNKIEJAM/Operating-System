#include <bits/stdc++.h>
using namespace std;

float pageFaults(int ref[], int pages, int frames)
{
 
    unordered_set<int> s;

    queue<int> indexes;

    float page_faults = 0;
    for (int i = 0; i < pages; i++)
    {
   
        if (s.size() <frames)
        {
          
            if (s.find(ref[i]) == s.end())
            {
               
                s.insert(ref[i]);

                page_faults++;

                indexes.push(ref[i]);
            }
        }
        else
        {
    
            if (s.find(ref[i]) == s.end())
            {

                int val = indexes.front();

       
                indexes.pop();

                s.erase(val);

                s.insert(ref[i]);

                indexes.push(ref[i]);

                page_faults++;
            }
        }
    }

    return page_faults;
}

int main()
{
    int pages,frames;
    cout<<"Enter the number of pages: ";
    cin>>pages;

    cout<<"Enter the number of frames: ";
    cin>>frames;

    int ref[pages];
    
    cout<<"Enter the reference string: ";
    for(int i=0;i<pages;i++){
        cin>>ref[i];
    }

    float pf=pageFaults(ref, pages, frames);
    float ph=pages-pf;

    float ratio = (ph/pages);

    cout<<"Number of Page Hits: "<<ph<<endl;
    cout << "Number of Page Faults: " << pf<< endl;

    cout<<"Page Hit Ratio: "<<ratio<<endl;
    cout << "Page Fault Ratio: " << 1-ratio << endl;

    return 0;
}
