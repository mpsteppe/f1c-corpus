// f1c  0x0056a240  size=334
int __thiscall sub_56A240(int this)
{
  double v2; // st7
  double v3; // st6
  double v4; // st7
  double v5; // st6
  double v6; // st7
  double v8[2]; // [esp+8h] [ebp-30h] BYREF
  double v9; // [esp+18h] [ebp-20h]
  double v10[3]; // [esp+20h] [ebp-18h] BYREF

  v2 = *(double *)(this + 164) * *(double *)(this + 132) - *(double *)(this + 156) * *(double *)(this + 140);
  v3 = *(double *)(this + 140) * *(double *)(this + 148) - *(double *)(this + 164) * *(double *)(this + 124);
  v9 = *(double *)(this + 156) * *(double *)(this + 124) - *(double *)(this + 132) * *(double *)(this + 148);
  v10[0] = *(double *)(this + 332) - v2;
  v4 = *(double *)(this + 340) - v3;
  v5 = *(double *)(this + 348) - v9;
  v8[0] = v5 * *(double *)(this + 252) + v4 * *(double *)(this + 244) + v10[0] * *(double *)(this + 236);
  v8[1] = v5 * *(double *)(this + 276) + v4 * *(double *)(this + 268) + v10[0] * *(double *)(this + 260);
  v9 = v5 * *(double *)(this + 300) + v4 * *(double *)(this + 292) + v10[0] * *(double *)(this + 284);
  v6 = *(double *)(this + 180);
  v10[0] = v6 * *(double *)(this + 308);
  v10[1] = v6 * *(double *)(this + 316);
  v10[2] = v6 * *(double *)(this + 324);
  sub_56A390(v8, v10);
  sub_56A5D0(v8);
  sub_56A840(v8, v10);
  sub_56AA60(this);
  sub_56B5D0(this);
  return sub_56BAF0(this);
}
