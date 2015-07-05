#include"stdio.h"
#include"iostream"
#include"vector"
#include"algorithm"
#include"utility"

using namespace std;

//Dijkstra Algorithm:
class Dijkstra_gpf{
typedef int dijk_type;//cost data type

public:
		//Construct Function
		Dijkstra_gpf(int Nedge,int Nnode):inf(-1),edge_num(Nedge),node_num(Nnode){
			//Create Edge Array
			edge=new dijk_type*[Nnode];
			for(int i=0;i<Nnode;i++){
				edge[i]=new dijk_type[Nnode];
			}
			//Create dist array:
			dist=new dijk_type[Nnode];
			//Create vis array:
			vis=new bool[Nnode];

			//init:
			for(int i=0;i<Nnode;i++){
				for(int j=0;j<Nnode;j++)edge[i][j]=inf;
				dist[i]=inf;
				vis[i]=false;
			}

		}
		 int edge_weight_input(){
		 	//ToDo..
			int a,b;	
			cout<<"Please input node index a&b(start with index 1)"<<endl;

			while(scanf("%d%d",&a,&b)==2){
				if(a==-1||b==-1){break;}
				a--;
				b--;

				dijk_type val;
				cout<<"Please input edge weight:"<<endl;
				cin>>val;
				edge[a][b]=val;
				edge[b][a]=val;

				cout<<"Please input node index a&b"<<endl;
			}
		 }

		 dijk_type dijkstra_n2(int ind1,int ind2){
		    Ps=ind1;
			Pt=ind2;
			dist[ind1]=0;

			//O(n2) algorithm
			for(int i=0;i<node_num;i++){

				//rep N times
				dijk_type min_val=inf;
				int min_ind=-1;
				for(int j=0;j<node_num;j++){
					//find cur min dist
					if(vis[j]==true){continue;}
					if(dist[j]==inf){continue;}
					if(min_val==inf){
						min_val=dist[j];
						min_ind=j;
					}else if(min_val>dist[j]){
						min_val=dist[j];
						min_ind=j;
					}
				}
				if(min_ind==-1)break;//No route to sink
				vis[min_ind]=true;
                //cout<<"rep"<<i<<endl;
				//found destination:
				if(vis[ind2]==true){break;}

				//relax dist
				for(int j=0;j<node_num;j++){
                    //printf("j=%d,min_ind=%d\n",j,min_ind);
					if(vis[j]==true)continue;
					if(edge[min_ind][j]==inf)continue;

					if(dist[j]==inf){
						if(dist[min_ind]+edge[min_ind][j]!=inf){
							dist[j]=dist[min_ind]+edge[min_ind][j];
						}
					}
					else{
						if(dist[min_ind]+edge[min_ind][j]<dist[j]){
							dist[j]=dist[min_ind]+edge[min_ind][j];
						}
					}
				}

			}

		 	return dist[ind2]==inf?-1:dist[ind2];
		 }

		 ~Dijkstra_gpf(){
		    //recollect garbage
			for(int i=0;i<node_num;i++){
				delete[] edge[i];
			}
		 	delete[] edge;
			delete[] dist;
			delete[] vis;
		 }
private:
	 int edge_num,node_num;
	 int Ps,Pt;
	 dijk_type **edge;//Edge of the graph
	 dijk_type *dist;//distance from start to sink
	 bool *vis;
	 const dijk_type inf; 
};


int main(){
	
	int ne,nn;	
	puts("Please input the graph:(nodes and edges)");
	cin>>nn>>ne;
	
	Dijkstra_gpf di(ne,nn);

	di.edge_weight_input();
	
	int s,t;
	cout<<"Please input dijkstra source & sink:"<<endl;

	cin>>s>>t
	cout<<"dijkstra distance from "<<s<<" to "<<t<<" is "<<di.dijkstra_n2(s-1,t-1)<<endl;
		
	
	return 0;
}
