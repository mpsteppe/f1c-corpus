void __thiscall sub_673A96(void *this)
{
  bool v2; // zf
  unsigned int i; // edi
  void *v4; // ecx

  v2 = *((_DWORD *)this + 5) == 0;
  *(_DWORD *)this = &off_73AE98;
  if ( !v2 )
  {
    for ( i = 0; i < *((_DWORD *)this + 6); ++i )
    {
      v4 = *(void **)(*((_DWORD *)this + 5) + 4 * i);
      if ( v4 )
        sub_673A75(v4, 1);
    }
    j__free(*((void **)this + 5));
  }
  j__free(*((void **)this + 2));
  j__free(*((void **)this + 7));
}
