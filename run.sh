make all
cd visualizer
echo "compiling random unique number generator"
gcc rnd_int.c -o rnd_int.exe
./rnd_int.exe ${1:-100} ${2:-0} ${3:-100} > ../unsorted_list.txt
cd ..
./push_swap -o -c $(cat unsorted_list.txt)
echo "generating json file with step by step operations"
./push_swap -j $(cat unsorted_list.txt) > visualizer/commands.json
cd visualizer
echo "injecting json to html hidden container"
sed '/<p id="commands">/ r commands.json' index_tpl.html > index.html

#open index.html
#awk 'FNR==NR{n=n ORS $0; next} /<integers>/{$0=$0 n} 1' output.txt index.html