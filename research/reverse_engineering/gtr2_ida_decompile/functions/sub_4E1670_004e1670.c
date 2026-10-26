int __thiscall sub_4E1670(_DWORD *this, int a2, char a3, char a4)
{
  int v5; // ebp
  int v6; // eax
  int v7; // ecx
  _DWORD *v8; // eax
  int i; // edi
  _DWORD **v10; // eax
  int v11; // ebx
  _DWORD *v12; // edi
  int v13; // ebp
  int v14; // eax
  _DWORD **v15; // eax
  int v17; // eax
  _DWORD *v18; // ecx
  int v19; // ecx

  v5 = this[6];
  if ( v5 )
  {
    if ( a3 )
    {
      v6 = this[147];
      if ( v6 == 8 )
      {
        v7 = 1;
        v8 = this + 139;
        do
        {
          *v8 = v8[1];
          ++v7;
          ++v8;
        }
        while ( v7 < this[147] );
      }
      else
      {
        this[147] = v6 + 1;
      }
      this[this[147] + 138] = *(_DWORD *)(v5 + 68);
    }
    for ( i = *(_DWORD *)(v5 + 64); i; i = sub_4CD340() )
      (*(void (__thiscall **)(int))(*(_DWORD *)i + 96))(i);
    sub_4E0D70(*(_DWORD **)(v5 + 68));
  }
  v10 = (_DWORD **)this[1];
  v11 = 0;
  this[3] = v10;
  if ( v10 )
  {
    v12 = *v10;
    if ( *v10 )
    {
      while ( 1 )
      {
        v13 = v12[15];
        if ( v13 )
          break;
LABEL_17:
        v14 = this[3];
        if ( v14 )
          this[3] = *(_DWORD *)(v14 + 4);
        v15 = (_DWORD **)this[3];
        if ( v15 )
        {
          v12 = *v15;
          if ( *v15 )
            continue;
        }
        goto LABEL_34;
      }
      while ( v13 != a2 )
      {
        v13 = *(_DWORD *)(v13 + 56);
        if ( !v13 )
          goto LABEL_17;
      }
      if ( v12[13] == 1 )
        a4 = 0;
      if ( *((float *)this + 16) > 0.0 )
      {
        a4 = 0;
        this[16] = -1082130432;
      }
      sub_4DE040(this, (int)v12);
      v12[22] = 0;
      v12[23] = 0;
      v17 = this[5];
      if ( v17 )
      {
        for ( ; *(_DWORD *)(v17 + 88); v17 = *(_DWORD *)(v17 + 88) )
          ;
        this[6] = v12;
        *(_DWORD *)(v17 + 88) = v12;
        v12[23] = v17;
      }
      else
      {
        this[5] = v12;
        this[6] = v12;
      }
      v12[17] = v13;
      if ( a4 )
      {
        sub_520350(&unk_BE1198, 2, 0, 1036831949, 1);
        sub_520350(&unk_BE1198, 0, 2, 1048576000, 0);
      }
      v11 = 1;
    }
  }
LABEL_34:
  v18 = (_DWORD *)this[6];
  if ( v18 )
  {
    if ( !sub_4DF600(v18, this[8]) )
      this[8] = 0;
    *(_BYTE *)(v19 + 56) = 1;
  }
  return v11;
}
