import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;

public class ReversalChain{
  public int minReversal(String init,String goal){
    return reverse(init.toCharArray(),goal.toCharArray(),0,init.length()-1);
  }

  int reverse(char[] init,char[] goal,int a,int b) {
    int i,j;
    for(i=0;a+i<init.length&&init[a+i]==goal[a+i];i++)
      ;
    for(j=0;b-j>=0&&init[b-j]==goal[b-j];j++)
      ;

    if(i+j!=0&&(int i=reverse(init,goal,a+i,b-j))!=-1)
      return i+1;
    return -1;
  }

  void reverse(char[] init,int a,int b){
    for(int i=0;i<(b-a)/2;i++){
      char tmp=init[a+i];
      init[a+i]=init[b-j];
      init[b-j]=tmp;
    }
  }
}

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
