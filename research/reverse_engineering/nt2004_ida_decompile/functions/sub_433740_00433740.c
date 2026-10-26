double __thiscall sub_433740(int this, double a2)
{
  int v4; // eax
  int v5; // ecx
  unsigned int v6; // edx
  double v7; // st7
  int v8; // edx
  unsigned int v9; // ecx
  unsigned int v10; // edx
  double v11; // st7
  double v12; // st6
  double v13; // st5
  int v14; // edi
  double v15; // st4
  double v16; // st7
  double v17; // [esp+0h] [ebp-B8h]
  double v18; // [esp+0h] [ebp-B8h]
  double v19; // [esp+8h] [ebp-B0h]
  double v20; // [esp+10h] [ebp-A8h]
  double v21; // [esp+10h] [ebp-A8h]
  double v22; // [esp+20h] [ebp-98h]
  double v23; // [esp+20h] [ebp-98h]
  double v24; // [esp+28h] [ebp-90h]
  double v25; // [esp+28h] [ebp-90h]
  int v26[2]; // [esp+30h] [ebp-88h] BYREF
  double v27; // [esp+38h] [ebp-80h] BYREF
  double i; // [esp+40h] [ebp-78h] BYREF
  int v29[2]; // [esp+48h] [ebp-70h] BYREF
  double v30; // [esp+50h] [ebp-68h]
  double v31; // [esp+58h] [ebp-60h]
  double v32; // [esp+60h] [ebp-58h]
  double v33; // [esp+68h] [ebp-50h]
  double v34; // [esp+70h] [ebp-48h]
  double v35; // [esp+78h] [ebp-40h]
  double v36; // [esp+80h] [ebp-38h]
  int v37[2]; // [esp+88h] [ebp-30h] BYREF
  double v38; // [esp+90h] [ebp-28h]
  double v39; // [esp+98h] [ebp-20h]
  double v40; // [esp+A0h] [ebp-18h]
  double v41; // [esp+A8h] [ebp-10h]
  double v42; // [esp+B0h] [ebp-8h]

  if ( !sub_500DC0(byte_7D83E4) )
    return 0.0;
  v4 = sub_5009C0(*(_DWORD *)(this + 3012));
  if ( !v4 )
    return 0.0;
  v27 = (double)*(int *)(this + 3140) * *(double *)(this + 3128) + *(double *)(this + 3120);
  v22 = 1.0 - v27;
  if ( dword_7D9780 )
  {
    if ( dword_7D9780 == 1 )
    {
      v7 = *(double *)(v4 + 1592) + *(double *)(v4 + 568);
      v26[0] = 0;
      v26[1] = 1072693248;
      v29[0] = 4;
      v31 = v7 * 0.5;
      v24 = 0.5
          / (v22 * 0.8200000000000001 + v27 * 1.18)
          * (v27 * *(double *)(v4 + 1568) * 1.18 + v22 * *(double *)(v4 + 544) * 0.8200000000000001);
      sub_4FEAA0(
        (*(double *)(v4 + 1680) + *(double *)(v4 + 656)) * 0.5,
        (*(double *)(v4 + 1688) + *(double *)(v4 + 664)) * 0.5,
        (*(double *)(v4 + 1696) + *(double *)(v4 + 672)) * 0.5);
      v22 = 1.0;
    }
    else
    {
      if ( dword_7D9780 != 2 )
        return 0.0;
      v5 = *(_DWORD *)(v4 + 572);
      LODWORD(v31) = *(_DWORD *)(v4 + 568);
      v6 = *(_DWORD *)(v4 + 544);
      HIDWORD(v31) = v5;
      *(double *)v26 = v22 * 0.8200000000000001;
      v24 = COERCE_DOUBLE(__PAIR64__(*(_DWORD *)(v4 + 548), v6));
      v20 = *(double *)(v4 + 672);
      v19 = *(double *)(v4 + 664);
      v17 = *(double *)(v4 + 656);
      v29[0] = 2;
      sub_4FEAA0(v17, v19, v20);
    }
  }
  else
  {
    v8 = *(_DWORD *)(v4 + 1572);
    LODWORD(v24) = *(_DWORD *)(v4 + 1568);
    HIDWORD(v21) = *(_DWORD *)(v4 + 1700);
    v31 = *(double *)(v4 + 1592) * 0.98;
    v9 = *(_DWORD *)(v4 + 1692);
    HIDWORD(v24) = v8;
    LODWORD(v21) = *(_DWORD *)(v4 + 1696);
    v10 = *(_DWORD *)(v4 + 1688);
    *(double *)v26 = v27 * 1.18;
    v18 = *(double *)(v4 + 1680);
    v29[0] = 2;
    sub_4FEAA0(v18, COERCE_DOUBLE(__PAIR64__(v9, v10)), v21);
    v22 = v27;
  }
  v31 = v31 * 0.98;
  if ( v31 <= 0.0 )
    return 0.0;
  sub_4332D0(this, (int)&dword_7D8360, (float *)&v27, (float *)&i);
  v34 = ((double)*(int *)(this + 3268) * *(double *)(this + 3256) + *(double *)(this + 3248)) * 0.726 + dbl_7D839C;
  v11 = (double)v29[0];
  v12 = (v34 * *(double *)v26 * 9.81 - *(float *)&i * v22 * a2 * a2) / v11;
  if ( v12 <= v42 )
    v13 = v12;
  else
    v13 = v42;
  v14 = 44;
  v15 = (((v38 * v13 + v39) * v13 + v40) * v13 + v41) * v12 * v11 * v24;
  v25 = 0.0;
  v36 = v15;
  do
  {
    if ( !*(_BYTE *)((v14 << 6) + this + 3020) )
      break;
    v32 = sub_431A00((int *)this, v14);
    if ( v32 <= 0.0 )
      return 0.0;
    v33 = 1.0 / v31;
    v23 = v33 * v32 * a2;
    v30 = (double)*(int *)(this + 5508) * *(double *)(this + 5496) + *(double *)(this + 5488);
    if ( v23 <= v30 )
    {
      sub_524050(v23, (int)v37, (int)v26);
      if ( v14 == 44 )
      {
        v30 = (v30 - dbl_7D8A4C) * 0.1000000014901161 + dbl_7D8A4C;
        v35 = (v30 - v23) * 0.1;
        if ( v35 > 0.0 )
        {
          for ( i = v23; i <= v30; i = i + v35 )
          {
            sub_524050(i, (int)v37, (int)v29);
            if ( *(double *)v26 < *(double *)v29 )
            {
              v26[0] = v29[0];
              v26[1] = v29[1];
            }
          }
        }
      }
      v16 = v33 * *(double *)v26 * v32;
      if ( v16 > v36 )
        v16 = v36;
      if ( v25 < v16 )
        v25 = v16;
    }
    ++v14;
  }
  while ( v14 <= 50 );
  return (v25 - *(float *)&v27 * a2 * a2) / v34;
}
