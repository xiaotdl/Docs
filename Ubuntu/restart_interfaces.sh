sleep 1
# subinterfaces needs to be shutdown first
ifdown eth1:2 eth1:1 eth1 eth0
mv /etc/network/interfaces.tmp /etc/network/interfaces
ifup eth0 eth1 eth1:1 eth1:2
