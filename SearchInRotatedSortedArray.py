class Solution:
    def search(self, nums: list[int], target: int) -> int:
        if nums[0] <= nums[-1]:
            return self.partition(nums, 0, len(nums) -1, target)
        rotation_index = self.rotate_partition(nums, 0, len(nums) -1)
        index = self.partition(nums, 0, rotation_index - 1, target)
        if index != -1:
            return index
        else:
            return self.partition(nums, rotation_index, len(nums) -1, target)

    def rotate_partition(self, nums, low, high) -> int:
        mid = int((low+high) / 2)
        if nums[mid] < nums[mid -1]:
            return mid
        if nums[mid + 1] < nums[mid]:
            return mid + 1
        if nums[mid] < nums[high]:
            return self.rotate_partition(nums, low, mid -1)
        if nums[mid] > nums[low]:
            return self.rotate_partition(nums, mid + 1, high)

    def partition(self, nums, low, high, target) -> int:
        if low > high:
            return -1
        mid = int((low + high) / 2)
        if nums[mid] == target:
            return mid
        if nums[mid] < target:
            return self.partition(nums, mid + 1, high, target)
        if nums[mid] > target:
            return self.partition(nums, low, mid -1, target)

if __name__ == '__main__':
    sol = Solution()
    print(sol.search([3, 1], 0))
        

        
        