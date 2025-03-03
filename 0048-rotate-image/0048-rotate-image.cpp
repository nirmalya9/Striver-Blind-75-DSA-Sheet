class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

    //Approach 1: Reverse
    // ranges::reverse(matrix);
    // for (int i = 0; i < matrix.size(); ++i)
    //   for (int j = i + 1; j < matrix.size(); ++j)
    //     swap(matrix[i][j], matrix[j][i]);

    //Approach 2: Indexing 
    for (int mn = 0; mn < matrix.size() / 2; ++mn) {
      const int mx = matrix.size() - mn - 1;
      for (int i = mn; i < mx; ++i) {
        const int offset = i - mn;
        const int top = matrix[mn][i];
        matrix[mn][i] = matrix[mx - offset][mn];
        matrix[mx - offset][mn] = matrix[mx][mx - offset];
        matrix[mx][mx - offset] = matrix[i][mx];
        matrix[i][mx] = top;
      }
    }
  }
};