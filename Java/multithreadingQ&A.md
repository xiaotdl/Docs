# Java multi-threading


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


> What is multithreading?

Multithreading is a process of executing multiple threads simultaneously.

Its main advantage is:
    Threads share the same address space.
    Thread is lightweight.
    Cost of communication between process is low.


> What is thread?

A thread is a lightweight subprocess.
It is a separate path of execution. It is called separate path of execution because each thread runs in a separate stack frame


> What is the difference between preemptive scheduling and time slicing?

Under preemptive scheduling, the highest priority task executes until it enters the waiting or dead states or a higher priority task comes into existence.

Under time slicing, a task executes for a predefined slice of time and then reenters the pool of ready tasks. The scheduler then determines which task should execute next, based on priority and other factors.


> What does join() method?

The join() method waits for a thread to die. In other words, it causes the currently running threads to stop executing until the thread it joins with completes its task.


> What is difference between wait() and sleep() method?

1) wait() method is defined in Object class.
   sleep() method is defined in Thread class.
2) wait() method releases the lock.
   sleep() method doesn't releases the lock.


> Is it possible to start a thread twice?

No, there is no possibility to start a thread twice. If we does, it throws an exception, java.lang.IllegalThreadStateException.


> Can we call the run() method instead of start()?

Yes, but it will not work as a thread rather it will work as a normal object so there will not be context-switching between the threads.


> What about the daemon threads?

The daemon threads are basically the low priority threads that provides the background support to the user threads. It provides services to the user threads.

void setDaemon(boolean status)
     mark the current thread as daemon thread or user thread.

boolean isDaemon()
     check if current thread is daemon.


> Can we make the user thread as daemon thread if thread is started?

No, if you do so, it will throw IllegalThreadStateException


> What is shutdown hook?

The shutdown hook is basically a thread i.e. invoked implicitely before JVM shuts down. So we can use it perform clean up resource.


> When should we interrupt a thread?

We should interrupt a thread if we want to break out the sleep or wait state of a thread.


> What is synchronization?

Synchronization is the capabilility of control the access of multiple threads to any shared resource.

It is used to:
    To prevent thread interference.
    To prevent consistency problem.


> What is the purpose of Synchronized block?

Synchronized block is used to lock an object for any shared resource.
Scope of synchronized block is smaller than the method.


> Can Java object be locked down for exclusive use by a given thread?

Yes. You can lock an object by putting it in a "synchronized" block. The locked object is inaccessible to any thread other than the one that explicitly claimed it.


> What is static synchronization?

If you make any static method as synchronized, the lock will be on the class not on object.


https://www.cnblogs.com/xrq730/p/5060921.html

> 多线程有什么用？

（1）发挥多核CPU的优势
    单核CPU上所谓的"多线程"那是假的多线程
    多核CPU上的多线程才是真正的多线程，它能让你的多段逻辑同时工作，多线程，可以真正发挥出多核CPU的优势
（2）防止阻塞
（3）便于建模


> 创建线程的方式

比较常见的一个问题了，一般就是两种：
（1）继承Thread类
（2）实现Runnable接口

后者好，因为实现接口的方式比继承类的方式更灵活，
也能减少程序之间的耦合度，面向接口编程也是设计模式6大原则的核心。


> start()方法和run()方法的区别

只有调用了start()方法，才会表现出多线程的特性，不同线程的run()方法里面的代码交替执行。start()会为每个线程建立自己的call stack。
如果只是调用run()方法，那么代码还是同步执行的，必须等待一个线程的run()方法里面的代码全部执行完毕之后，另外一个线程才可以执行其run()方法里面的代码。


> Runnable接口和Callable接口的区别

Runnable接口中的run()方法的返回值是void，它做的事情只是纯粹地去执行run()方法中的代码而已;

Callable接口中的call()方法是有返回值的，是一个泛型，和Future、FutureTask配合可以用来获取异步执行的结果。

这其实是很有用的一个特性，因为多线程相比单线程更难、更复杂的一个重要原因就是因为多线程充满着未知性，某条线程是否执行了？某条线程执行了多久？某条线程执行的时候我们期望的数据是否已经赋值完毕？无法得知，我们能做的只是等待这条多线程的任务执行完毕而已。而Callable+Future/FutureTask却可以获取多线程运行的结果，可以在等待时间太长没获取到需要的数据的情况下取消该线程的任务，真的是非常有用。


> CyclicBarrier和CountDownLatch的区别

两个看上去有点像的类，都在java.util.concurrent下，都可以用来表示代码运行到某个点上，二者的区别在于：

（1）CyclicBarrier的某个线程运行到某个点上之后，该线程即停止运行，直到所有的线程都到达了这个点，所有线程才重新运行；CountDownLatch则不是，某线程运行到某个点上之后，只是给某个数值-1而已，该线程继续运行

（2）CyclicBarrier只能唤起一个任务，CountDownLatch可以唤起多个任务

（3）CyclicBarrier可重用，CountDownLatch不可重用，计数值为0该CountDownLatch就不可再用了


> volatile关键字的作用

理解volatile关键字的作用的前提是要理解Java内存模型，这里就不讲Java内存模型了，可以参见第31点，volatile关键字的作用主要有两个：

（1）多线程主要围绕可见性和原子性两个特性而展开，使用volatile关键字修饰的变量，保证了其在多线程之间的可见性，即每次读取到volatile变量，一定是最新的数据

（2）代码底层执行不像我们看到的高级语言----Java程序这么简单，它的执行是Java代码-->字节码-->根据字节码执行对应的C/C++代码-->C/C++代码被编译成汇编语言-->和硬件电路交互，现实中，为了获取更好的性能JVM可能会对指令进行重排序，多线程下可能会出现一些意想不到的问题。使用volatile则会对禁止语义重排序，当然这也一定程度上降低了代码执行效率

从实践角度而言，volatile的一个重要作用就是和CAS结合，保证了原子性，详细的可以参见java.util.concurrent.atomic包下的类，比如AtomicInteger。


> 什么是线程安全

如果你的代码在多线程下执行和在单线程下执行永远都能获得一样的结果，那么你的代码就是线程安全的。

（1）不可变
像String、Integer、Long这些，都是final类型的类，任何一个线程都改变不了它们的值，要改变除非新创建一个，因此这些不可变对象不需要任何同步手段就可以直接在多线程环境下使用

（2）绝对线程安全
不管运行时环境如何，调用者都不需要额外的同步措施。要做到这一点通常需要付出许多额外的代价，Java中标注自己是线程安全的类，实际上绝大多数都不是线程安全的，不过绝对线程安全的类，Java中也有，比方说CopyOnWriteArrayList、CopyOnWriteArraySet

（3）相对线程安全
相对线程安全也就是我们通常意义上所说的线程安全，像Vector这种，add、remove方法都是原子操作，不会被打断，但也仅限于此，如果有个线程在遍历某个Vector、有个线程同时在add这个Vector，99%的情况下都会出现ConcurrentModificationException，也就是fail-fast机制。

（4）线程非安全
ArrayList、LinkedList、HashMap等都是线程非安全的类


> Java中如何获取到线程dump文件

死循环、死锁、阻塞、页面打开慢等问题，打线程dump是最好的解决问题的途径。

