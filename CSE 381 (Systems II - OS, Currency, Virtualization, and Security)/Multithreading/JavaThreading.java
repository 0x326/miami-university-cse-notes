import java.util.concurrent.*;

class Sum extends RecursiveTask<Integer> {
    static final int DATA_LENGTH_THRESHOLD = 1000;
    private int startIndex;
    private int length;
    private int[] array;

    public Sum(int[] array) {
        this(array, 0, array.length);
    }

    public Sum(int[] array, int startIndex, int length) {
        this.array = array;
        this.startIndex = startIndex;
        this.length = length;
    }

    protected Integer compute() {
        if (length - startIndex > DATA_LENGTH_THRESHOLD) {
            int midIndex = (startIndex + length) / 2;
            Sum leftSum = new Sum(array, startIndex, midIndex);
            Sum rightSum = new Sum(array, midIndex, length);

            rightSum.fork();

            return leftSum.compute() + rightSum.join();
        } else {
            int sum = 0;
            for (int i = startIndex; i < length; i++) {
                sum += array[i];
            }

            return sum;
        }
    }
}

public class JavaThreading {
    public static void main(String[] args) {
        int[] array = new int[10];
        for (int i = 0; i < array.length; i++) {
            array[i] = i;
        }

        ForkJoinPool pool = new ForkJoinPool();
        Sum task = new Sum(array);
        int sum = pool.invoke(task);

        System.out.println("The sum is " + sum);
    }
}
