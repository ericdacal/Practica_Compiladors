function mul
  params
    _result
    a
    b
  endparams

   _result = a*b
   return
endfunction

function main
  vars
    x 1
    y 1
  endvars

   readi x
   readi y
   %1 = 'x'
   writec %1
   %1 = '*'
   writec %1
   %1 = 'y'
   writec %1
   %1 = '*'
   writec %1
   %1 = '2'
   writec %1
   %1 = '='
   writec %1
   pushparam 
   pushparam x
   pushparam y
   call mul
   popparam x
   popparam y
   popparam %4
   %5 = 2
   %6 = %4 * %5
   writei %6
   %7 = '.'
   writec %7
   writeln
   return
endfunction


