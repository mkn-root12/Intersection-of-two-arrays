class Solution:
    def shortestPathBinaryMatrix(self, g):
        m = len(g)
        if g[0][0] == 1 or g[m - 1][m - 1] == 1:
            return -1
        if m == 1:
            return 1
        q = deque([[0, 0]])
        g[0][0] = 1
     
        while q:
            i, j = q.popleft()
            # print(i, j)
            for a in range(-1, 2):
                for b in range(-1, 2):
                    if a != 0 or b != 0:
                        x, y = i + a, j + b
                        if x < 0 or x >= m or y < 0 or y >= m or g[x][y] != 0:
                            continue
                        g[x][y] = g[i][j] + 1
                        q.append([x, y])

                        if x == m - 1 and y == m - 1:
                            return g[x][y]
        return -1


s = Solution()
g = [[0, 0, 0], [1, 1, 0], [1, 1, 0]]
print(s.shortestPathBinaryMatrix(g))
