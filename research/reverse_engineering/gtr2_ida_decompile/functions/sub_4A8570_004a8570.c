void __usercall sub_4A8570(_DWORD *a1@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  _DWORD *v4; // eax
  char *v5; // eax
  _DWORD *v6; // eax
  char *v7; // eax
  const CHAR *v8; // eax
  char *v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // ebx
  const char *v13; // eax
  const char *v14; // esi
  const CHAR *v15; // eax
  char *v16; // eax
  int v17; // eax
  void *Block; // [esp+0h] [ebp-588h]
  int v19; // [esp+Ch] [ebp-57Ch]
  int v21; // [esp+14h] [ebp-574h]
  const char *v22; // [esp+20h] [ebp-568h] BYREF
  _DWORD v23[2]; // [esp+24h] [ebp-564h] BYREF
  int v24; // [esp+2Ch] [ebp-55Ch]
  _BYTE v25[36]; // [esp+30h] [ebp-558h] BYREF
  _BYTE v26[12]; // [esp+54h] [ebp-534h] BYREF
  char v27[276]; // [esp+60h] [ebp-528h] BYREF
  char Buffer[984]; // [esp+174h] [ebp-414h] BYREF
  int v29; // [esp+578h] [ebp-10h]

  (*(void (__thiscall **)(_DWORD *))(*a1 + 36))(a1);
  v23[0] = 0;
  sub_4CE140(a1, v23);
  if ( *(_DWORD *)dword_B72314 == 4 )
  {
    v4 = (_DWORD *)sub_616840("Game Filter");
    if ( v4 )
    {
      v5 = sub_48D380(v4);
      sub_41D810(Buffer, 0x3FFu, "%s", v5);
    }
    v6 = (_DWORD *)sub_616840("Selection Filter");
    if ( v6 )
    {
      v7 = sub_48D380(v6);
      sub_41D810(Buffer, 0x3FFu, "%s %s", Buffer, v7);
    }
    sub_53BDE0(&unk_BE1CE0, Buffer);
  }
  v8 = dword_B6F708;
  if ( !dword_B6F708 )
    v8 = WindowName;
  sub_615860(v8);
  v23[0] = 0;
  v23[1] = -1;
  v9 = dword_B6F708;
  v29 = 0;
  if ( !dword_B6F708 )
    v9 = (char *)WindowName;
  v10 = sub_539670(v9);
  if ( v10 )
    sub_615860(v10 + 1980);
  sub_4D0AC0(v21);
  v11 = sub_4CF8C0(a1);
  sub_630FE0(v25, v11, 63);
  v27[15] = 0;
  v24 = sub_5A6E90(&unk_BE1CE0);
  v22 = 0;
  if ( v24 > 0 )
  {
    v19 = a3;
    do
    {
      v12 = ((int (__thiscall *)(void *, const char *, int))byte_53A070)(&unk_BE1CE0, v22, v19);
      v13 = v22;
      v14 = v22;
      if ( !v22 )
        v14 = WindowName;
      if ( !strcmp(v14, WindowName) )
        goto LABEL_21;
      if ( !v22 )
        v13 = WindowName;
      if ( !strcmp(v13, (const char *)(v12 + 1980)) )
      {
LABEL_21:
        if ( v12 )
        {
          sub_495B50();
          v15 = *(const CHAR **)v12;
          if ( !*(_DWORD *)v12 )
            v15 = WindowName;
          sub_4D93B0(v27, 0, &v22, v15, 0, 0, -1, -1, -1, -1);
        }
      }
      ++a2;
    }
    while ( a2 < 0 );
  }
  sub_4D41C0(0, -1);
  sub_4D41C0(0, 1);
  sub_4D41C0(2, 3);
  sub_4D41C0(0, 2);
  v16 = dword_B6F708;
  if ( !dword_B6F708 )
    v16 = (char *)WindowName;
  v17 = sub_539670(v16);
  if ( v17 )
  {
    Block = (void *)v17;
    sub_495B50();
    sub_4D4150(a1, v26);
  }
  a1[139] = sub_4CE1B0(a1);
  if ( Block )
    j_j__free(Block);
}
