import java.util.*;
import java.io.*;

public class d {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);
        solve(in, out);
        out.close();
    }

    public static void solve(InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int[] a = new int[n];

        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
        }

        int m = in.nextInt();
        int[] b = new int[m];

        for (int i = 0; i < m; ++i) {
            b[i] = in.nextInt();
        }

        int ai = 0, bi = 0;
        int result = 0;
        long aSum = 0, bSum = 0;

        while (ai < n && bi < m) {
            ++result;

            aSum = a[ai++];
            bSum = b[bi++];

            while (aSum != bSum) {
                if (aSum < bSum && ai < n) {
                    aSum += a[ai++];
                } else if (aSum > bSum && bi < m) {
                    bSum += b[bi++];
                } else {
                    break;
                }
            }
        }

        if (ai < n) {
            for (int i = ai; i < n; ++i) {
                aSum += a[ai];
            }
        }

        if (bi < m) {
            for (int i = bi; i < m; ++i) {
                bSum += b[bi];
            }
        }

        if (aSum != bSum) {
            result = -1;
        }

        out.println(result);
        out.flush();
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }
    }
}
