float *__stdcall sub_55D220(float *a1, float *a2)
{
  double v2; // st7
  double v3; // st6
  int v4; // edx
  double v5; // st5
  int v6; // ecx
  double v7; // st4
  int v8; // ebp
  int v9; // eax
  int v10; // edx
  long double v11; // st7
  long double v12; // st7
  float *v13; // ecx
  float *v14; // ebp
  long double v15; // st7
  long double v16; // st7
  _DWORD v18[3]; // [esp+0h] [ebp-24h]
  int v19; // [esp+Ch] [ebp-18h]

  v2 = *a2;
  v3 = a2[5];
  v4 = *((_DWORD *)a2 + 5);
  v5 = a2[10];
  v6 = *((_DWORD *)a2 + 10);
  v7 = v3 + v2 + v5;
  if ( flt_804158 < v7 )
  {
    v15 = sqrt(v7 + flt_804154) * flt_804150;
    a1[3] = v15;
    v16 = flt_80414C / v15;
    *a1 = (a2[6] - a2[9]) * v16;
    a1[1] = (a2[8] - a2[2]) * v16;
    a1[2] = v16 * (a2[1] - a2[4]);
  }
  else
  {
    *(float *)v18 = *a2;
    v18[1] = v4;
    v18[2] = v6;
    v8 = 2;
    if ( *(float *)&v18[v2 < v3] >= v5 )
      v8 = v2 < v3;
    v9 = dword_804140[v8];
    v19 = v9;
    v10 = dword_804140[v9];
    v11 = sqrt(flt_804154 + *(float *)&v18[v8] - *(float *)&v18[v10] - *(float *)&v18[v9]) * flt_804150;
    a1[v8] = v11;
    v12 = flt_80414C / v11;
    v13 = &a2[v8];
    v14 = &a2[4 * v8];
    a1[v9] = (v14[v9] + v13[4 * v9]) * v12;
    a1[v10] = (v13[4 * v10] + v14[v10]) * v12;
    a1[3] = v12 * (a2[4 * v9 + v10] - a2[4 * v10 + v19]);
  }
  return a1;
}
