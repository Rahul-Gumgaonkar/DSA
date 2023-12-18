#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int SumOfMimAndMax(vector<int> &arr, int k)
{
    deque<int> maxEle;
    deque<int> minEle;
    int sum = 0;

    // fist window of size k
    for (int i = 0; i < k; i++)
    {
        // chote element remove krdo
        while (!maxEle.empty() && arr[i] >= arr[maxEle.back()])
        {
            maxEle.pop_back();
        }
        maxEle.push_back(i);

        // bade element remove krdo
        while (!minEle.empty() && arr[i] <= arr[minEle.back()])
        {
            minEle.pop_back();
        }
        minEle.push_back(i);
    }

    sum += arr[maxEle.front()] + arr[minEle.front()];

    // remaining windows ko process
    for (int i = k; i < arr.size(); i++)
    {
        // out of window element ko remove krdla
        if (!maxEle.empty() && i - maxEle.front() >= k)
        {
            maxEle.pop_front();
        }

        if (!minEle.empty() && i - minEle.front() >= k)
        {
            minEle.pop_front();
        }

        while (!maxEle.empty() && arr[i] >= arr[maxEle.back()])
        {
            maxEle.pop_back();
        }
        while (!minEle.empty() && arr[i] <= arr[minEle.back()])
        {
            minEle.pop_back();
        }

        maxEle.push_back(i);
        minEle.push_back(i);

        sum += arr[maxEle.front()] + arr[minEle.front()];
    }

    return sum;
}

int main()
{

    vector<int> arr{2, 5, -1, 7, -3, -1, -2};
    int k = 4;

    cout << "Sum of Min And Max is : " << SumOfMimAndMax(arr, k) << endl;

    return 0;
}