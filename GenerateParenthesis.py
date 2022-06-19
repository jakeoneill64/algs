class Solution:

    def generateParenthesis(self, n: int) -> list[str]:
        return list(self.expand('', 0, 0, n, set()))

    def expand(self, previous: str, open: int, closed: int, n, result: set[str]) -> set[str]:
        if open == closed and open == n:
            return {previous}
        if open < n:
            result.update(self.expand(''.join([previous, '(']), open + 1, closed, n, result))
        if closed < open:
            result.update(self.expand(''.join([previous, ')']), open, closed + 1, n, result))
        return result



    

if __name__ == '__main__':
    sol = Solution()
    print(sol.generateParenthesis(3))


        