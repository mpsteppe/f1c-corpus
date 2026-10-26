int __init_time()
{
  void **v0; // esi

  if ( dword_FB83F0 )
  {
    v0 = (void **)calloc(1u, 0xB8u);
    if ( !v0 )
      return 1;
    if ( _get_lc_time((int)v0) )
    {
      _free_lc_time(v0);
      free(v0);
      return 1;
    }
    off_913090 = (void (__thiscall ***)(void **))v0;
    dword_FB83B0 = (int)v0;
  }
  else
  {
    dword_FB83B0 = 0;
    off_913090 = &off_913098;
  }
  return 0;
}
