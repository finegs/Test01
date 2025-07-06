#if 1
#include <cstdio>
#include <iostream>

int main(int argc, char **argv) {
  for (int i = 1; i < argc; i++) {
    printf("argv[%d]=%s\n", i, argv[i]);
  }
  return 0;
}
#endif

#if 0 /// ProblemE:트리전구3
/**
title : jungol_1747_트리전구

Define :
D[i][j][k] = i-1번 전구까지 처리하고
i번 전구가 j색을 i+1번 전구가 k번 색을 나타낼 때 최소 스위치 조작 횟수의 합
Recurrence Relation :
cost[c2] - i+2번 전구를 t번 색으로 하는 조작횟수
cost[c1] - i+1번 전구를 s번 색으로 하는 조작횟수
cost[c] - i번 전구를 dest[i]번 색으로 하는 조작횟수
i+2번 전구를 t번으로 할 때는 i+1번과 i번 전구의 색번호도 바뀐다.
i+1번 전구를 s번으로 할 때는 i번 전구의 색번호도 바뀐다.

costSum = D[i][j][k] + cost[c2] + cost[c1] + cost[c];
if (D[i + 1][s][t] > costSum) D[i + 1][s][t] = costSum;
*/
#include <cstdio>

const int LM = 104;
const int INF = 1001;
int N, D[LM][10][10];
int cost[] = { 0, 1, 1, 1, 2, 2, 2, 1, 1, 1 };
int A[LM], B[LM], dest[LM];

int main(){
	//freopen("in.txt", "r", stdin);
	scanf("%d", &N);
	int i, j, k, s, t;
	for (i = 0; i < N; ++i) scanf("%1d", A + i);
	for (i = 0; i < N; ++i) scanf("%1d", B + i);
	for (i = 0; i<N; ++i) dest[i] = (B[i] - A[i] + 10) % 10; // ↗방향
	for (i = 0; i <= N; ++i)for (j = 0; j < 10; j++)
		for (k = 0; k<10; k++) D[i][j][k] = INF;
	D[0][0][0] = 0;
	for (i = 0; i<N; ++i)for (j = 0; j<10; j++)for (k = 0; k<10; k++)if (D[i][j][k]<INF){
		/*
		i번 전구가 j번 색을 i+1번 전구가 k번 색을 가진 상태이다.
		i+1번을 s번으로 i+2번을 t번색을 바꿀때 최소 누적 비용을
		D[i+1][s][t]에 업데이트 한다.
		*/
		for (s = 0; s<10; ++s)for (t = 0; t<10; ++t){
			int c2 = t; // i+2번 전구를 (0) => (t) 돌리기

			// i+1번 전구가 (k+t) => (s)가 되기 위하여↗방향으로 움직인 거리
			int c1 = (s - (k + t) + 20) % 10;

			// i번 전구가 (j + t + c1) => dest[i]가 되기 위하여↗방향으로 움직인 거리
			int c = (dest[i] - (j + t + c1) + 30) % 10;

			int costSum = D[i][j][k] + cost[c] + cost[c1] + cost[c2];
			if (D[i + 1][s][t] > costSum) D[i + 1][s][t] = costSum;
		}
	}
	printf("%d\n", D[N][0][0]);
	return 0;
}
#endif // ProblemE

#if 0 /// ProblemA:경찰차
/*
title : jungol_1820_경찰차

Define : 
D[i][j] = 1번 경찰차가 i번 사건에 2번 경찰차가 j번 사건에 있을 때 최소 이동거리의 합
Recurrence Relation:
k = Max(i, j) + 1;
D[k][j] = Max(D[k][j],  D[i][j] + getDist(i, k))
D[i][k] = Max(D[i][k],  D[i][j] + getDist(j, k))
*/

#include <stdio.h>

const int LM = 1004;
int N, W, x[LM], y[LM], D[LM][LM], P[LM][LM];

inline int Abs(int t) { return t < 0 ? -t : t; }
inline int getDist(int s, int e){ return Abs(x[s] - x[e]) + Abs(y[s] - y[e]); }

void DPfunc(){
	int i, j, k;
	for (i = 0; i <= W; i++)
		for (j = 0; j <= W; j++) D[i][j] = (int)1e8;
	D[0][1] = 0;
	for (i = 0; i < W; i++) {
		for (j = 1; j < W; j++) {
			if (i>j) k = i + 1;
			else k = j + 1;
			if (D[k][j] > D[i][j] + getDist(i, k)){
				D[k][j] = D[i][j] + getDist(i, k);
				P[k][j] = i;
			}
			if (D[i][k] > D[i][j] + getDist(j, k)) {
				D[i][k] = D[i][j] + getDist(j, k);
				P[i][k] = j;
			}
		}
	}
}

