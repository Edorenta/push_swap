make all
cd visualizer/c
echo "compiling random unique number generator"
gcc rnd_int.c -o rnd_int
gcc list_jsonifier.c -o list_jsonifier
#gcc json_maker.c -o json_maker.exe
./rnd_int ${1:-100} ${2:-0} ${3:-99} > ../../unsorted_list.txt
cd ../..
./push_swap -o -c $(cat unsorted_list.txt)
echo "generating json file with step by step operations"
./push_swap -j $(cat unsorted_list.txt) > visualizer/commands.json
cd visualizer
echo "injecting json to html hidden container"
sed '/<p id="commands">/ r commands.json' html/index_tpl.html > html/index.html

#open index.html
#awk 'FNR==NR{n=n ORS $0; next} /<integers>/{$0=$0 n} 1' output.txt index.html
