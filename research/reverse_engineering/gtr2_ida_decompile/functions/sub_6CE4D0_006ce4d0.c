_DWORD *__thiscall sub_6CE4D0(_DWORD *this)
{
  _DWORD *result; // eax
  int v2; // edx
  int v3; // edx
  unsigned int v4; // esi
  int v5; // ecx

  result = (_DWORD *)this[108];
  v2 = 1;
  if ( (int)this[83] <= 1 )
  {
    v3 = this[81];
    v4 = this[38];
    v5 = this[84];
    if ( v4 < v3 - 1 )
    {
      result[7] = *(_DWORD *)(v5 + 12);
      result[5] = 0;
      result[6] = 0;
      return result;
    }
    v2 = *(_DWORD *)(v5 + 72);
  }
  result[7] = v2;
  result[5] = 0;
  result[6] = 0;
  return result;
}
