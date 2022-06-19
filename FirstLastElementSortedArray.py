class Solution:
    def searchRange(self, nums: list[int], target: int) -> list[int]:
        index = self._partition(0, len(nums) -1, target, nums)
        if index < 0:
            return [-1, -1]
        left, right = index, index
        while (left -1) >= 0 and nums[left -1] == target:
            left -= 1
        while (right + 1) < len(nums) and nums[right +1] == target:
            right += 1
        return[left, right]
    
    def _partition(self, low, high, target, nums) -> int:
        if low > high:
            return -1
        mid = int((high + low) / 2)
        print('low : ' + str(low) + '   high : ' + str(high) + '   mid : ' + str(mid))
        if nums[mid] == target:
            return mid
        if nums[mid] > target:
            return self._partition(low, mid -1, target, nums)
        if nums[mid] < target:
            return self._partition(mid + 1, high, target, nums)

if __name__ == '__main__':
     sol = Solution()
     print(sol.searchRange([1], 1))

        
