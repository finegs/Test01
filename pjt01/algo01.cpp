#if 1

//  merge sort : 20201009

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mmerge(int arr[], int arr_size, int tarr[], int start, int mid, int end);
void mmsort(int arr[], int arr_size, int start, int end);

void mmerge(int arr[], int tarr[], int start, int mid, int end) {
	int i,j,k,l;

	i = start;
	j = mid+1;
	k = start;

	while(i<=mid && j<=end) {
		if(arr[i]<=arr[j]) tarr[k++] = arr[i++];
		else tarr[k++] = arr[j++];
	}

	if(i>mid)
		for(l=j;l<=end;l++) tarr[k++]=arr[l];
	else
		for(l=i;l<=mid;l++) tarr[k++]=arr[l];

	for(l=start;l<=end;l++) arr[l]=tarr[l];
}

void mmsort(int arr[], int tarr[], int start, int end) {
	int mid;

	if(start>=end) return;
	mid = (start+end)/2;

	mmsort(arr, tarr, start, mid);
	mmsort(arr, tarr, mid+1, end);
	mmerge(arr, tarr, start, mid, end);

}


int main(int argc, char* argv[]) {
	int n,tt;
	int *arr;
	int *tarr;

	if(argc>1)
		n = atoi(argv[1]);
	else
		n = 100;

	if(!(arr = (int*)malloc(sizeof(int)*n))) {
		fprintf(stderr, "fail to malloc (arr) : %s.%d\n", __FILE__, __LINE__);
		return -1;
	}

	if(!(tarr = (int*)malloc(sizeof(int)*n))) {
		fprintf(stderr, "fail to malloc (tarr) : %s.%d\n", __FILE__, __LINE__);
		return -1;
	}

	srand((unsigned int)time(NULL));

	for(int i = 0;i<n;i++) arr[i]=((int)rand())%(n*n);
	for(int i = 0;i<n;i++) tarr[i]=0;

	tt = (int)time(NULL);
	mmsort(arr, tarr, 0, n-1);

	for(int i=0;i<n;i++) 
		printf("%d%s", arr[i],((i> 0 && i%30==0)?"\n":" "));
	printf("\n");
	tt = (int)time(NULL)-tt;
	printf("Elapsed Time  : %2d:%2d:%2d\n", (tt/3600), ((tt%3600)/60), ((tt%3600)%60));

	free(tarr);

	return 0;
}


#endif

#if 0

#include <cstdio>
#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

int findMinVertex(int* distance, bool* visited, int n)
{
	int minVertex = -1;
	for (size_t i = 0; i < n; i++)
	{
		if (visited[i]) continue;
		if (minVertex == -1 || distance[i] < distance[minVertex])
			minVertex = i;
	}
	return minVertex;
}

void dijkstra(int** edges, int n)
{
	int* distance = new int[n];
	bool* visited = new bool[n];

	for (size_t i = 0; i < n; i++)
	{
		distance[i] = INT_MAX;
		visited[i] = false;
	}

	distance[0] = 0;

	for (size_t i = 0; i < n-1; i++)
	{
		int minVertex = findMinVertex(distance, visited, n);
		visited[minVertex] = true;
		for (size_t j = 0; j < n; j++)
		{
			if (visited[j] || !edges[minVertex][j]) continue;

			int newDistance;
			if ((newDistance = distance[minVertex] + edges[minVertex][j]) < distance[j])
				distance[j] = newDistance;
		}
	}

	for (size_t i = 0; i < n; i++)
	{
		cout << i << " : " << distance[i] << endl;
	}

	delete[] distance;
	delete[] visited;
}

/* Input
  5 7
  0 1 4
  0 2 8
  1 2 2
  1 3 5
  2 3 5
  2 5 9
  3 4 4
*/

int main(int argc, char* argv[])
{
	int n;
	int e;

#if CIN_REDIRECT
	//std::cin.rdbuf(*std::ifstream("input.txt").rdbuf);

	//std::ifstream in("input.t/*xt");
	//std::streambuf *cinbuf = std::cin.rdbuf();
	//std::cin.rdbuf(in.rdbuf);*/
	fclose(stdin);
	freopen("input.txt", "r", stdin);
#endif

	cin >> n >> e;
	int** edges = new int*[n];
	for (size_t i = 0; i < n; i++)
	{
		edges[i] = new int[n];
		for (size_t j = 0; j < n; j++)
		{
			edges[i][j] = 0;
		}
	}
	//memset(edges, 0, sizeof(int)*(n*n));

	for (size_t i = 0; i < e; i++)
	{
		int f, s, weight;
		cin >> f >> s >> weight;
		edges[f][s] = weight;
		edges[s][f] = weight;
	}

	cout << endl;
	dijkstra(edges, n);

	for (size_t i = 0; i < n; i++)
	{
		delete[] edges[i];
	}
	delete[] edges;

	return EXIT_SUCCESS;
}

#endif



#if 0

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int  number, e;
int** a;
int* d;
bool* v;

int getSmallIndex()
{
	int min = INT_MAX;
	int index = 0;
	for (size_t i = 0; i < number; i++)
	{
		if (v[i]) continue;
		if (min < d[i]) continue;
		min = d[i];
		index = i;
	}
	return index;
}

void dijkstra(int start)
{
	for (size_t i = 0; i < number; i++)
	{
		d[i] = a[start][i];
		v[i] = false;
	}

	v[start] = true;
	for (size_t i = 0; i < number-2; i++)
	{
		int current = getSmallIndex();
		v[current] = true;
		for (int j = 0; j < number; j++)
		{
			if (v[j]) continue;
			//if (!a[current][j]) continue;
			if (d[current] + a[current][j] < d[j])
				d[j] = d[current] + a[current][j];
		}
	}
}



int main(int argc, char* argv[])
{
#if CIN_REDIRECT
	//std::cin.rdbuf(*std::ifstream("input.txt").rdbuf);

	//std::ifstream in("input.t/*xt");
	//std::streambuf *cinbuf = std::cin.rdbuf();
	//std::cin.rdbuf(in.rdbuf);*/
	fclose(stdin);
	freopen("input.txt", "r", stdin);
#endif

	cin >> number >> e;

	//number+=1; // array index start from 1

	a  = new int*[number];
	for (size_t i = 0; i < number; i++)
	{
		a[i] = new int[number];
		for (size_t j = 0; j < number; j++)
		{
			a[i][j] = 0;
		}
	}

	d = new int[number];
	v = new bool[number];
	memset(d, 0, sizeof(int)*number);

	for (size_t i = 0; i < e; i++)
	{
		int f, s, weight;
		cin >> f >> s >> weight;
		a[f][s] = weight;
		a[s][f] = weight;
	}

	cout << endl;

	dijkstra(0);


	for (size_t i = 0; i < number; i++)
	{
		cout << i << " : " << d[i] << endl;
	}

	for (size_t i = 0; i < number; i++)
	{
		delete[] a[i];
		a[i] = nullptr;
	}
	delete[] a;
	a = nullptr;

	return EXIT_SUCCESS;
}


#endif

