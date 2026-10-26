// f1c  0x0053ab20  size=78
int *__thiscall sub_53AB20(int *this, int a2, int a3)
{
  *this = a2;
  this[1] = sub_587BDC(__FYL2X__((double)a2, 0.6931471805599453094) * 1.442695036924675);
  this[3] = sub_587C03(8 * a2 + 16);
  this[5] = 0;
  this[4] = 0;
  sub_53AB80(a3);
  return this;
}
