subroutine atanq(x,v)
  
  real(kind=16), intent(in) :: x
  real(kind=16), intent(out) :: v
  
  v = qatan(x)
end
