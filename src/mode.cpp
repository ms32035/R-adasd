#include <Rcpp.h>
using namespace Rcpp;

//' @title Mode
//' @description
//' \code{mode} returns the most frequent value of an integer vector
//' 
//' @param x - An integer vector
//' 
//' @examples
//' mode(c(1,2,2))
//' 
//' @return Most frequent value of \code{x}
//' 
//' @export
// [[Rcpp::export]]
int mode(IntegerVector x) {
   
   if(x.size()==0)
    return NA_INTEGER;
   
   IntegerVector y = clone(x);
   std::sort(y.begin(),y.end());

   int maxCount=1, mode=y[0], count=1;



   for(int i=1;i<y.size();i++){
     if(y[i]==y[i-1])
      count++;
     else
      {
        if(count>maxCount)
        {
          maxCount=count;
          mode=y[i-1];
        }
        count=1;
      }
   }

  if(count>maxCount)
    mode=y[y.size()-1];


   return mode;
   
}
