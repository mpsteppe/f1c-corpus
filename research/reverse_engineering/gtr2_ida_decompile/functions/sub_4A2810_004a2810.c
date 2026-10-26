int __thiscall sub_4A2810(void *this)
{
  char v2; // al
  char *v3; // eax
  const char *v4; // eax
  const char *v6; // [esp-8h] [ebp-58h]
  int v7; // [esp+4h] [ebp-4Ch] BYREF
  int v8; // [esp+8h] [ebp-48h] BYREF
  int v9; // [esp+Ch] [ebp-44h] BYREF
  _BYTE v10[64]; // [esp+10h] [ebp-40h] BYREF

  v9 = 0;
  v8 = 0;
  v7 = 0;
  v2 = sub_53A7E0((int)&v9, (int)&v8, (int)&v7, 0);
  if ( *(_DWORD *)dword_B72314 == 4 || !v2 )
  {
    v4 = Str;
    if ( !Str )
      v4 = WindowName;
    if ( strstr(v4, "Custom") || *(_DWORD *)dword_B72314 != 4 || byte_B6F118 )
    {
      sub_53A410(&unk_BE1CFD, v10, 63);
    }
    else
    {
      v6 = v10;
      sub_53A390(&unk_BE1CFD);
    }
    (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)this + 36))(this, 0);
    v3 = sub_41D840(&byte_91CC38, v6);
  }
  else
  {
    (*(void (__thiscall **)(void *, int))(*(_DWORD *)this + 36))(this, 1);
    v3 = sub_41D840(&byte_91CC38, "None");
  }
  sub_4CE020(v3);
  return 0;
}
