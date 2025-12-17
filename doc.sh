#
# Copyright © 2025 Gaël Fortier <gael.fortier.1@ens.etsmtl.ca>
#
if [ ! -d "./out" ]; then
    mkdir ./out
fi
gcc -o ./out/program -Werror -Wreturn-type -ggdb $(find ./src -name '*.c' -print) -I/usr/include -L/usr/lib -static-libgcc
chmod +x ./out/program
./out/program
cp ./src/main.c.md ./docs/docs.md
