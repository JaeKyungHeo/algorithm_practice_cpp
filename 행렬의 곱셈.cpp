#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    //LxM, MxN = LxN
    //��������� ��� ���� �տ� �������� ����� ��� �ڿ� �������� ����� ���� ����
    //���� ����� �� ����� ���� �� ����� ���� ����ŭ �̷����

    //��� ��� ���� 0�� ����� ����
    for (int i = 0; i < arr1.size(); i++) {
        vector<int>R;
        for (int j = 0; j < arr2[0].size(); j++)
            R.push_back(0);
        answer.push_back(R);
    }

    for (int i = 0; i < arr1.size(); i++) {//��
        for (int j = 0; j < arr2[0].size(); j++) {//��
            for (int t = 0; t < arr2.size(); t++)//���
                answer[i][j] += arr1[i][t] * arr2[t][j];
        }
    }

    return answer;
}