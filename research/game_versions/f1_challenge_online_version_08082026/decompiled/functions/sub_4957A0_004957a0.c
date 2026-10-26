int __thiscall sub_4957A0(_DWORD *this, int a2, int a3, int a4)
{
  int i; // edi
  int v6; // eax
  int v7; // eax
  char *v8; // eax
  int v9; // eax
  int v10; // eax

  for ( i = 0; i < a2; ++i )
  {
    if ( *(_WORD *)(a3 + 2 * i) == 1 )
    {
      v9 = this[6];
      if ( v9 )
      {
        v10 = *(_DWORD *)(v9 + 80);
        if ( v10 )
        {
          v8 = *(char **)(v10 + 96);
          goto LABEL_10;
        }
      }
    }
    else if ( *(_WORD *)(a3 + 2 * i) == 28 )
    {
      v6 = this[6];
      if ( v6 )
      {
        v7 = *(_DWORD *)(v6 + 80);
        if ( v7 )
        {
          v8 = *(char **)(v7 + 88);
LABEL_10:
          if ( !v8 )
            v8 = byte_5EA438;
          sub_4988D0(v8);
        }
      }
    }
  }
  return (*(int (__thiscall **)(_DWORD *, int, int, int))(*this + 32))(this, a2, a3, a4);
}
