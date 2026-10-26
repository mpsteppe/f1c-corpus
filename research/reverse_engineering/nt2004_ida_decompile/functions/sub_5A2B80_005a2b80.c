int __stdcall sub_5A2B80(const char *a1)
{
  int v1; // edi
  char String[256]; // [esp+0h] [ebp-100h] BYREF

  strcpy(String, a1);
  _strupr(String);
  v1 = dword_7E5EC0;
  if ( !dword_7E5EC0 )
    return 0;
  while ( strcmp((const char *)(v1 + 20), String) )
  {
    v1 = *(_DWORD *)(v1 + 12);
    if ( !v1 )
      return 0;
  }
  return v1;
}
