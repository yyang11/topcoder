
public class KSubString {
  private class Sum implements Comparable{
    int start, val;
    public Sum(int start, int val) {
      this.start = start;
      this.val = val;
    }
    public int compareTo(Object o) {
      Sum s = (Sum)o;
      if(val < s.val)
        return -1;
      if(val == s.val)
        return start - s.start;
      return 1;
    }
  }

  int[] maxSubstring(int A0, int X, int Y, int M, int n) {
    int A = new int[n];
    long ss = new long[n];
    A[0] = A0;
    ss[0] = 0;
    ss[1] = A[0];
    for(int i=1; i<A.length; i++) {
      A[i] = ((long)A[i-1] * X + Y) % M;
      ss[i] = ss[i-1] + A[i];
    }
    long retVal = 1l << 60;
    int retK = 0;
    for(int k=1; k<n/2; k++) {
      Sum[] sums = new Sum[n];
      for(int i=0; i<n-len; i++) {
        sums[i] = new Sum(i, ss[i + len] - ss[i]);
      }
      Arrays.sort(sums);
      if(retVal > 0) {
        for(int i = 0; i < sums.length - 1; i++) {
          if(sums[i].val - sums[i - 1].val < retVal && sums[i].start - sums[i - 1].start >= k) {
            retVal = sums[i].val - sums[i - 1].val;
            retK = k;
          }
        }
      }
      else {
        //retVal == 0
        for(int i = 0; i < sums.length; i++) {
          int j = i + 1;
          for( ; sums[j] == sums[i]; j++);
          if(sums[j - 1].start - sums[i].start >= k) {
            retK = k;
          }
        }
      }
    }
    return new int[] {retK, (int)retVal};
  }
}
