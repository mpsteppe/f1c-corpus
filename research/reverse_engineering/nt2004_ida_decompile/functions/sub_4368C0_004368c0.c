int __thiscall sub_4368C0(_DWORD *this, int a2, char *String1)
{
  char *v3; // eax
  _DWORD *v4; // edi
  int v5; // ebx
  char *v6; // ecx
  char *v7; // eax
  int v8; // ebp
  int *v9; // eax
  int v10; // esi
  const char *v11; // eax
  CHAR *v12; // eax
  const char *v13; // eax
  int v14; // eax
  int *v15; // eax
  _DWORD *v16; // esi
  CHAR *v17; // ebp
  CHAR *v18; // eax
  _DWORD *v19; // eax
  int v22; // [esp+14h] [ebp-4h]
  char *String1a; // [esp+20h] [ebp+8h]

  v3 = String1;
  v4 = this;
  v5 = 1;
  if ( !String1 )
  {
    v6 = dword_766594;
    if ( !dword_766594 )
      v6 = &byte_629120;
    v3 = sub_435430(v6);
  }
  String1a = v3;
  v22 = sub_435C00(dword_75CBB0);
  v7 = dword_7665D8;
  if ( !dword_7665D8 )
    v7 = &byte_629120;
  v8 = sub_4E7790(v7);
  v9 = (int *)v4[7];
  v4[9] = v9;
  if ( v9 && (v10 = *v9) != 0 )
  {
    while ( 1 )
    {
      v11 = *(const char **)v10;
      if ( !*(_DWORD *)v10 )
        v11 = &byte_629120;
      if ( !_strcmpi(String1a, v11) )
      {
        v12 = *(CHAR **)(v10 + 8);
        if ( !v12 )
          v12 = &byte_629120;
        if ( !*v12 || !v8 )
          break;
        v13 = *(const char **)(v10 + 8);
        if ( !v13 )
          v13 = &byte_629120;
        if ( !_strcmpi((const char *)(v8 + 630), v13) )
          break;
      }
      v14 = v4[9];
      if ( v14 )
        v4[9] = *(_DWORD *)(v14 + 4);
      v15 = (int *)v4[9];
      if ( v15 )
      {
        v10 = *v15;
        if ( *v15 )
          continue;
      }
      goto LABEL_23;
    }
    sub_578600(a2);
    v18 = &byte_629120;
    if ( v8 )
      v18 = (CHAR *)(v8 + 630);
    sub_578600(v18);
    v5 = 0;
  }
  else
  {
LABEL_23:
    v16 = operator new(0x1Cu);
    if ( v16 )
    {
      *v16 = 0;
      v16[1] = -1;
      v16[2] = 0;
      v16[3] = -1;
      v16[5] = 0;
      v16[6] = -1;
      sub_435A40(v16);
      if ( v8 )
        v17 = (CHAR *)(v8 + 630);
      else
        v17 = &byte_629120;
      sub_578600(String1a);
      sub_578600(v17);
      v16[4] = v22;
      sub_578600(a2);
      v19 = operator new(0xCu);
      v5 = 0;
      if ( v19 )
      {
        *v19 = v16;
        v19[1] = 0;
        *((_BYTE *)v19 + 8) = 1;
      }
      else
      {
        v19 = 0;
      }
      if ( this[7] )
      {
        *(_DWORD *)(this[8] + 4) = v19;
      }
      else
      {
        this[7] = v19;
        this[9] = v19;
      }
      v4 = this;
      this[8] = v19;
      ++this[10];
    }
  }
  sub_578600(a2);
  sub_435E80(v4, (int)&unk_7663E0);
  return v5;
}
