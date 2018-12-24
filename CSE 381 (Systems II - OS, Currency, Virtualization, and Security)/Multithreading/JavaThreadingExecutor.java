import java.util.concurrent.*;

interface Expression {
    public int eval(int i);
}

class Sigma implements Callable<Integer> {
    private int i;
    private int n;
    private Expression exp;

    public Sigma(int n) {
        this(1, n);
    }

    public Sigma(int i, int n) {
        this(i, n, x -> x);
    }

    public Sigma(int n, Expression exp) {
        this(1, n, exp);
    }

    public Sigma(int i, int n, Expression exp) {
        this.i = i;
        this.n = n;
        this.exp = exp;
    }

    public Integer call() {
        int sum = 0;
        for (int i = this.i; i <= n; i++) {
            sum += exp.eval(i);
        }

        return sum;
    }
}

public class JavaThreadingExecutor {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Required args: N");
            return;
        }
        int n = Integer.parseInt(args[0]);

        ExecutorService pool = Executors.newSingleThreadExecutor();
        Future<Integer> sumI = pool.submit(new Sigma(n, i -> i));
        Future<Integer> sumISquared = pool.submit(new Sigma(n, i -> i * i));
        Future<Integer> sumICubed = pool.submit(new Sigma(n, i -> i * i * i));

        try {
            System.out.printf("Σ i  = %d\n", sumI.get());
            System.out.printf("Σ i² = %d\n", sumISquared.get());
            System.out.printf("Σ i³ = %d\n", sumICubed.get());
        } catch (InterruptedException | ExecutionException ie) {
            // Do nothing
        } finally {
            pool.shutdown();
        }
    }
}
