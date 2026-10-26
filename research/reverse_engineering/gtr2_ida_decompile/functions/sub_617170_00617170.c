int __thiscall sub_617170(_DWORD *this)
{
  void *v2; // eax

  *this = &off_72EAA4;
  v2 = (void *)this[29];
  if ( v2 )
    j__free(v2);
  this[29] = 0;
  sub_618530(this + 24);
  return sub_614140();
}
