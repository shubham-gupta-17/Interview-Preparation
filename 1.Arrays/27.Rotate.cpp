#include <iostream>
using namespace std;
// leetcode 48
void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(),matrix.end());
        for(int i=0;i<matrix.size();i++){
            for(int j=i+1;j<matrix.size();j++)
                swap(matrix[i][j],matrix[j][i]);
        }
        return ;
}
int main(){
    vector<vector<int>> a={{1,2,3},{4,5,6},{7,8,9}};
    rotate(a);
    return 0;
}