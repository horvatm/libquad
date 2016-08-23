subroutine ceilq(f,v)
  
  real(kind=16), intent(in) :: f
  real(kind=16), intent(out) :: v
  
  !v = ceiling(f,kind=16)
  v = ceiling(f,kind=8)
  !v = qceiling(f)
end
