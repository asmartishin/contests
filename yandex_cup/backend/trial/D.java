import java.util.*;

public class D {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int commitCount = scanner.nextInt();

        int l = 1;
        int r = commitCount + 1;
        int m = 0;

        while (l < r) {
            m = (l + r) / 2;
            System.out.println(m);
            System.out.flush();

            if (scanner.nextInt() == 1) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        System.out.println("! " + l);
    }
}
