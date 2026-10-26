_DWORD *__thiscall sub_65662C(_DWORD *this, int a2, int a3, int a4)
{
  _DWORD *result; // eax
  unsigned int v6; // edx
  _DWORD *v7; // ecx

  if ( this[4] )
    a4 = sub_650093(this, a4);
  result = (_DWORD *)(this[8] + a3 * this[25] + a2 * this[24]);
  v6 = 0;
  if ( this[26] )
  {
    v7 = (_DWORD *)a4;
    do
    {
      *result = *v7;
      result[1] = v7[1];
      result += 2;
      ++v6;
      v7 += 4;
    }
    while ( v6 < this[26] );
  }
  return result;
}
