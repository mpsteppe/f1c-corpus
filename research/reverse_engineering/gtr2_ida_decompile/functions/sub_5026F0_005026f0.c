char __thiscall sub_5026F0(_DWORD *this, int a2)
{
  int v3; // edi
  const char *v4; // eax
  _BYTE v6[4]; // [esp+Ch] [ebp-104h] BYREF
  _BYTE v7[252]; // [esp+10h] [ebp-100h] BYREF
  int v8; // [esp+10Ch] [ebp-4h]

  v7[0] = 0;
  sub_4EDB50(v6, (int)v7, (int)(this + 5));
  v3 = v8;
  (*(void (__stdcall **)(int, const char *))(*(_DWORD *)v8 + 32))(v8, "%s=\"%s\"");
  v4 = (const char *)this[3];
  if ( !v4 )
    v4 = WindowName;
  if ( strlen(v4) )
    (*(void (**)(int, const char *, ...))(*(_DWORD *)v3 + 32))(v3, " // %s", this[3], this[4]);
  (*(void (__cdecl **)(int, const char *))(*(_DWORD *)v3 + 32))(v3, word_6F2E64);
  return 0;
}
