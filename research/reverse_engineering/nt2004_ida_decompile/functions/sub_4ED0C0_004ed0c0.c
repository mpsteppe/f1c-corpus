char __thiscall sub_4ED0C0(_DWORD *this, int a2, int a3)
{
  int v4; // ecx
  int *v5; // eax
  int v6; // esi
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  int *v10; // eax
  _DWORD *v11; // eax
  _DWORD *v12; // esi
  __int16 v13; // ax
  _DWORD *v14; // edi
  CHAR *v15; // ebx
  _DWORD *v16; // edi
  _DWORD *v17; // eax
  CHAR **v19; // edi
  int v20; // eax
  _DWORD *v21; // esi
  CHAR *v22; // edi

  v4 = this[24];
  if ( !v4 )
    return 0;
  v5 = *(int **)(v4 + 68);
  *(_DWORD *)(v4 + 76) = v5;
  if ( v5 && (v6 = *v5) != 0 )
  {
    while ( *(__int16 *)(v6 + 36) != a3 || *(_DWORD *)(v6 + 8) != 3 )
    {
      v7 = this[24];
      v8 = *(_DWORD *)(v7 + 76);
      v9 = v7 + 68;
      if ( v8 )
        *(_DWORD *)(v9 + 8) = *(_DWORD *)(v8 + 4);
      v10 = *(int **)(v9 + 8);
      if ( v10 )
      {
        v6 = *v10;
        if ( *v10 )
          continue;
      }
      goto LABEL_10;
    }
    v19 = (CHAR **)(v6 + 12);
    sub_578600(a2);
    v20 = *(_DWORD *)(v6 + 40);
    v21 = (_DWORD *)(v6 + 40);
    if ( v20 )
    {
      sub_592310(v20);
      *v21 = 0;
    }
    v22 = *v19;
    if ( !v22 )
      v22 = &byte_629120;
    if ( sub_5922A0(v21, v22, 8, 1) )
      *v21 = 0;
    return 1;
  }
  else
  {
LABEL_10:
    v11 = operator new(0x2Cu);
    if ( v11 )
    {
      *v11 = 0;
      v11[1] = -1;
      v11[2] = 0;
      v11[3] = 0;
      v11[4] = -1;
      v11[5] = -1;
      *((_WORD *)v11 + 12) = 0;
      v11[7] = 0;
      v11[8] = -1;
      *((_WORD *)v11 + 18) = -1;
      v11[10] = 0;
      v12 = v11;
    }
    else
    {
      v12 = 0;
    }
    sub_578600(a2);
    v12[2] = 3;
    v13 = sub_4EB570(this);
    *((_WORD *)v12 + 18) = a3;
    v14 = v12 + 10;
    *((_WORD *)v12 + 12) = v13 + 1;
    if ( v12[10] )
    {
      sub_592310(v12[10]);
      *v14 = 0;
    }
    v15 = (CHAR *)v12[3];
    if ( !v15 )
      v15 = &byte_629120;
    if ( sub_5922A0(v12 + 10, v15, 8, 1) )
      *v14 = 0;
    v16 = (_DWORD *)(this[24] + 68);
    v17 = operator new(0xCu);
    if ( v17 )
    {
      *v17 = v12;
      v17[1] = 0;
      *((_BYTE *)v17 + 8) = 1;
    }
    else
    {
      v17 = 0;
    }
    if ( *v16 )
    {
      *(_DWORD *)(v16[1] + 4) = v17;
    }
    else
    {
      *v16 = v17;
      v16[2] = v17;
    }
    v16[1] = v17;
    ++v16[3];
    return 1;
  }
}
