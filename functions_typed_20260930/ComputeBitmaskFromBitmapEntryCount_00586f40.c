_DWORD *__thiscall sub_586F40(_DWORD *this, int a2, _DWORD *a3)
{
  unsigned int v3; // eax
  int v4; // edx
  unsigned int v5; // ecx
  _DWORD *result; // eax

  v3 = *(unsigned __int16 *)(this[2] + 4 * a2 + 2);
  v4 = 0;
  v5 = 0;
  if ( (_WORD)v3 )
  {
    do
      v4 |= 1 << v5++;
    while ( v5 < v3 );
  }
  result = a3;
  *a3 &= v4;
  return result;
}

