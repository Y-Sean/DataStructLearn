//#include<stdio.h>
//
////�������Ӽ�
//int missingNumber(int* nums, int numsSize) {
//	int i = 0;
//	int num = 0;
//	for (; i < numsSize + 1; i++) {
//		num ^= i;
//	}
//	for (i = 0; i < numsSize; i++) {
//		num ^= *(nums + i);
//	}
//	return num;
//}
//
//int main()
//{
//	int nums[3] = { 3,0,1 };
//	int n = 3;
//	int miss = missingNumber(nums, n);
//	int i = 0;
//	for (; i < n; i++)
//	{
//		printf("%d ", nums[i]);
//	}
//	printf("\n%d\n", miss);
//	return 0;
//}

#include<stdio.h>

//ǰ�������彻��
void swap(int* nums, int n) {
	int* left = nums;
	int* right = nums + n - 1;
	while (left < right) {
		int tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void rotate(int* nums, int numsSize, int k) {
	// ��ָֹ��Խ��
	k = k % numsSize;
	// ����ǰn-k��
	swap(nums, numsSize - k);
	// ������n��
	swap(nums + numsSize - k, k);
	// ���彻��
	swap(nums, numsSize);
}

int main()
{
	int nums[7] = { 1,2,3,4,5,6,7 };
	rotate(nums, 7, 3);
	return 0;
}