function f2
  vars
    x2 1
    y2 1
  endvars

     %1 = 0
     x2 = %1
     y2 = x2
     %7 = 3
     %8 = y2 * %7
     %9 = x2 == %8
     ifFalse %9 goto endif3
     %11 = 5
     %12 = y2 * %11
     %13 = 3
     %14 = %12 + %13
     x2 = %14
     %16 = 1
     %18 = %16 + y2
     %19 = 1
     %20 = %18 + %19
     y2 = %20
     %23 = 1
     %24 = x2 + %23
     %26 = 2
     %27 = y2 * %26
     %28 = %24 == %27
     ifFalse %28 goto endif1
     %29 = 'o'
     writec %29
     %29 = 'k'
     writec %29
  label endif1 :
     %31 = 1
     %32 = 1
     %33 = %31 + %32
     %34 = y2 == %33
     ifFalse %34 goto endif2
     %36 = 6
     %37 = x2 * %36
     writei %37
  label endif2 :
  label endif3 :
     return
endfunction

function main
     %1 = 7
     %2 = 7
     %3 = %1 == %2
     ifFalse %3 goto endif1
     call f2
  label endif1 :
     %5 = 'b'
     writec %5
     %5 = 'y'
     writec %5
     %5 = 'e'
     writec %5
     writeln
     return
endfunction


