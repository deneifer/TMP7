#include <iostream>;
#include <fstream>
using namespace std;

int zapisfile = 0;

const int population_size = 100;
float p_crossover = 0.9;
float p_mutation = 0.1;
const int max_generations = 20; // ���-�� ���������

void priv(int& mas,int& mas2)
{

}

void genindividuals(int **popul,int n)//��������� ��������� ���������, �� ���� ��������� ��������� ��������� ���������� � ������ [100101]
{
	int r;
	for (int i = 0;i < population_size;i++)
	{
		for (int j = 0;j < n;j++)
		{
			r = rand() % 100;
			if (r<=50)
			{
				popul[i][j] = 0;
			}
			else
			{
				popul[i][j] = 1;
			}
		}
	}
	//return mas;
}

int* fitness(int* ves, int* cen, int** popul, int** pred,int n)// ������� ���� � �������� ������� �������� (��������� ���������� � ������)
{
	
	for (int i = 0;i < population_size;i++)
	{
		ves[i] = 0;
		cen[i] = 0;
		for (int j = 0;j < n;j++)
		{
			if (popul[i][j] == 1)
			{
				ves[i] =ves[i]+ pred[j][0];
				cen[i] =cen[i]+ pred[j][1];
			}

		}
	}

	return ves, cen;
};

int** otbor(int** popul, int** newpopul, int** pred, int* ves, int* cen,int w ,int n)
{
	int newpop = 0;
	int otbr[3];
	while (newpop < population_size)
	{
		int i1 = rand() % population_size, i2 = rand() % population_size, i3 = rand() % population_size;
		otbr[0] = i1;
		otbr[1] = i2;
		otbr[2] = i3;
		int best = 0;
		int i_best = 0;
		for (int i = 0;i < 3;i++)
		{
			if (cen[otbr[i]]>best)
			{
				best = cen[otbr[i]];
				i_best = otbr[i];
			}
		}
		if (ves[i_best] <= w)
		{
			for (int i = 0;i < n;i++)
			{
				newpopul[newpop][i] = popul[i_best][i];
			}
			//newpopul[newpop] = popul[i_best];//������ ������� ��������� ��������� � ������� (������ �������) �������� �����
			//cout << "������ �������� ���������: "<<cen[i_best]<<endl;
			newpop=newpop+1;
		}
	};
	return newpopul;
}

void crossing(int n,int** newpop)//����������� 2 ���������
{
	int tmp;
	for (int j = 0;j < population_size;j++)
	{
		float r = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
		if (r<0.9)
		{
			//cout << "��������� �����������" << endl;
			int randi = rand() % (n - 1) + 1;
			int randind1 = rand() % population_size, randind2 = rand() % population_size;
			for (int i = 0;i < n;i++)
			{
				if (i < randi)
				{
					tmp = newpop[randind1][i];
					newpop[randind1][i] = newpop[randind2][i];
					newpop[randind2][i] = tmp;

				}

			}
		}
	}
}


void mutation(int** newpop,int n)
{
	float r;
	for (int i = 0;i < population_size;i++)
	{
		int randi = rand() % n;
		r = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
		if (r <= 0.1)
		{
			//cout << "��������� ������� � "<<i<<" ���������" << endl;
			if (newpop[i][randi] == 0)
			{
				newpop[i][randi] = 1;
			}
			else
			{
				newpop[i][randi] = 0;
			}
		}
	}

}

int proverka(int** newpop,int n,int* ves, int* cen, int** pred, int w, int*bestbest,ofstream & file)
{
	fitness(ves, cen, newpop, pred, n);
	int best = 0;
	int sred = 0;
	for (int i = 0;i < population_size;i++)
	{
		sred = sred + cen[i];
		
			if (cen[i] > best and ves[i]<=w)
			{
				best = cen[i];
			}
		
	}

	//bestbest[stop] = best;
	cout << "������� ��������� � ���������: " << sred/population_size << endl;
	cout <<"������ ��������� � ���������: "<< best << endl<<endl;
	if (zapisfile <population_size)
	{
		if (zapisfile < 1)
		{
			file << "�������" << "\t" << "����" << endl;
		}
		file << sred/population_size << "\t" << best << endl;
		zapisfile += 1;
	}

	return best;
}

