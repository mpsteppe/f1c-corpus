// f1c  0x00455f90  size=54
void __thiscall sub_455F90(float *this)
{
  if ( *this <= 3.1415927 )
  {
    if ( -3.1415927 > *this )
      *this = *this + 6.2831855;
  }
  else
  {
    *this = *this - 6.2831855;
  }
}
