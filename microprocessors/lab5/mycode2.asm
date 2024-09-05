.model small
.stack 100h

.data
    bolunen db ?
    bolen db ?
    sonuc db ?
    kalan db ?
    bolum db ?
    yeni_bolum db ?
    message1 db "Bolunecek sayiyi girin: $"
    message2 db "Bolen sayiyi girin: $"
    message3 db "Bolum: $"
    message4 db "Kalan: $"
    message5 db "Yeni Bolum: $"
    newline db 0ah, 0dh, '$'

.code
    main proc
        mov ax, @data
        mov ds, ax

        ; Bolunecek sayiyi girin
        lea dx, message1
        mov ah, 09h
        int 21h
        
        mov ah, 01h
        int 21h
        sub al, 30h ; ASCII'den sayiya donusturme
        mov bolunen, al
        
        ; Bolen sayiyi girin
        lea dx, message2
        mov ah, 09h
        int 21h
        
        mov ah, 01h
        int 21h
        sub al, 30h ; ASCII'den sayiya donusturme
        mov bolen, al

        mov al, bolunen
        cbw ; ASCII'den sayiya donusturme
        mov bl, bolen
        div bl ; bolunen / bolen
        mov bolum, al ; bolumun tam kismi

        mov al, bolunen
        cbw ; ASCII'den sayiya donusturme
        mov bl, bolen
        div bl ; bolunen / bolen
        mov kalan, ah ; kalan kismi

        mov al, kalan
        mov bl, bolen
        mov ah, 02h
        div bl ; kalan / bolen
        cmp al, 5 ; kalan > bolen / 2 mi?
        jle skip_inc_bolum ; Deðilse atla
        
        inc bolum ; bolum += 1

        skip_inc_bolum:

        
        mov al, bolum
        add al, 1 ; bolum += 1
        mov yeni_bolum, al

        
        lea dx, message3
        mov ah, 09h
        int 21h

        mov dl, bolum
        add dl, 30h
        mov ah, 02h
        int 21h

        lea dx, message4
        mov ah, 09h
        int 21h

        mov dl, kalan
        add dl, 30h
        mov ah, 02h
        int 21h

        lea dx, message5
        mov ah, 09h
        int 21h

        mov dl, yeni_bolum
        add dl, 30h
        mov ah, 02h
        int 21h

       
        mov dx, offset newline
        mov ah, 09h
        int 21h

       
        mov ah, 4ch
        int 21h
    main endp
end main