所谓线程dump也就是线程堆栈，获取到线程堆栈有两步：
（1）获取到线程的pid，可以通过使用jps命令，在Linux环境下还可以使用ps -ef | grep java

（2）打印线程堆栈，可以通过使用jstack pid命令，在Linux环境下还可以使用kill -3 pid

另外提一点，Thread类提供了一个getStackTrace()方法也可以用于获取线程堆栈。这是一个实例方法，因此此方法是和具体线程实例绑定的，每次获取到的是具体某个线程当前运行的堆栈，


> 一个线程如果出现了运行时异常会怎么样

如果这个异常没有被捕获的话，这个线程就停止执行了。
另外重要的一点是：如果这个线程持有某个某个对象的监视器，那么这个对象监视器会被立即释放


> 如何在两个线程之间共享数据

通过在线程之间**共享对象**就可以了，然后通过wait/notify/notifyAll、await/signal/signalAll进行唤起和等待，比方说阻塞队列BlockingQueue就是为线程之间共享数据而设计的


> sleep方法和wait方法有什么区别

这个问题常问，sleep方法和wait方法都可以用来放弃CPU一定的时间，不同点在于如果线程持有某个对象的监视器，sleep方法不会放弃这个对象的监视器，wait方法会放弃这个对象的监视器


> 生产者消费者模型的作用是什么

（1）通过平衡生产者的生产能力和消费者的消费能力来提升整个系统的运行效率，这是生产者消费者模型最重要的作用

（2）解耦，这是生产者消费者模型附带的作用，解耦意味着生产者和消费者之间的联系少，联系越少越可以独自发展而不需要收到相互的制约


> ThreadLocal有什么用

简单说ThreadLocal就是一种**以空间换时间**的做法，在每个Thread里面维护了一个以开地址法实现的ThreadLocal.

ThreadLocalMap，把数据进行隔离，数据不共享，自然就没有线程安全方面的问题了


> 为什么wait()方法和notify()/notifyAll()方法要在同步块中被调用

这是JDK强制的，wait()方法和notify()/notifyAll()方法在调用前都必须先获得对象的锁


> wait()方法和notify()/notifyAll()方法在放弃对象监视器时有什么区别

wait()方法和notify()/notifyAll()方法在放弃对象监视器的时候的区别在于：
wait()方法立即释放对象监视器，
notify()/notifyAll()方法则会等待线程剩余代码执行完毕才会放弃对象监视器。


> 为什么要使用线程池

避免频繁地创建和销毁线程，达到线程对象的重用。另外，使用线程池还可以根据项目灵活地控制并发的数目。


> 怎么检测一个线程是否持有对象监视器

我也是在网上看到一道多线程面试题才知道有方法可以判断某个线程是否持有对象监视器：Thread类提供了一个holdsLock(Object obj)方法，当且仅当对象obj的监视器被某条线程持有的时候才会返回true，注意这是一个static方法，这意味着"某条线程"指的是当前线程。


> synchronized和ReentrantLock的区别

synchronized是和if、else、for、while一样的关键字，ReentrantLock是类，这是二者的本质区别。

既然ReentrantLock是类，那么它就提供了比synchronized更多更灵活的特性，可以被继承、可以有方法、可以有各种各样的类变量，ReentrantLock比synchronized的扩展性体现在几点上：

（1）ReentrantLock可以对获取锁的等待时间进行设置，这样就避免了死锁

（2）ReentrantLock可以获取各种锁的信息

（3）ReentrantLock可以灵活地实现多路通知

另外，二者的锁机制其实也是不一样的。ReentrantLock底层调用的是Unsafe的park方法加锁，synchronized操作的应该是对象头中mark word，这点我不能确定。


> ConcurrentHashMap的并发度是什么

ConcurrentHashMap的并发度就是segment的大小，默认为16，这意味着最多同时可以有16条线程操作ConcurrentHashMap，这也是ConcurrentHashMap对Hashtable的最大优势，任何情况下，Hashtable能同时有两条线程获取Hashtable中的数据吗？


> ReadWriteLock是什么

首先明确一下，不是说ReentrantLock不好，只是ReentrantLock某些时候有局限。如果使用ReentrantLock，可能本身是为了防止线程A在写数据、线程B在读数据造成的数据不一致，但这样，如果线程C在读数据、线程D也在读数据，读数据是不会改变数据的，没有必要加锁，但是还是加锁了，降低了程序的性能。

因为这个，才诞生了读写锁ReadWriteLock。ReadWriteLock是一个读写锁接口，ReentrantReadWriteLock是ReadWriteLock接口的一个具体实现，实现了读写的分离，读锁是共享的，写锁是独占的，读和读之间不会互斥，读和写、写和读、写和写之间才会互斥，提升了读写的性能。


> FutureTask是什么?

这个其实前面有提到过，FutureTask表示一个异步运算的任务。FutureTask里面可以传入一个Callable的具体实现类，可以对这个异步运算的任务的结果进行等待获取、判断是否已经完成、取消任务等操作。当然，由于FutureTask也是Runnable接口的实现类，所以FutureTask也可以放入线程池中。


> 怎么唤醒一个阻塞的线程

如果线程是因为调用了wait()、sleep()或者join()方法而导致的阻塞，可以中断线程，并且通过抛出InterruptedException来唤醒它；如果线程遇到了IO阻塞，无能为力，因为IO是操作系统实现的，Java代码并没有办法直接接触到操作系统。


> 不可变对象对多线程有什么帮助

前面有提到过的一个问题，不可变对象保证了对象的内存可见性，对不可变对象的读取不需要进行额外的同步手段，提升了代码执行效率。


> 什么是多线程的上下文切换

多线程的上下文切换是指CPU控制权由一个已经正在运行的线程切换到另外一个就绪并等待获取CPU执行权的线程的过程。


> 如果你提交任务时，线程池队列已满，这时会发生什么

这里区分一下：

如果使用的是无界队列LinkedBlockingQueue，也就是无界队列的话，没关系，继续添加任务到阻塞队列中等待执行，因为LinkedBlockingQueue可以近乎认为是一个无穷大的队列，可以无限存放任务

如果使用的是有界队列比如ArrayBlockingQueue，任务首先会被添加到ArrayBlockingQueue中，ArrayBlockingQueue满了，会根据maximumPoolSize的值增加线程数量，如果增加了线程数量还是处理不过来，ArrayBlockingQueue继续满，那么则会使用拒绝策略RejectedExecutionHandler处理满了的任务，默认是AbortPolicy


> Java中用到的线程调度算法是什么

抢占式。一个线程用完CPU之后，操作系统会根据线程优先级、线程饥饿情况等数据算出一个总的优先级并分配下一个时间片给某个线程执行。


> Thread.sleep(0)的作用是什么

由于Java采用抢占式的线程调度算法，因此可能会出现某条线程常常获取到CPU控制权的情况，为了让某些优先级比较低的线程也能获取到CPU控制权，可以使用Thread.sleep(0)手动触发一次操作系统分配时间片的操作，这也是平衡CPU控制权的一种操作。


> 什么是自旋

