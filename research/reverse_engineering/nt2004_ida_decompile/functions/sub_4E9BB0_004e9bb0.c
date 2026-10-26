char __thiscall sub_4E9BB0(_DWORD *this)
{
  int v2; // eax
  int *v3; // eax
  int i; // eax
  _DWORD *v5; // edi
  CHAR *v6; // eax
  int v7; // eax
  int *v8; // eax
  int *v9; // eax
  int j; // eax
  _DWORD *v11; // edi
  CHAR *v12; // eax
  int v13; // eax
  int *v14; // eax
  _DWORD *v15; // edi
  CHAR *v16; // eax
  int v17; // eax

  v2 = sub_4ED8C0(&dword_7D6B74);
  sub_4EC010(v2);
  v3 = (int *)this[13];
  this[15] = v3;
  if ( v3 )
  {
    for ( i = *v3; i; i = *v8 )
    {
      v5 = (_DWORD *)(i + 40);
      if ( !*(_DWORD *)(i + 40) )
      {
        v6 = *(CHAR **)(i + 12);
        if ( !v6 )
          v6 = &byte_629120;
        if ( sub_5922A0(v5, v6, 8, 1) )
          *v5 = 0;
      }
      v7 = this[15];
      if ( !v7 )
        break;
      v8 = *(int **)(v7 + 4);
      this[15] = v8;
      if ( !v8 )
        break;
    }
  }
  v9 = (int *)this[17];
  this[19] = v9;
  if ( v9 )
  {
    for ( j = *v9; j; j = *v14 )
    {
      v11 = (_DWORD *)(j + 40);
      if ( !*(_DWORD *)(j + 40) )
      {
        v12 = *(CHAR **)(j + 12);
        if ( !v12 )
          v12 = &byte_629120;
        if ( sub_5922A0(v11, v12, 8, 1) )
          *v11 = 0;
      }
      v13 = this[19];
      if ( !v13 )
        break;
      v14 = *(int **)(v13 + 4);
      this[19] = v14;
      if ( !v14 )
        break;
    }
  }
  v15 = this + 35;
  if ( this[35] )
  {
    sub_592310(this[35]);
    *v15 = 0;
  }
  v16 = (CHAR *)this[28];
  if ( !v16 )
    v16 = &byte_629120;
  if ( sub_5922A0(this + 35, v16, 8, 1) )
    *v15 = 0;
  v17 = sub_4ED8C0(&dword_7D6B74);
  sub_4EC230(v17);
  return 1;
}
