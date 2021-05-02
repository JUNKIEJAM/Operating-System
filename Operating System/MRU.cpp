#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int mru_get(int requests[], int ref_size, int frame_size)
{
    int fault = 0;
    vector<int> frame;
    frame.push_back(requests[0]);
    ++fault;
    for (int i = 0; i < ref_size; i++)
    {
        vector<int>::iterator it = find(frame.begin(), frame.end(), requests[i]);
        if (it == frame.end())
        {
            if (frame.size() != frame_size)
                frame.push_back(requests[i]);
            else
            {
                it = find(frame.begin(), frame.end(), requests[i - 1]);
                int index = it - frame.begin();
                frame[index] = requests[i];
            }
            ++fault;
        }
    }

    return fault;
}
int main()
{
    int frame_size;
    int ref_size;
    cout << "Enter the number of frames in the main memory: ";
    cin >> frame_size;
    cout << "Enter the number of page requests: ";
    cin >> ref_size;
    cout << "Enter the reference string: ";
    int *requests = new int[ref_size];
    for (int i = 0; i < ref_size; i++)
        cin >> requests[i];
    int fault = mru_get(requests, ref_size, frame_size);
    cout << "The number of page faults for the above reference string is: " << fault << endl;
    cout << "The number of page hits for the above reference string is: " << ref_size-fault << endl;

    return 0;
}