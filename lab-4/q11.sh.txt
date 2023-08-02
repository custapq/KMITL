ans=20
correct=10
incorrect=7
cantcompile=5

for file in $(find . -type f -name "prog*.c"); do
    prog_name=$(echo $file | cut -d'/' -f2 | cut -d'.' -f1)
    print_name=$(echo $file | cut -d'/' -f2)

    if gcc "$file" -o "$prog_name" > /dev/null 2>&1; then
        result=$(./$prog_name) 
        if [ "$ans" -eq "$result" ]; then
            printf "%s %d\n" "$print_name" "$correct"
        else
            printf "%s %d\n" "$print_name" "$incorrect"
        fi
    else
        printf "%s %d\n" "$print_name" "$cantcompile"
    fi
done
