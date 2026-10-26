int __thiscall sub_4407C0(int this, double a2, double *a3)
{
  long double v4; // st7
  double v5; // st5
  double v6; // st5
  long double v7; // st6
  unsigned __int8 v9; // c0
  unsigned __int8 v10; // c3
  int v11; // eax
  int v12; // eax
  int v13; // ecx
  int v14; // eax
  double v15; // st7
  double v16; // st6
  _DWORD *v17; // ecx
  double v18; // st7
  double v19; // st7
  double v20; // st7
  int v21; // eax
  int result; // eax
  double v23; // [esp+8h] [ebp-20h]
  double v24; // [esp+8h] [ebp-20h]
  double v25; // [esp+10h] [ebp-18h] BYREF
  int v26; // [esp+18h] [ebp-10h]
  int v27; // [esp+1Ch] [ebp-Ch]
  int v28; // [esp+20h] [ebp-8h]
  int v29; // [esp+24h] [ebp-4h]

  v4 = fabs(*(double *)(this + 192)) * *(double *)(this + 1120);
  v5 = a3[12] * a3[15] + a3[9] * a3[14] + a3[6] * a3[13];
  if ( v5 >= 0.0 )
    v6 = 0.0;
  else
    v6 = -v5;
  v23 = ((flt_FB1F30 + 273.16 + flt_FB1F2C + 273.16) * 0.5 - *(double *)(this + 1168))
      * (v6 * *(double *)(this + 1200) + *(double *)(this + 1192))
      + v4 * *(double *)(this + 1184);
  if ( *(double *)(this + 1208) <= *(double *)(this + 1232) )
  {
    v15 = v23 / *(double *)(this + 1232);
  }
  else
  {
    v7 = *(double *)(this + 1208)
       - v4
       * (*(double *)(this + 1168)
        * *(double *)(this + 1168)
        * *(double *)(this + 1168)
        * *(double *)(this + 1224))
       * a2;
    *(long double *)(this + 1208) = v7;
    if ( v9 | v10 )
    {
      v11 = 0;
      if ( dword_757C10 > 0 )
      {
        while ( *(_DWORD *)(*(&dword_91E088 + v11) + 14820) )
        {
          if ( ++v11 >= dword_757C10 )
            goto LABEL_12;
        }
        v12 = *(&dword_91E088 + v11);
        v13 = *(_DWORD *)(v12 + 19384);
        v14 = v12 + 19272;
        if ( !v13 )
          *(_DWORD *)(v14 + 112) = 5;
      }
LABEL_12:
      *(double *)(this + 1208) = 0.0;
      *(double *)(this + 1136) = 0.0;
      v15 = 0.0;
    }
    else
    {
      v15 = v23 / v7;
      v24 = v23 / v7;
      v16 = fabs(*(double *)(this + 1168) - *(double *)(this + 1176));
      if ( v16 <= *(double *)(this + 1152) )
      {
        *(long double *)(this + 1136) = (cos(v16 * *(double *)(this + 1160)) * 0.25 + 0.75) * *(double *)(this + 1144);
      }
      else
      {
        if ( *(double *)(this + 1144) * 0.5 < *(double *)(this + 1136) )
        {
          sub_4EE320(29, 0);
          v15 = v24;
        }
        *(double *)(this + 1136) = *(double *)(this + 1144) * 0.5;
      }
    }
  }
  v17 = *(_DWORD **)(this + 352);
  *(double *)(this + 1168) = v15 * a2 + *(double *)(this + 1168);
  v18 = *(double *)(this + 1216);
  LODWORD(v25) = v17[48];
  v19 = v18 * *(double *)(this + 1208);
  HIDWORD(v25) = v17[49];
  v26 = v17[50];
  v27 = v17[51];
  v20 = v19 + *(double *)(this + 208);
  v28 = v17[52];
  v21 = v17[53];
  v25 = v20;
  v29 = v21;
  result = sub_619170(&v25);
  *(double *)(this + 216) = 1.0 / v20;
  return result;
}