很多synchronized里面的代码只是一些很简单的代码，执行时间非常快，此时等待的线程都加锁可能是一种不太值得的操作，因为线程阻塞涉及到用户态和内核态切换的问题。既然synchronized里面的代码执行得非常快，不妨让等待锁的线程不要被阻塞，而是在synchronized的边界做忙循环，这就是自旋。如果做了多次忙循环发现还没有获得锁，再阻塞，这样可能是一种更好的策略。


> 什么是Java内存模型

Java内存模型定义了一种多线程访问Java内存的规范。Java内存模型要完整讲不是这里几句话能说清楚的，我简单总结一下Java内存模型的几部分内容：

（1）Java内存模型将内存分为了主内存和工作内存。类的状态，也就是类之间共享的变量，是存储在主内存中的，每次Java线程用到这些主内存中的变量的时候，会读一次主内存中的变量，并让这些内存在自己的工作内存中有一份拷贝，运行自己线程代码的时候，用到这些变量，操作的都是自己工作内存中的那一份。在线程代码执行完毕之后，会将最新的值更新到主内存中去

（2）定义了几个原子操作，用于操作主内存和工作内存中的变量

（3）定义了volatile变量的使用规则

（4）happens-before，即先行发生原则，定义了操作A必然先行发生于操作B的一些规则，比如在同一个线程内控制流前面的代码一定先行发生于控制流后面的代码、一个释放锁unlock的动作一定先行发生于后面对于同一个锁进行锁定lock的动作等等，只要符合这些规则，则不需要额外做同步措施，如果某段代码不符合所有的happens-before规则，则这段代码一定是线程非安全的


> 什么是CAS

CAS，全称为Compare and Swap，即比较-替换。假设有三个操作数：内存值V、旧的预期值A、要修改的值B，当且仅当预期值A和内存值V相同时，才会将内存值修改为B并返回true，否则什么都不做并返回false。当然CAS一定要volatile变量配合，这样才能保证每次拿到的变量是主内存中最新的那个值，否则旧的预期值A对某条线程来说，永远是一个不会变的值A，只要某次CAS操作失败，永远都不可能成功。


> 什么是乐观锁和悲观锁

（1）乐观锁：就像它的名字一样，对于并发间操作产生的线程安全问题持乐观状态，乐观锁认为竞争不总是会发生，因此它不需要持有锁，将比较-替换这两个动作作为一个原子操作尝试去修改内存中的变量，如果失败则表示发生冲突，那么就应该有相应的重试逻辑。

（2）悲观锁：还是像它的名字一样，对于并发间操作产生的线程安全问题持悲观状态，悲观锁认为竞争总是会发生，因此每次对某资源进行操作时，都会持有一个独占的锁，就像synchronized，不管三七二十一，直接上了锁就操作资源了。


> 什么是AQS

简单说一下AQS，AQS全称为AbstractQueuedSychronizer，翻译过来应该是抽象队列同步器。

如果说java.util.concurrent的基础是CAS的话，那么AQS就是整个Java并发包的核心了，ReentrantLock、CountDownLatch、Semaphore等等都用到了它。AQS实际上以双向队列的形式连接所有的Entry，比方说ReentrantLock，所有等待的线程都被放在一个Entry中并连成双向队列，前面一个线程使用ReentrantLock好了，则双向队列实际上的第一个Entry开始运行。

AQS定义了对双向队列所有的操作，而只开放了tryLock和tryRelease方法给开发者使用，开发者可以根据自己的实现重写tryLock和tryRelease方法，以实现自己的并发功能。


> 单例模式的线程安全性

老生常谈的问题了，首先要说的是单例模式的线程安全意味着：某个类的实例在多线程环境下只会被创建一次出来。单例模式有很多种的写法，我总结一下：

（1）饿汉式单例模式的写法：线程安全

（2）懒汉式单例模式的写法：非线程安全

（3）双检锁单例模式的写法：线程安全


> Semaphore有什么作用

Semaphore就是一个信号量，它的作用是限制某段代码块的并发数。Semaphore有一个构造函数，可以传入一个int型整数n，表示某段代码最多只有n个线程可以访问，如果超出了n，那么请等待，等到某个线程执行完毕这段代码块，下一个线程再进入。由此可以看出如果Semaphore构造函数中传入的int型整数n=1，相当于变成了一个synchronized了。


> 线程类的构造方法、静态块是被哪个线程调用的

线程类的构造方法、静态块是被new这个线程类所在的线程所调用的，而run方法里面的代码才是被线程自身所调用的。

如果说上面的说法让你感到困惑，那么我举个例子，假设Thread2中new了Thread1，main函数中new了Thread2，那么：

（1）Thread2的构造方法、静态块是main线程调用的，Thread2的run()方法是Thread2自己调用的

（2）Thread1的构造方法、静态块是Thread2调用的，Thread1的run()方法是Thread1自己调用的


> 同步方法和同步块，哪个是更好的选择

同步块，这意味着同步块之外的代码是异步执行的，这比同步整个方法更提升代码的效率。请知道一条原则：同步的范围越小越好。

借着这一条，我额外提一点，虽说同步的范围越少越好，但是在Java虚拟机中还是存在着一种叫做锁粗化的优化方法，这种方法就是把同步范围变大。这是有用的，比方说StringBuffer，它是一个线程安全的类，自然最常用的append()方法是一个同步方法，我们写代码的时候会反复append字符串，这意味着要进行反复的加锁->解锁，这对性能不利，因为这意味着Java虚拟机在这条线程上要反复地在内核态和用户态之间进行切换，因此Java虚拟机会将多次append方法调用的代码进行一个锁粗化的操作，将多次的append的操作扩展到append方法的头尾，变成一个大的同步块，这样就减少了加锁-->解锁的次数，有效地提升了代码执行的效率。


> 并发高、任务执行时间短, 的业务怎样使用线程池？
> 并发不高、任务执行时间长, 的业务怎样使用线程池？
> 并发高、任务执行时间长, 的业务怎样使用线程池？

（1）高并发、任务执行时间短的业务，线程池线程数可以设置为CPU核数+1，减少线程上下文的切换

（2）并发不高、任务执行时间长的业务要区分开看：

　　a）假如是业务时间长集中在IO操作上，也就是IO密集型的任务，因为IO操作并不占用CPU，所以不要让所有的CPU闲下来，可以加大线程池中的线程数目，让CPU处理更多的业务

　　b）假如是业务时间长集中在计算操作上，也就是计算密集型任务，这个就没办法了，和（1）一样吧，线程池中的线程数设置得少一些，减少线程上下文的切换

（3）并发高、业务执行时间长，解决这种类型任务的关键不在于线程池而在于整体架构的设计，看看这些业务里面某些数据是否能做缓存是第一步，增加服务器是第二步，至于线程池的设置，设置参考（2）。最后，业务执行时间长的问题，也可能需要分析一下，看看能不能使用中间件对任务进行拆分和解耦。


http://www.androidchina.net/443.html

> 现在有T1、T2、T3三个线程，你怎样保证T2在T1执行完后执行，T3在T2执行完后执行？

t1.start()
t1.join()
t2.start()
t2.join()
t3.start()
t3.join()


> 在Java中Lock接口比synchronized块的优势是什么？你需要实现一个高效的缓存，它允许多个用户读，但只允许一个用户写，以此来保持它的完整性，你会怎样去实现它？

lock接口在多线程和并发编程中最大的优势是它们为读和写分别提供了锁，它能满足你写像ConcurrentHashMap这样的高性能数据结构和有条件的阻塞。


