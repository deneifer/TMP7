//#include <iostream>
//#include <fstream>
//
//using namespace std;
//
//ifstream in("input.txt");
//ofstream out("output.txt");
//ofstream out2("output2.xls");
//
//int  wts[100], cost[100];
//int* x = new int[100000];
//__int64 Sum_C = 0, Sum_W = 0, Best = 0;
//__int64 N, W;
//int val = 1, ak;
//
//void evolution()
//{
//    int i;
//
//    for (i = 1; i <= val; i++)
//    {
//        Sum_W = Sum_W + wts[x[i]];
//        Sum_C = Sum_C + cost[x[i]];
//
//        if (Sum_W <= W && Sum_C > Best) Best = Sum_C;
//    }
//    out << Best<<"\n";
//    out2 << Best << "\t";
//    Sum_C = 0;
//    Sum_W = 0;
//}
//
//void Generate(int n, int k)
//{
//    int i, j, p;
//    for (i = 1; i <= k; i++) x[i] = i;
//    evolution();
//    do
//    {
//        p = 0;
//        for (i = k; i >= 1; i--)
//            if (x[i] < n - k + i) 
//            { p = i; break; }
//        if (p > 0)
//        {
//            x[p]++;
//            for (i = p + 1; i <= k; i++) x[i] = x[i - 1] + 1;
//            evolution();
//        }
//    } while (p > 0);
//}
//
//void main()
//{
//    int i = 1;
//
//    in >> N;
//    in >> W;
//
//    while (!in.eof())
//    {
//        in >> wts[i];
//        in >> cost[i];
//        i++;
//    }
//
//    while (val <= N)
//    {
//        Generate(N, val);
//        val++;
//    }
//
//    //out << Best << endl;
//}