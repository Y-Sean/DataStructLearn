/*���������� �ǵݼ�˳�� ���е��������� nums1 �� nums2�������������� m �� n ���ֱ��ʾ nums1 �� nums2 �е�Ԫ����Ŀ��

���� �ϲ� nums2 �� nums1 �У�ʹ�ϲ��������ͬ���� �ǵݼ�˳�� ���С�*/

/*void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	int i = m - 1;
	int j = n - 1;
	int k = m + n - 1;
	while (i >= 0 && j >= 0) {
		if (nums1[i] >= nums2[j]) {
			nums1[k] = nums1[i];
			i--;
		} else {
			nums1[k] = nums2[j];
			j--;
		}
		k--;
	}
	// ���� nums2 ʣ��Ԫ��
	while (j >= 0) {
		nums1[k] = nums2[j];
		j--;
		k--;
	}
}*/

/*����һ�� ���ϸ�������� ������ nums ������ ԭ�� ɾ���ظ����ֵ�Ԫ�أ�ʹÿ��Ԫ�� ֻ����һ�� ������ɾ����������³��ȡ�Ԫ�ص� ���˳�� Ӧ�ñ��� һ�� ��Ȼ�󷵻� nums ��ΨһԪ�صĸ�����

���� nums ��ΨһԪ�ص�����Ϊ k ������Ҫ����������ȷ����������Ա�ͨ����

�������� nums ��ʹ nums ��ǰ k ��Ԫ�ذ���ΨһԪ�أ���������������� nums �г��ֵ�˳�����С�nums ������Ԫ���� nums �Ĵ�С����Ҫ��
���� k ��*/

int removeDuplicates(int* nums, int numsSize) {
	int slow = 0;
	int fast = 0;
	for (fast = 0; fast < numsSize - 1; fast++) {
		if (nums[fast] < nums[fast + 1]) {
			nums[slow] = nums[fast];
			slow++;
		}
	}
	nums[slow] = nums[numsSize - 1];
	slow++;
	return slow;
}