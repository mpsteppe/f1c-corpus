// f1c  0x00569de0  size=878
double __thiscall sub_569DE0(int this, double a2)
{
  double v3; // st7
  double v4; // st4
  long double v5; // st7
  long double v6; // st6
  long double v7; // st7
  double v8; // st7
  double v9; // st4
  double v10; // st3
  double v11; // st4
  double v12; // st3
  long double v13; // st7
  long double v14; // st3
  double v15; // st5
  long double v16; // st7
  long double v17; // st7
  double v18; // st6
  double v19; // st7
  double v21; // [esp+10h] [ebp-30h]
  double v22; // [esp+18h] [ebp-28h]
  double v23; // [esp+20h] [ebp-20h]
  double v24[3]; // [esp+28h] [ebp-18h] BYREF

  v3 = *(double *)(this + 308) - *(double *)(this + 500);
  v21 = 1.0;
  v4 = *(double *)(this + 324) - *(double *)(this + 516);
  v5 = v4 * v4
     + (*(double *)(this + 316) - *(double *)(this + 508)) * (*(double *)(this + 316) - *(double *)(this + 508))
     + v3 * v3;
  v6 = *(double *)(this + 500) * *(double *)(this + 500)
     + *(double *)(this + 508) * *(double *)(this + 508)
     + *(double *)(this + 516) * *(double *)(this + 516);
  if ( v5 > 0.25 * v6 )
  {
    v7 = sqrt(v5) / (sqrt(v6) + *(double *)(this + 172) * 128.0);
    if ( v7 > 0.5 )
    {
      v8 = 0.5 / v7;
      if ( v8 < 1.0 )
        v21 = v8;
    }
  }
  v9 = *(double *)(this + 348) - *(double *)(this + 540);
  v10 = *(double *)(this + 340) - *(double *)(this + 532);
  v11 = v9 * v9 + v10 * v10;
  v12 = *(double *)(this + 332) - *(double *)(this + 524);
  v13 = v11 + v12 * v12;
  v14 = *(double *)(this + 524) * *(double *)(this + 524)
      + *(double *)(this + 532) * *(double *)(this + 532)
      + *(double *)(this + 540) * *(double *)(this + 540);
  if ( v13 > 0.25 * v14 )
  {
    v15 = *(double *)(this + 204);
    v22 = *(double *)(this + 188);
    v23 = *(double *)(this + 196);
    if ( v22 >= v23 )
    {
      if ( v23 < v15 )
        v15 = v23;
    }
    else if ( v22 < v15 )
    {
      v15 = v22;
    }
    v16 = sqrt(v13) / (sqrt(v14) + v15 * 128.0);
    if ( v16 > 0.5 )
    {
      v17 = 0.5 / v16;
      if ( v17 < v21 )
        v21 = v17;
    }
  }
  *(double *)(this + 4) = a2 * *(double *)(this + 100) + *(double *)(this + 356);
  *(double *)(this + 12) = a2 * *(double *)(this + 108) + *(double *)(this + 364);
  *(double *)(this + 20) = a2 * *(double *)(this + 116) + *(double *)(this + 372);
  v18 = a2 * *(double *)(this + 180);
  *(double *)(this + 100) = v18 * *(double *)(this + 308) + *(double *)(this + 452);
  *(double *)(this + 108) = v18 * *(double *)(this + 316) + *(double *)(this + 460);
  *(double *)(this + 116) = v18 * *(double *)(this + 324) + *(double *)(this + 468);
  v24[0] = a2 * *(double *)(this + 124);
  v24[1] = a2 * *(double *)(this + 132);
  v19 = a2 * *(double *)(this + 140);
  qmemcpy((void *)(this + 28), (const void *)(this + 380), 0x48u);
  v24[2] = v19;
  sub_56C020(v24);
  *(double *)(this + 148) = a2 * *(double *)(this + 332) + *(double *)(this + 476);
  *(double *)(this + 156) = a2 * *(double *)(this + 340) + *(double *)(this + 484);
  *(double *)(this + 164) = a2 * *(double *)(this + 348) + *(double *)(this + 492);
  sub_5692A0(this);
  *(double *)(this + 124) = *(double *)(this + 252) * *(double *)(this + 164)
                          + *(double *)(this + 244) * *(double *)(this + 156)
                          + *(double *)(this + 236) * *(double *)(this + 148);
  *(double *)(this + 132) = *(double *)(this + 260) * *(double *)(this + 148)
                          + *(double *)(this + 276) * *(double *)(this + 164)
                          + *(double *)(this + 268) * *(double *)(this + 156);
  *(double *)(this + 140) = *(double *)(this + 284) * *(double *)(this + 148)
                          + *(double *)(this + 300) * *(double *)(this + 164)
                          + *(double *)(this + 292) * *(double *)(this + 156);
  return v21;
}
