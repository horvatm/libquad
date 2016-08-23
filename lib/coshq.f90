subroutine coshq(f,v)
  
  real(kind=16), intent(in) :: f
  real(kind=16), intent(out) :: v
  
  v = qcosh(f)
end
