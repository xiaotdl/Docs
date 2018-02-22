#!/bin/bash
# Title: How to Change Your Hostname on Ubuntu (or other Debian based Linux distro)
# Ref: http://www.howtogeek.com/197934/how-to-change-your-hostname-computer-name-on-ubuntu-linux/

# When the current user isn't root, re-exec the script through sudo.
[ "$(whoami)" != "root"  ] && exec sudo -- "$0" "$@"

prev_hostname=`hostname`
hostname=$1 # current hostname

Usage(){
    echo "Usage:"
    echo "  ./change_hostname.sh <hostname>"
}

if [ ! -n "$hostname" ]; then
        echo "<hostname> is required."
        Usage
        exit 1
else
        printf "Changing hostname from '$prev_hostname' to '$hostname' ... "
fi

# Ubuntu and other Debian-based distribution read the /etc/hostname file,
# while booting up and set your computer’s hostname to the one contained
# in the file. Your change won’t take effect immediately — you’ll have to
# reboot or use the hostname command to change it immediately.
sed -i "s/$prev_hostname/$hostname/g" /etc/hostname

# The hostname is also stored in the /etc/hosts file,
# where it’s set to redirect to your local computer — localhost.
sed -i "s/\(127.0.1.1\s\+\)$prev_hostname/\1$hostname/g" /etc/hosts

# Change your hostname immediately.
# This command only changes the hostname until the next time you reboot,
# so you do have to change the /etc/hostname file to change it permanently.
hostname $hostname

echo "[OK]"
echo "SSH again/open another terminal/restart to see the new hostname!"