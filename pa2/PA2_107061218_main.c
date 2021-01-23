#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    int y;
    int N = 20;
    int th;
    int th_arr[1000];
    int test;
    int temp_x;
    int par[20] = {450000, 265651, 140362, 71250, 35763, 17899, 8952, 4476, 2238, 1119, 560, 280, 140, 70, 35, 17, 9, 4, 2, 1};
    int cos_ans[1000], sin_ans[1000];

    FILE *fp;
    fp = fopen("result.txt", "w");

    scanf("%d", &test);
    for (int i = 0; i < test; i++)
    {
        scanf("%d", &th);
        x = 6072529;
        y = 0;
        th_arr[i] = th;
        for (int k = 0; k < N; k++)
        {
            temp_x = x;
            if (th >= 0)
            {
                x = x - (y >> k);
                y = (temp_x >> k) + y;
                th = th - par[k];
            }
            else
            {
                x = x + (y >> k);
                y = -(temp_x >> k) + y;
                th = th + par[k];
            }
        }
        cos_ans[i] = x;
        sin_ans[i] = y;
    }

    // print the answer
    printf("%d\n", test);
    fprintf(fp, "%d\n", test);
    for (int i = 0; i < test; i++)
    {
        printf("%d %d %d\n", th_arr[i], cos_ans[i], sin_ans[i]);
        fprintf(fp, "%d %d %d\n", th_arr[i], cos_ans[i], sin_ans[i]);
    }
    fclose(fp);
    return 0;
}