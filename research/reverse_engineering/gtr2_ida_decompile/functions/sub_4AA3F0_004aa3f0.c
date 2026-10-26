int sub_4AA3F0()
{
  int result; // eax
  const CHAR **v1; // esi
  const CHAR *v2; // eax
  const CHAR *v3; // eax
  bool v4; // zf
  const CHAR *v5; // eax
  int v6; // [esp+0h] [ebp-50h]
  _BYTE v7[56]; // [esp+Ch] [ebp-44h] BYREF
  int v8; // [esp+4Ch] [ebp-4h]

  sub_4D0AC0(v6);
  result = dword_B76250;
  dword_B76258 = dword_B76250;
  if ( dword_B76250 )
  {
    v1 = *(const CHAR ***)dword_B76250;
    if ( *(_DWORD *)dword_B76250 )
    {
      sub_617030(v7);
      v2 = *(const CHAR **)dword_91CA70;
      v8 = 0;
      if ( !*(_DWORD *)dword_91CA70 )
        v2 = WindowName;
      sub_615860(v2);
      v3 = *v1;
      v4 = *v1 == 0;
      LOBYTE(v8) = 1;
      if ( v4 )
        v3 = WindowName;
      sub_615A50(v3);
      sub_616F90(WindowName, 0);
      v5 = (const CHAR *)sub_616930("Game Name");
      if ( !v5 )
      {
        v5 = *v1;
        if ( !*v1 )
          v5 = WindowName;
      }
      sub_4D93B0(v5, 0, 0, 0, 0, 0, -1, -1, -1, -1);
      if ( dword_B76258 )
        dword_B76258 = *(_DWORD *)(dword_B76258 + 4);
      v8 = -1;
      return sub_617060(v7);
    }
  }
  return result;
}
