# Java Concurrency Tutorial
https://www.tutorialspoint.com/java_concurrency/index.htm


## Java Concurrency Overview

> Life Cycle of a Thread?

- New, init
- Runnable, in start()
- Running, in run()
- Waiting, in sleep(), wait()
- Dead, end of execution


> Thread Priorities

- MIN_PRIORITY: 1
- MAX_PRIORITY: 10
- NORM_PRIORITY: 5


Thread Creation
1. implement Runnable Interface
2. extend Thread class



## Java Concurrency - Major Operation

void suspend()
    puts a thread in the suspended state and can be resumed using resume()

void stop()
    stops a thread completely

void resume()
    resumes a thread, which was suspended using suspend()

void wait()
    causes the current thread to wait until another thread invokes the notify()

void notify()
    wakes up a single thread that is waiting on this object's monitor


The latest versions of Java has deprecated:
- suspend( )
- resume( )
- stop( )
so you need to use available alternatives.


## Interthread Communication


void wait()
    causes current thread to wait until another thread invokes the notify()

void notify()
    wakes up a single thread that's waiting on this object's monitor

void notifyAll()
    waks up all the threads that called wait() on the same object


These methods have been implemented as **final** methods in Object, so they are available in all the classes.
All three methods can be called only from within a **synchronized** context.



## Java Concurrency - Synchronization

    // Only one thread can require the lock at a time
    Object lock = new Object();
    synchronized(lock) {
        // do something
    }


## Java Concurrency - Deadlock

Object lock1 = new Object();
Object lock2 = new Object();

class Thread1
    void run()
        synchronized(lock1)
            // Thread.sleep(1000)
            // deadlock waiting for lock2
            synchronized(lock2)

class Thread2
    void run()
        synchronized(lock2)
            // Thread.sleep(1000)
            // deadlock waiting for lock1
            synchronized(lock1)




== Utility Class Examples ==

## Java Concurrency - ThreadLocal Class

The ThreadLocal class is used to create thread local variables which can only be read and written by the same thread. For example, if two threads are accessing code having reference to same threadLocal variable then each thread will not see any modification to threadLocal variable done by other thread.


ThreadLocal Methods

protected T initialValue()
    returns the current thread's "initial value" for this thread-local variable

void set(T value)
    set the current thread's copy of the thread-local variable

T get()
    returns the value in current thread's copy of this thread-local variable

void remove()
    removes the current thread's value this this thread-local variable



== Lock Examples ==

## Java Concurrency - ThreadLocalRandom Class

static ThreadLocalRandom current()
    returns the current thread's ThreadLocalRandom

protected int next(int bits)
    generates the next pseudorandom number

double nextDouble(double n)
    returns a pseudorandom, uniformly distributed double value between [0, n)

double nextDouble(double least, double bound)
    returns a pseudorandom, uniformly distributed double value between [least, bound)

int nextInt(int least, int bound)

long nextLong(long n)

long nextLong(long n, long bound)

void setSeed(long seed)
    Throws UnsupportedOperationException.




## Java Concurrency - Lock Interface

A java.util.concurrent.locks.Lock interface is used to as a thread synchronization mechanism similar to synchronized blocks.
New Locking mechanism is more flexible and provides more options than a synchronized block.

Diff between Lock vs. a synchronized block:
- Guarantee of sequence
    Synchronized block does not provide any guarantee of sequence in which waiting thread will be given access.
    Lock interface handles it.
- No timeout
    Synchronized block has no option of timeout if lock is not granted.
    Lock interface provides such option.
- Single method
    Synchronized block must be fully contained within a single method.
    lock interface's methods lock() and unlock() can be called in different methods.


Lock Methods

void lock()
    acquires the lock

void lockInterruptibly()
    acquires the lock unless the current thread is interrupted

Condition newCondition()
    returns a new Condition instance that is bound to this Lock instance

boolean tryLock()
    acquires the lock only if it is free at the time of invocation

boolena tryLock(long time, TimeUnit unit)
    acquires the lock if it is free within the given waiting time and the current thread has not been interrupted

void unlock()
    releases the lock

class Printer {
    private final Lock lock = new ReentrantLock();
    void print() {
        lock.lock()
        // do sth
        try {}
        catch (InterruptedException e) {}
        finally {
            lock.unlock()
        }
    }
}

