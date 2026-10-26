int __thiscall sub_4637C0(void *this)
{
  int v1; // eax

  if ( *(_DWORD *)(*(_DWORD *)this + 30148) )
  {
    v1 = sub_5B9F90() - 1;
    if ( !v1 )
      return 1;
    if ( v1 == 1 )
      return 2;
  }
  return 0;
}
