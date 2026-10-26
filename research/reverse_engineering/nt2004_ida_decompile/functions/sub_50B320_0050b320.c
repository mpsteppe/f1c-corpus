int __thiscall sub_50B320(_DWORD *this, int a2)
{
  _DWORD *v3; // esi
  int v4; // edi
  int v5; // ecx
  int v6; // edi
  int v7; // ecx
  int result; // eax

  v3 = (_DWORD *)this[38];
  if ( v3 )
  {
    sub_4667A0(v3 + 18);
    v4 = v3[14];
    while ( v4 )
    {
      v5 = v4;
      v4 = *(_DWORD *)(v4 + 4);
      sub_466750(v5, 1);
    }
    v3[14] = 0;
    v3[15] = 0;
    v3[16] = 0;
    v3[17] = 0;
    v6 = v3[10];
    while ( v6 )
    {
      v7 = v6;
      v6 = *(_DWORD *)(v6 + 4);
      sub_466750(v7, 1);
    }
    v3[10] = 0;
    v3[11] = 0;
    v3[12] = 0;
    v3[13] = 0;
    if ( v3[8] )
      sub_5BE8AE();
    if ( v3[6] )
      sub_5BE8AE();
    if ( v3[4] )
      sub_5BE8AE();
    if ( v3[2] )
      sub_5BE8AE();
    if ( *v3 )
      sub_5BE8AE();
    sub_5BE8AE();
    result = a2;
    this[38] = a2;
  }
  else
  {
    this[38] = a2;
  }
  return result;
}
