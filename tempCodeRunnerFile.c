
void BubbleSort(int Array [], int n ){
 bool change = true ; 
 int i ; 
 while (change)
 {
   change = false;
   for (i=0 ;i<n-1 ; i++){
    if (Array[i]>Array[i+1]){
       Swap(&Array[i],&Array[i+1]);
       change=true;
    }
   }
 }
 
}