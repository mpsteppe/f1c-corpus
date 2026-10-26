BOOL __thiscall sub_4AF230(_DWORD *this, int a2, int a3)
{
  _DWORD *v3; // eax
  int v4; // ecx
  int v5; // edx
  int v6; // esi
  BOOL result; // eax

  result = 0;
  if ( a2 >= this[3] && a2 <= this[4] && a3 >= this[1] && a3 <= this[2] )
  {
    v3 = (_DWORD *)this[17];
    if ( v3 )
    {
      v4 = v3[15];
      if ( v4 )
      {
        v5 = a2 - v3[3];
        v6 = a3 - v3[1];
        if ( v5 < *(_DWORD *)(v4 + 20) && v5 >= 0 && v6 < *(_DWORD *)(v4 + 24) && v6 >= 0 )
          return 1;
      }
    }
  }
  return result;
}
