import java.util.*;

public class C {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int scoreTarget = scanner.nextInt();
        int numberOfCards = scanner.nextInt();

        List<Integer> cards = new ArrayList();

        int scoreVasya = 0;
        int scorePetya = 0;
        int score;

        for (int i = 0; i < numberOfCards; ++i) {
            score = scanner.nextInt();

            if (score % 15 == 0) {
                continue;
            }

            if (score % 5 == 0) {
                ++scoreVasya;
            } else if (score % 3 == 0) {
                ++scorePetya;
            }

            if (scoreVasya == scoreTarget) {
                System.out.println("Vasya");
                return;
            } else if (scorePetya == scoreTarget) {
                System.out.println("Petya");
                return;
            }
        }

        if (scoreVasya > scorePetya) {
            System.out.println("Vasya");
        } else if (scorePetya > scoreVasya) {
            System.out.println("Petya");
        } else {
            System.out.println("Draw");
        }
    }
}
