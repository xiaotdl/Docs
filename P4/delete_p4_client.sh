if [ $# != 1 ]
then
  echo "USAGE: $0 <client_name>"
  exit
fi
 
( p4 -c $1 client -o | perl -pne 's/\blocked\s//' | p4 -c $1  client -i ) && p4 client -d $1