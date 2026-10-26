void __thiscall sub_431A70(_DWORD *this)
{
  void *v2; // eax
  void *v3; // eax

  v2 = (void *)this[1];
  *this = 0;
  if ( v2 )
    j_j__free(v2);
  v3 = (void *)this[3];
  this[1] = 0;
  this[2] = 0;
  if ( v3 )
    j_j__free(v3);
  this[3] = 0;
}
