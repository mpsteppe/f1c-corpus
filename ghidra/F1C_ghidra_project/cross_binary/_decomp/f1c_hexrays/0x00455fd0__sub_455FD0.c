// f1c  0x00455fd0  size=54
void __thiscall sub_455FD0(float *this)
{
  if ( *this <= 3.1415927 )
  {
    if ( -3.1415927 > *this )
      *this = *this + 6.2831855;
  }
  else
  {
    *this = 6.2831855 - *this;
  }
}
