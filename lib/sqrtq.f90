subroutine sqrtq(f,v)
  
  real(kind=16), intent(in) :: f
  real(kind=16), intent(out) :: v
  
  v = qsqrt(f)
end
