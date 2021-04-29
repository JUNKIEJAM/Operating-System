#include <iostream>

using namespace std;

int main()

{

    int nBlocks, nProcess, blockSize[20], processSize[20];

    cout << " Enter the number of blocks: ";
    cin >> nBlocks;

    cout << " Enter the number of processes: ";
    cin >> nProcess;

    cout << " Enter the size of " << nBlocks << " blocks: ";

    for (int i = 0; i < nBlocks; i++)
        cin >> blockSize[i];

    cout << " Enter the size of " << nProcess << " processes: ";

    for (int i = 0; i < nProcess; i++)
        cin >> processSize[i];

    for (int i = 0; i < nProcess; i++)

    {

        int max = blockSize[0];

        int pos = 0;

        for (int j = 0; j < nBlocks; j++)

            if (max < blockSize[j])
            {
                max = blockSize[j];
                pos = j;
            }
        if (max >= processSize[i])

        {

            cout << "\nProcess " << i + 1 << " is allocated to block " << pos + 1;

            blockSize[pos] = blockSize[pos] - processSize[i];
        }

        else
        {

            cout << "\nProcess " << i + 1 << " can't be allocated";
        }
    }

    return 0;
}