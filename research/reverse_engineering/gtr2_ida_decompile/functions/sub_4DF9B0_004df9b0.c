int __thiscall sub_4DF9B0(_DWORD *this, int a2, int a3, int a4)
{
  int i; // edi
  int v6; // eax
  int v7; // eax
  const char *v8; // eax
  int v9; // eax
  int v10; // eax

  for ( i = 0; i < a2; ++i )
  {
    if ( *(_WORD *)(a3 + 2 * i) == 1 )
    {
      v9 = this[6];
      if ( v9 )
      {
        v10 = *(_DWORD *)(v9 + 68);
        if ( v10 )
        {
          v8 = *(const char **)(v10 + 92);
          goto LABEL_10;
        }
      }
    }
    else if ( *(_WORD *)(a3 + 2 * i) == 28 )
    {
      v6 = this[6];
      if ( v6 )
      {
        v7 = *(_DWORD *)(v6 + 68);
        if ( v7 )
        {
          v8 = *(const char **)(v7 + 84);
LABEL_10:
          if ( !v8 )
            v8 = WindowName;
          sub_4DF410(this, v8);
        }
      }
    }
  }
  return (*(int (__thiscall **)(_DWORD *, int, int, int))(*this + 32))(this, a2, a3, a4);
}
