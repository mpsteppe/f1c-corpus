int __thiscall sub_601270(void *this)
{
  void *v2; // eax

  *(_DWORD *)this = &off_72D6F8;
  v2 = (void *)*((_DWORD *)this + 1475);
  if ( v2 )
  {
    sub_5F5D40(v2);
    *((_DWORD *)this + 1475) = 0;
  }
  if ( *((int *)this + 2283) > 0 && *((_DWORD *)this + 2284) )
  {
    j__free(*((void **)this + 2284));
    *((_DWORD *)this + 2283) = 0;
  }
  return sub_606BF0(this);
}
