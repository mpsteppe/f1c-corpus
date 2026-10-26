void __thiscall sub_498070(_BYTE *this)
{
  _BYTE *v1; // ebx
  int v2; // eax
  int v3; // edx
  int v4; // eax
  const char *v5; // edx
  int v6; // eax
  const char *i; // eax
  char *v8; // ecx
  const CHAR *v9; // eax
  char *v10; // eax
  char v11; // bl
  int v12; // eax
  char *v13; // eax
  unsigned int v14; // kr00_4
  __int32 v15; // edi
  __int32 v16[5]; // [esp+8h] [ebp-5FCh] BYREF
  _BYTE *v17; // [esp+1Ch] [ebp-5E8h]
  LPCSTR lpFileName; // [esp+20h] [ebp-5E4h]
  int v19; // [esp+24h] [ebp-5E0h]
  void *Block[2]; // [esp+28h] [ebp-5DCh] BYREF
  unsigned int v21; // [esp+30h] [ebp-5D4h]
  char v22[61]; // [esp+34h] [ebp-5D0h] BYREF
  __int16 v23; // [esp+71h] [ebp-593h]
  char v24; // [esp+73h] [ebp-591h]
  char Buffer[125]; // [esp+74h] [ebp-590h] BYREF
  __int16 v26; // [esp+F1h] [ebp-513h]
  char v27; // [esp+F3h] [ebp-511h]
  char v28[3]; // [esp+F4h] [ebp-510h] BYREF
  char v29[125]; // [esp+F7h] [ebp-50Dh] BYREF
  char v30[128]; // [esp+174h] [ebp-490h] BYREF
  _BYTE v31[2]; // [esp+1F4h] [ebp-410h] BYREF
  char v32[1026]; // [esp+1F6h] [ebp-40Eh] BYREF
  int v33; // [esp+600h] [ebp-4h]

  v1 = this;
  memset(v22, 0, sizeof(v22));
  v23 = 0;
  v17 = this;
  v24 = 0;
  v2 = sub_4CE170(this);
  v1[524] = 0;
  if ( v2 )
  {
    sub_630FE0(v22, v2, 63);
    v24 = 0;
  }
  sub_4D0AC0(v16[1]);
  sub_615FC0(&unk_FAECBC);
  lpFileName = 0;
  v19 = -1;
  v3 = *(_DWORD *)dword_B6E090;
  v33 = 0;
  v4 = (*(int (__thiscall **)(int, int))(v3 + 28))(dword_B6E090, 57);
  if ( v4 )
    sub_615860(v4 + 608);
  sub_615A50("*.ds");
  Block[0] = 0;
  Block[1] = (void *)-1;
  v16[0] = (__int32)Block;
  LOBYTE(v33) = 1;
  sub_42A7F0();
  v5 = (const char *)Block[0];
  if ( !Block[0] )
    v5 = WindowName;
  v6 = strlen(v5);
  if ( v6 > 0 )
  {
    for ( i = &v5[v6 - 1]; i >= v5; *i-- = 0 )
    {
      if ( *i == 92 )
        break;
    }
  }
  v8 = (char *)Block[0];
  if ( !Block[0] )
    v8 = (char *)WindowName;
  v9 = lpFileName;
  if ( !lpFileName )
    v9 = WindowName;
  sub_615FE0(v9, 1, v8, 0);
  sub_615F10(0);
  sub_615D10(&unk_FAECBC);
  if ( sub_615CC0(&unk_FAECBC) )
  {
    do
    {
      v26 = 0;
      v27 = 0;
      memset(Buffer, 0, sizeof(Buffer));
      sub_617A70(128);
      sprintf(Buffer, "%s", v30);
      sub_630FE0(v28, Buffer, 127);
      v29[124] = 0;
      v10 = &v28[strlen(v28)];
      if ( v10 > v28 )
      {
        while ( *v10 != 46 )
        {
          if ( --v10 <= v28 )
            goto LABEL_21;
        }
        *v10 = 0;
      }
LABEL_21:
      v11 = -77;
      v12 = sub_41D990(dword_B761EC, Buffer);
      if ( v12 == 3 || v12 == 4 )
        v11 = -67;
      v31[0] = v11;
      v31[1] = 32;
      v13 = sub_41D840(&byte_91CC38, v29);
      v16[0] = (__int32)v28;
      v14 = __readeflags();
      v15 = dword_16C6E98 - (dword_16F5AAC + 1);
      __writeeflags(v14);
      _InterlockedExchange(v16, v15);
      sub_630FE0(v32, v13, v16[0]);
      v32[1021] = 0;
      v21 = strlen(Buffer);
      if ( v21 )
        sub_4D93B0(v31, 0, 0, Buffer, 0, 0, -1, -1, -1, -1);
      if ( !strcmp(&v22[2], v32) )
      {
        sub_630FE0(v22, v31, 63);
        v24 = 0;
      }
      sub_615CE0(&unk_FAECBC);
    }
    while ( sub_615CC0(&unk_FAECBC) );
    v1 = v17;
  }
  v21 = strlen(v22);
  v16[0] = 0;
  if ( v21 )
    sub_4D4150(v1, v22);
  else
    sub_4D4060(1, v16[0]);
  sub_615FC0(&unk_FAECBC);
  if ( Block[0] )
    j_j__free(Block[0]);
  if ( lpFileName )
    j_j__free((void *)lpFileName);
}
