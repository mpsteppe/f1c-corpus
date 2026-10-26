int __thiscall sub_680D41(_DWORD *this, int a2, _DWORD *a3)
{
  int result; // eax

  result = *this & 0xFFFFF;
  if ( (unsigned int)(a2 * result + result) <= this[1] )
  {
    if ( a3 )
      *a3 = this[2] + 4 * a2 * result;
  }
  else
  {
    if ( a3 )
      *a3 = 0;
    return 0;
  }
  return result;
}
