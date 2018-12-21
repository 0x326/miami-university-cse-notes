public class PetersonsAlgorithm extends MutualExclusionAlgorithm {
    private volatile int turn = 0;
    private volatile boolean[] threadWantsCriticalSection = {false, false};

    public void requestCriticalSection(int threadId) {
        int otherThreadId = 1 - threadId;

        threadWantsCriticalSection[threadId] = true;
        turn = otherThreadId;
        while (threadWantsCriticalSection[otherThreadId] && turn == otherThreadId) {
            Thread.yield();
        }
    }

    public void notifyDone(int threadId) {
        threadWantsCriticalSection[threadId] = false;
    }
}
