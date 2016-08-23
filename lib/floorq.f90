subroutine floorq(f,v)
  
  real(kind=16), intent(in) :: f
  real(kind=16), intent(out) :: v
  
  !v = floor(f,kind=16)
  v = floor(f,kind=8)
  !v = qfloor(f)
end
