//Abhishek Bansal
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define sout(n) printf("%d\n",n)
#define loop(a,b) for(i=a;i<b;i++)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define SET(a,b) memset(a,b,sizeof(a))
#define l(k) 2*k
#define r(k) l(k)+1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef long long int lli;
typedef struct node{
	int u,v;
	lli w;
}node;
typedef struct node1{
	int v;
	lli w;
}node1;
node1 heap1[10000];
int last1=0;
typedef struct vert{
	int v;
	lli w;
	struct vert* next;
}vert;
node heap[10000];
vert* graph[10000];
int visit[10000];
int last=0;
node mn(int u,int v,lli w){
	node n;
	n.u=u;n.v=v;n.w=w;
	return n;
}
void swap(node* a,node* b){
	node tmp=*a;
	*a=*b;
	*b=tmp;
	return;
}
mn1(lli d,int v){
	node1 n;
	n.w=d;n.v=v;
	return n;
}
void swap1(node1* a,node1* b){
	node1 tmp=*a;
	*a=*b;
	*b=tmp;
	return;
}
void insert1(node1 n){
	heap1[++last1]=n;
	int k=last1;
	while(k!=1&&heap1[k].w<heap1[k/2].w){swap1(&heap1[k],&heap1[k/2]);k/=2;}
	return;
}
void delete1(){
	if(last1==0)return;
	heap1[1]=heap1[last1--];
	int k=1;
	while(k<=last1){
		if(l(k)>last1)break;
		else if(r(k)>last1){
			if(heap1[l(k)].w<heap1[k].w){swap(&heap1[k],&heap1[l(k)]);k=l(k);}
			else break;
		}
		else{
			if(heap1[k].w<heap1[l(k)].w&&heap1[k].w<heap1[r(k)].w)break;
			else{
				int t=heap1[l(k)].w<heap1[r(k)].w?l(k):r(k);
				swap(&heap1[k],&heap1[t]);
				k=t;
			}
		}
	}
	return;
}
void insert(node n){
	heap[++last]=n;
	int k=last;
	while(k!=1&&heap[k].w<heap[k/2].w){swap(&heap[k],&heap[k/2]);k/=2;}
	return;
}
void delete(){
	if(last==0)return;
	heap[1]=heap[last--];
	int k=1;
	while(k<=last){
		if(l(k)>last)break;
		else if(r(k)>last){
			if(heap[l(k)].w<heap[k].w){swap(&heap[k],&heap[l(k)]);k=l(k);}
			else break;
		}
		else{
			if(heap[k].w<heap[l(k)].w&&heap[k].w<heap[r(k)].w)break;
			else{
				int t=heap[l(k)].w<heap[r(k)].w?l(k):r(k);
				swap(&heap[k],&heap[t]);
				k=t;
			}
		}
	}
	return;
}
vert* ins(vert* head,int v,int w){
	vert* new=(vert*)malloc(sizeof(vert));
	new->v=v;new->w=w;
	new->next=head;
	return new;
}
node top(){return heap[1];}
int  prims(int s){
	int flag=1;
	SET(visit,0);
	dist[s]=0;
	visit[s]=1;
	vert* tmp;
	tmp=graph[s];
	while(tmp){
		insert(mn(s,tmp->v,tmp->w));
		tmp=tmp->next;
	}
	while(last>0){
		node e=top();
		int t=visit[e.u]==0?e.u:e.v;
		int t1=visit[e.u]!=0?e.u:e.v;
		if(dist[t1]+e.w==mindist[t]){
			visit[t]=1;
			delete();
		}
		tmp=graph[t];
		while(tmp){
			if(!visit[tmp->v]){
				insert(mn(t,tmp->v,tmp->w));
			}
			tmp=tmp->next;
		}
	}
	return ans;
}
void dij(int s){
	SET(visit,0);
	int i;
	for(i=0;i<=n;i++)dist[i]=inf;
	dist[s]=0;
	insert1(dist[s],s);
	while(last1){
		node1 t=top1();
		if(!visit[t.v]){
			visit[t.v]=1;
			vert* tmp=graph[t.v];
			while(tmp){
				if(dist[tmp->v]>dist[t.v]+tmp->w){
					dist[tmp->val]=dist[t.v]+tmp->w;
					insert1(mn1(dist[tmp->v],tmp->v));
				}
			}
		}
	}
	return;
}
int main(){
	int n,m,u,v;
	lli w;
	si(n);si(m);
	while(m--){si(u);si(v);sll(w);
		graph[u]=ins(graph[u],v,w);
	}
	printf("%lld\n",prims(1));
	return 0;
}
