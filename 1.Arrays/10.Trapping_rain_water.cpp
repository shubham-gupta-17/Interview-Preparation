#include <iostream>
#include <climits>
using namespace std;
int rain_water_1(int *a, int n)
{
	int *left = new int[n]();
	int *right = new int[n]();
	left[0] = a[0];
	for (int i = 1; i < n; i++)
		left[i] = max(left[i - 1], a[i]);
	right[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--)
		right[i] = max(right[i + 1], a[i]);

	int ans = 0;
	for (int i = 0; i < n; i++)
		ans += min(left[i], right[i]) - a[i];
	return ans;
}
int rain_water_2_opti(int *height, int n)
{
	if (n <= 2)
		return 0;
	int i = 0, j = n - 1;
	int lmax = height[0];
	int rmax = height[j];
	int water = 0;
	while (i < j)
	{
		if (rmax < lmax)
		{
			water += rmax - height[j--];
			rmax = max(rmax, height[j]);
		}
		if (lmax <= rmax)
		{
			water += lmax - height[i++];
			lmax = max(lmax, height[i]);
		}
	}
	return water;
}
int main()
{

	int n = 4;
	int arr[] = {7, 4, 0, 9};
	cout << rain_water_1(arr, n) << endl; // O(n) time and O(n) space
	cout << rain_water_2_opti(arr, n);	  // O(n) time and O(1) space
	return 0;
}
