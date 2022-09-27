#include <iostream>
#include <random>

using namespace std;

int num = 1000;

void show_germs(unsigned char germs[][2])
{
  int count = 0;
  double percent = 0;
  for (int i = 0; i < num; i++)
  {
    printf("%d %d\n", germs[i][0], germs[i][1]);
    if (germs[i][0] == 1 || germs[i][1] == 1)
    {
      count++;
    }
  }
  if (count != num)
  {
    percent = 1.0 * count / (1.0 * num - 1.0 * count);
  }
  printf("Dominant:%d\nRecessive:%d\n%f:1\n", count, num - count, percent);
}

void zoogamy(unsigned char p1[2], unsigned char p2[2], unsigned char *f1, unsigned char *f2, unsigned char *f3, unsigned char *f4)
{
  random_device rnd;
  mt19937 mt(rnd());
  uniform_int_distribution<> rand2(0, 1);
  *f1 = p1[rand2(mt)];
  *f2 = p2[rand2(mt)];
  *f3 = p1[rand2(mt)];
  *f4 = p2[rand2(mt)];
}

int main()
{
  unsigned char p[num][2];
  unsigned char f1[num][2];
  unsigned char f2[num][2];
  for (int i = 0; i < num; i++)
  {
    if (i < num / 2)
    {
      p[i][0] = 0;
      p[i][1] = 0;
    }
    else
    {
      p[i][0] = 1;
      p[i][1] = 1;
    }
  }
  for (int i = 0; i < num / 2; i++)
  {
    zoogamy(p[i], p[num - 1 - i], &f1[i][0], &f1[i][1], &f1[num - 1 - i][0], &f1[num - 1 - i][1]);
  }
  show_germs(f1);
  printf("f1");
  for (int i = 0; i < num / 2; i++)
  {
    zoogamy(f1[i], f1[num - 1 - i], &f2[i][0], &f2[i][1], &f2[num - 1 - i][0], &f2[num - 1 - i][1]);
  }
  show_germs(f2);
  printf("f2");

  cout << endl;
}