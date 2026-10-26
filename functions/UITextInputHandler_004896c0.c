int __thiscall sub_4896C0(_DWORD *this, int a2, int a3)
{
  int v4; // eax
  char *v5; // eax
  int v6; // edx
  int v7; // esi
  int v8; // esi
  int v9; // edx
  int v10; // ebx
  int v11; // esi
  char v12; // dl
  const char *v13; // eax
  bool v14; // zf
  char v15; // cl
  char v17; // [esp+Bh] [ebp-319h]
  int v18; // [esp+Ch] [ebp-318h] BYREF
  const char *v19; // [esp+10h] [ebp-314h]
  _BYTE v20[4]; // [esp+14h] [ebp-310h] BYREF
  char v21[77]; // [esp+18h] [ebp-30Ch] BYREF
  __int16 v22; // [esp+65h] [ebp-2BFh]
  char v23; // [esp+67h] [ebp-2BDh]
  _BYTE v24[700]; // [esp+68h] [ebp-2BCh] BYREF

  if ( !a2 )
    return -1;
  v4 = this[50];
  if ( v4 )
  {
    v5 = *(char **)(v4 + 64);
    if ( !v5 )
      v5 = byte_5EA438;
    sub_498560(v5);
  }
  sub_587DD0(v24, a2, 700);
  v6 = this[80];
  v7 = this[3];
  v19 = v24;
  v8 = v6 + v7;
  v9 = *this;
  v24[699] = 0;
  v10 = (*(int (__thiscall **)(_DWORD *))(v9 + 24))(this) - v8 - this[80];
  TextRenderToSurface(v24, &v18, v20, 1);
  v17 = 1;
  while ( v18 > v10 )
  {
    v21[0] = byte_5EA438[0];
    memset(&v21[1], 0, 0x4Cu);
    v22 = 0;
    v23 = 0;
    sub_587DD0(v21, v19, 79);
    v23 = 0;
    v11 = strlen(v21);
    TextRenderToSurface(v21, &v18, v20, 1);
    if ( v18 <= v10 )
    {
LABEL_16:
      if ( v11 > 0 )
      {
        UIMenuItemCreator(this, (int)v21, 0, 0, 0, 0);
        if ( a3 )
          UIItemNameSetter(this[37] - 1, a3);
        goto LABEL_20;
      }
    }
    else
    {
      while ( v11 > 0 )
      {
        v12 = 0;
        do
        {
          if ( v12 )
            break;
          if ( v20[v11 + 3] == 32 || !v17 )
            v12 = 1;
          v20[v11 + 3] = 0;
          v11 = strlen(v21);
        }
        while ( v11 > 0 );
        TextRenderToSurface(v21, &v18, v20, 1);
        if ( v18 <= v10 )
          goto LABEL_16;
      }
    }
    v17 = 0;
LABEL_20:
    v13 = &v19[strlen(v21)];
    v14 = *v13 == 32;
    v19 = v13;
    if ( v14 )
    {
      do
        v15 = *++v13;
      while ( v15 == 32 );
      v19 = v13;
    }
    TextRenderToSurface(v13, &v18, v20, 1);
  }
  if ( strlen(v19) )
  {
    UIMenuItemCreator(this, (int)v19, 0, 0, 0, 0);
    if ( a3 )
      UIItemNameSetter(this[37] - 1, a3);
  }
  sub_489D00(this);
  (*(void (__thiscall **)(_DWORD *, int))(*this + 44))(this, 1);
  return 0;
}
