import sys

class Solution:
    def threeSumClosest(self, nums: list[int], target: int) -> int:
        nums.sort()
        smallest = sys.maxsize
        for i in range(len(nums)):
            low, high = i + 1, len(nums) -1
            while low < high:
                sum = nums[i] + nums[low] + nums[high]
                print(f'sum = {sum} = {nums[i]} + {nums[low]} + {nums[high]}')
                smallest = sum if abs(smallest - target) > abs(sum - target) else smallest
                print(f'smallest = {smallest}')
                if sum < target:
                    low += 1
                    continue
                if sum > target:
                    high -= 1
                    continue
                return target
        return smallest

if __name__ == '__main__':
    sol = Solution()
    print(sol.threeSumClosest([-1,2,1,-4], 1))

        