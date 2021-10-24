g++ -H -std=c++17 -O2 -Wall -Wextra -pedantic -Wshadow -Wformat=2 -Wfloat-equal -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -Wno-unused-result -Wno-sign-conversion -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fstack-protector -D_FORTIFY_SOURCE=2 main.cpp -o ./main
echo ""

cnt=1

for i in *.in; do
    cnt=$((cnt+1))
done

program_output="output"
sample_output="sample"
num_wa=0
for (( i=1; i<cnt; i++))
do
    ./main < "$sample_output$i".in > "$program_output$i".out
    if [ $? -eq 0 ]; then
        diff -q "$program_output$i".out "$sample_output$i".out 1>/dev/null
        if [[ $? == "0" ]]
        then
            echo -e "TEST CASE $i: \e[1;30m\e[1;42mAC\e[0m"
        else
            echo -e "TEST CASE $i: \e[1;30m\e[1;41mWA\e[0m"
            python3 ~/git/melt/start.py "$program_output$i".out "$sample_output$i".out 
            num_wa=$((num_wa+1))
        fi
    else
        echo -e "\e[1;30m\e[1;45mRTE / MLE\e[0m"
        exit 1
    fi
done

echo ""

if [ $num_wa == 0 ]
then
    echo -e "\e[1;30m\e[1;42m$((cnt-num_wa-1)) / $((cnt-1))\e[0m"
else
    echo -e "\e[1;30m\e[1;41m$((cnt-num_wa-1)) / $((cnt-1))\e[0m"
fi

echo ""