int main()
{
	setlocale(LC_ALL, "Rus");

	ofstream res("res2.txt", ios::app);
	if (!res)
		exit(1);


	int bestbest[max_generations];

	int ves[population_size], cen[population_size];// ������� ����� � �������� ������� �������
	cout << "������� ���������� ���������: ";
	int n;
	cin >> n;
	cout << "������� max ��������� ��� ��������� � �������: ";
	int w;
	cin >> w;
	int **maspred;//������ ���������
	maspred = new int* [n];
	for (int i = 0;i < n;i++)
	{
		maspred[i] = new int[2];//� ������� �������� 2 ��������� ��� � ��������
	}

	int** population;// ������ ���� ���������(��������) - ���������
	population = new int* [population_size];
	for (int i = 0;i < population_size;i++)
	{
		population[i] = new int[n];//������ ������ � ������� ��������� ��������� �������� 
	}

	int** newpopulation;// y����� ������ ���� ���������(��������) - ���������
	newpopulation = new int* [population_size];
	for (int i = 0;i < population_size;i++)
	{
		newpopulation[i] = new int[n];//������ ������ � ������� ��������� ��������� �������� 
	}

	for (int i=0;i<population_size;i++)
	{
		for (int j=0;j<n;j++)
		{
			newpopulation[i][j] = 0;
		}
	}


	for (int i = 0;i < n;i++)
	{
	/*	cout << "��� " << i+1 << " ��������: ";
		cin >> predm[i].val[0];
		cin>>maspred[i][0];
		cout << "���������� " << i+1 << " ��������: ";
		cin >> maspred[i][1];
		cout << endl;*/

		maspred[i][0] =rand()%w ;
		maspred[i][1] = rand()%n;
		cout <<endl<< "��� " << i + 1 << " ��������: " << maspred[i][0] << endl;;
		cout << "���������� " << i + 1 << " ��������: " << maspred[i][1] << endl;
	}
	genindividuals(population, n);

	int stop = 0;
	int luchii = 0;
	int best = 0;
	while (stop < max_generations)
	{
	    fitness(ves, cen, population, maspred, n);

	    otbor(population, newpopulation, maspred, ves, cen, w,n);

		crossing(n, newpopulation);

		mutation(newpopulation, n);
		proverka(newpopulation, n,ves,cen,maspred,w,bestbest,res);

		for (int i = 0;i < population_size;i++)
		{
			for (int j = 0;j < n;j++)
			{
				population[i][j] = newpopulation[i][j];

			}
		}
		//memcpy(population, newpopulation, population_size);
		
		//population=newpopulation;
	//population = newtmp;
	   stop++;
	}
	best = proverka(newpopulation, n, ves, cen, maspred, w, bestbest,res);
	cout << "����� �������� ��� ��������: ";
	for (int i = 0;i < population_size;i++)
	{
		if (cen[i] == best)
		{
			for (int j = 0;j < n;j++)
			{
				if (newpopulation[i][j] == 1)
				{

					cout << j + 1 << " ";
				}
			}
			break;
		}
	}
	cout << endl;

	  //for (int i = 0;i < population_size;i++)
	  //{
		 // for (int j = 0;j < n;j++)
		 // {
			//  cout << newpopulation[i][j];

		 // }
		 // cout << endl;
		 // //cout << " " << cen[i] << " " << ves[i] << endl;
	  //}

	/*for (int i=0;i< max_generations;i++)
	{
		cout << bestbest[i] << endl;
	}*/

	res.close();
	for (int i = 0;i < population_size;i++)
	{
		delete[] population[i];
			delete [] newpopulation[i];
		//delete[] newtmp[i];
	}

	
	delete[] population,newpopulation;
	delete[] maspred;

	system("PAUSE");
	return 0;
}