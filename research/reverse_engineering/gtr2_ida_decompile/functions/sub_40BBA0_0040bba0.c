char __thiscall sub_40BBA0(_DWORD *this, int *a2, int a3)
{
  char result; // al
  int v6; // eax
  bool v7; // zf
  int v8; // esi
  _DWORD **v9; // eax
  _DWORD *v10; // edi
  _DWORD *v11; // eax
  int v12; // eax
  _DWORD **v13; // eax
  int v14; // esi
  FILE *v15; // eax
  char v16; // [esp+Fh] [ebp-19h]
  char v17; // [esp+2Ch] [ebp+4h]

  result = 0;
  v16 = 0;
  if ( a2 )
  {
    v6 = *a2;
    v7 = *a2 == 0;
    v17 = 0;
    if ( !v7 )
      sub_615860(v6);
    v8 = a2[1];
    if ( v8 )
      sub_615A50(v8);
    v9 = (_DWORD **)this[14];
    v10 = this + 14;
    v10[2] = v9;
    if ( v9 )
    {
      v11 = *v9;
      if ( v11 )
      {
        while ( *v11 != a3 )
        {
          v12 = v10[2];
          if ( v12 )
            v10[2] = *(_DWORD *)(v12 + 4);
          v13 = (_DWORD **)v10[2];
          if ( v13 )
          {
            v11 = *v13;
            if ( v11 )
              continue;
          }
          goto LABEL_15;
        }
        v17 = 1;
      }
    }
LABEL_15:
    if ( !_stricmp(WindowName, WindowName) || v17 )
      return v16;
    v14 = operator new(0x60u) ? sub_40A860() : 0;
    if ( !v14 )
      return v16;
    v15 = fopen(WindowName, "rb");
    *(_DWORD *)(v14 + 12) = v15;
    if ( v15 )
    {
      if ( !sub_40B350() )
      {
        *(_DWORD *)(v14 + 16) = _fileno(*(FILE **)(v14 + 12));
        *(_DWORD *)v14 = a3;
        sub_615860(WindowName);
        sub_5FDFB0(v14, 1);
        return 1;
      }
      fclose(*(FILE **)(v14 + 12));
      *(_DWORD *)(v14 + 12) = 0;
    }
    sub_40A8E0();
    if ( *(_DWORD *)(v14 + 4) )
      j_j__free(*(void **)(v14 + 4));
    j__free((void *)v14);
    return v16;
  }
  return result;
}
