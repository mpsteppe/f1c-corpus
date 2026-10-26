void __thiscall sub_59BAA3(_DWORD *this)
{
  void *v2; // esi

  *this = &off_5B9DB8;
  CriticalSectionLazyInitEnter(27);
  v2 = (void *)this[1];
  if ( v2 )
    sub_58AA6F(v2);
  CritSectLeave(27);
}

