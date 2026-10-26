BOOL __thiscall sub_4DF650(_DWORD *this, int a2, int a3)
{
  _DWORD *v3; // eax
  int v4; // ecx
  int v5; // edi
  int v6; // eax
  int v7; // esi
  BOOL result; // eax

  if ( a2 < this[3] || a2 > this[4] || a3 < this[1] || a3 > this[2] )
    return 0;
  v3 = (_DWORD *)this[17];
  result = 0;
  if ( v3 )
  {
    if ( v3[15] )
    {
      v4 = v3[3];
      v5 = v3[1];
      v6 = v3[15];
      v7 = a3 - v5;
      if ( a2 - v4 < *(_DWORD *)(v6 + 20) && a2 - v4 >= 0 && v7 < *(_DWORD *)(v6 + 24) && v7 >= 0 )
        return 1;
    }
  }
  return result;
}
