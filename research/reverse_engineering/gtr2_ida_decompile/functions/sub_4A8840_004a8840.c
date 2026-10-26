int __stdcall sub_4A8840(int a1, int a2, int a3, char *String1)
{
  int v4; // edi
  const char **v5; // eax
  const char **v6; // esi
  const char *v7; // eax
  const CHAR *v8; // eax
  const CHAR *v9; // eax
  const CHAR *v10; // eax
  int result; // eax
  _BYTE v12[12]; // [esp+0h] [ebp-210h] BYREF

  sub_615860(String1);
  v4 = 0;
  do
  {
    do
    {
      v5 = (const char **)((int (__thiscall *)(void *, int))byte_53A070)(&unk_BE1CE0, v4);
      v6 = v5;
      ++v4;
    }
    while ( !v5 );
    v7 = *v5;
    if ( !*v6 )
      v7 = WindowName;
  }
  while ( _stricmp(String1, v7) );
  v8 = *v6;
  if ( !*v6 )
    v8 = WindowName;
  sub_615860(v8);
  v9 = *v6;
  if ( !*v6 )
    v9 = WindowName;
  sub_615860(v9);
  sub_615860(v6 + 463);
  if ( *(_DWORD *)dword_B72314 != 4 && *(_DWORD *)dword_B72314 != 8 )
  {
    v10 = *v6;
    if ( !*v6 )
      v10 = WindowName;
    sub_615860(v10);
  }
  sub_501CC0(&byte_B6F530, 1);
  sub_53BDE0(&unk_BE1CE0, v12);
  sub_539FF0(&unk_BE1CE0);
  result = sub_53A0E0(&unk_BE1CE0);
  dword_BE1BD0 = result;
  return result;
}
