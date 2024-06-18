src="src"
out="build"

CC="gcc"
GA="gcc"
LD="ld"

CFLAGS="-Wall -Wextra -Werror -I."

name="libertyft.a"

rm -Rf $out
mkdir  $out

for file in $(find src -name "*.c"); do
    out_name=$(basename $file .c).o
    echo "CC $file"
    $CC $CFLAGS -c $file -o $out/$out_name
done

for file in $(find src -name "*.s"); do
    out_name=$(basename $file .s).o
    echo "AS $file"
    $GA -c $file -o $out/$out_name
done

objs=$(find $out -name "*.o")
echo "AR $name"
ar rcs $name $objs
