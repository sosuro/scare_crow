#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

int maps[1005][1005];
int smap[1005][1005];
int d[4][2] = {1,0,-1,0,0,1,0,-1};

typedef struct nodep {
	int x,y,s;
	nodep( int X, int Y, int S ){x = X;y= Y;s = S;}
	nodep(){}
}point;
point queue[1000005];

int bfs( int sx, int sy, int ex, int ey, int R, int C )
{
	int move = 0,save = 0;
	queue[save ++] = point( sx, sy, 0 );
	smap[sx][sy] = 1;
	while ( move < save ) {
		point q,p = queue[move ++];
		for ( int i = 0 ; i < 4 ; ++ i ) {
			q.x = p.x + d[i][0];
			q.y = p.y + d[i][1];
			q.s = p.s + 1;
			if ( q.x >= 0 && q.x < R && q.y >= 0 && q.y < C )
			if ( !smap[q.x][q.y] && !maps[q.x][q.y] ) {
				smap[q.x][q.y] = 1;
				queue[save ++] = q;
			}
			if ( q.x == ex && q.y == ey ) return q.s;
		} 
	}
}

int main()
{
	int R,C,id,n,m,k,sx,sy,ex,ey;
	while ( scanf("%d%d",&R,&C) && R+C ) {
		memset( maps, 0, sizeof(maps) );
		memset( smap, 0, sizeof(smap) );
		scanf("%d",&n);
		for ( int i = 0 ; i < n ; ++ i ) {
			scanf("%d%d",&id,&m);
			for ( int j = 0 ; j < m ; ++ j ) {
				scanf("%d",&k);
				maps[id][k] = 1;
			}
		}
		scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
		printf("%d\n",bfs(sx,sy,ex,ey,R,C));
	}
	return 0;
}