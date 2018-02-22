#!/usr/bin/perl
# Ref:
# Title: How to add a new monitor resolusion in ubuntu?
# http://askubuntu.com/questions/138408/how-to-add-display-resolution-fo-an-lcd-in-ubuntu-12-04-xrandr-problem
#
# $ xrandr
# Screen 0: minimum 320 x 200, current 1024 x 768, maximum 2048 x 2048
# VGA1 connected 1024x768+0+0 (normal left inverted right x axis y axis) 0mm x 0mm
#    1024x768       60.0*
#    800x600        60.3     56.2
#    848x480        60.0
#    640x480        59.9
#
# $ cvt 1920 1080 60
#  1920x1080 59.96 Hz (CVT) hsync: 79.57 kHz; pclk: 206.25 MHz
# Modeline "1920x1080_60.00"  206.25  1920 2056 2256 2592  1080 1283 1293 1327 -hsync +vsync
#
# $ xrandr --newmode "1920x1080_60.00"  206.25  1920 2056 2256 2592  1080 1283 1293 1327 -hsync +vsync
#
# $ xrandr --addmode VGA1 "1920x1080_60.00"

sub run {
    my $cmd = shift;
    print "`$cmd`" . "\n";
    my $out = `$cmd`;
    chomp $out;
    return $out;
}


my $monitor_name = &run('xrandr | grep " connected " | cut -d" " -f1');
# print $monitor_name;
# >>>
# VGA1

my $modeline = &run('cvt 1920 1080 60 | grep Modeline');
(my $modeline = $modeline) =~ s/Modeline\s+(\S+)/\1/;
# print $modeline;
# >>>
# "1920x1080_60.00"  206.25  1920 2056 2256 2592  1080 1283 1293 1327 -hsync +vsync
$modeline =~ /"([^"]+)"/;
my $modename = $1; 
# print $modename;
# >>>
# 1920x1080_60.00

# create new resolution mode
&run("xrandr --newmode $modeline");

# add the new resolution mode to the selected monitor
&run("xrandr --addmode $monitor_name \"$modename\"");

# activate the new resolution mode
&run("xrandr --output $monitor_name --mode $modename");
