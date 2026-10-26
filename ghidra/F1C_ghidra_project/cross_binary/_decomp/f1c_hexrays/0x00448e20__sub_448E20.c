// f1c  0x00448e20  size=36
_DWORD *__thiscall sub_448E20(_DWORD *this)
{
  _DWORD *result; // eax
  unsigned int v2; // ecx

  result = this;
  v2 = this[6];
  if ( v2 >= 0xB )
    v2 = 11;
  if ( v2 )
  {
    result += 7;
    do
    {
      *result = *(_DWORD *)(*result + 28);
      ++result;
      --v2;
    }
    while ( v2 );
  }
  return result;
}
