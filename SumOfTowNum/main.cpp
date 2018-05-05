
/*
排序数组中和为给定值的两个数字[算法]

题目：输入一个已经按升序排序过的数组和一个数字，在数组中查找两个数，使得它们的和正好是输入的那个数字。要求时间复杂度是O(n)。
 如果有多对数字的和等于输入的数字，输出任意一对即可。

例如输入数组1、2、4、7、11、15和数字15。由于4+11=15，因此输出4和11。

分析：如果我们不考虑时间复杂度，最简单想法的莫过去先在数组中固定一个数字，再依次判断数组中剩下的n-1个数字与它的和是不是等于输入的数字。
 可惜这种思路需要的时间复杂度是O(n2)。
 我们假设现在随便在数组中找到两个数。如果它们的和等于输入的数字，那太好了，我们找到了要找的两个数字；
 如果小于输入的数字呢？我们希望两个数字的和再大一点。由于数组已经排好序了，我们是不是可以把较小的数字的往后面移动一个数字？
 因为排在后面的数字要大一些，那么两个数字的和也要大一些，就有可能等于输入的数字了；同样，当两个数字的和大于输入的数字的时候，
 我们把较大的数字往前移动，因为排在数组前面的数字要小一些，它们的和就有可能等于输入的数字了。
 我们把前面的思路整理一下：最初我们找到数组的第一个数字和最后一个数字。当两个数字的和大于输入的数字时，把较大的数字往前移动；
 当两个数字的和小于数字时，把较小的数字往后移动；当相等时，打完收工。这样扫描的顺序是从数组的两端向数组的中间扫描。
*/

#include <iostream>

using namespace std;

///////////////////////////////////////////////////////////////////////
// Find two numbers with a sum in a sorted array
// Output: ture is found such two numbers, otherwise false
///////////////////////////////////////////////////////////////////////

bool FindTwoNumbersWithSum(
                const int* data,           // a sorted array
                unsigned int length,  // the length of the sorted array
                int sum,              // the sum
                int& num1,            // the first number, output
                int& num2             // the second number, output
         )
{

    bool found = false;
    if(length < 1)
        return found;

    int ahead  = length - 1;
    int behind = 0;

    while(ahead > behind)
    {
        long long curSum = data[ahead] + data[behind];

        // if the sum of two numbers is equal to the input
        // we have found them
        if(curSum == sum)
        {
            num1 = data[behind];
            num2 = data[ahead];
            found = true;
            break;
        } else if(curSum > sum) {
            // if the sum of two numbers is greater than the input
            // decrease the greater number
            ahead--;
        } else {
            // if the sum of two numbers is less than the input
            // increase the less number
            behind++;
        }
    }

    return found;
}



int main() {

    int data[] = {1, 3, 5, 7, 9, 11, 13};
    int num1;
    int num2;

    bool bFound = FindTwoNumbersWithSum((const int*)data, sizeof(data)/sizeof(data[0]), 14, num1, num2);

    if (!bFound)
        cout << "Not Found!!!" << endl;
    else
        cout << "Found: num1 = " << num1 << ", num2 = " << num2 << endl;

    return 0;
}