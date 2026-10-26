char __thiscall sub_469630(_DWORD **this)
{
  int v2; // eax
  char *v3; // esi
  char *v4; // eax
  char *v5; // eax
  const char *v6; // esi
  const char *v7; // eax
  const char *v8; // ecx
  const char *v9; // eax
  int v10; // esi
  int v11; // edi
  _BYTE v13[253]; // [esp+14h] [ebp-500h] BYREF
  __int16 v14; // [esp+111h] [ebp-403h]
  char v15; // [esp+113h] [ebp-401h]
  char v16[1024]; // [esp+114h] [ebp-400h] BYREF

  v2 = sub_48D360();
  v3 = sub_4693E0((int)this, v2);
  if ( !v3 || !strlen(v3) )
    return 0;
  strcpy(v16, v3);
  v4 = &v16[strlen(v16)];
  if ( v4 > v16 )
  {
    while ( *v4 != 46 )
    {
      if ( --v4 <= v16 )
        goto LABEL_8;
    }
    *v4 = 0;
  }
LABEL_8:
  sub_566650(v16);
  v5 = (char *)dword_7D0434;
  if ( !dword_7D0434 )
    v5 = byte_5EA438;
  sub_566650(v5);
  sub_4B04E0(v3, 0);
  v6 = (const char *)dword_7D0434;
  if ( !dword_7D0434 )
    v6 = byte_5EA438;
  if ( strcmp(byte_5EA438, v6) )
  {
    v13[0] = byte_5EA438[0];
    memset(&v13[1], 0, 0xFCu);
    v14 = 0;
    v15 = 0;
    v7 = (const char *)dword_5EC3D8;
    if ( !dword_5EC3D8 )
      v7 = byte_5EA438;
    if ( (int)sub_58969D(v13, 255, "%s%s", v7, byte_5EA438) >= 0 )
    {
      sub_5684A0(v13);
      v8 = (const char *)dword_7D0434;
      if ( !dword_7D0434 )
        v8 = byte_5EA438;
      v9 = (const char *)dword_5EC3D8;
      if ( !dword_5EC3D8 )
        v9 = byte_5EA438;
      if ( (int)sub_58969D(v13, 255, "%s%s", v9, v8) >= 0 )
        sub_567F40(v13, 0);
    }
  }
  v10 = (*(int (__thiscall **)(_DWORD *, int))(*this[16] + 28))(this[16], 29);
  v11 = (*(int (__thiscall **)(_DWORD *, int))(*this[16] + 28))(this[16], 2);
  if ( v10 )
    sub_470190(v10);
  if ( v11 )
    ((void (__thiscall *)(int))loc_468640)(v11);
  return 1;
}
