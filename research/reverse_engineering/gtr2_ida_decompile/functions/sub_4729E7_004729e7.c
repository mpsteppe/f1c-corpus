// positive sp value has been detected, the output may be wrong!
int __thiscall sub_4729E7(void **this)
{
  sub_568880();
  if ( this[12] )
    j_j__free(this[12]);
  if ( this[10] )
    j_j__free(this[10]);
  return ((int (__thiscall *)(void **))sub_567D00)(this);
}
