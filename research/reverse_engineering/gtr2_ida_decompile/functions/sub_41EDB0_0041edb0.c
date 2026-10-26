int __thiscall sub_41EDB0(_DWORD *this)
{
  _DWORD *v1; // edi
  const CHAR *v2; // eax
  _DWORD *v3; // ebp
  const char *v4; // esi
  _DWORD *v5; // eax
  _DWORD *v6; // edi
  char *v7; // esi
  int v8; // eax
  const char *v9; // eax
  int v10; // eax
  const char *v11; // eax
  _DWORD *v12; // eax
  int v13; // edx
  const CHAR *v15; // [esp+10h] [ebp-168h]
  char v17[56]; // [esp+30h] [ebp-148h] BYREF
  char Buffer[260]; // [esp+68h] [ebp-110h] BYREF
  int v19; // [esp+174h] [ebp-4h]

  v1 = this;
  this[20] = 0;
  v2 = *(const CHAR **)dword_91CA70;
  v19 = 0;
  if ( !*(_DWORD *)dword_91CA70 )
    v2 = WindowName;
  sub_615860(v2);
  v15 = (const CHAR *)dword_91CA80;
  if ( !dword_91CA80 )
    v15 = WindowName;
  sub_615A50(v15);
  sub_615FE0("*.GDB", 0, (char *)WindowName, 1);
  v3 = v1 + 29;
  v1[20] = sub_615D30(&unk_FAECBC);
  sub_41ED50(v1 + 29);
  v4 = (const char *)sub_615D40(&unk_FAECBC);
  if ( v4 )
  {
    do
    {
      LOBYTE(v19) = 1;
      v5 = operator new(0x10u);
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
      v6[2] = 0;
      v6[3] = 0;
      sub_617030(v17);
      LOBYTE(v19) = 2;
      sprintf(Buffer, "%s%s", WindowName, v4);
      v7 = &Buffer[strlen(Buffer)];
      if ( v7 > Buffer )
      {
        while ( *v7 != 92 )
        {
          if ( --v7 <= Buffer )
            goto LABEL_14;
        }
        ++v7;
      }
LABEL_14:
      sub_616F90(Buffer, 0);
      LOBYTE(v19) = 3;
      if ( v15 )
        sub_615860(v15);
      v8 = sub_616840("UnlockGold");
      if ( v8 )
      {
        v9 = (const char *)sub_48D380(v8);
        v6[2] = atol(v9);
      }
      v10 = sub_616840("UnlockPass");
      if ( v10 )
      {
        v11 = (const char *)sub_48D380(v10);
        v6[3] = atol(v11);
      }
      sub_615A50(v7);
      sub_615860(WindowName);
      v12 = operator new(0xCu);
      if ( v12 )
      {
        *v12 = v6;
        v12[1] = 0;
        *((_BYTE *)v12 + 8) = 1;
      }
      else
      {
        v12 = 0;
      }
      if ( *v3 )
      {
        *(_DWORD *)(v3[1] + 4) = v12;
      }
      else
      {
        *v3 = v12;
        v3[2] = v12;
      }
      v13 = v3[3] + 1;
      v3[1] = v12;
      v3[3] = v13;
      sub_615CE0(&unk_FAECBC);
      LOBYTE(v19) = 1;
      sub_617060(v17);
      LOBYTE(v19) = 0;
      v4 = (const char *)sub_615D40(&unk_FAECBC);
    }
    while ( v4 );
    v1 = this;
  }
  return v1[20];
}