> 在java中wait和sleep方法的不同？

通常会在电话面试中经常被问到的Java线程面试问题。最大的不同是在等待时wait会释放锁，而sleep一直持有锁。Wait通常被用于线程间交互，sleep通常被用于暂停执行。


> 用Java实现阻塞队列。
第一，它可以检测侯选者是否能实际的用Java线程写程序；
第二，可以检测侯选者对并发场景的理解，并且你可以根据这个问很多问题。如果他用wait()和notify()方法来实现阻塞队列，你可以要求他用最新的Java 5中的并发类来再写一次。



> 用Java写代码来解决生产者——消费者问题。


> 用Java写代码来实现哲学家进餐问题。


> Java中的volatile关键是什么作用？怎样使用它？在Java中它跟synchronized方法有什么不同？

自从Java 5和Java内存模型改变以后，基于volatile关键字的线程问题越来越流行。应该准备好回答关于volatile变量怎样在并发环境中确保可见性、顺序性和一致性。


> 什么是竞争条件？你怎样发现和解决竞争？
《Concurrency practices in Java》。


> 你将如何使用thread dump？你将如何分析Thread dump？

在UNIX中你可以使用kill -3，然后thread dump将会打印日志，在windows中你可以使用”CTRL+Break”。


> 在Java中CycliBarriar和CountdownLatch有什么区别？

这个线程问题主要用来检测你是否熟悉JDK5中的并发包。这两个的区别是CyclicBarrier可以重复使用已经通过的障碍，而CountdownLatch不能重复使用。


> 你在多线程环境中遇到的共同的问题是什么？你是怎么解决它的？

多线程和并发程序中常遇到的有Memory-interface、竞争条件、死锁、活锁和饥饿。问题是没有止境的，如果你弄错了，将很难发现和调试。



50道Java多线程面试题
http://www.mayou18.com/detail/Sd1ptRC6.html

> Java内存模型是什么？

Java内存模型规定和指引Java程序在不同的内存架构、CPU和操作系统间有确定性地行为。它在多线程的情况下尤其重要。Java内存模型对一个线程所做的变动能被其它线程可见提供了保证，它们之间是先行发生关系。这个关系定义了一些规则让程序员在并发编程时思路更清晰。比如，先行发生关系确保了：

线程内的代码能够按先后顺序执行，这被称为程序次序规则。

对于同一个锁，一个解锁操作一定要发生在时间上后发生的另一个锁定操作之前，也叫做管程锁定规则。

前一个对volatile的写操作在后一个volatile的读操作之前，也叫volatile变量规则。

一个线程内的任何操作必需在这个线程的start()调用之后，也叫作线程启动规则。

一个线程的所有操作都会在线程终止之前，线程终止规则。

一个对象的终结操作必需在这个对象构造完成之后，也叫对象终结规则。

可传递性


>  Java中的volatile 变量是什么？

volatile是一个特殊的修饰符，只有成员变量才能使用它。在Java并发程序缺少同步类的情况下，多线程对成员变量的操作对其它线程是透明的。volatile变量可以保证下一个读取操作会在前一个写操作之后发生，就是上一题的volatile变量规则。


> Java中如何停止一个线程？
当run() 或者 call() 方法执行完的时候线程会自动结束,如果要手动结束一个线程，你可以用volatile 布尔变量来退出run()方法的循环或者是取消任务来中断线程。


> 为什么wait, notify 和 notifyAll这些方法不在thread类里面？

这是个设计相关的问题，它考察的是面试者对现有系统和一些普遍存在但看起来不合理的事物的看法。回答这些问题的时候，你要说明为什么把这些方法放在Object类里是有意义的，还有不把它放在Thread类里的原因。一个很明显的原因是JAVA提供的锁是对象级的而不是线程级的，每个对象都有锁，通过线程获得。如果线程需要等待某些锁那么调用对象中的wait()方法就有意义了。如果wait()方法定义在Thread类中，线程正在等待的是哪个锁就不明显了。简单的说，由于wait，notify和notifyAll都是锁级别的操作，所以把他们定义在Object类中因为锁属于对象。


> 什么是FutureTask？

在Java并发程序中FutureTask表示一个可以取消的异步运算。它有启动和取消运算、查询运算是否完成和取回运算结果等方法。只有当运算完成的时候结果才能取回，如果运算尚未完成get方法将会阻塞。一个FutureTask对象可以对调用了Callable和Runnable的对象进行包装，由于FutureTask也是调用了Runnable接口所以它可以提交给Executor来执行。


> Java中interrupted 和 isInterruptedd方法的区别？

interrupted() 和 isInterrupted()的主要区别是前者会将中断状态清除而后者不会。Java多线程的中断机制是用内部标识来实现的，调用Thread.interrupt()来中断一个线程就会设置中断标识为true。当中断线程调用静态方法Thread.interrupted()来检查中断状态时，中断状态会被清零。而非静态方法isInterrupted()用来查询其它线程的中断状态且不会改变中断状态标识。简单的说就是任何抛出InterruptedException异常的方法都会将中断状态清零。无论如何，一个线程的中断状态有有可能被其它线程调用中断来改变。


> 为什么wait和notify方法要在同步块中调用？

主要是因为Java API强制要求这样做，如果你不这么做，你的代码会抛出IllegalMonitorStateException异常。还有一个原因是为了避免wait和notify之间产生竞态条件。


> 什么是线程池？ 为什么要使用它？
创建线程要花费昂贵的资源和时间，如果任务来了才创建线程那么响应时间会变长，而且一个进程能创建的线程数有限。为了避免这些问题，在程序启动的时候就创建若干线程来响应处理，它们被称为线程池，里面的线程叫工作线程。从JDK1.5开始，Java API提供了Executor框架让你可以创建不同的线程池。比如单线程池，每次处理一个任务；数目固定的线程池或者是缓存线程池（一个适合很多生存期短的任务的程序的可扩展线程池）。


> 如何写代码来解决生产者消费者问题？
在现实中你解决的许多线程问题都属于生产者消费者模型，就是一个线程生产任务供其它线程进行消费，你必须知道怎么进行线程间通信来解决这个问题。
比较低级的办法是用wait和notify来解决这个问题，
比较赞的办法是用Semaphore
或者 BlockingQueue来实现生产者消费者模型，


> 怎么检测一个线程是否拥有锁？

在java.lang.Thread中有一个方法叫holdsLock()，它返回true如果当且仅当当前线程拥有某个具体对象的锁。


> JVM中哪个参数是用来控制线程的栈堆栈小的
这个问题很简单， -Xss参数用来控制线程的堆栈大小。你可以查看JVM配置列表来了解这个参数的更多信息。


> Thread类中的yield方法有什么作用？

Yield方法可以暂停当前正在执行的线程对象，让其它有相同优先级的线程执行。它是一个静态方法而且只保证当前线程放弃CPU占用而不能保证使其它线程一定能占用CPU，执行yield()的线程有可能在进入到暂停状态后马上又被执行。


> Java中Semaphore是什么？

