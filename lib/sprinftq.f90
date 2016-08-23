subroutine sprintfq(s, l, f, a)
  
  use iso_c_binding
    
  implicit none
     
  character(kind=c_char, len=*), intent(out) :: s
 
  character(kind=c_char, len=*), intent(in) :: f

  integer, intent(in) :: l
   
  real(kind=16), intent(in) :: a
  
  integer i

  character(len=512) :: buf
    
  i = 1
  do while (f(i:i).ne.char(0)) 
    i=i+1
  end do
  
  write (buf, fmt=f(1:i-1)) a
  
  buf = adjustl(buf)
  
  i = len_trim(buf)
    
  if (i .lt. l) then
    s(1:i+1) = buf(1:i)//char(0)
  else
    s(1:6) = "Error"//char(0)
  endif
end 
