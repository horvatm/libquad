function isinfq(f)
  use, intrinsic :: ieee_arithmetic
  
  real(kind=16), intent(in) :: f
  
  integer(kind=4) :: i
  
  integer :: isinfq
  
  i = fp_class(f)
  
  if ( (i == FOR_K_FP_POS_INF) .or. (i == FOR_K_FP_NEG_INF) ) then
    isinfq = 1
  else
    isinfq = 0
  endif
end
