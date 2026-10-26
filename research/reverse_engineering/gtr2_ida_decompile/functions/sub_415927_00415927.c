// positive sp value has been detected, the output may be wrong!
int __thiscall sub_415927(int this)
{
  void *v2; // eax

  v2 = *(void **)(this + 168);
  if ( v2 )
    j_j__free(v2);
  if ( *(_DWORD *)(this + 136) )
    j__free(*(void **)(this + 136));
  ((void (__thiscall *)(int))sub_617060)(this + 76);
  return sub_438450(this + 20);
}
