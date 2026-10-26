int __thiscall sub_4B6110(_DWORD *this)
{
  _DWORD *v1; // edi
  char *v2; // eax
  const char *i; // ebx
  _DWORD *v4; // eax
  _DWORD *v5; // esi
  const char *v6; // eax
  char *v7; // eax
  char *v8; // ebp
  int v9; // ebx
  _DWORD *v10; // eax
  int v11; // edx
  int v12; // eax
  int v13; // ecx
  int j; // edx
  int v17; // [esp+14h] [ebp-314h]
  char Buffer[256]; // [esp+18h] [ebp-310h] BYREF
  _BYTE v19[509]; // [esp+118h] [ebp-210h] BYREF
  __int16 v20; // [esp+315h] [ebp-13h]
  char v21; // [esp+317h] [ebp-11h]
  int v22; // [esp+324h] [ebp-4h]

  v1 = this;
  sub_59EAD0(this + 218);
  v2 = dword_91CB00;
  if ( !dword_91CB00 )
    v2 = (char *)WindowName;
  sub_615FE0("*.PLR", 1, v2, 1);
  sub_615F10(2);
  for ( i = (const char *)sub_615D40(&unk_FAECBC); i; i = (const char *)sub_615D40(&unk_FAECBC) )
  {
    v4 = operator new(0x64u);
    v5 = v4;
    HIBYTE(v17) = HIBYTE(v4);
    v22 = 0;
    if ( v4 )
    {
      sub_4D3020(v4, v1);
      *v5 = &off_6FB984;
      v5[21] = 0;
      v5[22] = -1;
      v5[23] = 0;
      v5[24] = -1;
    }
    else
    {
      v5 = 0;
    }
    v22 = -1;
    v6 = dword_91CB00;
    if ( !dword_91CB00 )
      v6 = WindowName;
    sprintf(Buffer, "%s%s", v6, i);
    sub_615860(Buffer);
    v7 = &Buffer[strlen(Buffer)];
    if ( v7 > Buffer )
    {
      while ( *v7 != 46 )
      {
        if ( --v7 <= Buffer )
          goto LABEL_14;
      }
      *v7 = 0;
    }
LABEL_14:
    v8 = &Buffer[strlen(Buffer)];
    if ( v8 > Buffer )
    {
      while ( *v8 != 92 )
      {
        if ( --v8 <= Buffer )
          goto LABEL_19;
      }
      ++v8;
    }
LABEL_19:
    v9 = sub_4CF8C0(v1);
    if ( !v9 )
      v9 = sub_4DF190(v1[12]);
    memset(v19, 0, sizeof(v19));
    v20 = 0;
    v21 = 0;
    sub_617A70(512);
    sub_4D30B0(v9, v19);
    _strupr(v8);
    sub_615860(v8);
    v5[2] = (*(int (__thiscall **)(_DWORD *))(*v5 + 8))(v5) + 12;
    v10 = operator new(0xCu);
    if ( v10 )
    {
      *v10 = v5;
      v10[1] = 0;
      *((_BYTE *)v10 + 8) = 1;
    }
    else
    {
      v10 = 0;
    }
    if ( this[218] )
    {
      *(_DWORD *)(this[219] + 4) = v10;
    }
    else
    {
      this[218] = v10;
      this[220] = v10;
    }
    v11 = this[221] + 1;
    this[219] = v10;
    this[221] = v11;
    sub_615CE0(&unk_FAECBC);
    v1 = this;
  }
  v12 = sub_4AB960(v1[218]);
  v13 = v12;
  v1[218] = v12;
  if ( v12 )
  {
    for ( j = *(_DWORD *)(v12 + 4); j; j = *(_DWORD *)(j + 4) )
      v13 = j;
  }
  v1[219] = v13;
  v1[220] = v12;
  sub_615FC0(&unk_FAECBC);
  sub_4A0720();
  return 0;
}
