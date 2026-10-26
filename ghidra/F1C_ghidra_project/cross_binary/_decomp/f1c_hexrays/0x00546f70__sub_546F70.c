// f1c  0x00546f70  size=105
int __thiscall sub_546F70(_DWORD *this, int a2)
{
  int v3; // ecx

  v3 = this[41];
  if ( a2 < v3 && v3 < 8 )
  {
    sub_54FC40(&unk_800000);
    sub_54FC80(0, 0);
    sub_54FD30(1065353216, 1065353216);
    sub_54FCA0(2);
    this[39] |= 0x80u;
  }
  return 0;
}
