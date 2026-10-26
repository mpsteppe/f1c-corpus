// f1c  0x004c6e80  size=137
int __thiscall sub_4C6E80(_DWORD *this)
{
  _DWORD *v2; // edi
  int i; // edi

  v2 = this + 3;
  sub_410B40(dword_5EA560, (int)(this + 3));
  sub_4E4790(v2);
  sub_4E09E0(this + 444);
  sub_4A4DB0((int)(this + 3251));
  sub_4F83B0(this + 5);
  sub_4BB950((int)(this + 4109));
  for ( i = 0; i < dword_5C329C; ++i )
    sub_42AE20(dword_7C54F0[i], (int)this);
  this[4649] = -1;
  this[4650] = -1;
  sub_4C79E0(this);
  return sub_4D1670(&unk_8ACEE0);
}
