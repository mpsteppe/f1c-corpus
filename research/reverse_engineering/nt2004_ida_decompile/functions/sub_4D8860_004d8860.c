char __thiscall sub_4D8860(float *this, _DWORD *a2)
{
  char v3; // bl

  v3 = 1;
  if ( this[516] - this[515] <= 0.0 )
    return 0;
  sub_4EFA90(-1.0);
  sub_4D89D0(*a2, 0);
  sub_4DA510(&dword_7D5DA4);
  sub_4F78B0(&unk_7D73D0);
  sub_404B10((int)&flt_628F60);
  sub_4FCB50(&unk_7D7428);
  sub_458570((float *)&ppvOut);
  sub_42E720(&unk_62BF64);
  sub_40C3D0(&dword_6291CC);
  sub_4F0020(&byte_7D6B78);
  sub_4D2430(byte_7D4458);
  sub_4B7AB0(&dword_765E70);
  sub_528430(&unk_7DA938);
  sub_4BB880();
  if ( dword_763B58 || (dword_761FF8 & 1) != 0 && (byte_7620FD & 2) != 0 || sub_4D83C0(this) >= this[516] )
    return 0;
  return v3;
}
