int __thiscall sub_434F50(int this)
{
  _DWORD *v2; // edi
  int v3; // ebx
  int v4; // ebp
  int v5; // edi
  int *v6; // ecx
  int v7; // eax
  int v8; // ebx
  double v9; // st7
  char v10; // al
  int v11; // eax
  int *v12; // ecx
  int *v13; // ecx
  double v14; // st7
  double v15; // st7
  int v16; // edx
  int v17; // eax
  int v18; // ebp
  double v19; // st7
  int v20; // eax
  int v21; // edx
  int v22; // ebx
  _DWORD *v23; // eax
  int v24; // edi
  double v25; // st6
  int v26; // eax
  int v27; // edi
  double v28; // st6
  int v29; // ebx
  int v30; // eax
  int v31; // ebp
  int v32; // edi
  int v33; // edx
  double v34; // st7
  int v35; // edi
  int v36; // ebp
  double v37; // st6
  long double v38; // st6
  int result; // eax
  int v40; // edx
  int v41; // edx
  double v42; // [esp+18h] [ebp-3F8h]
  int v43; // [esp+18h] [ebp-3F8h]
  double v44; // [esp+18h] [ebp-3F8h]
  int v45; // [esp+24h] [ebp-3ECh]
  int v46; // [esp+24h] [ebp-3ECh]
  double v47; // [esp+28h] [ebp-3E8h]
  double v48; // [esp+28h] [ebp-3E8h]
  double v49; // [esp+28h] [ebp-3E8h]
  double v50; // [esp+28h] [ebp-3E8h]
  int v51; // [esp+30h] [ebp-3E0h]
  int v52; // [esp+34h] [ebp-3DCh]
  int v53; // [esp+34h] [ebp-3DCh]
  int v54; // [esp+38h] [ebp-3D8h]
  int v55; // [esp+38h] [ebp-3D8h]
  int *v56; // [esp+3Ch] [ebp-3D4h]
  int *v57; // [esp+3Ch] [ebp-3D4h]
  double v58[45]; // [esp+40h] [ebp-3D0h]
  double v59; // [esp+1A8h] [ebp-268h]
  double v60; // [esp+1B0h] [ebp-260h]
  double v61; // [esp+1B8h] [ebp-258h]
  double v62; // [esp+1C0h] [ebp-250h]
  double v63; // [esp+1C8h] [ebp-248h]
  double v64; // [esp+1D0h] [ebp-240h]
  double v65; // [esp+1D8h] [ebp-238h]
  double v66[45]; // [esp+228h] [ebp-1E8h]
  double v67; // [esp+390h] [ebp-80h]
  double v68; // [esp+398h] [ebp-78h]
  double v69; // [esp+3A0h] [ebp-70h]
  double v70; // [esp+3A8h] [ebp-68h]
  double v71; // [esp+3B0h] [ebp-60h]
  double v72; // [esp+3B8h] [ebp-58h]
  double v73; // [esp+3C0h] [ebp-50h]

  v47 = (*(float *)(this + 7728) - 0.5) * 0.5 + *(float *)(this + 7724);
  sub_431F80((_DWORD *)(this + 4784), v47);
  sub_431F80((_DWORD *)(this + 3632), v47);
  sub_431F80((_DWORD *)(this + 3696), v47);
  sub_431F80((_DWORD *)(this + 4848), (0.5 - *(float *)(this + 7728)) * 0.5 + *(float *)(this + 7724));
  sub_431F80((_DWORD *)(this + 5040), *(float *)(this + 7728));
  sub_431F80((_DWORD *)(this + 3376), (1.0 - *(float *)(this + 7728) + *(float *)(this + 7732)) * 0.5);
  sub_431F80((_DWORD *)(this + 3440), (*(float *)(this + 7732) + *(float *)(this + 7728)) * 0.5);
  v2 = (_DWORD *)(this + 496);
  v3 = 4;
  do
  {
    sub_431F80(v2 - 16, *(float *)(this + 7732));
    sub_431F80(v2, *(float *)(this + 7732));
    sub_431F80(v2 + 16, *(float *)(this + 7732));
    sub_431F80(v2 + 32, *(float *)(this + 7732));
    sub_431F80(v2 + 48, *(float *)(this + 7732));
    v2 += 176;
    --v3;
  }
  while ( v3 );
  v4 = 45;
  *(_DWORD *)(this + 5764) = *(_DWORD *)(this + 5768);
  v54 = 45;
  v5 = 45;
  v6 = (int *)(this + 6896);
  do
  {
    v7 = *(_DWORD *)((v5 << 6) + this + 3016);
    v8 = (v5 << 6) + this;
    *(_DWORD *)(v8 + 3012) = v7;
    v9 = sub_431630(v6, v7, *(_DWORD *)(this + 5764));
    if ( v5 == 44 )
      v9 = -v9;
    v10 = *(_BYTE *)(v8 + 3020);
    v66[v5] = v9;
    if ( v10 )
    {
      v54 = v5;
      v4 = v5;
    }
    ++v5;
  }
  while ( v5 <= 51 );
  *(_DWORD *)(this + 5764) = 0;
  *(_DWORD *)(this + 5892) = 0;
  v42 = sub_431630(v6, 0, *(_DWORD *)(this + 5764));
  *(_DWORD *)(this + 5764) = *(_DWORD *)(this + 5760) - 1;
  v11 = *(_DWORD *)(((v4 + 47) << 6) + this) - 1;
  v56 = (int *)((v4 << 6) + this + 3012);
  *v56 = v11;
  v14 = sub_431630(v12, v11, *(_DWORD *)(this + 5764));
  if ( v4 == 44 )
    v14 = -v14;
  v48 = *(float *)(this + 7736);
  if ( v48 < 0.5 )
    v15 = v48 + v48 + v42 / v67 * (1.0 - (v48 + v48));
  else
    v15 = v14 / v66[v4] * (v48 + v48 - 1.0) + 1.0 - (v48 + v48 - 1.0);
  v16 = *(_DWORD *)(this + 5760);
  v17 = *(_DWORD *)(this + 5768);
  v18 = 0;
  v59 = v67 * v15;
  v45 = v17;
  v52 = 0;
  v60 = v68 * v15;
  v61 = v69 * v15;
  v62 = v70 * v15;
  v63 = v71 * v15;
  v64 = v72 * v15;
  v65 = v73 * v15;
  v49 = 1.797693134862316e308;
  if ( v16 > 0 )
  {
    v51 = -v17;
    do
    {
      v19 = 0.0;
      *(_DWORD *)(this + 5764) = v18;
      v20 = *(_DWORD *)(this + 5892);
      v21 = v18;
      if ( v20 < 0
        || v20 >= *v13
        || v18 < 0
        || v18 >= v13[2]
        || *(int *)(v13[1] + 8 * v20) <= 0
        || *(int *)(v13[3] + 8 * v18) <= 0
        || (v22 = v13[4], v22 <= 0) )
      {
        v25 = 0.0;
      }
      else
      {
        v23 = (_DWORD *)(v13[1] + 8 * v20);
        v24 = v13[3];
        v43 = v23[1] * *(_DWORD *)(v24 + 8 * v18 + 4) * v13[5];
        v18 = v52;
        v25 = (double)v43 / (double)(*(_DWORD *)(v24 + 8 * v21) * v22 * *v23);
      }
      if ( v25 < v59 )
        v19 = v59 - v25;
      v26 = *v56;
      if ( *v56 < 0
        || v26 >= *v13
        || v21 < 0
        || v21 >= v13[2]
        || *(int *)(v13[1] + 8 * v26) <= 0
        || *(int *)(v13[3] + 8 * v21) <= 0
        || (v27 = v13[4], v27 <= 0) )
      {
        v28 = 0.0;
      }
      else
      {
        v28 = (double)(*(_DWORD *)(v13[1] + 8 * v26 + 4) * *(_DWORD *)(v13[3] + 8 * v21 + 4) * v13[5])
            / (double)(*(_DWORD *)(v13[1] + 8 * v26) * v27 * *(_DWORD *)(v13[3] + 8 * v21));
      }
      if ( v54 == 44 )
        v28 = -v28;
      if ( v28 > v58[v54] )
      {
        v44 = v28 - v58[v54];
        if ( v19 < v44 )
          v19 = v44;
      }
      if ( v19 == v49 )
      {
        if ( (int)abs32(v51) < (int)abs32(v45 - *(_DWORD *)(this + 5768)) )
        {
          v49 = v19;
          v45 = v18;
        }
      }
      else if ( v19 < v49 )
      {
        v49 = v19;
        v45 = v18;
      }
      v52 = ++v18;
      ++v51;
    }
    while ( v18 < *(_DWORD *)(this + 5760) );
  }
  v29 = 45;
  *(_DWORD *)(this + 5764) = v45;
  v53 = 45;
  do
  {
    v30 = (v29 + 47) << 6;
    v50 = 1.797693134862316e308;
    v31 = *(_DWORD *)(v30 + this);
    v32 = 0;
    v33 = 0;
    v46 = 0;
    v55 = v31;
    if ( v31 > 0 )
    {
      v34 = v58[v29];
      v57 = (int *)((v29 << 6) + this + 3012);
      do
      {
        *v57 = v33;
        v35 = *(_DWORD *)(this + 5764);
        if ( v33 < 0
          || v33 >= *v13
          || v35 < 0
          || v35 >= v13[2]
          || *(int *)(v13[1] + 8 * v33) <= 0
          || *(int *)(v13[3] + 8 * v35) <= 0
          || (v36 = v13[4], v36 <= 0) )
        {
          v37 = 0.0;
        }
        else
        {
          v29 = v53;
          v37 = (double)(*(_DWORD *)(v13[3] + 8 * v35 + 4) * v13[5] * *(_DWORD *)(v13[1] + 8 * v33 + 4))
              / (double)(*(_DWORD *)(v13[3] + 8 * v35) * v36 * *(_DWORD *)(v13[1] + 8 * v33));
        }
        if ( v29 == 44 )
          v37 = -v37;
        v38 = fabs(v37 - v34);
        if ( v38 < v50 )
        {
          v50 = v38;
          v46 = v33;
        }
        ++v33;
      }
      while ( v33 < *(_DWORD *)(this + v30) );
      v32 = v46;
      v31 = v55;
    }
    result = (v29 << 6) + this;
    *(_DWORD *)(result + 3012) = v32;
    if ( v29 > 45 )
    {
      v40 = *(_DWORD *)(result + 2948);
      if ( v40 >= v32 )
      {
        v41 = v40 + 1;
        if ( v41 >= v31 )
          *(_DWORD *)(result + 3012) = v31 - 1;
        else
          *(_DWORD *)(result + 3012) = v41;
      }
    }
    v53 = ++v29;
  }
  while ( v29 <= 51 );
  return result;
}