Java中的Semaphore是一种新的同步类，它是一个计数信号。从概念上讲，从概念上讲，信号量维护了一个许可集合。如有必要，在许可可用前会阻塞每一个 acquire()，然后再获取该许可。每个 release()添加一个许可，从而可能释放一个正在阻塞的获取者。但是，不使用实际的许可对象，Semaphore只对可用许可的号码进行计数，并采取相应的行动。信号量常常用于多线程的代码中，比如数据库连接池。


> 如果你提交任务时，线程池队列已满。会时发会生什么？

这个问题问得很狡猾，许多程序员会认为该任务会阻塞直到线程池队列有空位。事实上如果一个任务不能被调度执行那么ThreadPoolExecutor’s submit()方法将会抛出一个RejectedExecutionException异常。


> Java线程池中submit() 和 execute()方法有什么区别？

两个方法都可以向线程池提交任务，execute()方法的返回类型是void，它定义在Executor接口中,

submit()方法可以返回持有计算结果的Future对象，它定义在ExecutorService接口中，它扩展了Executor接口，其它线程池类像ThreadPoolExecutor和ScheduledThreadPoolExecutor都有这些方法。


> 什么是阻塞式方法？

阻塞式方法是指程序会一直等待该方法完成期间不做其他事情，ServerSocket的accept()方法就是一直等待客户端连接。这里的阻塞是指调用结果返回之前，当前线程会被挂起，直到得到结果之后才会返回。此外，还有异步和非阻塞式方法在任务完成前就返回。


> Java中的ReadWriteLock是什么？

一般而言，读写锁是用来提升并发程序性能的锁分离技术的成果。Java中的ReadWriteLock是Java 5 中新增的一个接口，一个ReadWriteLock维护一对关联的锁，一个用于只读操作一个用于写。在没有写线程的情况下一个读锁可能会同时被多个读线程持有。写锁是独占的，你可以使用JDK中的ReentrantReadWriteLock来实现这个规则，它最多支持65535个写锁和65535个读锁。


> 多线程中的忙循环是什么?

忙循环就是程序员用循环让一个线程等待，不像传统方法wait(), sleep() 或 yield() 它们都放弃了CPU控制，而忙循环不会放弃CPU，它就是在运行一个空循环。这么做的目的是为了保留CPU缓存，在多核系统中，一个等待线程醒来的时候可能会在另一个内核运行，这样会重建缓存。为了避免重建缓存和减少等待重建的时间就可以使用它了。


> volatile 变量和 atomic 变量有什么不同？

这是个有趣的问题。首先，volatile 变量和 atomic 变量看起来很像，但功能却不一样。Volatile变量可以确保先行关系，即写操作会发生在后续的读操作之前, 但它并不能保证原子性。例如用volatile修饰count变量那么 count++ 操作就不是原子性的。而AtomicInteger类提供的atomic方法可以让这种操作具有原子性如getAndIncrement()方法会原子性的进行增量操作把当前值加一，其它数据类型和引用变量也可以进行相似操作。


> 如果同步块内的线程抛出异常会发生什么？

无论你的同步块是正常还是异常退出的，里面的线程都会释放锁，所以对比锁接口我更喜欢同步块，因为它不用我花费精力去释放锁，该功能可以在finally block里释放锁实现。


> 单例模式的双检锁是什么？


> 写出3条你遵循的多线程最佳实践

这种问题我最喜欢了，我相信你在写并发代码来提升性能的时候也会遵循某些最佳实践。以下三条最佳实践我觉得大多数Java程序员都应该遵循：

1) 给你的线程起个有意义的名字。
这样可以方便找bug或追踪。OrderProcessor, QuoteProcessor or TradeProcessor 这种名字比 Thread-1. Thread-2 and Thread-3 好多了，给线程起一个和它要完成的任务相关的名字，所有的主要框架甚至JDK都遵循这个最佳实践。

2) 避免锁定和缩小同步的范围
锁花费的代价高昂且上下文切换更耗费时间空间，试试最低限度的使用同步和锁，缩小临界区。因此相对于同步方法我更喜欢同步块，它给我拥有对锁的绝对控制权。

3) 多用同步类少用wait 和 notify
首先，CountDownLatch, Semaphore, CyclicBarrier 和 Exchanger 这些同步类简化了编码操作，而用wait和notify很难实现对复杂控制流的控制。

其次，这些类是由最好的企业编写和维护在后续的JDK中它们还会不断优化和完善，使用这些更高等级的同步工具你的程序可以不费吹灰之力获得优化。

4) 多用并发集合少用同步集合
这是另外一个容易遵循且受益巨大的最佳实践，并发集合比同步集合的可扩展性更好，所以在并发编程时使用并发集合效果更好。如果下一次你需要用到map，你应该首先想到用ConcurrentHashMap。


> 如何强制启动一个线程？

这个问题就像是如何强制进行Java垃圾回收，目前还没有觉得方法，虽然你可以使用System.gc()来进行垃圾回收，但是不保证能成功。在Java里面没有办法强制启动一个线程，它是被线程调度器控制着且Java没有公布相关的API。


> Java中的fork join框架是什么？

fork join框架是JDK7中出现的一款高效的工具，Java开发人员可以通过它充分利用现代服务器上的多处理器。它是专门为了那些可以递归划分成许多子模块设计的，目的是将所有可用的处理能力用来提升程序的性能。fork join框架一个巨大的优势是它使用了工作窃取算法，可以完成更多任务的工作线程可以从其它线程中窃取任务来执行。


> Java多线程中调用wait() 和 sleep()方法有什么不同？
Java程序中wait 和 sleep都会造成某种形式的暂停，它们可以满足不同的需要。
wait()方法用于线程间通信，如果等待条件为真且其它线程被唤醒时它会释放锁，
sleep()方法仅仅释放CPU资源或者让当前线程停止执行一段时间，但不会释放锁。



https://www.geeksforgeeks.org/tag/java-multithreading/

> Difference between Traditional Collections and Concurrent Collections in java

- Queue vs. BlockingQueue
- HashMap vs. ConcurrentHashMap
- ArrayList vs. CopyOnWriteArrayList


> Deadlock and Starvation in Java

Deadlock: Deadlock is a situation when two threads are waiting for each other and the waiting is never ends. Here both threads cant completes their tasks.

Starvation:In Starvation, threads are also waiting for each other. But here waiting time is not infinite after some interval of time, waiting thread always gets the resources whatever is required to execute thread run() method.


> isAlive() and join() methods of Thread Class in Java


How can one thread know when another thread has ended?
Thread provides a means by which you can answer this question. Java multi-threading provides two ways to find that

1) isAlive() : It tests if this thread is alive. A thread is alive if it has been started and has not yet died.

2) join() : When the join() method is called, the current thread will simply wait until the thread it is joining with is no longer alive.


> How a thread can interrupt an another thread in Java?

interrupt() method : If any thread is in sleeping or waiting state then using interrupt() method, we can interrupt the execution of that thread by showing InterruptedException. A thread which is in the sleeping or waiting state can be interrupted with the help of interrupt() method of Thread class.


Different scenarios where we can interrupt a thread:

1) Interrupting a thread that doesn’t stop working

2) Interrupting a thread that stops working : In the program, after interrupting currently executing thread, we are throwing a new exception in the catch block so it will stop working.

3) Interrupting a thread that works normally : In the program, there is no exception occurred during the execution of thread. Here, interrupt only sets the interrupted flag to true, which can be used by java programmer later.



