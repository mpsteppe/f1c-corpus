int __thiscall sub_4503F0(int this)
{
  double v2; // st7
  double v3; // st7
  double v4; // st7
  double v5; // st7
  double v6; // st7
  double v7; // st7
  double v8; // st7
  double v9; // st7
  double v10; // st7
  double v11; // st7
  double v13; // [esp+8h] [ebp-8h]
  double v14; // [esp+8h] [ebp-8h]
  double v15; // [esp+8h] [ebp-8h]
  double v16; // [esp+8h] [ebp-8h]
  double v17; // [esp+8h] [ebp-8h]
  double v18; // [esp+8h] [ebp-8h]
  double v19; // [esp+8h] [ebp-8h]

  v13 = *(double *)(this + 8568);
  v2 = v13;
  if ( v13 <= *(double *)(this + 7224) )
  {
    if ( *(double *)(this + 7224) <= v13 )
      goto LABEL_5;
    v2 = v13;
  }
  *(double *)(this + 7224) = v2;
LABEL_5:
  v14 = *(double *)(this + 8576);
  v3 = v14;
  if ( v14 <= *(double *)(this + 7248) )
  {
    if ( *(double *)(this + 7248) <= v14 )
      goto LABEL_9;
    v3 = v14;
  }
  *(double *)(this + 7248) = v3;
LABEL_9:
  v4 = *(double *)(this + 8560);
  *(double *)(this + 7680) = v4 * *(double *)(this + 7240) * v4
                           + v4 * *(double *)(this + 7232)
                           + *(double *)(this + 7224);
  *(double *)(this + 7888) = v4 * *(double *)(this + 7264) * v4
                           + v4 * *(double *)(this + 7256)
                           + *(double *)(this + 7248);
  v15 = *(double *)(this + 8592);
  v5 = v15;
  if ( v15 <= *(double *)(this + 7320) )
  {
    if ( *(double *)(this + 7320) <= v15 )
      goto LABEL_13;
    v5 = v15;
  }
  *(double *)(this + 7320) = v5;
LABEL_13:
  v16 = *(double *)(this + 8600);
  v6 = v16;
  if ( v16 <= *(double *)(this + 7336) )
  {
    if ( *(double *)(this + 7336) <= v16 )
      goto LABEL_17;
    v6 = v16;
  }
  *(double *)(this + 7336) = v6;
LABEL_17:
  v7 = *(double *)(this + 8584);
  *(double *)(this + 8344) = v7 * *(double *)(this + 7328) + *(double *)(this + 7320);
  *(double *)(this + 8160) = v7 * *(double *)(this + 7344) + *(double *)(this + 7336);
  *(double *)(this + 8984) = v7 * *(double *)(this + 7360) + *(double *)(this + 7352);
  v17 = *(double *)(this + 8608);
  v8 = v17;
  if ( v17 <= *(double *)(this + 8392) )
  {
    if ( *(double *)(this + 8392) <= v17 )
      goto LABEL_21;
    v8 = v17;
  }
  *(double *)(this + 8392) = v8;
LABEL_21:
  v18 = *(double *)(this + 8624);
  v9 = v18;
  if ( v18 <= *(double *)(this + 7272) )
  {
    if ( *(double *)(this + 7272) <= v18 )
      goto LABEL_25;
    v9 = v18;
  }
  *(double *)(this + 7272) = v9;
LABEL_25:
  v19 = *(double *)(this + 8632);
  v10 = v19;
  if ( v19 > *(double *)(this + 7296) )
  {
LABEL_28:
    *(double *)(this + 7296) = v10;
    goto LABEL_29;
  }
  if ( *(double *)(this + 7296) > v19 )
  {
    v10 = v19;
    goto LABEL_28;
  }
LABEL_29:
  v11 = *(double *)(this + 8616);
  *(double *)(this + 7928) = v11 * *(double *)(this + 7288) * v11
                           + v11 * *(double *)(this + 7280)
                           + *(double *)(this + 7272);
  *(double *)(this + 8128) = v11 * *(double *)(this + 7312) * v11
                           + v11 * *(double *)(this + 7304)
                           + *(double *)(this + 7296);
  sub_4474F0((_DWORD *)this, 0);
  sub_4474F0((_DWORD *)this, 1);
  sub_4474F0((_DWORD *)this, 2);
  sub_4474F0((_DWORD *)this, 3);
  return sub_4FB7E0(*(_DWORD *)(this + 9392) + 14824, 0, 8);
}
