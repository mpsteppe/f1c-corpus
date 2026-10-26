int __thiscall sub_57C9A0(int this, double a2)
{
  double v3; // st6
  double v4; // st6
  double v5; // st6
  double v6; // st6
  double v7; // st5
  double v8; // st5
  double v9; // st6
  int result; // eax
  double v11[3]; // [esp+4h] [ebp-18h] BYREF

  v3 = a2 * *(double *)(this + 100) + *(double *)(this + 4);
  qmemcpy((void *)(this + 356), (const void *)(this + 4), 0x18u);
  *(double *)(this + 4) = v3;
  v4 = a2 * *(double *)(this + 108) + *(double *)(this + 12);
  qmemcpy((void *)(this + 380), (const void *)(this + 28), 0x48u);
  *(double *)(this + 12) = v4;
  v5 = a2 * *(double *)(this + 116) + *(double *)(this + 20);
  qmemcpy((void *)(this + 452), (const void *)(this + 100), 0x18u);
  *(double *)(this + 20) = v5;
  v6 = a2 * *(double *)(this + 180);
  v7 = v6 * *(double *)(this + 308) + *(double *)(this + 100);
  qmemcpy((void *)(this + 476), (const void *)(this + 148), 0x18u);
  *(double *)(this + 100) = v7;
  v8 = v6 * *(double *)(this + 316) + *(double *)(this + 108);
  qmemcpy((void *)(this + 500), (const void *)(this + 308), 0x18u);
  *(double *)(this + 108) = v8;
  v9 = v6 * *(double *)(this + 324) + *(double *)(this + 116);
  qmemcpy((void *)(this + 524), (const void *)(this + 332), 0x18u);
  *(double *)(this + 116) = v9;
  v11[0] = a2 * *(double *)(this + 124);
  v11[1] = a2 * *(double *)(this + 132);
  v11[2] = a2 * *(double *)(this + 140);
  sub_57EDB0(v11);
  *(double *)(this + 148) = a2 * *(double *)(this + 332) + *(double *)(this + 148);
  *(double *)(this + 156) = a2 * *(double *)(this + 340) + *(double *)(this + 156);
  *(double *)(this + 164) = a2 * *(double *)(this + 348) + *(double *)(this + 164);
  result = sub_57C030(this);
  *(double *)(this + 124) = *(double *)(this + 252) * *(double *)(this + 164)
                          + *(double *)(this + 244) * *(double *)(this + 156)
                          + *(double *)(this + 236) * *(double *)(this + 148);
  *(double *)(this + 132) = *(double *)(this + 276) * *(double *)(this + 164)
                          + *(double *)(this + 268) * *(double *)(this + 156)
                          + *(double *)(this + 260) * *(double *)(this + 148);
  *(double *)(this + 140) = *(double *)(this + 300) * *(double *)(this + 164)
                          + *(double *)(this + 292) * *(double *)(this + 156)
                          + *(double *)(this + 284) * *(double *)(this + 148);
  return result;
}
