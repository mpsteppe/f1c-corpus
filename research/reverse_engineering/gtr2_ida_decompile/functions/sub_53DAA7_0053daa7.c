// positive sp value has been detected, the output may be wrong!
void __thiscall sub_53DAA7(int *this)
{
  void *v2; // esi

  sub_615860(WindowName);
  sub_510C20(this + 2);
  this[6] = 0;
  sub_510C20(this + 2);
  v2 = (void *)*this;
  if ( v2 )
    j_j__free(v2);
}
