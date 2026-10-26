int __thiscall sub_546FE0(_DWORD *this, int a2)
{
  int v2; // edx

  v2 = this[41];
  if ( a2 < v2 && v2 < 8 )
  {
    SimpleSetter_fc40(0x400000);
    DualFieldSetter(0, 0);
    ShortComputation_fd30(1065353216, 1065353216);
    FieldSetter_fca0(4);
  }
  return 0;
}
