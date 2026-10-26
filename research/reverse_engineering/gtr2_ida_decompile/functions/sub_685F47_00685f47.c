_DWORD *__thiscall sub_685F47(_DWORD *this, int a2, unsigned int a3)
{
  _DWORD *v3; // eax
  int v4; // edx
  int v5; // edx
  _DWORD *v6; // edx
  _DWORD *result; // eax

  v3 = *(_DWORD **)(this[5] + 4 * a2);
  v4 = *(_DWORD *)(this[4] + 4 * v3[1]);
  v3[18] = a3;
  v5 = *(_DWORD *)(v4 + 32);
  if ( v5 )
  {
    v6 = (_DWORD *)(v5 + 4 * (v3[4] + 4 * v3[3]));
    if ( *v6 != -1 )
    {
      v3[19] = *v6;
      *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *v6) + 80) = a2;
    }
    *v6 = a2;
  }
  result = (_DWORD *)v3[5];
  if ( result != (_DWORD *)-1 )
    return sub_685EE9(this, (int)result, a3);
  return result;
}
