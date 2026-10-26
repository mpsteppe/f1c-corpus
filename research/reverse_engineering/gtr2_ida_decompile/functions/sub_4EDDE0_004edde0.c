char __thiscall sub_4EDDE0(_DWORD *this, int a2)
{
  const CHAR *v3; // eax

  (*(void (__thiscall **)(int, const char *))(*(_DWORD *)a2 + 40))(a2, word_6F2E64);
  v3 = (const CHAR *)this[1];
  if ( !v3 )
    v3 = WindowName;
  (*(void (__thiscall **)(int, const CHAR *))(*(_DWORD *)a2 + 40))(a2, v3);
  (*(void (__thiscall **)(int, const char *))(*(_DWORD *)a2 + 40))(a2, word_6F2E64);
  return 1;
}
