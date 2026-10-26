int __thiscall sub_43B590(int this, int a2, int a3)
{
  int v4; // esi
  _DWORD *v5; // ecx
  int v6; // eax
  _DWORD *v7; // ecx
  long double v8; // st7
  double v9; // st6
  long double v10; // st7
  int result; // eax
  long double v12; // st7
  int v13; // [esp-8h] [ebp-B0h]
  int v14; // [esp-8h] [ebp-B0h]
  double v15[3]; // [esp+10h] [ebp-98h] BYREF
  long double v16; // [esp+28h] [ebp-80h]
  double v17; // [esp+30h] [ebp-78h] BYREF
  double v18; // [esp+38h] [ebp-70h]
  double v19; // [esp+40h] [ebp-68h]
  double v20[3]; // [esp+48h] [ebp-60h] BYREF
  double v21; // [esp+60h] [ebp-48h] BYREF
  double v22; // [esp+68h] [ebp-40h]
  double v23; // [esp+70h] [ebp-38h]
  double v24[3]; // [esp+78h] [ebp-30h] BYREF
  double v25[3]; // [esp+90h] [ebp-18h] BYREF

  SuspensionBarLookup((int)aFlSteering, *(_DWORD *)(this + 1004), (int)v25);
  SuspensionBarLookup((int)aFrSteering, *(_DWORD *)(this + 2128), (int)v20);
  v4 = *(_DWORD *)(this + 5616);
  F_3DVectorTransformBy33Matrix((double *)(v4 + 28), (double *)(v4 + 4), v25, v24);
  F_3DVectorTransformBy33Matrix((double *)(v4 + 28), (double *)(v4 + 4), v20, v25);
  v5 = *(_DWORD **)(this + 5680);
  *(_DWORD *)(this + 5684) = *v5;
  v6 = v5[1];
  v7 = *(_DWORD **)(this + 5700);
  *(_DWORD *)(this + 5688) = v6;
  *(_DWORD *)(this + 5704) = *v7;
  *(_DWORD *)(this + 5708) = v7[1];
  v8 = (double)*(int *)(a2 + 5188) * *(double *)(a2 + 5176) + *(double *)(a2 + 5168);
  if ( v8 <= 0.0 )
  {
    *(_DWORD *)(this + 140) = 0;
    *(_DWORD *)(this + 144) = 0;
  }
  else
  {
    *(long double *)(this + 140) = 1.0 / v8;
  }
  LODWORD(v16) = *(_DWORD *)(a2 + 5184) - 1;
  v9 = (double)SLODWORD(v16) * *(double *)(a2 + 5176) + *(double *)(a2 + 5168);
  if ( v9 <= 0.0 )
  {
    *(_DWORD *)(this + 132) = 0;
    *(_DWORD *)(this + 136) = 0;
  }
  else
  {
    *(long double *)(this + 132) = v8 / v9;
  }
  *(_DWORD *)(this + 164) = 0;
  *(_DWORD *)(this + 168) = 0;
  v13 = *(_DWORD *)(this + 1004);
  v16 = fabs(sin(v8));
  *(long double *)(this + 148) = v8 * -0.5;
  SuspensionBarLookup((int)aFlForeUpper, v13, (int)&v17);
  SuspensionBarLookup((int)aFlForeLower, *(_DWORD *)(this + 1004), (int)&v21);
  v20[0] = v17 - v21;
  v20[1] = v18 - v22;
  v20[2] = v19 - v23;
  qmemcpy(v15, v20, sizeof(v15));
  v10 = 1.0 / sqrt(v20[2] * v20[2] + v20[1] * v20[1] + v20[0] * v20[0]);
  v15[0] = v20[0] * v10;
  v15[1] = v15[1] * v10;
  v15[2] = v15[2] * v10;
  v20[1] = v15[2] * -1.0 - v15[0] * 0.0;
  v14 = *(_DWORD *)(this + 2128);
  *(long double *)(this + 5692) = -(fabs(
                                      (v24[2] - v19) * (v15[0] * 0.0 - v15[1] * -1.0)
                                    + (v24[1] - v18) * v20[1]
                                    + (v24[0] - v17) * (v15[1] * 0.0 - v15[2] * 0.0))
                                  * v16);
  SuspensionBarLookup((int)aFrForeUpper, v14, (int)&v17);
  result = SuspensionBarLookup((int)aFrForeLower, *(_DWORD *)(this + 2128), (int)&v21);
  v24[0] = v17 - v21;
  v24[1] = v18 - v22;
  v24[2] = v19 - v23;
  qmemcpy(v15, v24, sizeof(v15));
  v12 = 1.0 / sqrt(v24[2] * v24[2] + v24[1] * v24[1] + v24[0] * v24[0]);
  v15[0] = v24[0] * v12;
  v15[1] = v15[1] * v12;
  v15[2] = v15[2] * v12;
  v20[1] = v15[2] * -1.0 - v15[0] * 0.0;
  *(long double *)(this + 5712) = -(fabs(
                                      (v25[2] - v19) * (v15[0] * 0.0 - v15[1] * -1.0)
                                    + (v25[1] - v18) * v20[1]
                                    + (v25[0] - v17) * (v15[1] * 0.0 - v15[2] * 0.0))
                                  * v16);
  return result;
}
