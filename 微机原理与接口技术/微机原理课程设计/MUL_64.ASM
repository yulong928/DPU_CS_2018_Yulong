data segment
x1      dw      2 dup(?)
x2      dw      2 dup(?)
y       dw      4 dup(0)
tip     db      'please input a number: $'
war     db      'error input! $'
data ends
code segment
        assume  cs:code,ds:data
start:  mov     ax,data
        mov     ds,ax
        lea     dx,tip
        mov     ah,09h
        int     21h
        mov     cx,4
        xor     dx,dx
        call    scan
        mov     [x1+2],dx
        mov     cx,4
        xor     dx,dx
        call    scan
        mov     [x1],dx
        mov     dx,0ah
        mov     ah,02h
        int     21h
        lea     dx,tip
        mov     ah,09h
        int     21h
        mov     cx,4
        xor     dx,dx
        call    scan
        mov     [x2+2],dx
        mov     cx,4
        xor     dx,dx
        call    scan
        mov     [x2],dx
        mov     ax,[x1]
        mov     bx,[x2]
        mul     bx
        mov     [y],ax
        mov     [y+2],dx
        mov     ax,[x1+2]
        mov     bx,[x2]
        mul     bx
        add     [y+2],ax
        adc     [y+4],dx
        mov     ax,[x1]
        mov     bx,[x2+2]
        mul     bx
        add     [y+2],ax
        adc     [y+4],dx
check:  jc      doi
        mov     ax,[x1+2]
        mov     bx,[x2+2]
        mul     bx
        add     [y+4],ax
        adc     [y+6],dx
        jmp     outo
doi:    add     [y+6],1
        jmp     check
outo:   mov     dx,0ah
        mov     ah,02h
        int     21h
        mov     bx,[y+6]
        mov     cl,4
        shr     bh,cl
        mov     al,bh
        and     al,0fh
        call    output
        mov     bx,[y+6]
        mov     al,bh
        and     al,0fh
        call    output
        mov     bx,[y+6]
        mov     cl,4
        shr     bl,cl
        mov     al,bl
        and     al,0fh
        call    output
        mov     bx,[y+6]
        mov     al,bl
        and     al,0fh
        call    output
        mov     bx,[y+4]
        mov     cl,4
        shr     bh,cl
        mov     al,bh
        and     al,0fh
        call    output
        mov     bx,[y+4]
        mov     al,bh
        and     al,0fh
        call    output
        mov     bx,[y+4]
        mov     cl,4
        shr     bl,cl
        mov     al,bl
        and     al,0fh
        call    output
        mov     bx,[y+4]
        mov     al,bl
        and     al,0fh
        call    output
        mov     bx,[y+2]
        mov     cl,4
        shr     bh,cl
        mov     al,bh
        and     al,0fh
        call    output
        mov     bx,[y+2]
        mov     al,bh
        and     al,0fh
        call    output
        mov     bx,[y+2]
        mov     cl,4
        shr     bl,cl
        mov     al,bl
        and     al,0fh
        call    output
        mov     bx,[y+2]
        mov     al,bl
        and     al,0fh
        call    output
        mov     bx,[y]
        mov     cl,4
        shr     bh,cl
        mov     al,bh
        and     al,0fh
        call    output
        mov     bx,[y]
        mov     al,bh
        and     al,0fh
        call    output
        mov     bx,[y]
        mov     cl,4
        shr     bl,cl
        mov     al,bl
        and     al,0fh
        call    output
        mov     bx,[y]
        mov     al,bl
        and     al,0fh
        call    output
half:   mov     ah,4ch
        int     21h
input   proc    near
        mov     bx,10h
        mov     ax,dx
        mul     bx
        mov     dx,ax
        mov     ah,01h
        int     21h
        cmp     al,30h
        jb      error
        cmp     al,46h
        ja      error
        cmp     al,39h
        ja      check2
next2:  and     ax,000fh
        add     dx,ax
        ret
check2: cmp     al,41h
        jb      error
        sub     al,7
        jmp     next2
error:  lea     dx,war
        mov     ah,09h
        int     21h
        mov     bx,0
        ret
input   endp
scan    proc    near
scan1:  cmp     cx,0
        je      finish
        call    input
        cmp     bx,0
        je      half
        sub     cx,1
        jmp     scan1
finish: ret
scan    endp
output  proc    near
        cmp     al,0ah
        jb      ones
        add     al,37h
        jmp     next
ones:   add     al,30h
next:   mov     dl,al
        mov     ah,02h
        int     21h
        ret
output  endp
code    ends
        end     start