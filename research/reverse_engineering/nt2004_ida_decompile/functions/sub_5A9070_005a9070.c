int __stdcall sub_5A9070(int **a1, const char *a2, char a3, int a4)
{
  int *v4; // esi
  _DWORD *v5; // eax
  int v7; // ecx
  int i; // eax

  v4 = (int *)sub_5A91C0(a2);
  if ( !v4 )
  {
    v5 = operator new(0x11Cu);
    if ( v5 )
      v4 = sub_5A8480(v5);
    else
      v4 = 0;
    if ( sub_5A84D0(v4, a2, a3, a4) )
    {
      if ( v4 )
      {
        sub_5A84B0(v4);
        sub_5BE8AE();
      }
      return -1;
    }
    v7 = dword_7E5D58;
    if ( dword_7E5D58 )
    {
      for ( i = *(_DWORD *)(dword_7E5D58 + 280); i; i = *(_DWORD *)(i + 280) )
        v7 = i;
      *(_DWORD *)(v7 + 280) = v4;
      v4[69] = v7;
    }
    else
    {
      dword_7E5D58 = (int)v4;
    }
    ++dword_7E8D54;
  }
  ++v4[2];
  if ( a1 )
    *a1 = v4;
  return 0;
}
