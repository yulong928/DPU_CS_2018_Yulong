data    segment
        str1    db      'input a number : $'
        str2    db      'error input! $'
data    ends
code    segment
        assume  cs:code,ds:data
start:  mov     ax,data
        mov     ds,ax
        lea     dx,str1
        mov     ah,09h
        int     21h
        mov     ah,01h
        int     21h
        push    ax
        mov     dl,0ah
        mov     ah,02h
        int     21h
        pop     ax
        cmp     al,31h
        jb      error
        cmp     al,39h
        ja      error
        and     al,0fh
        mov     cx,0
        call    alad
;alad:   add     cl,al
        ;push    ax
        ;mov     al,cl
        ;daa
        ;mov     cl,al
        ;pop     ax
        ;sub     al,1
        ;ja      alad
        mov     al,cl
        push    ax
        and     al,0f0h
        mov     cl,4
        shr     al,cl
        or      al,30h
        mov     dl,al
        mov     ah,02h
        int     21h
        pop     ax
        and     al,0fh
        or      al,30h
        mov     dl,al
        mov     ah,02h
        int     21h
        jmp     half
half:   mov     ah,4ch
        int     21h
error:  lea     dx,str2
        mov     ah,09h
        int     21h
        jmp     half
alad    proc    near
        cmp     al,0
        je      init
        add     cl,al
        push    ax
        mov     al,cl
        daa
        mov     cl,al
        pop     ax
        sub     al,1
        call    alad
init:   ret
alad    endp
code    ends
        end     start
