use FindBin;
use lib ("$FindBin::Bin/../lib");
use IPC::Run qw( timeout );

sub run {
    my ($cmd, $timeout) = @_;
    $timeout ||= 10;
    my $success = IPC::Run::run $cmd, \undef, \my $out, \my $err, timeout($timeout);
    my $debugInfo =
        "Command: " . join(" ", @$cmd) . "\n"
        . "Output: $out\n"
        . "Error: $err\n";

    die "Failed with error " . ($? >> 8) . ", status " . ($? & 0xff) . ":\n"
        . $debugInfo
        unless $success;
    return $out;
}

sub add_rsa_fingerprint_to_ssh_known_hosts {
    my $host = shift;

    my $home = (getpwuid($<))[7];

    # remove old known host entry
    &run(['ssh-keygen', '-R', "'" . $host . "'", '-f', "$home/.ssh/known_hosts"]);

    # append server pub key (fingerprint) to known_hosts file if not exist
    my $fingerprint = &run(['ssh-keyscan', '-t', 'rsa', '-H', $host]);
    $fingerprint =~ /.* ssh-rsa (.*)/;
    my $pubkey = $1;
    system("grep -q \Q$pubkey\E $home/.ssh/known_hosts || echo \Q$fingerprint\E >> $home/.ssh/known_hosts");
}

&add_rsa_fingerprint_to_ssh_known_hosts('10.0.1.215');
