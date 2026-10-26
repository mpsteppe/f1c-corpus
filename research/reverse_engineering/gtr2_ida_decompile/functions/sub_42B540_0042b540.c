char __thiscall sub_42B540(_DWORD *this, int a2)
{
  int v3; // edi
  const char *v4; // eax
  _BYTE v6[4]; // [esp+Ch] [ebp-110h] BYREF
  _BYTE v7[256]; // [esp+10h] [ebp-10Ch] BYREF
  int v8; // [esp+118h] [ebp-4h]

  v7[0] = 0;
  v8 = 0;
  sub_4EDB50(v6, v7, this + 5);
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
