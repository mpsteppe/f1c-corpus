int __thiscall sub_4DE8F0(void *this, float a2)
{
  int result; // eax

  result = *(_DWORD *)this;
  if ( *(_DWORD *)(*(_DWORD *)this + 16584) != 1 )
  {
    result = dword_767310;
    if ( dword_767310 )
      return sub_4DF490(a2, 0);
  }
  return result;
}
