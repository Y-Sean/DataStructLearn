/*给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。

请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。*/

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
	// 处理 nums2 剩余元素
	while (j >= 0) {
		nums1[k] = nums2[j];
		j--;
		k--;
	}
}*/

/*给你一个 非严格递增排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。然后返回 nums 中唯一元素的个数。

考虑 nums 的唯一元素的数量为 k ，你需要做以下事情确保你的题解可以被通过：

更改数组 nums ，使 nums 的前 k 个元素包含唯一元素，并按照它们最初在 nums 中出现的顺序排列。nums 的其余元素与 nums 的大小不重要。
返回 k 。*/

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