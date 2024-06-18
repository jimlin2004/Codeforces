#include <cstdio>
#include <cstring>

char input[100005];

//for counting sort
int C[5];

int main()
{
    scanf("%s", input);
    char* token = strtok(input, "+");
    do
    {
        ++C[token[0] - '0'];
    } while (token = strtok(NULL, "+"));
    
    //不需要
    // for (int i = 0; i < 5; ++i)
        // C[i] += C[i];
    
    bool first = true;
    for (int i = 1; i <= 3; ++i)
    {
        for (int j = 0; j < C[i]; ++j)
        {
            if (first)
                first = false;
            else
                printf("+");

            printf("%d", i);
        }
    }
    puts("");

    return 0;
}