void __thiscall sub_681C77(void *this)
{
  bool v2; // zf
  unsigned int i; // edi
  void *v4; // ecx
  unsigned int j; // edi
  void *v6; // ecx
  unsigned int k; // edi
  void *v8; // ecx

  v2 = *((_DWORD *)this + 4) == 0;
  *(_DWORD *)this = &off_73D02C;
  if ( !v2 )
  {
    for ( i = 0; i < *((_DWORD *)this + 1); ++i )
    {
      v4 = *(void **)(*((_DWORD *)this + 4) + 4 * i);
      if ( v4 )
        sub_681758(v4, 1);
    }
    j__free(*((void **)this + 4));
  }
  if ( *((_DWORD *)this + 5) )
  {
    for ( j = 0; j < *((_DWORD *)this + 2); ++j )
    {
      v6 = *(void **)(*((_DWORD *)this + 5) + 4 * j);
      if ( v6 )
        sub_663A9B(v6, 1);
    }
    j__free(*((void **)this + 5));
  }
  if ( *((_DWORD *)this + 6) )
  {
    for ( k = 0; k < *((_DWORD *)this + 3); ++k )
    {
      v8 = *(void **)(*((_DWORD *)this + 6) + 4 * k);
      if ( v8 )
        sub_66238F(v8, 1);
    }
    j__free(*((void **)this + 6));
  }
}
