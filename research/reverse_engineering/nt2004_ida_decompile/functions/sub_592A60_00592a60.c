int __stdcall sub_592A60(_DWORD *a1, const char *a2, int a3)
{
  int v3; // eax
  char v4; // cl
  signed int v5; // ecx
  _DWORD *v6; // eax
  void *v8; // eax
  void *v9; // esi
  char String[256]; // [esp+Ch] [ebp-200h] BYREF
  char Str[256]; // [esp+10Ch] [ebp-100h] BYREF

  strcpy(String, a2);
  _strupr(String);
  v3 = 0;
  do
  {
    v4 = String[v3];
    Str[v3++] = v4;
  }
  while ( v4 );
  v5 = strlen(String) - 1;
  if ( v5 > 0 )
  {
    while ( String[v5] != 46 )
    {
      if ( --v5 <= 0 )
        goto LABEL_8;
    }
    String[v5] = 0;
  }
LABEL_8:
  v6 = (_DWORD *)sub_592CD0(String);
  if ( v6 && (a3 & 0x1000) == 0 )
  {
    ++*v6;
    if ( a1 )
    {
      *a1 = v6;
      return 0;
    }
    return 0;
  }
  v8 = operator new(0x10BCu);
  if ( v8 )
    v9 = (void *)sub_5A2C20(v8);
  else
    v9 = 0;
  if ( !sub_5A2CE0(Str, 24, 400, 0xFFFFFF, 0, a3) )
  {
    sub_592E50(v9);
    if ( a1 )
      *a1 = v9;
    return 0;
  }
  if ( v9 )
  {
    j_nullsub_6(v9);
    sub_5BE8AE();
  }
  return -1;
}
