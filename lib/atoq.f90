subroutine atoq(s, v)
  
  use iso_c_binding
  
  implicit none
     
  character(kind=c_char, len=*), intent(in) :: s
  
  integer :: i
  
  real(kind=16), intent(out) :: v
  
  i = 1
  do while (s(i:i).ne.char(0)) 
    i=i+1
  end do
  
  read (s(1:i-1), *) v
end 
