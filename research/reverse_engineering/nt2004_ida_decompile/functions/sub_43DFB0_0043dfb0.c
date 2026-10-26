int __thiscall sub_43DFB0(int this, int a2, int a3)
{
  int v4; // esi
  _DWORD *v5; // ecx
  int v6; // eax
  _DWORD *v7; // ecx
  double v8; // st7
  double v9; // st7
  long double v10; // st7
  int v11; // ecx
  int result; // eax
  long double v13; // st7
  int v14; // [esp-8h] [ebp-B0h]
  double v15[3]; // [esp+10h] [ebp-98h] BYREF
  long double v16; // [esp+28h] [ebp-80h]
  int v17[2]; // [esp+30h] [ebp-78h] BYREF
  double v18; // [esp+38h] [ebp-70h]
  double v19; // [esp+40h] [ebp-68h]
  int v20[6]; // [esp+48h] [ebp-60h] BYREF
  int v21[2]; // [esp+60h] [ebp-48h] BYREF
  double v22; // [esp+68h] [ebp-40h]
  double v23; // [esp+70h] [ebp-38h]
  double v24[3]; // [esp+78h] [ebp-30h] BYREF
  int v25[2]; // [esp+90h] [ebp-18h] BYREF
  double v26; // [esp+98h] [ebp-10h]
  double v27; // [esp+A0h] [ebp-8h]

  sub_43D970(aFlSteering, *(_DWORD *)(this + 1020), (int)v25);
  sub_43D970(aFrSteering, *(_DWORD *)(this + 2276), (int)v20);
  v4 = *(_DWORD *)(this + 6164);
  sub_4388F0((double *)(v4 + 28), (double *)(v4 + 4), (double *)v25, v24);
  sub_4388F0((double *)(v4 + 28), (double *)(v4 + 4), (double *)v20, (double *)v25);
  v5 = *(_DWORD **)(this + 6228);
  *(_DWORD *)(this + 6232) = *v5;
  v6 = v5[1];
  v7 = *(_DWORD **)(this + 6248);
  *(_DWORD *)(this + 6236) = v6;
  *(_DWORD *)(this + 6252) = *v7;
  *(_DWORD *)(this + 6256) = v7[1];
  *(double *)(this + 112) = (double)*(int *)(a2 + 5188) * *(double *)(a2 + 5176) + *(double *)(a2 + 5168);
  LODWORD(v16) = *(_DWORD *)(a2 + 5184) - 1;
  v8 = (double)SLODWORD(v16) * *(double *)(a2 + 5176) + *(double *)(a2 + 5168);
  *(double *)(this + 96) = v8;
  if ( v8 <= 0.0 )
  {
    *(_DWORD *)(this + 104) = 0;
    *(_DWORD *)(this + 108) = 0;
  }
  else
  {
    *(double *)(this + 104) = 1.0 / v8;
  }
  v9 = *(double *)(this + 104) * *(double *)(this + 112);
  v14 = *(_DWORD *)(this + 1020);
  *(_DWORD *)(this + 180) = 0;
  *(double *)(this + 120) = v9;
  *(_DWORD *)(this + 184) = 0;
  v16 = fabs(sin(*(double *)(this + 96)));
  *(double *)(this + 164) = *(double *)(this + 96) * -0.5;
  sub_43D970(aFlForeUpper, v14, (int)v17);
  sub_43D970(aFlForeLower, *(_DWORD *)(this + 1020), (int)v21);
  *(double *)v20 = *(double *)v17 - *(double *)v21;
  *(double *)&v20[2] = v18 - v22;
  *(double *)&v20[4] = v19 - v23;
  qmemcpy(v15, v20, sizeof(v15));
  v10 = 1.0
      / sqrt(
          *(double *)&v20[4] * *(double *)&v20[4]
        + *(double *)&v20[2] * *(double *)&v20[2]
        + *(double *)v20 * *(double *)v20);
  v15[0] = *(double *)v20 * v10;
  v15[1] = v15[1] * v10;
  v15[2] = v15[2] * v10;
  v11 = *(_DWORD *)(this + 2276);
  *(double *)&v20[2] = v15[2] * -1.0 - v15[0] * 0.0;
  *(long double *)(this + 6240) = -(fabs(
                                      (v24[2] - v19) * (v15[0] * 0.0 - v15[1] * -1.0)
                                    + (v24[1] - v18) * *(double *)&v20[2]
                                    + (v24[0] - *(double *)v17) * (v15[1] * 0.0 - v15[2] * 0.0))
                                  * v16);
  sub_43D970(aFrForeUpper, v11, (int)v17);
  result = sub_43D970(aFrForeLower, *(_DWORD *)(this + 2276), (int)v21);
  v24[0] = *(double *)v17 - *(double *)v21;
  v24[1] = v18 - v22;
  v24[2] = v19 - v23;
  qmemcpy(v15, v24, sizeof(v15));
  v13 = 1.0 / sqrt(v24[2] * v24[2] + v24[1] * v24[1] + v24[0] * v24[0]);
  v15[0] = v24[0] * v13;
  v15[1] = v15[1] * v13;
  v15[2] = v15[2] * v13;
  *(double *)&v20[2] = v15[2] * -1.0 - v15[0] * 0.0;
  *(long double *)(this + 6260) = -(fabs(
                                      (v27 - v19) * (v15[0] * 0.0 - v15[1] * -1.0)
                                    + (v26 - v18) * *(double *)&v20[2]
                                    + (*(double *)v25 - *(double *)v17) * (v15[1] * 0.0 - v15[2] * 0.0))
                                  * v16);
  return result;
}
