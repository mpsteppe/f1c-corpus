int __thiscall sub_59FFB0(_DWORD *this, int a2, int a3, int a4, int a5, int a6)
{
  int result; // eax

  result = sub_5A00B0(&a2, &a3, &a4, &a5);
  if ( a4 > 0 )
  {
    result = a5;
    if ( a5 > 0 )
    {
      result = sub_5A7610(this, a2, a3, a4, a5, a6);
      this[14] &= ~0x400u;
    }
  }
  return result;
}
