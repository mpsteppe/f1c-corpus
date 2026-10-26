// f1c  0x00461fc0  size=41
int __thiscall sub_461FC0(void *this)
{
  int v1; // eax

  if ( *(_DWORD *)(*(_DWORD *)this + 112540) )
  {
    v1 = sub_563E70() - 1;
    if ( !v1 )
      return 1;
    if ( (unsigned int)(v1 - 1) <= 1 )
      return 2;
  }
  return 0;
}
