int __userpurge sub_4A8440@<eax>(int a1@<ebx>, int a2@<edi>, int a3@<esi>, int a4, int a5, int a6, char *String1)
{
  char *v7; // eax
  int v8; // esi
  int result; // eax
  int v10; // edi
  int v11; // eax
  const CHAR *v12; // eax
  const CHAR *v13; // eax
  const CHAR *v14; // eax
  _DWORD v15[132]; // [esp+0h] [ebp-210h] BYREF

  v7 = dword_B6F708;
  if ( !dword_B6F708 )
    v7 = (char *)WindowName;
  v15[3] = a1;
  v15[2] = a3;
  v8 = sub_539670(v7);
  result = _stricmp(String1, (const char *)(v8 + 1980));
  if ( result )
  {
    v15[1] = a2;
    v10 = 0;
    do
    {
      do
      {
        v15[0] = v10;
        v11 = ((int (__thiscall *)(void *))byte_53A070)(&unk_BE1CE0);
        v8 = v11;
        ++v10;
      }
      while ( !v11 );
      result = _stricmp(String1, (const char *)(v11 + 1980));
    }
    while ( result );
  }
  if ( v8 )
  {
    v12 = *(const CHAR **)v8;
    if ( !*(_DWORD *)v8 )
      v12 = WindowName;
    sub_615860(v12);
    v13 = *(const CHAR **)v8;
    if ( !*(_DWORD *)v8 )
      v13 = WindowName;
    sub_615860(v13);
    sub_615860(v8 + 1852);
    if ( *(_DWORD *)dword_B72314 != 4 && *(_DWORD *)dword_B72314 != 8 )
    {
      v14 = *(const CHAR **)v8;
      if ( !*(_DWORD *)v8 )
        v14 = WindowName;
      sub_615860(v14);
    }
    v15[0] = 512;
    sub_501CC0(&byte_B6F530, 1);
    sub_53BDE0(&unk_BE1CE0, v15);
    sub_539FF0(&unk_BE1CE0);
    result = sub_53A0E0(&unk_BE1CE0);
    dword_BE1BD0 = result;
  }
  return result;
}
