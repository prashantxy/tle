import java.util.*;

public class MyTaskRunner {

    public static void main(String[] args) {
        List<Integer> arrayList = Arrays.asList(1, 2, 3, 4, 5);

        Thread printThread = new Thread(() -> {
            System.out.println("Original Elements:");
            for (int num : arrayList) {
                System.out.print(num + " ");
            }
            System.out.println();
        });

        Thread prefixSumThread = new Thread(() -> {
            System.out.println("Prefix Sum:");
            int sum = 0;
            for (int num : arrayList) {
                sum += num;
                System.out.print(sum + " ");
            }
            System.out.println();
        });

        Thread multiplyAndSetThread = new Thread(() -> {
            Set<Integer> resultSet = new HashSet<>();
            for (int num : arrayList) {
                resultSet.add(num * 2);
            }
            System.out.println("Elements multiplied by 2 and added to Set:");
            System.out.println(resultSet);
        });

        printThread.start();
        prefixSumThread.start();
        multiplyAndSetThread.start();

        try {
            printThread.join();
            prefixSumThread.join();
            multiplyAndSetThread.join();
        } catch (InterruptedException e) {
        }

        System.out.println("All operations completed.");
    }
}