> Difference between notify() and notifyAll() in Java

notify() and notifyAll() methods with wait() method are used to for communication between the threads. A thread which goes into waiting state by calling wait() method will be in waiting state until any other thread calls either notify() or notifyAll() method on the same object.


Applications of notify() and notifyAll():

A maintenance operation on a shared resource, where multiple threads are waiting for the operation to complete before accessing the resource; for these we should go for notifyAll().

Let’s say we have a producer thread and a consumer thread. Each “packet” produced by the producer should be consumed by a consumer. The consumer puts something in a queue and then calls notify().

We want to have a notification when a lengthy process has finished. You want a beep and a screen update. The process performs notifyAll() to notify both the beeping-thread and the screen-update-thread.


> Object level and Class level locks in Java

In synchronization, there are two types of locks on threads:

1) Object level lock
Every object in java has a unique lock.
Acquiring and release lock internally is taken care by JVM and programmer is not responsible for these activities.

class Klass implements Runnable {
    void run() {
        synchronized(this) {...}
    }
}


2) Class level lock
If a thread wants to execute a static synchronized method, then thread requires class level lock.

class Klass implements Runnable {
    void run() {
        synchronized(this) {Klass.class}
    }
}


> Overloading of Thread class run() method


> Implement Runnable vs Extend Thread in Java

Define a thread in the following two ways:
    1. By extending Thread class
    2. By implementing Runnable interface

Java doesn't support multi inheritance.
Thus implementing Runnable interface gave us more flexibility.


> Reentrant Lock in Java

The traditional way to achieve thread synchronization in Java is by the use of synchronized keyword. While it provides a certain basic synchronization, the synchronized keyword is quite rigid in its use. For example, a thread can take a lock only once. Synchronized blocks don’t offer any mechanism of a waiting queue and after the exit of one thread, any thread can take the lock. This could lead to starvation of resources for some other thread for a very long period of time.

Reentrant Locks are provided in Java to provide synchronization with greater flexibility.


What are Reentrant Locks?

The ReentrantLock class implements the Lock interface and provides synchronization to methods while accessing shared resources. The code which manipulates the shared resource is surrounded by calls to lock and unlock method. This gives a lock to the current working thread and blocks all other threads which are trying to take a lock on the shared resource.

As the name says, ReentrantLock allow threads to enter into lock on a resource more than once. When the thread first enters into lock, a hold count is set to one. Before unlocking the thread can re-enter into lock again and every time hold count is incremented by one. For every unlock request, hold count is decremented by one and when hold count is 0, the resource is unlocked.

Reentrant Locks also offer a fairness parameter, by which the lock would abide by the order of the lock request i.e. after a thread unlocks the resource, the lock would go to the thread which has been waiting for the longest time. This fairness mode is set up by passing true to the constructor of the lock.

These locks are used in the following way:

public void some_method() {
    reentrantlock.lock();
    try {}
    catch(Exception e){
        e.printStackTrace();
    }
    finally {
        reentrantlock.unlock();
    }
}

The unlock statement is always called in the finally block to ensure that the lock is released even if an exception is thrown in the method body(try block).


ReentrantLock Methods

lock()
    Call to the lock() method increments the hold count by 1 and gives the lock to the thread if the shared resource is initially free.

unlock()
    Call to the unlock() method decrements the hold count by 1. When this count reaches zero, the resource is released.

tryLock()
    If the resource is not held by any other thread, then call to tryLock() returns true and the hold count is incremented by one. If the resource is not free then the method returns false and the thread is not blocked but it exits.

tryLock(long timeout, TimeUnit unit)
    As per the method, the thread waits for a certain time period as defined by arguments of the method to acquire the lock on the resource before exiting.

lockInterruptibly()
    This method acquires the lock if the resource is free while allowing for the thread to be interrupted by some other thread while acquiring the resource. It means that if the current thread is waiting for lock but some other thread requests the lock, then the current thread will be interrupted and return immediately without acquiring lock.

int getHoldCount()
    This method returns the count of the number of locks held on the resource.

isHeldByCurrentThread()
    This method returns true if the lock on the resource is held by the current thread.


Producer-Consumer solution using threads in Java

In computing, the producer–consumer problem (also known as the bounded-buffer problem) is a classic example of a multi-process synchronization problem. The problem describes two processes, the producer and the consumer, which share a common, fixed-size buffer used as a queue.

The producer’s job is to generate data, put it into the buffer, and start again.
At the same time, the consumer is consuming the data (i.e. removing it from the buffer), one piece at a time.


Problem :
1) To make sure that the producer won’t try to add data into the buffer if it’s full
2) the consumer won’t try to remove data from an empty buffer.

