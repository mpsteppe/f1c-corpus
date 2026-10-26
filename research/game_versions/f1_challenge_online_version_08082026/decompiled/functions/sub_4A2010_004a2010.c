int __thiscall sub_4A2010(__int16 *this, const char *a2, int a3, int a4, char a5)
{
  _DWORD *v7; // edi
  int v8; // esi
  int v9; // eax
  int j; // esi
  int v11; // esi
  int k; // edi
  char i; // [esp+Fh] [ebp-105h]
  _BYTE v14[256]; // [esp+14h] [ebp-100h] BYREF

  if ( !a3 )
    return -1;
  if ( dword_7CF884 < *this )
    return 0;
  v7 = this + 50;
  if ( !sub_5450E0(this + 50, a2, a3, 16) )
  {
    v8 = *(_DWORD *)(a3 + 68);
    for ( i = 0; v8; v8 = *(_DWORD *)(v8 + 68) )
    {
      sub_54A870(v8);
      if ( !*(_BYTE *)(v8 + 64) )
        i = 1;
    }
    if ( a4 )
      sub_54BA00(*v7, 0);
    else
      sub_545250(*v7);
    v9 = sub_54C210(*v7);
    *((_DWORD *)this + 26) = v9;
    *((_DWORD *)this + 27) = sub_587C03(4 * v9);
    for ( j = 0; j < *((_DWORD *)this + 26); ++j )
      *(_DWORD *)(*((_DWORD *)this + 27) + 4 * j) = sub_54C230(j);
    if ( a5 || dword_7CF884 >= 2 )
    {
      v11 = sub_54C230(0);
      for ( k = a3; v11; k = *(_DWORD *)(k + 68) )
      {
        if ( !k )
          break;
        if ( *(_BYTE *)(k + 64) )
        {
          sub_545930(v11, a4);
          if ( i )
            *(_DWORD *)(v11 + 20) |= 0x2000000u;
        }
        v11 = *(_DWORD *)(v11 + 16);
      }
    }
    strcpy((char *)this + 4, a2);
    return 0;
  }
  sub_53C5B0(0, v14);
  if ( (unsigned __int8)sub_4D7A50(1, aDDevF119992002_2, 180) )
    sub_4D7AA0(&unk_8AD25C, aCubeErrorLoadi);
  return -1;
}
