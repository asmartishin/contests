import java.util.*;

public class B {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int alarmsCount = scanner.nextInt();
        int frequency = scanner.nextInt();
        long occurrencesTarget = scanner.nextLong();

        HashMap<Integer, Integer> remindersToAlarmsStart = new HashMap<>();

        int alarmStart;
        int reminder;
        Integer reminderAlarmStart;

        for (int i = 0; i < alarmsCount; ++i) {
            alarmStart = scanner.nextInt();
            reminder = alarmStart % frequency;
            reminderAlarmStart = remindersToAlarmsStart.get(reminder);

            if (reminderAlarmStart == null) {
                remindersToAlarmsStart.put(reminder, alarmStart);
            } else {
                remindersToAlarmsStart.put(reminder, Math.min(reminderAlarmStart, alarmStart));
            }
        }

        long l = 0;
        long r = (long) 1e18;
        long occurrences;

        while (l < r) {
            long m = (l + r) / 2;

            occurrences = 0;
            for (Map.Entry<Integer, Integer> entry : remindersToAlarmsStart.entrySet()) {
                if (m >= entry.getValue()) {
                    occurrences += 1 + (m - entry.getValue()) / frequency;
                }
            }

            System.out.println(l + " " + r + " " + m + " " + occurrences);

            if (occurrencesTarget > occurrences) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        System.out.println(l);

        TreeSet<Integer> tSet = new TreeSet<Integer>();

        for (int i = 0; i < 1e5; ++i) {
            for (Map.Entry<Integer, Integer> entry : remindersToAlarmsStart.entrySet()) {
                tSet.add(entry.getValue() + i * frequency);
            }
        }

        Integer[] numberArray = tSet.toArray( new Integer[tSet.size()] );

        System.out.println(numberArray[(int)occurrencesTarget - 1]);
    }
}
