import java.util.*;
import java.util.stream.Collectors;

public class A {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        Set<Character> gems = new HashSet<>(scanner.nextLine().chars().mapToObj(e -> (char)e).collect(Collectors.toList()));
        String stones = scanner.nextLine();
        int occurances = 0;

        for (int i = 0; i < stones.length(); ++i) {
            if (gems.contains(stones.charAt(i))) {
                ++occurances;
            }
        }

        System.out.println(occurances);
    }
}
