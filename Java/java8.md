# Upgrade from jdk7 to jdk8 in IntelliJ

## download and install jdk8
http://www.oracle.com/technetwork/java/javase/downloads/jdk8-downloads-2133151.html

## verify jdk8 is installed
$ ls -l /Library/Java/JavaVirtualMachines
total 0
drwxr-xr-x  3 root  wheel  96 Apr  4  2015 jdk1.7.0_75.jdk
drwxr-xr-x  3 root  wheel  96 Jun 15  2015 jdk1.7.0_79.jdk
drwxr-xr-x  3 root  wheel  96 Jan 31 09:36 jdk1.8.0_161.jdk

## switch to jdk8
https://www.jetbrains.com/help/idea/defining-a-jdk-and-a-mobile-sdk-in-intellij-idea.html

## define language level to allow diamonds
https://stackoverflow.com/questions/44005097/java-diamond-types-are-not-supported-at-this-language-level
