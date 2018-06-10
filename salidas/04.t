function f1
  params
    a
    b
  endparams

  vars
    c 1
    d 1
    found 1
  endvars

     %1 = 0
     found = %1
     %4 = 0.7
     %6 = float a
     %5 = %6 +. %4
     c = %5
     %8 = 0
     d = %8
     %12 = a + d
     %15 = float %12
     %14 = %12 <=. c
     %14 = not %14
     %17 = not found
     %18 = %14 or %17
     ifFalse %18 goto endif1
     %20 = 0
     %21 = b <= %20
     %21 = not %21
     ifFalse %21 goto endwhile1
  label loop28 :
     %23 = 1
     %24 = b - %23
     b = %24
     %26 = 1
     found = %26
     %20 = 0
     %21 = b <= %20
     %21 = not %21
     ifFalse %21 goto endwhile1
     goto loop28
  label endwhile1 :
  label endif1 :
     %30 = 11
     %31 = b <= %30
     ifFalse %31 goto endif2
     %32 = 2
     %35 = float %32
     %34 = %35 *. c
     %36 = 1
     %38 = float %36
     %37 = %34 +. %38
     c = %37
  label endif2 :
     writef c
     writeln
     return
endfunction

function main
  vars
    a 1
    b 1
  endvars

   %1 = 4
   a = %1
   %3 = 2
   %5 = %3 * a
   %6 = 1
   %7 = %5 + %6
   b = %7
   pushparam b
   %10 = 3
   %12 = %10 + b
   pushparam %12
   call f1
   popparam 
   popparam 
   return
endfunction


