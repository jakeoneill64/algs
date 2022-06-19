
class Solution:
    
    def letterCombinations(self, digits: str) -> list[str]:
        if len(digits) < 1:
            return []
        lookup = {2 : 'abc', 3:'def', 4:'ghi', 5:'jkl', 6:'mno', 7:'pqrs', 8:'tuv', 9:'wxyz'}
        selected = []
        for char in digits:
            digit = int(char)
            selected.append(lookup[digit])
        return self._permutate(set(), '', *selected)

    def _permutate(self, results: set[str], current: str, *args) -> set[str]:
        for char in args[0]:
            if len(args) < 2:
                results.update({''.join([current, char])})
            else:
                results.update(self._permutate(results, ''.join([current, char]), *args[1:]))
        return results

if __name__ == '__main__':
    sol = Solution()
    print(sol.letterCombinations(''))