void out(int x, int y){
	if (x + y <= 1) return;
	if (x > y) {
		out(P[x][y], y);
		printf("1\n");
	}
	else {
		out(x, P[x][y]);
		printf("2\n");
	}
}

int main(){
	int i, j, ans = (int)1e8, ex, ey;
	scanf("%d %d", &N, &W), ++W;
	x[0] = y[0] = 1;
	x[1] = y[1] = N;
	for (i = 2; i <= W; i++) scanf("%d %d", x + i, y + i);
	DPfunc();
	for (i = 0; i <= W; i++) {
		if (ans > D[i][W]) {
			ans = D[i][W];
			ex = i, ey = W;
		}
		if (ans > D[W][i]) {
			ans = D[W][i];
			ex = W, ey = i;
		}
	}
	printf("%d\n", ans);
	out(ex, ey);
	return 0;
}
#endif // ProblemA

#if 0 /// ProblemB:고돌이고소미
/*
title : jungol_20528_고돌이고소미

Define :
state[a][b][c][d] : 돌이가 (a, b)로 소미가 (c, d)로 이동하는데 걸리는 최단 시간

Recurrence Relation :
if(state[a][b][c][d]>=0)
state[a+p][b+q][c+r][d+s] = Min(state[a+p][b+q][c+r][d+s], state[a][b][c][d] + 1)
(단, -1 <= p, q, r, s <= 1)
*/

// 고돌이고소미c_version
#if 0
#include <stdio.h>
#define LM 28
#define INF 1048576

int N, A[LM][LM], dhr, dhc, shr, shc;
int state[LM][LM][LM][LM], fr, re;
typedef struct Data{
	int dr, dc, sr, sc, lev;
}Data;
Data Q[1 << 20];

int enque(int w, int x, int y, int z, int nl){
	if (!A[w][x] || !A[y][z] || state[w][x][y][z] <= nl) return 0;
	Q[re].dr = w, Q[re].dc = x, Q[re].sr = y, Q[re].sc = z;	/****/
	state[w][x][y][z] = Q[re].lev = nl;	/****/
	if (dhr == w && dhc == x && shr == y && shc == z) return 1;
	re++;
	return 0;
}

int bfs(){
	int i, j, k, l;
	for (; fr < re; fr++){
		Data t = Q[fr];
		for (i = -1; i < 2; ++i)for (j = -1; j < 2; ++j)for (k = -1; k < 2; ++k)for (l = -1; l < 2; ++l){
			int rv = enque(t.dr + i, t.dc + j, t.sr + k, t.sc + l, t.lev + 1); /****/
			if (rv) return state[dhr][dhc][shr][shc];
		}
	}
	return 0;
}

int Abs(int a){ return a<0 ? -a : a; }
int main(){
	int i, j, k, l, a, b, c, d;
	//freopen("in.txt", "r", stdin);
	scanf("%d", &N);

	// preprocess state table
	for (i = 0; i <= N + 1; ++i)for (j = 0; j <= N + 1; ++j){
		for (k = 0; k <= N + 1; ++k)for (l = 0; l <= N + 1; ++l) {
			int id = Abs(i - k), jd = Abs(j - l);
			if (id<2 && jd<2) state[i][j][k][l] = -1;
			else state[i][j][k][l] = INF;
		}
	}
	scanf("%d %d %d %d", &a, &b, &dhr, &dhc);
	scanf("%d %d %d %d", &c, &d, &shr, &shc);
	for (i = 1; i <= N; ++i){
		for (j = 1; j <= N; ++j){
			scanf("%d", &k);
			A[i][j] = !k;
		}
	}
	enque(a, b, c, d, 0);/***/
	printf("%d\n", bfs());
	return 0;
}

#endif // 0

// 고돌이고소미cpp _ version
#if 1

#include <cstdio>

