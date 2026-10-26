int __init_time()
{
  int v0; // eax
  void *v1; // esi

  if ( dword_7FF1F4 )
  {
    v0 = sub_5C1C71(1, 172);
    v1 = (void *)v0;
    if ( !v0 )
      return 1;
    if ( _get_lc_time(v0) )
    {
      _free_lc_time(v1);
      sub_5C1B88(v1);
      return 1;
    }
    off_628670 = (_UNKNOWN ***)v1;
    _free_lc_time(dword_7FF208);
    sub_5C1B88(dword_7FF208);
    dword_7FF208 = v1;
  }
  else
  {
    off_628670 = (_UNKNOWN ***)off_628678;
    _free_lc_time(dword_7FF208);
    sub_5C1B88(dword_7FF208);
    dword_7FF208 = 0;
  }
  return 0;
}
