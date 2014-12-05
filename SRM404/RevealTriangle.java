import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;


public class RevealTriangle
{
    public String[] calcTriangle(String[] questionMarkTriangle)
    {
        String[] triangle = questionMarkTriangle;
        for(int row=triangle.length-2; row>=0; row--) {
            int known;
            for(known=0; known<triangle.length-row && !Character.isDigit(triangle[row].charAt(known)); known++);
            char[] array = triangle[row].toCharArray();
            for(int i=known-1; i>=0; i--) {
                array[i] = minus(triangle[row+1].charAt(i), triangle[row].charAt(i));
            }
            for(int i=known+1; i<triangle.length-row; i++) {
                array[i] = minus(triangle[row+1].charAt(i-1), triangle[row].charAt(i-1));
            }
            triangle[row] = new String(array);
        }
        return triangle;
    }

    char minus(char a, char b) {
        int ret = ((a - b) + 10) % 10;
        return (char)(ret + 'a');
    }


}
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
