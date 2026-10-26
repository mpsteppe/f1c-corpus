// positive sp value has been detected, the output may be wrong!
void __thiscall sub_53C1D7(int *this)
{
  void *v2; // esi

  sub_615860(WindowName);
  sub_525140(this + 2);
  this[6] = 0;
  sub_525140(this + 2);
  v2 = (void *)*this;
  if ( v2 )
    j_j__free(v2);
}
