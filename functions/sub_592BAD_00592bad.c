int sub_592BAD()
{
  CHAR *v0; // edi
  int v1; // esi
  int result; // eax
  int v3; // [esp+Ch] [ebp-8h] BYREF
  int v4; // [esp+10h] [ebp-4h] BYREF

  if ( !dword_8D5A4C )
    LazyInitSingletonWithFlagGuard_7218();
  GetModuleFileNameA(0, Filename, 0x104u);
  dword_8D3EA0 = (int)Filename;
  v0 = Filename;
  if ( *(_BYTE *)dword_8D5A44 )
    v0 = (CHAR *)dword_8D5A44;
  sub_592C46(v0, 0, 0, &v4, &v3);
  v1 = MallocWrapperForNhMalloc(v3 + 4 * v4);
  if ( !v1 )
    CRTAmsgExit(8u);
  sub_592C46(v0, v1, v1 + 4 * v4, &v4, &v3);
  result = v4 - 1;
  dword_8D3E88 = v1;
  dword_8D3E84 = v4 - 1;
  return result;
}
