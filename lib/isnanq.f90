function isnanq(f)
  
  real(kind=16), intent(in) :: f
  integer :: isnanq
  
  if (isnan(f)) then
    isnanq=1
  else  
    isnanq=0
  endif
end
