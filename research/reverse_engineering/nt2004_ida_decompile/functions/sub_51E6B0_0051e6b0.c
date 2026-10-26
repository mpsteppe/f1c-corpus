char __thiscall sub_51E6B0(float *this)
{
  int v3; // eax
  unsigned __int8 v5; // c0
  unsigned __int8 v6; // c2

  if ( sub_4EED40(*(_DWORD **)this) )
    return byte_76082D & byte_76082C;
  v3 = *((_DWORD *)this + 4333);
  if ( v3 < 2 || v3 > 4 || v5 | v6 && sub_51C6B0(this) )
    return 0;
  else
    return *((_BYTE *)this + 18824);
}