class PrinterThread extends Thread {
    PrinterThread(threadName, printer) {
        super(threadName);
        this.printer = printer;
    }
    @Override
    public void run() {
        printer.print();
    }
}

class Main
    Printer printer = new Printer();
    new PrinterThread("p1", printer).start();
    new PrinterThread("p2", printer).start();

We've use ReentrantLock class as an implementation of Lock interface here.
ReentrantLock class allows a thread to lock a method even if it already have the lock on other method.



## Java Concurrency - ReadWriteLock Interface

A java.util.concurrent.locks.ReadWriteLock interface allows multiple threads to read at a time but only one thread can write at a time.

Read Lock − If no thread has locked the ReadWriteLock for writing then multiple thread can access the read lock.

Write Lock − If no thread is reading or writing, then one thread can access the write lock.


Lock Methods

Lock readLock()
    returns the lock used for reading

Lock writeLock()
    returns the lock used for writing



class Writer implements Runnable {
    void run() {
        lock.writeLock().lock();

        try { Thread.sleep(1000) } // writing
        catch (InterruptedException e) {}
        finally {
            lock.writeLock().unlock();
        }
    }
}

class Reader implements Runnable {
    void run() {
        if (lock.isWriteLocked()) {
            print "write lock present."
        }

        lock.readLock().lock();

        try { Thread.sleep(1000) } // reading
        catch (InterruptedException e) {}
        finally {
            lock.readLock().unlock();
        }
}

class Main {
    private static final ReentrantReadWriteLock lock = new ReentrantReadWriteLock(true);

    Thread[] writers = new Thread[3];
    for (int i = 0; i < 3; i++) {
        writers[i] = new Thread(new Writer());
        writers[i].setName("writer " + i);
    }

    Thread[] readers = new Thread[3];
    for (int i = 0; i < 3; i++) {
        writers[i] = new Thread(new Reader());
        writers[i].setName("Reader " + i);
    }

    // randomly start all writers and readers (e.g. concat writers and readers and shuffle)

    // join all writers and readers

}




## Java Concurrency - Condition Interface

A java.util.concurrent.locks.Condition interface provides a thread ability to suspend its execution, until the given condition is true.
A Condition object is necessarily bound to a Lock and to be obtained using the newCondition() method.

Condition Methods
void await()
    causes current thread to wait until it is signalled or interrupted.

boolean await(long time, TimeUnit unit)
    causes current thread to wait until it is signalled or interrupted, within given timeout.

long awaitNanos(long nanosTimeout)

long awaitUninterruptibly()
    causes the current thread to wait until it is signalled.

long awaitUntil(..)

void signal()
    wakes up one waiting thread

void signalAll()
    wakes up all waiting threads


class ItemQueue {
    Object[] items;
    int size = 0;

    private int addIndex = 0;
    private int removeIndex = 0;

    private final Lock lock;
    private final Condition isEmpty;
    private final Condition isFull;

    ItemQueue(int capacity) {
        this.items = new Object[capacity];
        lock = new ReentrantLock();
        isEmpty = lock.newCondition();
        isFull = lock.newCondition();
    }

    void add(Object item) throws InterruptedException {
        lock.lock();

        while (size >= items.length) isFull.await();

        items[addIndex] = item;
        addIndex = (addIndex + 1) % items.length;
        size++;

        isEmpty.signal();
        lock.unlock();
    }

    void remove() throws InterruptedException {
        lock.lock();

        while (size <= 0) isEmpty().await();

        Object item = null;
        item = items[removeIndex];
        removeIndex = (removeIndex + 1) % items.length;
        size--;

        isFull.signal();
        lock.unlock();
    }

    boolean isEmpty() {
        return items.length == 0;
    }
}


class Producer extends Thread {
    private final ItemQueue queue;

    Producer(ItemQueue queue) {
        this.queue = queue;
    }

    @Override
    void run() {
        try {
            for (int i = 1; i < 5; i++) {
                queue.add(i);
            }
        }
        catch (InterruptedException e) {..};
    }
}

class Consumer extends Thread {
    private final ItemQueue queue;

    Consumer(ItemQueue queue) {
        this.queue = queue;
    }

    @Override
    void run() {
        try {
            while (!queue.isEmpty()) {
                Object o = queue.remove();
                if (o == null) return;
            }
        }
        catch (InterruptedException e) {..};
    }
}

class Main {
    ItemQueue q = new ItemQueue(10);

