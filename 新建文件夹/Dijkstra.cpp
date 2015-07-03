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
		Dijkstra_gpf(int Nedge,int Nnode):edge_num(Nedge),node_num(Nnode){
			//Create Edge Array
			edge=new int*[Nnode];
			for(int i=0;i<Nnode;i++){
				edge[i]=new int[Nnode];
			}

		}
		 int edge_weight_input(){
		 	//ToDo..
		 }

		 dijk_type dijkstra_n2(int ind1,int ind2){
		 	return ind1+ind2;
		 }

		 ~Dijkstra_gpf(){
			for(int i=0;i<node_num;i++){
				delete[] edge[i];
			}
		 	delete[]edge;
		 }
private:
	 int edge_num,node_num;
	 dijk_type **edge;
		 
};


int main(){


	return 0;
}
