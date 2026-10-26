// positive sp value has been detected, the output may be wrong!
void __thiscall sub_616587(_DWORD *this)
{
  void *v2; // eax
  void *v3; // esi

  v2 = (void *)this[5];
  if ( v2 )
    j__free(v2);
  v3 = (void *)this[3];
  if ( v3 )
    j__free(v3);
}
