int __stdcall sub_5A29F0(_DWORD *a1, char *Str, int a3, int a4, int a5, int a6, int a7, int a8)
{
  _DWORD *v8; // esi
  _DWORD *v9; // eax
  int v10; // eax
  int v12; // ecx
  int i; // eax

  v8 = (_DWORD *)sub_5A2B80(Str);
  if ( !v8 )
  {
    v9 = operator new(0x60u);
    if ( v9 )
      v8 = sub_5A1D10(v9);
    else
      v8 = 0;
    v8[1] |= a8;
    if ( a3 && a4 )
    {
      v10 = sub_5A1DC0((int)v8, Str, a3, a4, a5, a7);
    }
    else
    {
      if ( !Str )
      {
LABEL_13:
        j_nullsub_6(v8);
        sub_5BE8AE();
        return -1;
      }
      if ( strstr(Str, dword_608FD8) )
        v10 = sub_5A2210((int)v8, Str, a6, a7);
      else
        v10 = sub_5A1F80((int)v8, Str, a6, a7);
    }
    if ( v10 )
      goto LABEL_13;
    v12 = dword_7E5EC0;
    if ( dword_7E5EC0 )
    {
      for ( i = *(_DWORD *)(dword_7E5EC0 + 12); i; i = *(_DWORD *)(i + 12) )
        v12 = i;
      *(_DWORD *)(v12 + 12) = v8;
      v8[2] = v12;
    }
    else
    {
      dword_7E5EC0 = (int)v8;
    }
    ++dword_7E8D44;
  }
  ++*v8;
  if ( a1 )
    *a1 = v8;
  return 0;
}
