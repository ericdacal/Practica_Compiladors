function prod_escalar
  params
    _result
    a1
    a2
  endparams

  vars
    i 1
    s 1
  endvars

     %1 = 0
     s = %1
     %4 = 10
     %5 = i < %4
     ifFalse %5 goto endwhile1
  label loop24 :
     %9 = 1
     %8 = %9 * i
     %11 = a1
     %10 = %11[%8]
     %14 = 1
     %13 = %14 * i
     %16 = a2
     %15 = %16[%13]
     %17 = %10 * %15
     %18 = s + %17
     s = %18
     %21 = 1
     %22 = i + %21
     i = %22
     %4 = 10
     %5 = i < %4
     ifFalse %5 goto endwhile1
     goto loop24
  label endwhile1 :
     %26 = s
     _result = %26
     return
endfunction

function main
  vars
    i 1
    v1 10
    v2 10
  endvars

     %1 = 0
     i = %1
     %4 = 10
     %5 = i < %4
     ifFalse %5 goto endwhile1
  label loop25 :
     %8 = 1
     %7 = %8 * i
     %11 = - i
     v1[%7] = %11
     %15 = 1
     %14 = %15 * i
     %19 = i * i
     v2[%14] = %19
     %22 = 1
     %23 = i + %22
     i = %23
     %4 = 10
     %5 = i < %4
     ifFalse %5 goto endwhile1
     goto loop25
  label endwhile1 :
     pushparam 
     %29 = &v1
     pushparam %29
     %30 = &v2
     pushparam %30
     call prod_escalar
     popparam 
     popparam 
     popparam %28
     writei %28
     writeln
     return
endfunction


