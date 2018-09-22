import java.util.*;
import java.io.*;

public class b {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);
        solve(in, out);
        out.close();
    }

    public static void solve(InputReader in, PrintWriter out) {
        int q = in.nextInt();

        for (int i = 0; i < q; ++i) {
            long n = in.nextLong();
            long m = in.nextLong();
            long k = in.nextLong();

            if (k < Math.max(n, m)) {
                out.println(-1);
            } else {
                if (k % 2 == 0) {
                    if (n % 2 == 1) {
                        --k;
                    }

                    if (m % 2 == 1) {
                        --k;
                    }
                } else {
                    if (n % 2 == 0) {
                        --k;
                    }

                    if (m % 2 == 0) {
                        --k;
                    }
                }
                out.println(k);
            }
            out.flush();
        }
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