const int LM = 28;
const int INF = (int)1e9;
int N, A[LM][LM], dhr, dhc, shr, shc;
int state[LM][LM][LM][LM], fr, re;
struct Data{
	int dr, dc, sr, sc, lev;
	int enque(int w, int x, int y, int z, int nl){
		if (!A[w][x] || !A[y][z] || state[w][x][y][z] <= nl) return 0;
		dr = w, dc = x, sr = y, sc = z, state[w][x][y][z] = lev = nl;
		if (dhr == w && dhc == x && shr == y && shc == z) return 1;
		re++;
		return 0;
	}
}Q[1 << 20];

int bfs(){
	int i, j, k, l;
	for (; fr < re; fr++){
		Data t = Q[fr];
		for (i = -1; i < 2; ++i)for (j = -1; j < 2; ++j)for (k = -1; k < 2; ++k)for (l = -1; l < 2; ++l){
			int rv = Q[re].enque(t.dr + i, t.dc + j, t.sr + k, t.sc + l, t.lev + 1);
			if (rv) return state[dhr][dhc][shr][shc];
		}
	}
	return 0;
}

int Abs(int a){ return a < 0 ? -a : a; }
int main(){
	//freopen("in.txt", "r", stdin);
	scanf("%d", &N);
	int i, j, k, l, a, b, c, d;
	// preprocess state table
	for (i = 0; i <= N + 1; ++i)for (j = 0; j <= N + 1; ++j){
		for (k = 0; k <= N + 1; ++k)for (l = 0; l <= N + 1; ++l) {
			int id = Abs(i - k), jd = Abs(j - l);
			if (id < 2 && jd < 2) state[i][j][k][l] = -1;
			else state[i][j][k][l] = INF;
		}
	}
	scanf("%d %d %d %d", &a, &b, &dhr, &dhc);
	scanf("%d %d %d %d", &c, &d, &shr, &shc);
	for (i = 1; i <= N; ++i){
		for (j = 1; j <= N; ++j){
			scanf("%d", &k);
			A[i][j] = !k;
		}
	}
	Q[re].enque(a, b, c, d, 0);
	printf("%d\n", bfs());
	return 0;
}
#endif // 1
#endif // ProblemB

#if 0 /// ProblemC:트리전구1
/*
title : jungol_3002_트리전구1
loop and math(modulo)
*/

#include <cstdio>

const int LM = (int)1e5 + 4;
int N, K, A[LM], ans;

int main(){
	scanf("%d %d", &N, &K);
	int i, v, spin;
	for (i = 0; i<N; ++i) scanf("%1d", A + i);
	for (i = 0; i<N; ++i){
		scanf("%1d", &v);
		spin = (A[i] - v + 10) % 10;
		spin = spin>5 ? 10 - spin : spin;
		ans += (spin + K - 1) / K;
	}

	printf("%d\n", ans);
	return 0;
}
#endif // ProblemC

#if 0 /// ProblemD:트리전구2
/*
title : jungol_3003_트리전구2
Define:
D[i][j]   : i-1번 전구까지 모두 맞추었고 	i번 전구가 j번 위치에 있을 때 최소 조작 횟수의 합
Recurrence Relation:
D[i+1][s] = D[i][j] + T[s] + T[jj]
(T[s]:i+1번 전구를 s번색으로 할 때 비용, T[jj]:i번전구를 맞추는 비용)
*/
#include <cstdio>
#define SW 0

const int INF = (int)1e9;
const int LM = 10004;
int N, dest[LM], D[LM][11], T[] = { 0, 1, 1, 1, 2, 2, 2, 1, 1, 1 };
char A[LM], B[LM];

int main(){
	scanf("%d %s %s", &N, A, B);
	int i, j, s;
	for (i = 0; i < N; ++i){ // 방향을 고려한 두 상태의 차 구하기
		dest[i] = (B[i] - A[i] + 10) % 10;
	}
	for (i = 0; i <= N; ++i) for (j = 0; j < 10; ++j){
		D[i][j] = INF;
	}
	D[0][0] = 0;
	for (i = 0; i < N; ++i)for (j = 0; j < 10; ++j) if (D[i][j] < INF){
		for (s = 0; s < 10; ++s){              // i+1번 전구의 색을 가정하기
			int jj = (j + s) % 10;             // i번 전구의 이동된 전구 번호 구하기
			jj = (dest[i] - jj+ 10) % 10;     // i번 전구를 dest[i]로 이동
			int cost = D[i][j] + T[s] + T[jj]; // 비용계산
			if (D[i + 1][s] > cost){
				D[i + 1][s] = cost;
			}
		}
	}
	printf("%d\n", D[N][0]);
	return 0;
}
#endif // ProblemD
