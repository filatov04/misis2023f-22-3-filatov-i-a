#include<set>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<vector>
#include<string>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define INF 0x3f3f3f3f
#define N 200010
#define maxn 1000000
#define ll long long
#define pi 4*atan(1.0)
#define f1(i,j,k) for(int i=j;i<=k;i++)
#define f2(i,j,k) for(int i=j;i>=k;i--)
const double EPS = 1E-8;
int t, n;
struct node {
	int num, rating, like, rr;
}a[N];
bool cmp(node aa, node bb) {
	if (aa.like != bb.like) return aa.like < bb.like;
	return aa.rating < bb.rating;
}
bool cmp1(node cc, node dd) {
	return cc.num < dd.num;
}
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		char s[N] = "";
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i].rating);
			a[i].num = i;
		}
		for (int i = 1; i <= n; i++) {
			scanf("%1d", &a[i].like);
		}
		std::sort(a + 1, 1 + a + n, cmp);
		for (int i = 1; i <= n; i++) {
			a[i].rr = i;
		}
		std::sort(a + 1, 1 + a + n, cmp1);
		for (int i = 1; i <= n; i++) {
			printf("%d", a[i].rr);
			if (i != n) printf(" ");
		}
		printf("\n");
	}
}