    Thread producer = new Producer(q);
    Thread consumer = new Consumer(q);

    producer.start();
    consumer.start();

    producer.join();
    consumer.join();
}



== Atomic Variable Examples ==

## Java Concurrency - AtomicInteger Class

A java.util.concurrent.atomic.AtomicInteger class provides operations on underlying int value that can be read and written atomically, and also contains advanced atomic operations.


AtomicInteger Methods

int addAndGet(int delta)
    atomically adds the given value to the current value

int getAndAdd(int delta)
    same as addAndGet()

boolean compareAndSet(int expect, int update)
    atomically sets the value to the given updated value if the current value is the same as expected value

boolean weakCompareAndSet(int expect, int update)
    same as compareAndSet()

int decrementAndGet()
    atomically decrements by one the current value

int getAndDecrement()
    same as decrementAndGet()

int incrementAndGet()
    atomically increments by one the current value

int intValue()
    returns the value of the specified number as an int

double doubleValue()
    returns the value of the specified number as a double

float floatValue()
    returns the value of the specified number as a float

int get()
    get the current value

void set(int newValue)
    sets to the given value.

int getAndSet(int newValue)
    atomically sets to the given value and returns the old value

int incrementAndGet()
    atomically increments by one the current value

void lazySet(int newValue)
    eventually sets to the given value.

String toString()
    returns the String representation of the current value.



== Executor Examples ==

## Java Concurrency - Executor Interface

A java.util.concurrent.Executor interface is a simple interface to support launching new tasks.


ExecutorService Methods

void execute(Runnable command)
    executes the given command at some time in the future


## ExecutorService Interface

A java.util.concurrent.ExecutorService interface is a subinterface of Executor interface, and adds features to manage the lifecycle, both of the individual tasks and of the executor itself.


## ScheduledExecutorService Interface


== Thread Pool Examples ==



== Concurrent Collections ==

## Java Concurrency - BlockingQueue Interface

A java.util.concurrent.BlockingQueue interface is a subinterface of Queue interface, and additionally supports operations such as waiting for the queue to become non-empty before retrieving an element, and wait for space to become available in the queue before storing an element.

BlockingQueue Methods

boolean add(E e)
    Inserts the specified element into this queue if it is possible to do so immediately without violating capacity restrictions, returning true upon success and throwing an IllegalStateException if no space is currently available.

boolean offer(E e)
    same as add()

boolean offer(E e, long timeout, TimeUnit unit)
    Inserts the specified element into this queue, waiting up to the specified wait time if necessary for space to become available.

void put(E e)
    Inserts the specified element into this queue, waiting if necessary for space to become available.


boolean remove(Object o)
    Removes a single instance of the specified element from this queue, if it is present.

E poll(long timeout, TimeUnit unit)
    Retrieves and removes the head of this queue, waiting up to the specified wait time if necessary for an element to become available.

E take()
    Retrieves and removes the head of this queue, waiting if necessary until an element becomes available.

boolean contains(Object o)
    Returns true if this queue contains the specified element.

int drainTo(Collection<\? super E> c)
    Removes all available elements from this queue and adds them to the given collection.

int remainingCapacity()
    Returns the number of additional elements that this queue can ideally (in the absence of memory or resource constraints) accept without blocking, or Integer.MAX_VALUE if there is no intrinsic limit.


class Producer implements Runnable {
    @Override
    void run() {
        try {
            queue.put(new Random().nextInt(100));
        }
        catch (InterruptedException e) {..}
    }
}

class Consumer implements Runnable {
    @Override
    void run() {
        try {
            queue.take();
        }
        catch (InterruptedException e) {..}
    }
}

class Main {
    BlockingQueue<Integer> queue = new ArrayBlockingQueue<Integer>(10);

    Producer producer = new Producer(queue);
    Consumer consumer = new Consumer(queue);

    new Thread(producer).start();
    new Thread(consumer).start();
}


## Java Concurrency - ConcurrentMap Interface

A java.util.concurrent.ConcurrentMap interface is a subinterface of Map interface, supports atomic operations on underlying map variable. It have get and set methods that work like reads and writes on volatile variables. That is, a set has a happens-before relationship with any subsequent get on the same variable. This interface ensures thread safety and atomicity guarantees.

ConcurrentMap Methods

V get()

V remove(K key)











































