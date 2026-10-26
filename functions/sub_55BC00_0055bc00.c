int __thiscall sub_55BC00(int *this, int a2, int a3, int a4, int a5)
{
  _DWORD *v6; // esi
  _DWORD *v7; // eax
  _DWORD *v8; // ecx
  _DWORD *v9; // eax
  _DWORD *v10; // ecx
  _DWORD *i; // eax
  _DWORD *v13; // eax
  _DWORD *v14; // eax
  int v15; // eax
  int v16; // ecx

  v6 = (_DWORD *)this[72];
  v7 = v6;
  if ( v6 && (v8 = (_DWORD *)v6[8]) != 0 )
  {
    while ( v7[2] != a2 || v7[3] != a3 || v7[5] != a4 || v7[6] != a5 )
    {
      v7 = v8;
      v8 = (_DWORD *)v8[8];
      if ( !v8 )
        goto LABEL_8;
    }
    return -3;
  }
  else
  {
LABEL_8:
    if ( v6 )
    {
      for ( i = (_DWORD *)v6[8]; i; i = (_DWORD *)i[8] )
        v6 = i;
      v13 = (_DWORD *)OperatorNewNhMallocWrapper(36);
      if ( v13 )
        v14 = SmallStructInit_baf0(v13);
      else
        v14 = 0;
      v6[8] = v14;
      v14[7] = v6;
      v10 = (_DWORD *)v6[8];
    }
    else
    {
      v9 = (_DWORD *)OperatorNewNhMallocWrapper(36);
      if ( v9 )
      {
        v10 = SmallStructInit_baf0(v9);
        this[72] = (int)v10;
        v10[7] = 0;
      }
      else
      {
        v10 = 0;
        this[72] = 0;
        MEMORY[0x1C] = 0;
      }
    }
    switch ( a4 )
    {
      case 6:
        v15 = 16;
        break;
      case 5:
        v15 = 16;
        break;
      case 7:
        v15 = 24;
        break;
      default:
        v15 = 32;
        if ( a4 != 8 )
          v15 = a5;
        break;
    }
    F_6FieldStructSetter(v10, this[71], a2, a3, v15, a4, a5);
    *(_DWORD *)(v16 + 32) = 0;
    ++this[71];
    return 0;
  }
}
