subroutine atan2q(y,x,v)
  
  real(kind=16), intent(in) :: y
  real(kind=16), intent(in) :: x
  real(kind=16), intent(out) :: v
  
  v = qatan2(y,x)
end
