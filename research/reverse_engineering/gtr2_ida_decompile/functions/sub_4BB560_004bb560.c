void __thiscall sub_4BB560(_DWORD *this)
{
  _DWORD *v1; // edi
  const char *v2; // ebp
  const CHAR *v3; // eax
  const CHAR *v4; // esi
  const CHAR *v5; // eax
  const char *v6; // esi
  _DWORD *v7; // eax
  const char *v8; // eax
  char *v9; // esi
  char v10; // bl
  int v11; // ebp
  const char *v12; // edi
  const CHAR *v13; // eax
  const CHAR *v14; // eax
  char v15; // bl
  int v16; // eax
  const char *v17; // eax
  int v18; // eax
  char *v19; // eax
  const CHAR *v20; // eax
  const CHAR *v21; // eax
  const CHAR **v22; // eax
  _DWORD *v23; // eax
  char *v24; // eax
  int v25; // [esp-14h] [ebp-59Ch]
  int v26; // [esp-10h] [ebp-598h]
  int v27; // [esp+0h] [ebp-588h]
  const CHAR *v28; // [esp+4h] [ebp-584h]
  _DWORD *v29; // [esp+8h] [ebp-580h]
  CHAR *Block; // [esp+Ch] [ebp-57Ch]
  void *v31; // [esp+10h] [ebp-578h]
  const CHAR *v33; // [esp+20h] [ebp-568h]
  _DWORD v34[3]; // [esp+34h] [ebp-554h] BYREF
  char v35[56]; // [esp+40h] [ebp-548h] BYREF
  char Buffer[238]; // [esp+78h] [ebp-510h] BYREF
  _BYTE v37[1026]; // [esp+166h] [ebp-422h] BYREF
  char v38; // [esp+578h] [ebp-10h]
  int v39; // [esp+584h] [ebp-4h]

  v1 = this;
  v2 = 0;
  v33 = 0;
  v3 = *(const CHAR **)dword_91CA70;
  v39 = 0;
  if ( !*(_DWORD *)dword_91CA70 )
    v3 = WindowName;
  sub_615860(v3);
  if ( *(_DWORD *)dword_B72314 == 4 )
  {
    v4 = "*.GDB";
    if ( v1[149] == 65 )
      v5 = (const CHAR *)dword_91CA78;
    else
      v5 = (const CHAR *)dword_91CA80;
    if ( !v5 )
      v5 = WindowName;
    v2 = v5;
    v33 = v5;
    if ( v5 )
      sub_615A50(v5);
  }
  else
  {
    v4 = "24H*.GDB";
  }
  sub_615FE0(v4, 0, (char *)WindowName, 1);
  sub_615F10(0);
  sub_4D0AC0(v27);
  sub_41ED50(v1 + 152);
  v34[0] = dword_B76220 + dword_B76224;
  v6 = (const char *)sub_615D40(&unk_FAECBC);
  if ( v6 )
  {
    v34[1] = 0;
    v34[2] = -1;
    while ( 1 )
    {
      LOBYTE(v39) = 1;
      v7 = operator new(8u);
      if ( v7 )
      {
        *v7 = 0;
        v7[1] = -1;
      }
      sub_617030(v35);
      v8 = *(const char **)dword_91CA70;
      if ( v2 )
      {
        if ( !*(_DWORD *)dword_91CA70 )
          v8 = WindowName;
        sprintf(Buffer, "%s%s%s", v8, v2, v6);
      }
      else
      {
        if ( !*(_DWORD *)dword_91CA70 )
          v8 = WindowName;
        sprintf(Buffer, "%s%s", v8, v6);
      }
      v9 = &Buffer[strlen(Buffer)];
      if ( v9 > Buffer )
      {
        while ( *v9 != 92 )
        {
          if ( --v9 <= Buffer )
            goto LABEL_29;
        }
        ++v9;
      }
LABEL_29:
      LOBYTE(v39) = 3;
      if ( v2 )
        sub_615860(v2);
      sub_615A50(v9);
      sub_616F90(Buffer, 0);
      v10 = sub_41E190();
      v11 = sub_4CF8C0(v1);
      if ( v10 )
        v11 = sub_4CF900(v1);
      v12 = (const char *)sub_616930("Game Name");
      if ( v12 )
      {
        v14 = Block;
        if ( *(_DWORD *)dword_B72314 == 4 )
        {
          if ( !Block )
            v14 = WindowName;
          sub_5100A0(&byte_B6F530, v14);
          v15 = -77;
          v16 = sub_534F50(&unk_B76270) - 2;
          if ( v16 )
          {
            if ( v16 == 1 )
            {
              v17 = Str;
              if ( !Str )
                v17 = WindowName;
              if ( strstr(v17, "Custom") && ((v25 = 0, v18 = sub_41D9E0(), v18 <= 0) || v18 > 2) )
                v15 = -66;
              else
                v15 = -67;
            }
          }
          else
          {
            v15 = -68;
          }
          Buffer[236] = v15;
          Buffer[237] = 32;
          v19 = sub_41D840(&byte_91CC38, v12);
          sub_630FE0(v37, v19, 1021);
          v20 = v28;
          v37[1021] = 0;
          if ( !v28 )
            v20 = WindowName;
          sub_4D93B0(v11, v20, 0, 0, -1, -1, -1, -1, v25, v26);
        }
        else
        {
          if ( !Block )
            v14 = WindowName;
          sub_4D93B0(v12, 0, v11, v14, 0, 0, -1, -1, -1, -1);
        }
      }
      else
      {
        v13 = Block;
        if ( !Block )
          v13 = WindowName;
        sub_4D93B0(v9, 0, v11, v13, 0, 0, -1, -1, -1, -1);
      }
      v21 = Block;
      if ( !Block )
        v21 = WindowName;
      sub_615860(v21);
      if ( v33 )
      {
        v22 = (const CHAR **)operator new(0xCu);
        if ( v22 )
        {
          *v22 = v33;
          v22[1] = 0;
          *((_BYTE *)v22 + 8) = 1;
        }
        else
        {
          v22 = 0;
        }
        if ( v29[152] )
        {
          *(_DWORD *)(v29[153] + 4) = v22;
        }
        else
        {
          v29[152] = v22;
          v29[154] = v22;
        }
        v29[153] = v22;
        ++v29[155];
      }
      sub_615CE0(&unk_FAECBC);
      if ( Block )
        j_j__free(Block);
      v38 = 1;
      sub_617060(v34);
      v38 = 0;
      v1 = v29;
      v6 = (const char *)sub_615D40(&unk_FAECBC);
      if ( !v6 )
        break;
      v2 = (const char *)this;
    }
  }
  sub_615FC0(&unk_FAECBC);
  v23 = (_DWORD *)sub_616840("Game Name");
  if ( v23 )
  {
    v24 = sub_48D380(v23);
    sub_4D4150(v1, v24);
  }
  if ( sub_4CE1B0(v1) < 1 )
    sub_4D4060(1, 1);
  v1[139] = sub_4CE1B0(v1);
  if ( v31 )
    j_j__free(v31);
}
