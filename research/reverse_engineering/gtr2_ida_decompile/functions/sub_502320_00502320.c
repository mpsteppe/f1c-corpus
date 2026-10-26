char __thiscall sub_502320(_DWORD *this, int a2)
{
  const CHAR *v3; // eax
  const char *v4; // eax
  _BYTE v6[256]; // [esp+10h] [ebp-100h] BYREF

  v6[0] = 0;
  sub_4ED9C0();
  v3 = (const CHAR *)this[1];
  if ( !v3 )
    v3 = WindowName;
  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "%s=\"%s\"", v3, v6);
  v4 = (const char *)this[3];
  if ( !v4 )
    v4 = WindowName;
  if ( strlen(v4) )
    (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, " // %s", this[3], this[4]);
  (*(void (__cdecl **)(int, const char *))(*(_DWORD *)a2 + 32))(a2, word_6F2E64);
  return 0;
}
