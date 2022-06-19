class Solution:
    def isValidSudoku(self, board: list[list[str]]) -> bool:
        for k in range(3):
            for l in range(3):
                items = set()
                for i in range(3):
                    for j in range(3):
                        item = board[i + (3*k)][j + (3*l)]
                        if not item == '.':
                            if item in items:
                                return False
                            items.add(board[i + (3*k)][j + (3*l)])                            
        horizontal, vertical = [], []
        for x in range(9):
            horizontal.append(set())
            vertical.append(set())
        for i in range(9):
            for j in range(9):
                item = board[i][j]
                if not item == '.':
                    if (item in horizontal[i]) or (item in vertical[j]):
                        return False
                    horizontal[i].add(item)
                    vertical[j].add(item)
        return True
            


        


    

if __name__ == '__main__':
    sol = Solution()
    board = [['5', '.', '.', '.', '.', '.', '.', '.', '.'],
             ['6', '.', '.', '.', '.', '.', '.', '.', '.'],
             ['.', '.', '.', '.', '.', '.', '.', '.', '.'],
             ['8', '.', '.', '.', '.', '.', '.', '.', '.'],
             ['4', '.', '.', '.', '.', '.', '.', '.', '.'],
             ['7', '.', '.', '.', '2', '.', '.', '.', '6'],
             ['.', '.', '.', '.', '.', '.', '.', '.', '.'],
             ['.', '.', '.', '.', '.', '.', '.', '.', '.'],
             ['.', '.', '.', '.', '.', '.', '.', '.', '.']]
    incorrect = [
                 ["5","3",".",".","7",".",".",".","."],
                 ["6",".",".","1","9","5",".",".","."],
                 [".","9","8",".",".",".",".","6","."],
                 ["8",".",".",".","6",".",".",".","3"],
                 ["4",".",".","8",".","3",".",".","1"],
                 ["7",".",".",".","2",".",".",".","6"],
                 [".","6",".",".",".",".","2","8","."],
                 [".",".",".","4","1","9",".",".","5"],
                 [".",".",".",".","8",".",".","7","9"]
                ]

    print(sol.isValidSudoku(board))