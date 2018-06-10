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
     %3 = 0.7
     %5 = float a
     %4 = %5 +. %3
     c = %4
     %6 = 0
     d = %6
     %9 = a + d
     %12 = float %9
     %11 = %9 <=. c
     %11 = not %11
     %14 = not found
     %15 = %11 or %14
     ifFalse %15 goto endif1
     %17 = 0
     %18 = b <= %17
     %18 = not %18
     ifFalse %18 goto endwhile1
  label loop23 :
     %20 = 1
     %21 = b - %20
     b = %21
     %22 = 1
     found = %22
     %17 = 0
     %18 = b <= %17
     %18 = not %18
     ifFalse %18 goto endwhile1
     goto loop23
  label endwhile1 :
  label endif1 :
     %25 = 11
     %26 = b <= %25
     ifFalse %26 goto endif2
     %27 = 2
     %30 = float %27
     %29 = %30 *. c
     %31 = 1
     %33 = float %31
     %32 = %29 +. %33
     c = %32
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
   %2 = 2
   %4 = %2 * a
   %5 = 1
   %6 = %4 + %5
   b = %6
   pushparam b
   %8 = 3
   %10 = %8 + b
   pushparam %10
   call f1
   popparam b
   popparam %10
   return
endfunction


