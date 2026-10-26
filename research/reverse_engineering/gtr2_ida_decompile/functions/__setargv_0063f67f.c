int _setargv()
{
  char *v0; // ebx
  int v1; // esi
  char **v2; // eax
  int v3; // edi
  int v5; // [esp+Ch] [ebp-8h] BYREF
  int v6; // [esp+10h] [ebp-4h] BYREF

  if ( !dword_FBC614 )
    __initmbctable();
  byte_FB860C = 0;
  GetModuleFileNameA(0, Filename, 0x104u);
  dword_FB81C4 = (int)Filename;
  if ( !dword_FBC604 || (v0 = (char *)dword_FBC604, !*(_BYTE *)dword_FBC604) )
    v0 = Filename;
  parse_cmdline(v0, 0, &v5, 0, &v6);
  v1 = v6;
  v2 = (char **)malloc(4 * v6 + v5);
  v3 = (int)v2;
  if ( !v2 )
    return -1;
  parse_cmdline(v0, (char *)&v2[v1], &v5, v2, &v6);
  dword_FB81A8 = v6 - 1;
  dword_FB81AC = v3;
  return 0;
}
