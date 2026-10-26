char __thiscall sub_502420(int this, int a2)
{
  const CHAR *v3; // eax
  const char *v4; // eax
  char v6[256]; // [esp+10h] [ebp-100h] BYREF

  v6[0] = 0;
  sub_4EDA50(v6, (float *)(this + 20));
  v3 = *(const CHAR **)(this + 4);
  if ( !v3 )
    v3 = WindowName;
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "%s=\"%s\"", v3, v6);
  v4 = *(const char **)(this + 12);
  if ( !v4 )
    v4 = WindowName;
  if ( strlen(v4) )
    (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(
      a2,
      " // %s",
      *(_DWORD *)(this + 12),
      *(_DWORD *)(this + 16));
  (*(void (__cdecl **)(int, const char *))(*(_DWORD *)a2 + 32))(a2, word_6F2E64);
  return 0;
}
