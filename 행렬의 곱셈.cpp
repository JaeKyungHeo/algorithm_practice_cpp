#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    //LxM, MxN = LxN
    //결과적으로 행과 열은 앞에 곱해지는 행렬의 행과 뒤에 곱해지는 행렬의 열을 따라감
    //사이 계산은 앞 행렬의 열과 뒤 행렬의 행의 수만큼 이루어짐

    //모든 행과 열이 0인 행렬은 만듬
    for (int i = 0; i < arr1.size(); i++) {
        vector<int>R;
        for (int j = 0; j < arr2[0].size(); j++)
            R.push_back(0);
        answer.push_back(R);
    }

    for (int i = 0; i < arr1.size(); i++) {//행
        for (int j = 0; j < arr2[0].size(); j++) {//열
            for (int t = 0; t < arr2.size(); t++)//계산
                answer[i][j] += arr1[i][t] * arr2[t][j];
        }
    }

    return answer;
}