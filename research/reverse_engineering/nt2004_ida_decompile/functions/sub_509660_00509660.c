_DWORD *__thiscall sub_509660(_DWORD *this, int a2)
{
  int v3; // esi
  int v4; // ecx
  int v5; // esi
  int v6; // ecx
  int v7; // esi
  LPVOID **v8; // ecx
  CHAR *v9; // eax
  CHAR *v10; // eax
  CHAR *v11; // eax
  CHAR *v12; // eax
  CHAR *v13; // eax
  _DWORD **v14; // eax
  _DWORD *v15; // ebx
  _DWORD *v16; // edi
  _DWORD *v17; // eax
  _DWORD *v18; // eax
  int v19; // eax
  _DWORD **v20; // eax
  _DWORD **v21; // eax
  _DWORD *v22; // edi
  _DWORD *v23; // eax
  int v24; // eax
  _DWORD **v25; // eax
  CHAR ***v26; // eax
  CHAR **i; // esi
  _DWORD *v28; // eax
  CHAR *v29; // esi
  _DWORD *v30; // eax

  v3 = this[10];
  while ( v3 )
  {
    v4 = v3;
    v3 = *(_DWORD *)(v3 + 4);
    sub_466750(v4, 1);
  }
  this[10] = 0;
  this[11] = 0;
  this[12] = 0;
  this[13] = 0;
  v5 = this[14];
  while ( v5 )
  {
    v6 = v5;
    v5 = *(_DWORD *)(v5 + 4);
    sub_466750(v6, 1);
  }
  this[14] = 0;
  this[15] = 0;
  this[16] = 0;
  this[17] = 0;
  v7 = this[18];
  while ( v7 )
  {
    v8 = (LPVOID **)v7;
    v7 = *(_DWORD *)(v7 + 4);
    sub_414480(v8, 1);
  }
  this[18] = 0;
  this[19] = 0;
  this[20] = 0;
  this[21] = 0;
  v9 = *(CHAR **)a2;
  if ( !*(_DWORD *)a2 )
    v9 = &byte_629120;
  sub_578600(v9);
  v10 = *(CHAR **)(a2 + 8);
  if ( !v10 )
    v10 = &byte_629120;
  sub_578600(v10);
  v11 = *(CHAR **)(a2 + 16);
  if ( !v11 )
    v11 = &byte_629120;
  sub_578600(v11);
  v12 = *(CHAR **)(a2 + 24);
  if ( !v12 )
    v12 = &byte_629120;
  sub_578600(v12);
  v13 = *(CHAR **)(a2 + 32);
  if ( !v13 )
    v13 = &byte_629120;
  sub_578600(v13);
  v14 = *(_DWORD ***)(a2 + 40);
  *(_DWORD *)(a2 + 48) = v14;
  if ( v14 )
  {
    v15 = *v14;
    if ( *v14 )
    {
      do
      {
        v16 = operator new(4u);
        if ( v16 )
        {
          *v16 = *v15;
          v17 = operator new(0xCu);
          if ( v17 )
            v18 = sub_4DB610(v17, (int)v16, 1);
          else
            v18 = 0;
          if ( this[10] )
          {
            *(_DWORD *)(this[11] + 4) = v18;
          }
          else
          {
            this[10] = v18;
            this[12] = v18;
          }
          this[11] = v18;
          ++this[13];
        }
        v19 = *(_DWORD *)(a2 + 48);
        if ( !v19 )
          break;
        v20 = *(_DWORD ***)(v19 + 4);
        *(_DWORD *)(a2 + 48) = v20;
        if ( !v20 )
          break;
        v15 = *v20;
      }
      while ( *v20 );
    }
  }
  v21 = *(_DWORD ***)(a2 + 56);
  *(_DWORD *)(a2 + 64) = v21;
  if ( v21 )
  {
    v22 = *v21;
    if ( *v21 )
    {
      do
      {
        v23 = operator new(4u);
        if ( v23 )
          *v23 = *v22;
        else
          v23 = 0;
        sub_414410(this + 14, (int)v23, 1);
        v24 = *(_DWORD *)(a2 + 64);
        if ( !v24 )
          break;
        v25 = *(_DWORD ***)(v24 + 4);
        *(_DWORD *)(a2 + 64) = v25;
        if ( !v25 )
          break;
        v22 = *v25;
      }
      while ( *v25 );
    }
  }
  v26 = *(CHAR ****)(a2 + 72);
  *(_DWORD *)(a2 + 80) = v26;
  if ( v26 )
  {
    for ( i = *v26; i; i = (CHAR **)sub_50EE10(a2 + 72) )
    {
      v28 = operator new(8u);
      if ( v28 )
      {
        v29 = *i;
        if ( !v29 )
          v29 = &byte_629120;
        v30 = sub_410DE0(v28, (int)v29);
      }
      else
      {
        v30 = 0;
      }
      sub_414410(this + 18, (int)v30, 1);
    }
  }
  return this;
}
