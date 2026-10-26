int __init_monetary()
{
  int v0; // eax
  _DWORD *v1; // esi

  if ( dword_7FF1EC )
  {
    v0 = sub_5C1C71(1, 48);
    v1 = (_DWORD *)v0;
    if ( !v0 )
      return 1;
    if ( _get_lc_lconv(v0) )
    {
      _free_lc_lconv(v1);
      sub_5C1B88(v1);
      return 1;
    }
    *v1 = *off_628760;
    v1[1] = off_628760[1];
    v1[2] = off_628760[2];
    off_628760 = (_UNKNOWN **)v1;
    _free_lc_lconv(dword_7FF218);
    sub_5C1B88(dword_7FF218);
    dword_7FF218 = v1;
  }
  else
  {
    off_628730 = *off_628760;
    off_628734 = off_628760[1];
    off_628738 = off_628760[2];
    off_628760 = &off_628730;
    _free_lc_lconv(dword_7FF218);
    sub_5C1B88(dword_7FF218);
    dword_7FF218 = 0;
  }
  return 0;
}
