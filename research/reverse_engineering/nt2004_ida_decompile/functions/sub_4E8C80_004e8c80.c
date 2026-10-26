char __stdcall sub_4E8C80(const char *a1)
{
  int v1; // ebp
  int i; // edi
  int v3; // eax
  char *v4; // edx
  char v5; // cl
  char v7[80]; // [esp+0h] [ebp-A0h] BYREF
  char String[80]; // [esp+50h] [ebp-50h] BYREF

  strcpy(String, a1);
  _strupr(String);
  v1 = 0;
  if ( dword_7D6B50 <= 0 )
    return 0;
  for ( i = 0; ; i += 400 )
  {
    v3 = i + dword_7D6B58 + 260;
    v4 = &v7[-v3];
    do
    {
      v5 = *(_BYTE *)v3;
      v4[v3] = *(_BYTE *)v3;
      ++v3;
    }
    while ( v5 );
    _strupr(v7);
    if ( !strcmp(String, v7) )
      break;
    if ( ++v1 >= dword_7D6B50 )
      return 0;
  }
  dword_7D6B54 = v1;
  return 1;
}
