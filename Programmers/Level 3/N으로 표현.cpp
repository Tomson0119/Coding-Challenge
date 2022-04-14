int solution(int N, int number)
{
	vector<vector<int>> nums(9);
	for (int i=1;i <= 8; i++)
	{
		int firstNum = getNum(N, i);
		if (firstNum == number)	return i;

		bool found = false;
		nums[i].push_back(firstNum);
		for (int j = i - 1; j > 0; j--)
		{
			for (int n : nums[j])
			{
				for (int currNum : nums[i - j])
				{
					int a = n + currNum;
					int b = n - currNum;
					int c = n / currNum;
					int d = n * currNum;

					if (a == number || b == number || c == number || d == number)
					{
						found = true;
						break;
					}

					if (a > 0) nums[i].push_back(a);
					if (b > 0) nums[i].push_back(b);
					if (c > 0) nums[i].push_back(c);
					if (d > 0) nums[i].push_back(d);
				}
				if (found) return i;
			}
		}
	}
	return -1;
}