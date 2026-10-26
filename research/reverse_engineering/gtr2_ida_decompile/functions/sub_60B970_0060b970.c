int __thiscall sub_60B970(char *this, int a2, int a3, int a4)
{
  int result; // eax

  result = *((_DWORD *)this + 7);
  if ( result )
  {
    if ( *this >= 0 )
      return off_16C9750(a2, a3, a4);
  }
  return result;
}
