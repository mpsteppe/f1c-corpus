int __thiscall sub_46AE60(_DWORD *this)
{
  int result; // eax
  int i; // esi
  _DWORD *v4; // ebx
  char v5; // al
  LPVOID *v6; // ebp
  int v7; // esi
  char *v8; // eax
  char v9[80]; // [esp+8h] [ebp-50h] BYREF

  result = sub_489CB0(this);
  for ( i = this[17]; i; result = sub_587BCF(v4) )
  {
    v4 = (_DWORD *)i;
    v5 = *(_BYTE *)(i + 8);
    i = *(_DWORD *)(i + 4);
    if ( v5 )
    {
      v6 = (LPVOID *)*v4;
      if ( *v4 )
      {
        if ( *v6 )
          sub_587BCF(*v6);
        sub_587BCF(v6);
      }
    }
  }
  v7 = 0;
  this[17] = 0;
  this[18] = 0;
  this[19] = 0;
  for ( this[20] = 0; v7 < dword_7D1424; ++v7 )
  {
    v8 = sub_455560(&ppvOut, v7);
    sub_486F30(v8, -1);
    sub_46AD50(v7, v9, 1);
    result = dword_7D1424;
  }
  return result;
}
