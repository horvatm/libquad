subroutine powq(f,p,v)
  
  real(kind=16), intent(in) :: f
  real(kind=16), intent(in) :: p
  real(kind=16), intent(out) :: v
  
  v = f**p
end
