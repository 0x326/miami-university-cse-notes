public class PetersonsAlgorithmTest {
    public static void main(String[] args) {
        MutualExclusionAlgorithm mutexAlg = new PetersonsAlgorithm();

        Worker thread1 = new Worker("Thread 1", 0, mutexAlg);
        Worker thread2 = new Worker("Thread 2", 1, mutexAlg);

        thread1.start();
        thread2.start();
    }
}

class Worker extends Thread {
    private String name;
    private int threadId;
    private MutualExclusionAlgorithm mutexAlg;

    public Worker(String name, int threadId, MutualExclusionAlgorithm mutexAlg) {
        this.name = name;
        this.threadId = threadId;
        this.mutexAlg = mutexAlg;
    }

    public void run() {
        while (true) {
            System.out.printf("%s: requesting critical section\n", name);
            mutexAlg.requestCriticalSection(threadId);
            System.out.printf("%s: entered critical section\n", name);
            long startTime = System.nanoTime();

            System.out.printf("%s: doing critical work\n", name);
            MutualExclusionAlgorithm.doCriticalWork();

            mutexAlg.notifyDone(threadId);
            long endTime = System.nanoTime();
            double duration = (endTime - startTime) / 1000000.0;
            System.out.printf("%s: left critical section (critical work lasted for %f ms)\n", name, duration);

            System.out.printf("%s: doing normal work\n", name);
            MutualExclusionAlgorithm.doWork();
        }
    }
}
