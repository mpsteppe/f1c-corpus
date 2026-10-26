int __thiscall sub_486B10(int *this)
{
  int *v1; // ebx
  int v2; // esi
  int *v3; // ebp
  _BYTE *v4; // edi
  _DWORD *v5; // eax
  _DWORD *v6; // ebx
  char *v7; // eax
  _DWORD *v8; // eax
  const char ***v9; // eax
  const char ***v10; // ecx
  const char **i; // edx
  const char *v12; // eax
  bool v13; // zf
  int v14; // eax
  int v15; // esi
  int v16; // ecx
  _DWORD *v17; // eax
  int v18; // ecx
  int v19; // eax
  const char **v20; // eax
  const char *v21; // eax
  char v23[5]; // [esp+13h] [ebp-1C5h] BYREF
  char Buffer[32]; // [esp+18h] [ebp-1C0h] BYREF
  char v25[32]; // [esp+38h] [ebp-1A0h] BYREF
  char v26[128]; // [esp+58h] [ebp-180h] BYREF
  char String1[128]; // [esp+D8h] [ebp-100h] BYREF
  char Destination[128]; // [esp+158h] [ebp-80h] BYREF

  v1 = this;
  v2 = this[216];
  v3 = this + 216;
  *(_DWORD *)&v23[1] = this;
  while ( v2 )
  {
    v4 = (_BYTE *)v2;
    v2 = *(_DWORD *)(v2 + 4);
    sub_4145A0(v4);
    sub_5BE8AE(v4);
  }
  *v3 = 0;
  v3[1] = 0;
  v3[2] = 0;
  v3[3] = 0;
  sub_4CD5B0(Destination, 128);
  sub_4CD640(v25, 32);
  sprintf(Buffer, "%s\\*%s", v25, aSvm);
  sub_578960(&unk_7D7A0C);
  sub_578A30(Buffer, 0, Destination, 1);
  if ( sub_578D80(&unk_7D7A0C) )
  {
    do
    {
      v5 = operator new(8u);
      if ( v5 )
      {
        *v5 = 0;
        v5[1] = -1;
        v6 = v5;
      }
      else
      {
        v6 = 0;
      }
      sub_57B340(128);
      v7 = &v26[strlen(v26)];
      if ( v7 > v26 )
      {
        while ( *v7 != 46 )
        {
          if ( --v7 <= v26 )
            goto LABEL_12;
        }
        *v7 = 0;
      }
LABEL_12:
      sub_578600(v26);
      if ( v6 )
      {
        v8 = operator new(0xCu);
        if ( v8 )
        {
          *v8 = v6;
          v8[1] = 0;
          *((_BYTE *)v8 + 8) = 1;
        }
        else
        {
          v8 = 0;
        }
        if ( *v3 )
        {
          *(_DWORD *)(v3[1] + 4) = v8;
        }
        else
        {
          *v3 = (int)v8;
          v3[2] = (int)v8;
        }
        v3[1] = (int)v8;
        ++v3[3];
      }
      sub_5789D0(&unk_7D7A0C);
    }
    while ( sub_578D80(&unk_7D7A0C) );
    v1 = *(int **)&v23[1];
  }
  v9 = sub_436F70(*v3);
  v10 = v9;
  *v3 = (int)v9;
  if ( v9 )
  {
    for ( i = v9[1]; i; i = (const char **)i[1] )
      v10 = (const char ***)i;
  }
  v3[1] = (int)v10;
  v3[2] = (int)v9;
  v12 = (const char *)sub_4CE000(&unk_7663E0);
  strncpy((char *)v1 + 884, v12, 0x7Fu);
  *((_BYTE *)v1 + 1011) = 0;
  sub_436120((const char **)&dword_75E8F0, String1, 127, v23);
  v13 = _strcmpi(String1, asc_5FE190) == 0;
  v14 = v1[219];
  if ( v13 )
  {
    if ( v14 > 0 )
      v1[220] = 0;
  }
  else
  {
    v15 = 0;
    if ( v14 > 0 )
    {
      while ( 1 )
      {
        v16 = v15;
        if ( v15 >= 0 && v15 < v3[3] )
        {
          v17 = (_DWORD *)*v3;
          if ( v15 > 0 )
          {
            while ( v17 )
            {
              v17 = (_DWORD *)v17[1];
              if ( --v16 <= 0 )
                goto LABEL_32;
            }
            goto LABEL_44;
          }
LABEL_32:
          if ( v17 && *v17 )
            break;
        }
LABEL_44:
        if ( ++v15 >= v1[219] )
          return sub_486F30(v1);
      }
      v18 = v15;
      if ( v15 < v3[3] )
      {
        v19 = *v3;
        if ( v15 <= 0 )
        {
LABEL_38:
          if ( v19 )
          {
            v20 = *(const char ***)v19;
LABEL_41:
            v21 = *v20;
            if ( !v21 )
              v21 = &byte_629120;
            if ( !_strcmpi(v21, String1) )
            {
              v1[220] = v15;
              return sub_486F30(v1);
            }
            goto LABEL_44;
          }
        }
        else
        {
          while ( v19 )
          {
            v19 = *(_DWORD *)(v19 + 4);
            if ( --v18 <= 0 )
              goto LABEL_38;
          }
        }
      }
      v20 = 0;
      goto LABEL_41;
    }
  }
  return sub_486F30(v1);
}