class Main
    final PC pc = new PC();

    Thread tProducer = new Thread(new Runnable() {
        @Override
        public void run()
            pc.produce();

    Thread tConsumer = new Thread(new Runnable() {
        @Override
        public void run()
            pc.consume();

    tProducer.start();
    tConsumer.start();


class PC
    LinkedList<Integer> list = new LinkedList<>();
    int capacity = 2;

    // called by producer thread
    public void produce() throws InterruptedException
            int value = 0;
            while (true) {
                synchronized (this) {
                    // is full
                    while (list.size()==capacity) wait();
                    list.add(value++);

                    notify();

                    Thread.sleep(1000);
                }

    // called by consumer thread
    public void consume() throws InterruptedException
            while (true) {
                synchronized (this) {
                    // is empty
                    while (list.size()==0) wait();

                    int val = list.removeFirst();

                    notify();

                    Thread.sleep(1000);


> Producer-Consumer solution using Semaphores in Java

In this post, we will use Semaphores to implement the same.


The below solution consists of four classes:

Q : the queue that you’re trying to synchronize
Producer : the threaded object that is producing queue entries
Consumer : the threaded object that is consuming queue entries
PC : the driver class that creates the single Q, Producer, and Consumer.

class Q {
    int item;

    // semCon initialized with 0 permits
    // to ensure put() executes first
    static Semaphore semCon = new Semaphore(0);
    static Semaphore semProd = new Semaphore(1);

    void put(int item) {
        semProd.acquire();
        this.item = item;
        semCon.release();
    }

    void get() {
        semCon.acquire();
        print "consuming " + item;
        semProd.release();
    }
}

class Producer implements Runnable {
    void run() {
        for(int i=0; i < 5; i++) q.put();
    }
}

class Consumer implements Runnable {
    void run() {
        for(int i=0; i < 5; i++) q.get();
    }
}

class Main {
    Q q = new Q();

    Thread tProducer = new Thread(new Producer(q));
    Thread tConsumer = new Thread(new Consumer(q));

    tProducer.start();
    t.Consumer.start();
}


> Thread Pools in Java

Server Programs such as database and web servers repeatedly execute requests from multiple clients and these are oriented around processing a large number of short tasks. An approach for building a server application would be to create a new thread each time a request arrives and service this new request in the newly created thread. While this approach seems simple to implement, it has significant disadvantages. A server that creates a new thread for every request would spend more time and consume more system resources in creating and destroying threads than processing actual requests.

Since active threads consume system resources, a JVM creating too many threads at the same time can cause the system to run out of memory. This necessitates the need to limit the number of threads being created.

What is ThreadPool in Java?

A thread pool reuses previously created threads to execute current tasks and offers a solution to the problem of thread cycle overhead and resource thrashing.

Since the thread is already existing when the request arrives, the delay introduced by thread creation is eliminated, making the application more responsive.


- Java provides the Executor framework which is centered around the Executor interface, its sub-interface –ExecutorService and the class-ThreadPoolExecutor, which implements both of these interfaces. By using the executor, one only has to implement the Runnable objects and send them to the executor to execute.

- They allow you to take advantage of threading, but focus on the tasks that you want the thread to perform, instead of thread mechanics.

- To use thread pools, we first create a object of ExecutorService and pass a set of tasks to it. ThreadPoolExecutor class allows to set the core and maximum pool size.The runnables that are run by a particular thread are executed sequentially.



ThreadPoolExecutor Methods

newFixedThreadPool(int)
    Creates a fixed size thread pool.

newCachedThreadPool()
    Creates a thread pool that creates new threads as needed, but will reuse previously constructed threads when they are available

newSingleThreadExecutor()
    Creates a single thread.


In case of a fixed thread pool, if all threads are being currently run by the executor then the pending tasks are placed in a queue and are executed when a thread becomes idle.


Thread Pool Example
In the following tutorial, we will look at a basic example of thread pool executor- FixedThreadPool.

Steps to be followed
1. Create a task(Runnable Object) to execute
2. Create Executor Pool using Executors
3. Pass tasks to Executor Pool
4. Shutdown the Executor Pool


import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

class Task implements Runnable {
    public void run() {
        Thread.sleep(1000);
        System.out.println(name+" complete");
    }
}

class Main {
    Task[] tasks = new Task[5];
    for (int i = 0; i < tasks.length; i++) {
        tasks[i] = new Task();
    }

    static final int MAX_THREAD_NUM = 3;
    ExecutorService pool = Executors.newFixedThreadPool(MAX_THREAD_NUM);

    for (Task task : tasks) {
        pool.execute(task);
    }

    pool.shutdown();
}


> Semaphore in Java

A semaphore controls access to a shared resource through the use of a counter. If the counter is greater than zero, then access is allowed. If it is zero, then access is denied. What the counter is counting are permits that allow access to the shared resource. Thus, to access the resource, a thread must be granted a permit from the semaphore.

Constructors:
Semaphore(int num)
Semaphore(int num, boolean fair=false)


acquire(); cnt-- // blocking call
release(); cnt++

boolean tryAcquire(); // non-blocking



> Java.lang.Thread class in Java

Constructors:
Thread(): Allocates a new Thread object
Thread(Runnable target): Allocates a new Thread object
Thread(Runnable target, String name): Allocates a new Thread object
Thread(String name): Allocates a new Thread object
Thread(ThreadGroup group, Runnable target): Allocates a new Thread object
Thread(ThreadGroup group, Runnable target, String name): Allocates a new Thread object so that it has target as its run object, has the specified name as its name, and belongs to the thread group referred to by group
Thread(ThreadGroup group, Runnable target, String name, long stackSize): Allocates a new Thread object so that it has target as its run object, has the specified name as its name, and belongs to the thread group referred to by group, and has the specified stack size
Thread(ThreadGroup group, String name): CAllocates a new Thread object


Methods:
static int activeCount()
    java.lang.Thread.activeCount() Returns an estimate of the number of active threads in the current thread’s thread group and its subgroups

static Thread currentThread()
    java.lang.Thread.currentThread() Returns a reference to the currently executing thread object

static void dumpStack()
    Prints a stack trace of the current thread to the standard error stream. This method is used only for debugging


> Lifecycle and States of a Thread in Java

A thread lies only in one of the shown states at any instant:
Thread.State NEW
Thread.State RUNNABLE
Thread.State BLOCKED
Thread.State WAITING
Thread.State TIMED_WAITING
Thread.State TERMINATED
    New
    Runnable
    Blocked
    Waiting
    Timed Waiting
    Terminated


> Main thread in Java


JVM -> starts Main Threads -> starts Child Thread1 -> starts Child Thread3
                           -> starts Child Thread2

    -> starts Other Daemon Threads (e.g. Garbage Collector)

How to control Main thread
Thread main = Thread.currentThread();
main.join() // deadlock


> Daemon thread in Java

Properties:

- They can not prevent the JVM from exiting when all the user threads finish their execution.
- JVM terminates itself when all user threads finish their execution
- If JVM finds running daemon thread, it terminates the thread and after that shutdown itself. JVM does not care whether Daemon thread is running or not.
- It is an utmost low priority thread.

Methods

void setDaemon(boolean on)
    on : if true, marks this thread as a daemon thread.

boolean isDaemon()
    This method is used to check that current is daemon. It returns true if the thread is Daemon else it returns false.

Daemon thread is a low priority thread that runs in background to perform tasks such as garbage collection.

Daemon vs User Threads

Priority: When the only remaining threads in a process are daemon threads, the interpreter exits. This makes sense because when only daemon threads remain, there is no other thread for which a daemon thread can provide a service.
Usage: Daemon thread is to provide services to user thread for background supporting task.


Exceptions in Daemon thread

If you call the setDaemon() method after starting the thread, it would throw IllegalThreadStateException.



> Java.util.concurrent.CyclicBarrier in Java

CyclicBarrier is used to make threads wait for each other. It is used when different threads process a part of computation and when all threads have completed the execution, the result needs to be combined in the parent thread. In other words, a CyclicBarrier is used when multiple thread carry out different sub tasks and the output of these sub tasks need to be combined to form the final output. After completing its execution, threads call await() method and wait for other threads to reach the barrier. Once all the threads have reached, the barriers then give the way for threads to proceed.


Working of CyclicBarrier

CyclicBarriers are defined in java.util.concurrent package. First a new instance of a CyclicBarriers is created specifying the number of threads that the barriers should wait upon.


CyclicBarrier newBarrier = new CyclicBarrier(numberOfThreads);


Each and every thread does some computation and after completing it’s execution, calls await() methods as shown:

public void run()
{
    // thread does the computation
    newBarrier.await();
}

Runnable action = ...
//action to be performed when all threads reach the barrier;
CyclicBarrier newBarrier = new CyclicBarrier(numberOfThreads, action);


Important Methods of CyclicBarrier:
int getParties()
    Returns the number of parties required to trip this barrier

void reset()
    resets the barrier to its initial state. If any parties are currently waiting at the barrier, they will return with a BrokenBarrierException.

boolean isBroken()
    true if one or more parties broke out of this barrier due to interruption or timeout since construction or the last reset, or a barrier action failed due to an exception; false otherwise.

int getNumberWaiting()
    returns the number of parties currently blocked in await()

int await() throws InterruptedException, BrokenBarrierException
    Returns:
    the arrival index of the current thread, where index getParties() – 1 indicates the first to arrive and zero indicates the last to arrive.

int await(long timeout, TimeUnit unit)
throws InterruptedException,
BrokenBarrierException, TimeoutException



> SwingWorker in Java

SwingWorker is an abstract class developed for Swing library of the Java programming language. It is used to performed lengthy GUI interaction tasks in a background thread. While developing applications, sometimes the GUI hangs when it is trying to do some huge or lengthy task. This lag is a big bottleneck. For such purposes, swingworker is developed which schedules the execution of this lengthy task on a different thread while the GUI still remains responsive.

Java language has three threads, namely:

- Current Thread (Initial Thread): this is the thread on which the initial application logic executes.
- Event Dispatch Thread: all event handling code executes on this thread.
- Worker Threads: also known as background thread where all time consuming background tasks are executed.



> Callable and Future in Java

Callable

Runnable is that we cannot make a thread return result when it terminates, i.e. when run() completes. For supporting this feature, the Callable interface is present in Java.


Callable vs Runnable

For implementing Runnable, the run() method needs to be implemented which does not return anything, while for a Callable, the call() method needs to be implemented which returns a result on completion.

Note that a thread can’t be created with a Callable, it can only be created with a Runnable.

Another difference is that the call() method can throw an exception whereas run() cannot.

Method signature that has to overridden for implementing Callable.

public Object call() throws Exception;


Future

When the call() method completes, answer must be stored in an object known to the main thread, so that the main thread can know about the result that the thread returned. How will the program store and obtain this result later? For this, a Future object can be used. Think of a Future as an object that holds the result – it may not hold it right now, but it will do so in the future (once the Callable returns). Thus, a Future is basically one way the main thread can keep track of the progress and result from other threads. To implement this interface, 5 methods have to be overridden, but as the example below uses a concrete implementation from the library, only the important methods are listed here.

Observe that Callable and Future do two different things – Callable is similar to Runnable, in that it encapsulates a task that is meant to run on another thread, whereas a Future is used to store a result obtained from a different thread. In fact, the Future can be made to work with Runnable as well, which is something that will become clear when Executors come into the picture.


Methods

public boolean cancel(boolean mayInterrupt)
    Used to stop the task. It stops the task if it has not started. If it has started, it interrupts the task only if mayInterrupt is true.

public Object get() throws InterruptedException, ExecutionException
    Used to get the result of the task. If the task is complete, it returns the result immediately, otherwise it waits till the task is complete and then returns the result.

public boolean isDone()
    Returns true if the task is complete and false otherwise

To create the thread, a Runnable is required.
To obtain the result, a Future is required.

The Java library has the concrete type FutureTask, which implements Runnable and Future, combining both functionality conveniently.

A FutureTask can be created by providing its constructor with a Callable.
Then the FutureTask object is provided to the constructor of Thread to create the Thread object.


> Java Concurrency – yield(), sleep() and join() methods

yield()

basically means that the thread is not doing anything particularly important and if any other threads or processes need to be run, they should run. Otherwise, the current thread will continue to run.

Use of yield method:

Whenever a thread calls java.lang.Thread.yield method, it gives hint to the thread scheduler that it is ready to pause its execution. Thread scheduler is free to ignore this hint.
If any thread executes yield method , thread scheduler checks if there is any thread with same or high priority than this thread. If processor finds any thread with higher or same priority then it will move the current thread to Ready/Runnable state and give processor to other thread and if not – current thread will keep executing.


sleep()

This method causes the currently executing thread to sleep for the specified number of milliseconds, subject to the precision and accuracy of system timers and schedulers.

//  sleep for the specified number of milliseconds
public static void sleep(long millis) throws InterruptedException

//sleep for the specified number of milliseconds plus nano seconds
public static void sleep(long millis, int nanos)
                         throws InterruptedException

yield() vs sleep()

yield:() indicates that the thread is not doing anything particularly important and if any other threads or processes need to be run, they can. Otherwise, the current thread will continue to run.

sleep(): causes the thread to definitely stop executing for a given amount of time; if no other thread or process needs to be run, the CPU will be idle (and probably enter a power saving mode).


join()

The join() method of a Thread instance is used to join the start of a thread’s execution to end of other thread’s execution such that a thread does not start running until another thread ends. If join() is called on a Thread instance, the currently running thread will block until the Thread instance has finished executing.
The join() method waits at most this much milliseconds for this thread to die. A timeout of 0 means to wait forever



> Method and Block Synchronization in Java


Method Synchronization

class Line
    // if multiple threads(trains) trying to access
    // this synchronized method on the same Object
    // but only one thread will be able
    // to execute it at a time.
    synchronized public void getLine()

class Train extends Thread
   @Override
    public void run() {
        line.getLine();
    }

class Main
    Line o = new Line();

    // we are creating two threads which share
    // same line Object.
    Train train1 = new Train(o);
    Train train2 = new Train(o);


Block Synchronization

class Resource
    int count;
    // Only one thread is permitted
    // to increase counter at a time.
    synchronized(this) {
        count++;
    }


> Java Thread Priority in Multithreading

MIN_PRIORITY: 1
MAX_PRIORITY: 10
NORM_PRIORITY: 5

public final int getPriority()
    java.lang.Thread.getPriority() method returns priority of given thread.
public final void setPriority(int newPriority)
    java.lang.Thread.setPriority() method changes the priority of thread to the value newPriority.
    throws IllegalArgumentException if value of parameter newPriority goes beyond minimum(1) and maximum(10) limit.


> CountDownLatch in Java

CountDownLatch is used to make sure that a task waits for other threads before it starts. To understand its application, let us consider a server where the main task can only start when all the required services have started.

Working of CountDownLatch:
When we create an object of CountDownLatch, we specify the number of threads it should wait for, all such thread are required to do count down by calling CountDownLatch.countDown() once they are completed or ready to the job. As soon as count reaches zero, the waiting task starts running.

Methods:
CountDownLatch latch = new CountDownLatch(4);

latch.countDown(); // in worker thread, cnt--

latch.await(); // in main thread, waiting for all worker process completed(cnt == 0)


Facts about CountDownLatch:

Creating an object of CountDownLatch by passing an int to its constructor (the count), is actually number of invited parties (threads) for an event.
The thread, which is dependent on other threads to start processing, waits on until every other thread has called count down. All threads, which are waiting on await() proceed together once count down reaches to zero.
countDown() method decrements the count and await() method blocks until count == 0


> What does start() function do in multithreading in Java?


What happens when a function is called?

When a function is called the following operations take place:
1. The arguments are evaluated.
2. A new stack frame is pushed into the call stack.
3. Parameters are initialized.
4. Method body is executed.
5. Value is retured and current stack frame is popped from the call stack.


The purpose of start() is to create a separate call stack for the thread. A separate call stack is created by it, and then run() is called by JVM.


> Inter-thread Communication in Java

What is Polling and what are problems with it?

The process of testing a condition repeatedly till it becomes true is known as polling.

Polling is usually implemented with the help of loops to check whether a particular condition is true or not. If it is true, certain action is taken. This waste many CPU cycles and makes the implementation inefficient.


For example, in a classic queuing problem where one thread is producing data and other is consuming it.


How Java multi threading tackles this problem?
To avoid polling, Java uses three methods, namely, wait(), notify() and notifyAll().


All these methods belong to object class as final so that all classes have them. They must be used within a synchronized block only.

wait()
It tells the calling thread to give up the lock and go to sleep until some other thread enters the same monitor and calls notify().

notify()
It wakes up one single thread that called wait() on the same object. It should be noted that calling notify() does not actually give up a lock on a resource.

notifyAll()
It wakes up all the threads that called wait() on the same object.




















