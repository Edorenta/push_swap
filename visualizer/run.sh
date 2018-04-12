sed '/<p id="integers">/ r output.txt' index_tpl.html >> index.html
#awk 'FNR==NR{n=n ORS $0; next} /<integers>/{$0=$0 n} 1' output.txt index.html