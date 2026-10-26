int __thiscall sub_43AF90(int this, double a2, int a3)
{
  double v4; // st7
  double v5; // st7
  double v6; // st6
  unsigned __int8 v8; // c0
  unsigned __int8 v9; // c3
  int v10; // eax
  int v11; // eax
  int v12; // ecx
  int v13; // eax
  double v14; // st7
  double v15; // st6
  const void *v16; // esi
  int result; // eax
  double v18; // [esp+10h] [ebp-40h]
  double v19; // [esp+10h] [ebp-40h]
  double v20; // [esp+18h] [ebp-38h]
  double v21; // [esp+18h] [ebp-38h]
  _BYTE v22[16]; // [esp+20h] [ebp-30h] BYREF
  double v23; // [esp+30h] [ebp-20h]
  double v24[3]; // [esp+38h] [ebp-18h] BYREF

  v20 = fabs(*(double *)(this + 188)) * *(double *)(this + 1112);
  v18 = v20 * *(double *)(this + 1176);
  sub_43B1D0(a3 + 100, v22);
  if ( v23 >= 0.0 )
    v4 = 0.0;
  else
    v4 = -v23;
  v5 = ((flt_7DAB0C + 273.16 + flt_7DAB10 + 273.16) * 0.5 - *(double *)(this + 1160))
     * (v4 * *(double *)(this + 1192) + *(double *)(this + 1184))
     + v18;
  if ( *(double *)(this + 1200) <= *(double *)(this + 1224) )
  {
    v14 = v5 / *(double *)(this + 1224);
  }
  else
  {
    v6 = *(double *)(this + 1200)
       - *(double *)(this + 1160)
       * *(double *)(this + 1160)
       * *(double *)(this + 1160)
       * *(double *)(this + 1216)
       * v20
       * a2;
    *(double *)(this + 1200) = v6;
    if ( v8 | v9 )
    {
      v10 = 0;
      if ( (int)NumOfElements > 0 )
      {
        while ( *(_DWORD *)(dword_75AAD0[v10] + 16584) )
        {
          if ( ++v10 >= (int)NumOfElements )
            goto LABEL_12;
        }
        v11 = dword_75AAD0[v10];
        v12 = *(_DWORD *)(v11 + 20896);
        v13 = v11 + 20836;
        if ( !v12 )
          *(_DWORD *)(v13 + 60) = 5;
      }
LABEL_12:
      v14 = 0.0;
      *(_DWORD *)(this + 1200) = 0;
      *(_DWORD *)(this + 1204) = 0;
      *(_DWORD *)(this + 1128) = 0;
      *(_DWORD *)(this + 1132) = 0;
    }
    else
    {
      v19 = v5 / v6;
      v14 = v19;
      v15 = fabs(*(double *)(this + 1160) - *(double *)(this + 1168));
      if ( v15 <= *(double *)(this + 1144) )
      {
        *(long double *)(this + 1128) = (cos(v15 * *(double *)(this + 1152)) * 0.25 + 0.75) * *(double *)(this + 1136);
      }
      else
      {
        if ( *(double *)(this + 1136) * 0.5 < *(double *)(this + 1128) )
        {
          sub_41BDD0();
          v14 = v19;
        }
        *(double *)(this + 1128) = *(double *)(this + 1136) * 0.5;
      }
    }
  }
  v16 = (const void *)(*(_DWORD *)(this + 348) + 188);
  *(double *)(this + 1160) = v14 * a2 + *(double *)(this + 1160);
  qmemcpy(v24, v16, sizeof(v24));
  v24[0] = *(double *)(this + 1208) * *(double *)(this + 1200) + *(double *)(this + 204);
  v21 = v24[0];
  result = sub_57C530(v24);
  *(double *)(this + 212) = 1.0 / v21;
  return result;
}
