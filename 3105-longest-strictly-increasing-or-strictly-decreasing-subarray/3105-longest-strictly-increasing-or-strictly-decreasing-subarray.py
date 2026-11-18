class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        res = 0
        for i in range(len(nums)):
            for j in range(i, len(nums)):
                cur = nums[i:j+1]
                if all(x < y for x, y in zip(cur, cur[1:])) or all(x > y for x, y in zip(cur, cur[1:])):
                    res = max(res, j - i + 1)
        return res