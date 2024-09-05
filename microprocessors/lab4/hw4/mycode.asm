org 100h

.model small
.stack 100h

.data
BLOCKA db 'tolgaHan toRos id nO.20155829 aSSG1=90, aSSG2=70, aSSG3=80 sPRING 2024#'
BLOCKB db 100h dup(?)
UPPER db ?
LOWER db ?
result_upper db 'kucuk harf sayisi:$'
result_lower db 0Dh, 0Ah, 'buyuk harf sayisi:$'

.code
main:
    mov ax, @data
    mov ds, ax

    mov UPPER, 0
    mov LOWER, 0

    mov si, offset BLOCKA
    mov di, offset BLOCKB
    mov cx, 100h
    cld

copy_and_count_loop:
    mov al, [si]
    cmp al, '#'
    je end_copy_and_count

    cmp al, 'a'
    jb not_lowercase
    cmp al, 'z'
    ja not_lowercase
    inc LOWER
    jmp copy_next_char_and_count

not_lowercase:
    cmp al, 'A'
    jb copy_next_char_and_count
    cmp al, 'Z'
    ja copy_next_char_and_count
    inc UPPER

copy_next_char_and_count:
    inc si
    jmp copy_char

copy_char:
    mov al, [si-1]
    mov [di], al
    inc di
    loop copy_and_count_loop

end_copy_and_count:

    mov ah, 09h
    mov dx, offset result_upper
    int 21h

    ; ASCII karakter kodunu sayýya dönüþtürme iþlemi
    add UPPER, '0'

    mov dl, UPPER
    mov ah, 02h
    int 21h

    mov dl, 0Dh
    mov ah, 02h
    int 21h

    mov dl, 0Ah
    mov ah, 02h
    int 21h

    mov ah, 09h
    mov dx, offset result_lower
    int 21h

    ; ASCII karakter kodunu sayýya dönüþtürme iþlemi
    add LOWER, '0'

    mov dl, LOWER
    mov ah, 02h
    int 21h

    mov ah, 4Ch
    int 21h

end main
ret
