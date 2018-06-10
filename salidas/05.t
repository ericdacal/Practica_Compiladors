function f
  params
    _result
    a
    b
  endparams

  vars
    x 1
    y 1
    z 10
  endvars

     %1 = 9
     %3 = 1
     %2 = %3 * %1
     %6 = 67
     %7 = a + %6
     z[%2] = %7
     %9 = 34
     x = %9
     %11 = 3
     %13 = 1
     %12 = %13 * %11
     %15 = 56
     %16 = 9
     %18 = 1
     %17 = %18 * %16
     %19 = z[%17]
     %20 = %15 + %19
     z[%12] = %20
     %22 = 3
     %24 = 1
     %23 = %24 * %22
     %25 = z[%23]
     %27 = %25 <= x
     %27 = not %27
     ifFalse %27 goto endif1
     %28 = 78
     x = %28
     writef b
     writeln
  label endif1 :
     %34 = 3
     %36 = 1
     %35 = %36 * %34
     %37 = z[%35]
     writei %37
     writeln
     %39 = 1
     %40 = %39
     _result = %40
     return
endfunction

function fz
  params
    r
  endparams

     %2 = 0
     %3 = r <= %2
     %3 = not %3
     ifFalse %3 goto endwhile1
  label loop8 :
     %5 = 1
     %6 = r - %5
     r = %6
     %2 = 0
     %3 = r <= %2
     %3 = not %3
     ifFalse %3 goto endwhile1
     goto loop8
  label endwhile1 :
     return
endfunction

function main
  vars
    a 1
  endvars

     pushparam 
     %1 = 3
     pushparam %1
     %2 = 2
     %2 = float %2
     pushparam %2
     call f
     popparam 
     popparam 
     popparam %3
     ifFalse %3 goto endif1
     %5 = 3.7
     %7 = float a
     %6 = %7 +. %5
     %8 = 4
     %10 = float %8
     %9 = %6 +. %10
     writef %9
     writeln
  label endif1 :
     return
endfunction


