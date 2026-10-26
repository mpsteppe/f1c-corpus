void __cdecl __freetlocinfo(void *Block)
{
  void *v1; // eax
  _DWORD *v2; // eax
  _DWORD *v3; // eax
  _DWORD *v4; // eax
  int v5; // eax

  v1 = (void *)*((_DWORD *)Block + 15);
  if ( v1 != dword_FB83B4 && v1 && !**((_DWORD **)Block + 11) )
  {
    v2 = (_DWORD *)*((_DWORD *)Block + 13);
    if ( v2 && !*v2 && v2 != (_DWORD *)dword_FBB5F0 )
    {
      free(*((void **)Block + 13));
      __free_lconv_mon(*((_DWORD *)Block + 15));
    }
    v3 = (_DWORD *)*((_DWORD *)Block + 12);
    if ( v3 && !*v3 && v3 != (_DWORD *)dword_FBB5F8 )
    {
      free(*((void **)Block + 12));
      __free_lconv_num(*((_DWORD *)Block + 15));
    }
    free(*((void **)Block + 11));
    free(*((void **)Block + 15));
  }
  v4 = (_DWORD *)*((_DWORD *)Block + 16);
  if ( v4 != (_DWORD *)dword_FBB5EC && v4 && !*v4 )
  {
    free(*((void **)Block + 16));
    free((void *)(*((_DWORD *)Block + 17) - 254));
  }
  v5 = *((_DWORD *)Block + 20);
  if ( v5 != dword_FB83B0 && v5 && !*(_DWORD *)(v5 + 180) )
  {
    _free_lc_time(*((_DWORD *)Block + 20));
    free(*((void **)Block + 20));
  }
  free(Block);
}
