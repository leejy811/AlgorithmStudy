#include <iostream>
#include <vector>

using namespace std;

int MinDiff(vector<vector<int>> a, vector<vector<int>> b, int n)
{
   int min = n * (n + 1) / 2;

   for (int i = 0; i < 6; i++)
   {
      int cnt = 0;

      for (int j = 0; j < n; j++)
      {
         for (int k = 0; k < j + 1; k++)
         {
            int l = 0, r = 0;

            if (i == 0)         //그대로
            {
               l = j;
               l = k;
            }
            else if (i == 1)   //시계
            {
               r = n - j - 1;
               l = r + k;
            }
            else if (i == 2)   //반시계
            {
               l = n - k - 1;
               r = j - k;
            }
            else if (i == 3)   //반대
            {
               l = j;
               r = j - k;
            }
            else if (i == 4)   //시계-반대
            {
               //시계
               r = n - j - 1;
               l = r + k;

               //반대
               r = l - r;
            }
            else if (i == 5)   //반시계-반대
            {
               //반시계
               l = n - k - 1;
               r = j - k;

               //반대
               r = l - r;
            }

            if (a[l][r] != b[j][k])
                  cnt++;
         }
      }

      if (cnt < min)
         min = cnt;
   }

   return min;
}

int main(void)
{
   int n = 0, i, j;
   vector<vector<int>> a;
   vector<vector<int>> b;

   cin >> n;

   for (i = 0; i < n; i++)
   {
      vector<int> temp;
      for (j = 0; j < i + 1; j++)
      {
         int input = 0;
         cin >> input;
         temp.push_back(input);
      }
      a.push_back(temp);
   }

   for (i = 0; i < n; i++)
   {
      vector<int> temp;
      for (j = 0; j < i + 1; j++)
      {
         int input = 0;
         cin >> input;
         temp.push_back(input);
      }
      b.push_back(temp);
   }

   cout << MinDiff(a, b, n);

   return 0;
}