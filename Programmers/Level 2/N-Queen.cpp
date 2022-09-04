#include <vector>

using namespace std;

void backtracking(vector<int> board, int col, int& answer)
{	
	for (int i = col - 1; i >= 0; i--)
	{
		if (board[col] > 0 && board[i] == board[col])
			return;
		if (board[col] > (col-i) 
			&& board[col] - (col - i) == board[i])
			return;
		if (board[col] <= board.size() - (col - i) 
			&& board[col] + (col - i) == board[i])
			return;
	}

	if (col == board.size() - 1)
	{
		answer += 1;
		return;
	}

	for (int i = 1; i <= board.size(); i++)
	{
		board[col+1] = i;
		backtracking(board, col+1, answer);
		board[col+1] = 0;
	}
}

int solution(int n)
{
	vector<int> board(n, 0);
	int answer = 0;
	backtracking(board, -1, answer);
	return answer;
}