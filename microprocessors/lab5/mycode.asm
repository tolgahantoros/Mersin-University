section .data
    dividend dd 8       ; Dividend
    divisor  dd 3       ; Divisor
    result   dd 0       ; Result

section .text
    global _start

_start:
    ; Load dividend into eax
    mov eax, [dividend]
    ; Load divisor into ebx
    mov ebx, [divisor]
    ; Perform division
    idiv ebx

    ; Check if the remainder is greater than or equal to half of the divisor
    ; If yes, round up
    ; If no, round down
    cmp edx, 0
    jl round_down
    jmp round_up

round_up:
    ; Round up: Add 1 to the quotient
    inc eax
    jmp end_rounding

round_down:
    ; Round down: Keep the quotient as it is
    ; Do nothing

end_rounding:
    ; Store the result
    mov [result], eax

    ; Exit program
    mov eax, 1          ; syscall number for exit
    xor ebx, ebx        ; exit status 0
    int 0x80            ; call kernel
