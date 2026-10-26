bool __thiscall sub_45AD90(float *this, float *a2)
{
  double v2; // st7
  int v3; // ebx
  double v4; // st6
  double *v5; // edi
  float *v6; // edx
  double v8; // st6
  float *v9; // esi
  unsigned __int8 v10; // c2
  unsigned __int8 v11; // c3
  double v12; // st6
  double v13; // st5
  double v14; // st6
  double v15; // st5
  double v16; // st6
  double v17; // st5
  double v18; // st6
  int v20; // edi
  float *v21; // ebx
  double *v22; // esi
  int v23; // ecx
  float *v24; // edx
  double v25; // [esp+10h] [ebp-98h]
  double v26; // [esp+18h] [ebp-90h] BYREF
  double v27; // [esp+20h] [ebp-88h] BYREF
  double v28; // [esp+28h] [ebp-80h] BYREF
  double v29; // [esp+30h] [ebp-78h]
  double v30; // [esp+38h] [ebp-70h] BYREF
  double v31; // [esp+40h] [ebp-68h]
  double v32; // [esp+48h] [ebp-60h]
  double v33; // [esp+50h] [ebp-58h]
  double v34; // [esp+58h] [ebp-50h] BYREF
  double v35; // [esp+60h] [ebp-48h] BYREF
  double v36[2]; // [esp+68h] [ebp-40h] BYREF
  double v37[2]; // [esp+78h] [ebp-30h] BYREF
  double v38[2]; // [esp+88h] [ebp-20h] BYREF
  _DWORD v39[3]; // [esp+9Ch] [ebp-Ch]

  v2 = *a2 - 0.01;
  v3 = 0;
  v4 = a2[1] + 0.01;
  v39[0] = 1;
  v39[1] = 2;
  v32 = v4;
  v39[2] = 0;
  v5 = &v27;
  v6 = this + 14;
  v25 = a2[2] - 0.01;
  v33 = a2[3] + 0.01;
  do
  {
    v8 = this[3 * v39[v3] + 12];
    v9 = &this[3 * v39[v3] + 12];
    if ( v11 | v10 )
    {
      if ( 0.0 == v8 )
        return 1;
      v16 = -(*(v6 - 2) / *v9);
      v17 = v9[1] * v16 + *(v6 - 1);
      if ( v17 == 0.0 )
        return 1;
      v18 = (v16 * v9[2] + *v6) / v17;
      *v5 = v18;
      v15 = (v9[2] - v9[1] * v18) / *v9;
    }
    else
    {
      v12 = -(v8 / *(v6 - 2));
      v13 = *(v6 - 1) * v12 + v9[1];
      if ( v13 == 0.0 )
        return 1;
      v14 = (v12 * *v6 + v9[2]) / v13;
      *v5 = v14;
      v15 = (*v6 - *(v6 - 1) * v14) / *(v6 - 2);
    }
    *(v5 - 1) = v15;
    if ( v2 <= *(v5 - 1) && *(v5 - 1) <= v32 && *v5 >= v25 && *v5 < v33 )
      return 1;
    ++v3;
    v6 += 3;
    v5 += 2;
  }
  while ( v3 < 3 );
  if ( v26 < v2 && v28 < v2 && v30 < v2
    || v26 > v32 && v28 > v32 && v30 > v32
    || v27 < v25 && v29 < v25 && v31 < v25
    || v27 > v33 && v29 > v33 && v31 > v33 )
  {
    return 0;
  }
  v34 = v2;
  v20 = 0;
  v21 = this + 13;
  v35 = v25;
  v22 = &v35;
  v36[0] = v2;
  v36[1] = v33;
  v37[0] = v32;
  v37[1] = v33;
  v38[0] = v32;
  v38[1] = v25;
LABEL_28:
  v23 = 0;
  v24 = v21;
  while ( v24[1] < *(v24 - 1) * *(v22 - 1) + *v24 * *v22 )
  {
    ++v23;
    v24 += 3;
    if ( v23 >= 3 )
    {
      ++v20;
      v22 += 2;
      if ( v20 < 4 )
        goto LABEL_28;
      if ( !sub_45A380(&v34, v36, &v26, &v28)
        && !sub_45A380(&v34, v36, &v26, &v30)
        && !sub_45A380(&v34, v36, &v30, &v28)
        && !sub_45A380(v36, v37, &v26, &v28)
        && !sub_45A380(v36, v37, &v26, &v30)
        && !sub_45A380(v36, v37, &v30, &v28)
        && !sub_45A380(v37, v38, &v26, &v28)
        && !sub_45A380(v37, v38, &v26, &v30)
        && !sub_45A380(v37, v38, &v30, &v28)
        && !sub_45A380(v38, &v34, &v26, &v28)
        && !sub_45A380(v38, &v34, &v26, &v30) )
      {
        return sub_45A380(v38, &v34, &v30, &v28);
      }
      return 1;
    }
  }
  return 1;
}
