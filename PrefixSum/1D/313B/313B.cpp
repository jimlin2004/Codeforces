#include <cstdio>
#include <cstring>
using namespace std;

//prefixSum

#define maxn 200005

char input[maxn];
int prefixSumOfDot[maxn];
int prefixSumOfHashtag[maxn];

int main()
{
	scanf("%s", input);
	int len = strlen(input);
	for (int i = 0; i < len - 1; ++i)
	{
		if (input[i] == '.' && input[i] == input[i + 1])
		{
			prefixSumOfDot[i + 1] = prefixSumOfDot[i] + 1;
			prefixSumOfHashtag[i + 1] = prefixSumOfHashtag[i];
		}
		else if (input[i] == '#' && input[i] == input[i + 1])
		{
			prefixSumOfDot[i + 1] = prefixSumOfDot[i];
			prefixSumOfHashtag[i + 1] = prefixSumOfHashtag[i] + 1;
		}
		else
		{
			prefixSumOfDot[i + 1] = prefixSumOfDot[i];
			prefixSumOfHashtag[i + 1] = prefixSumOfHashtag[i];
		}
	}
	int n, l, r;
	scanf("%d", &n);
	int res;
	while (n--)
	{
		scanf("%d %d", &l, &r);
		res = 0;
		res += prefixSumOfDot[r - 1] - prefixSumOfDot[l - 1];
		res += prefixSumOfHashtag[r - 1] - prefixSumOfHashtag[l - 1];
		printf("%d\n", res);
	}
	return 0;
}