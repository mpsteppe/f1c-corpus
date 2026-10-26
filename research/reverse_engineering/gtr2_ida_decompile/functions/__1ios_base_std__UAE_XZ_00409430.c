void __thiscall std::ios_base::~ios_base(std::ios_base *this)
{
  void *v2; // edi

  *(_DWORD *)this = &off_6F1D14;
  if ( *((_DWORD *)this + 2) )
    sub_408AC0((_DWORD *)this + 2);
  v2 = (void *)*((_DWORD *)this + 3);
  if ( v2 )
  {
    nullsub_7(*((void **)this + 3));
    j__free(v2);
  }
  *(_DWORD *)this = &off_6F1D04;
}
