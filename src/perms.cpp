#include <Rcpp.h>
using namespace Rcpp;

void swap(IntegerVector&,const int, const int);
int fact(int);
void permute(IntegerMatrix&, IntegerVector&,const int, int&);

//' @title Perms
//' @description
//' \code{perms} returns all permutations of set {1,2,..,n}
//' 
//' @param n - integer 
//' 
//' @examples
//' perms(2)
//' 
//' @return \code{IntegerArray(n!,n)} containing all permutations
//' 
//' @export
// [[Rcpp::export]]
IntegerMatrix perms(int n) {
   
   if(n<1)
     throw(exception("Invalid n value"));
   
   IntegerVector nums(n);
   
   for(int i=1;i<=n;i++)
     nums(i-1)=i;
     
   IntegerMatrix result(fact(n),n);
   
   int permnum=0; 
   
   permute(result,nums,n,permnum);

   return result;

}

void swap(IntegerVector& v,const int i, const int j) {
  
  int temp = v(i);
  v(i) = v(j);
  v(j) = temp;
  
}

int fact(int n){
  
  int fact;
  
  for (int i=0; i<=n; i++)
		if (i==0)
		  fact=1;
		else
		  fact=fact*i;
        
  return(fact);
  
}

void permute(IntegerMatrix& m,IntegerVector& v,const int k, int& permnum){
 
  if(k==0){
    for(int r=0; r<v.size();r++)
      m(permnum,r)=v(r);
    permnum=permnum+1;
  }
  else
    for(int t=k-1; t>=0;t--){
      swap(v,t,k-1);
      permute(m,v,k-1,permnum);
      swap(v,k-1,t);
    }
   
}