import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;


public class StrongPrimePower
{
  public int[] baseAndExponent(String str){
    long n=Long.parseLong(str);
    for(int q=2;q<60;q++){
      double fp=Math.pow(n,1.0/q);
      int p=(int)Math.round(fp);
      if(!isPrime(p)) continue;
      long x=1;
      for(int i=0;i<q;i++) x*=p;
      if(x==n) return new int[]{p,q};
    }
    return new int[]{};
  }
  boolean isPrime(long x) {
    for(int i=2;i*i<=x;i++) if(x%i==0) return false;
    return true;
  }

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
