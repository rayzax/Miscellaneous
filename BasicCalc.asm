;BasicCalculator Assembly Logic
.586                    ; Target processor. Use instructions for Pentium class machines
.MODEL FLAT, C          ; Use the flat memory model. Use C calling conventions
.STACK                  ; Define a stack segment of 1KB (Not required for this example)
.DATA                   ; Create a near data segment. Local variables are declared after
.CODE                   ; Indicates the start of a code segment.

PUBLIC add_asm
PUBLIC sub_asm
PUBLIC mult_asm
;PUBLIC mult_asm         ; Make this function public to everybody

add_asm PROC, arg1:DWORD, arg2:DWORD
    mov eax, arg1       ; Get first argument
    add eax, arg2       ; Get second argument, do the add, and save the results in register eax
    ret                 ; Return result in register eax
add_asm ENDP

sub_asm PROC, arg1:DWORD, arg2:DWORD
    mov eax, arg1
    sub eax, arg2
    ret
sub_asm ENDP

mult_asm PROC, arg1:DWORD, arg2:DWORD
    mov eax, arg1
    imul eax, arg2
    ret
mult_asm ENDP

div_asm PROC, arg1:DWORD, arg2:DWORD
    mov eax, arg1
    cdq
    idiv arg2
    ret
div_asm ENDP

END
