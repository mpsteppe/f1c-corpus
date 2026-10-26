int __thiscall sub_541280(_DWORD *this)
{
  const CHAR *v2; // eax
  const CHAR *v3; // eax
  int v4; // edi
  int v5; // eax
  int result; // eax
  char *v7; // eax
  const CHAR *v8; // [esp-Ch] [ebp-14h]
  const CHAR *v9; // [esp-4h] [ebp-Ch]

  sub_409FB0(this);
  v2 = (const CHAR *)dword_91CB08;
  if ( !dword_91CB08 )
    v2 = WindowName;
  v9 = v2;
  sub_5406E0();
  v3 = (const CHAR *)dword_91CB08;
  if ( !dword_91CB08 )
    v3 = WindowName;
  v8 = v3;
  sub_5406E0();
  v4 = this[3];
  if ( v4 > 0 )
  {
    v5 = rand();
    sub_47F6E0(this, v5 % v4);
  }
  result = this[3];
  if ( !result && dword_BE1D0C )
  {
    v7 = (char *)dword_91CB08;
    if ( !dword_91CB08 )
      v7 = (char *)WindowName;
    off_903980[0] = v7;
    return (*(int (__cdecl **)(char **, int, const CHAR *, const char *, const CHAR *))(*(_DWORD *)dword_BE1D0C + 72))(
             off_903980,
             dword_903978,
             v8,
             "*.wav",
             v9);
  }
  return result;
}
