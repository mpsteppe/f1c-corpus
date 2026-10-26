int __stdcall sub_592CD0(const char *a1)
{
  int v1; // edi
  char String[256]; // [esp+Ch] [ebp-100h] BYREF

  v1 = dword_7E8D34;
  strcpy(String, a1);
  _strupr(String);
  if ( !v1 )
    return 0;
  while ( strcmp((const char *)(v1 + 36), String) )
  {
    v1 = *(_DWORD *)(v1 + 32);
    if ( !v1 )
      return 0;
  }
  return v1;
}
