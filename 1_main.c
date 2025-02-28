//202411716230
//1030027168@qq.com
//马冰洁

def count_jewels_in_stones(jewels, stones):
    # 将jewels转换为集合，以便快速查找
    jewels_set = set(jewels)
    # 遍历stones，统计每个字符是否在jewels_set中
    count = sum(1 for stone in stones if stone in jewels_set)
    return count

# 输入处理
input_str = input("请输入jewels和stones（以逗号分隔）：")
jewels, stones = input_str.split(',')

# 计算并输出结果
num = count_jewels_in_stones(jewels, stones)
print(num)

def triangularSum(nums):
    # 循环直到数组长度为1
    while len(nums) > 1:
        # 计算新的数组
        newNums = [(nums[i] + nums[i + 1]) % 10 for i in range(len(nums) - 1)]
        # 更新数组
        nums = newNums
    # 返回最终结果
    return nums[0]

# 示例
nums = [1, 2, 3, 4, 5]
result = triangularSum(nums)
print(result)

def solveNQueens(n):
    def backtrack(row, cols, diagonals, anti_diagonals, board):
        # 如果行数等于n，说明已经找到一个解
        if row == n:
            solutions.append(board[:])
            return
        for col in range(n):
            # 检查当前列和对角线是否已经有皇后
            if col in cols or (row - col) in diagonals or (row + col) in anti_diagonals:
                continue
            # 选择当前列
            cols.add(col)
            diagonals.add(row - col)
            anti_diagonals.add(row + col)
            board.append('.' * col + 'Q' + '.' * (n - col - 1))
            # 递归下一行
            backtrack(row + 1, cols, diagonals, anti_diagonals, board)
            # 撤销选择
            cols.remove(col)
            diagonals.remove(row - col)
            anti_diagonals.remove(row + col)
            board.pop()

    solutions = []
    backtrack(0, set(), set(), set(), [])
    return solutions

# 示例
n = 4
result = solveNQueens(n)
for solution in result:
    for row in solution:
        print(row)
    print()

def numberOfBeams(bank):
    # 计算每一行中安全设备的数量
    device_counts = [row.count('1') for row in bank]
    # 初始化上一个有安全设备的行的安全设备数量
    prev_count = 0
    # 初始化激光束的总数量
    total_beams = 0
    # 遍历每一行
    for count in device_counts:
        # 如果当前行有安全设备
        if count > 0:
            # 计算激光束的数量
            total_beams += prev_count * count
            # 更新上一个有安全设备的行的安全设备数量
            prev_count = count
    return total_beams

# 示例
bank = ["011001", "000000", "010100", "001000"]
result = numberOfBeams(bank)
print(result)

def maxRookValueSum(board):
    m, n = len(board), len(board[0])
    # 计算每行和每列的价值之和
    row_sums = [sum(row) for row in board]
    col_sums = [sum(col) for col in zip(*board)]
    # 选择三行和三列，使得它们的价值之和最大
    row_sums.sort(reverse=True)
    col_sums.sort(reverse=True)
    max_sum = sum(row_sums[:3]) + sum(col_sums[:3])
    # 检查是否可以放置三个车
    if m < 3 or n < 3:
        return -1
    # 返回最大价值之和
    return max_sum

# 示例
board = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]
result = maxRookValueSum(board)
print(result)
