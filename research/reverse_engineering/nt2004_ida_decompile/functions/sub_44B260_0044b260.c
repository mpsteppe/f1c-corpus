_DWORD *__thiscall sub_44B260(_DWORD *this)
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
