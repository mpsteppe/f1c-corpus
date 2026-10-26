int __stdcall sub_592910(const char *a1, int nNumber, int a3, int a4, int a5, int a6, _DWORD *a7)
{
  int v7; // eax
  char v8; // cl
  signed int v9; // ecx
  _DWORD *v10; // eax
  void *v12; // eax
  void *v13; // esi
  char String[256]; // [esp+Ch] [ebp-200h] BYREF
  char Str[256]; // [esp+10Ch] [ebp-100h] BYREF

  strcpy(String, a1);
  _strupr(String);
  v7 = 0;
  do
  {
    v8 = String[v7];
    Str[v7++] = v8;
  }
  while ( v8 );
  v9 = strlen(String) - 1;
  if ( v9 > 0 )
  {
    while ( String[v9] != 46 )
    {
      if ( --v9 <= 0 )
        goto LABEL_8;
    }
    String[v9] = 0;
  }
LABEL_8:
  v10 = (_DWORD *)sub_592CD0(String);
  if ( v10 && (a6 & 0x1000) == 0 )
  {
    ++*v10;
    if ( a7 )
    {
      *a7 = v10;
      return 0;
    }
    return 0;
  }
  v12 = operator new(0x10BCu);
  if ( v12 )
    v13 = (void *)sub_5A2C20(v12);
  else
    v13 = 0;
  if ( !sub_5A2CE0(Str, nNumber, a3, a4, a5, a6) )
  {
    sub_592E50(v13);
    if ( a7 )
      *a7 = v13;
    return 0;
  }
  if ( v13 )
  {
    j_nullsub_6(v13);
    sub_5BE8AE();
  }
  return -1;
}
