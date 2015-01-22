#include <Rcpp.h>
#include <queue>
#include <vector>
#define INFINITE_DISTANCE 999999999
#define intpair std::pair<int,int>

using namespace Rcpp;

struct comp {
bool operator() (const intpair &a, const intpair &b) {
  return a.second > b.second;
  }
};


//' @title Shortest path
//' @description
//' \code{shortestpath} is an implementation of Dijkstra's algorithm to compute
//' the length of the shortest path between vertices \code{x} and \code{j} represented 
//' by 0-1 matrix \code{G}
//' @param G - \code{n*n} matrix with values in \{0,1\} 
//' @param x - An integer number of starting vertex
//' @param y - An integer number of ending vector
//' 
//' @examples
//' shortestpath(matrix(c(0,1,0,0),nrow=2),1,2)
//' 
//' @return Length of the longest path or 999999999 if there is no path between vertices
//' 
//' @export
// [[Rcpp::export]]
int shortestpath(IntegerMatrix G,int x, int y) {
   
   int n = G.nrow();
   
   int node, nodeNext, dsf;
   
   if(G.ncol() != n)
     throw(exception("Matrix G should be n*n"));
   
   if(x <=0 || y <=0 || x > n || y >n )
     throw(exception("Invalid vertex parameters"));
   
   int dist[n+1];
   
   std::priority_queue< intpair, std::vector< intpair >, comp > pq;
   
   for(int i=1; i<=n; i++)
    dist[i] = INFINITE_DISTANCE;
    
   dist[x] = 0;
   pq.push(intpair(x,0));
   
   while(!pq.empty()){
     
     node=pq.top().first;
     dsf=pq.top().second;
     pq.pop();
     
     if(dist[node] < dsf)
       continue;
     
     for(int i=0;i<n;i++){
       if(G(node-1,i)==1){
         nodeNext=i+1;
         if(dist[nodeNext]>dist[node]+1){
           dist[nodeNext]=dist[node]+1;
           pq.push(intpair(nodeNext,dist[nodeNext]));
         }
       }
       else if(G(node-1,i)!=0)
         throw(exception("Invalid matrix values"));
     }
     
   }
      
   return dist[y];
}