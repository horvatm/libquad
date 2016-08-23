subroutine moduloq(x,y,v)
  
  real(kind=16), intent(in) :: x
  real(kind=16), intent(in) :: y
  real(kind=16), intent(out) :: v
  
  v = qmodulo(x,y)
end
