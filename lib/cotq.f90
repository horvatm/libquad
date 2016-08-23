subroutine cotq(f,v)
  
  real(kind=16), intent(in) :: f
  real(kind=16), intent(out) :: v
  
  v = qcotan(f)
end
