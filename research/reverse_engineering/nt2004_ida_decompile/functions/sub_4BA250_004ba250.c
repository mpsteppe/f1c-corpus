int sub_4BA250()
{
  bool v0; // bl
  int v1; // eax
  bool v2; // al
  bool v4; // [esp+Bh] [ebp-1h]

  if ( (!*(_DWORD *)dword_76693C || *(_DWORD *)(dword_75AACC + 20892) == 3 && sub_463490(dword_764D70))
    && !byte_76617C
    && dword_75CBB0 != 8
    && dword_7D7988 == -1 )
  {
    v4 = dword_75CBB0 == 7;
    v0 = (dword_75CBB4 == 8 || dword_75CBB4 == 5) && flt_7D74C0 < dbl_7DA9D0;
    v2 = 0;
    if ( sub_42DBC0() )
    {
      v1 = *(_DWORD *)(dword_75AACC + 20892);
      if ( v1 == 1 || v1 == 3 )
        v2 = 1;
    }
    if ( !v4 && v0 || v2 )
      sub_4BA1A0(1, -1.0);
  }
  return 0;
}
