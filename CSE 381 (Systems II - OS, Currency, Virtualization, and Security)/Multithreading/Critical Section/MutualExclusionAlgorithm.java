public abstract class MutualExclusionAlgorithm {
    private static final int MAX_WAIT_TIME = 3000;

    public abstract void requestCriticalSection(int t);

    public abstract void notifyDone(int t);

    public static void doCriticalWork() {
        try {
            // Simulate work
            Thread.sleep((int) (Math.random() * MAX_WAIT_TIME));
        } catch (InterruptedException e) {
            // Do nothing
        }
    }

    public static void doWork() {
        try {
            // Simulate work
            Thread.sleep((int) (Math.random() * MAX_WAIT_TIME));
        } catch (InterruptedException e) {
            // Do nothing
        }
    }
}
