void __thiscall sub_431AF0(_DWORD *this)
{
  void *v2; // eax
  void *v3; // eax
  void *v4; // esi

  v2 = (void *)this[1725];
  this[1724] = 0;
  if ( v2 )
    j_j__free(v2);
  v3 = (void *)this[1727];
  this[1725] = 0;
  this[1726] = 0;
  if ( v3 )
    j_j__free(v3);
  this[1727] = 0;
  v4 = (void *)this[26];
  if ( v4 )
    j_j__free(v4);
}
