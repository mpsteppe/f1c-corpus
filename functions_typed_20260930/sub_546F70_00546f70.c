int __thiscall sub_546F70(_DWORD *this, int a2)
{
  int v3; // ecx

  v3 = this[41];
  if ( a2 < v3 && v3 < 8 )
  {
    SimpleSetter_fc40(&unk_800000);
    DualFieldSetter(0, 0);
    ShortComputation_fd30(1065353216, 1065353216);
    FieldSetter_fca0(2);
    this[39] |= 0x80u;
  }
  return 0;
}

