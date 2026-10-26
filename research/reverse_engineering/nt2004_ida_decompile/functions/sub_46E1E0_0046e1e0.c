int __thiscall sub_46E1E0(void *this)
{
  void *v2; // edi

  *(_DWORD *)this = &off_5D64E8;
  sub_46E780();
  v2 = (void *)*((_DWORD *)this + 85);
  if ( v2 )
  {
    sub_459AC0(*((LPVOID ***)this + 85));
    sub_5BE8AE(v2);
  }
  if ( !--dword_765598 )
    sub_46F170(this);
  return sub_4A42D0(this);
}
