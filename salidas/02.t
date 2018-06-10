function main
  vars
    n 1
    f 1
    aux 1
    end 1
  endvars

     readi n
     aux = n
     %3 = 0
     %4 = n < %3
     ifFalse %4 goto endif1
     %5 = 'n'
     writec %5
     %5 = ' '
     writec %5
     %5 = '>'
     writec %5
     %5 = '='
     writec %5
     %5 = ' '
     writec %5
     %5 = '0'
     writec %5
     %5 = '!'
     writec %5
     writeln
     %6 = 1
     end = %6
  label endif1 :
     %7 = 1
     f = %7
     %9 = not end
     %11 = 1
     %12 = n <= %11
     %12 = not %12
     %13 = %9 and %12
     ifFalse %13 goto endwhile1
  label loop20 :
     %16 = f * n
     f = %16
     %18 = 1
     %19 = n - %18
     n = %19
     %9 = not end
     %11 = 1
     %12 = n <= %11
     %12 = not %12
     %13 = %9 and %12
     ifFalse %13 goto endwhile1
     goto loop20
  label endwhile1 :
     %22 = 0
     %23 = end == %22
     ifFalse %23 goto endif2
     writei aux
     %25 = '!'
     writec %25
     %25 = '='
     writec %25
     writei f
     writeln
  label endif2 :
     return
endfunction


