char __thiscall sub_426430(int this)
{
  double v2; // st7
  float *v3; // ebp
  float *v4; // edi
  int v5; // eax
  double v7; // st7
  double v8; // st6
  int v9; // eax
  float *v10; // ecx
  int v11; // ebx
  _DWORD *v12; // eax
  int v13; // ecx
  int v14; // edi
  int v15; // edx
  int v16; // eax
  int v17; // eax
  double v18; // st7
  int v19; // ecx
  double v20; // st7
  int v21; // eax
  float v22; // ecx
  double v23; // st7
  double v24; // st6
  int v25; // edx
  int v26; // ecx
  double v27; // st7
  int v28; // edi
  double v29; // st5
  double v30; // st4
  double v31; // st7
  long double v32; // st7
  long double v33; // st6
  double v34; // st6
  long double v35; // st6
  long double v36; // st6
  long double v37; // st6
  long double v38; // st7
  float *v39; // eax
  long double v40; // st6
  long double v41; // st5
  double v42; // st4
  double v43; // st3
  long double v44; // st2
  long double v45; // st7
  long double v46; // st7
  long double v47; // st6
  int v48; // eax
  double v49; // st7
  int *v50; // edx
  int v51; // edi
  int v52; // ecx
  double v53; // st7
  int v54; // [esp-Ch] [ebp-58h]
  int v55; // [esp-8h] [ebp-54h]
  float v56; // [esp+10h] [ebp-3Ch]
  float v57; // [esp+10h] [ebp-3Ch]
  float v58; // [esp+14h] [ebp-38h]
  int v59; // [esp+18h] [ebp-34h]
  float v60; // [esp+18h] [ebp-34h]
  float v61; // [esp+1Ch] [ebp-30h]
  float v62; // [esp+24h] [ebp-28h]
  float v63; // [esp+28h] [ebp-24h]
  float v64; // [esp+30h] [ebp-1Ch]
  float v65; // [esp+34h] [ebp-18h]
  float v66; // [esp+3Ch] [ebp-10h]
  float v67; // [esp+40h] [ebp-Ch]

  v2 = *(float *)(this + 13568);
  v3 = *(float **)(this + 17236);
  v4 = (float *)(this + 13536);
  *(float *)(this + 17472) = sqrt(
                               *(float *)(this + 13560) * *(float *)(this + 13560)
                             + *(float *)(this + 13564) * *(float *)(this + 13564)
                             + v2 * v2);
  if ( !v3 )
  {
    v5 = SpatialNearestNeighborQueryWithPlaneTest(dword_5EA2C0, (float *)(this + 13536), *(_DWORD *)(this + 17744));
    *(_DWORD *)(this + 17236) = v5;
    if ( !v5 )
      return 0;
    v3 = (float *)v5;
    goto LABEL_12;
  }
  v7 = *v4 - v3[37];
  v8 = *(float *)(this + 13544) - v3[39];
  if ( v8 * v8 + v7 * v7 > 3200.0 )
  {
    v9 = SpatialNearestNeighborQueryWithPlaneTest(dword_5EA2C0, (float *)(this + 13536), *(_DWORD *)(this + 17744));
    *(_DWORD *)(this + 17236) = v9;
    if ( !v9 )
      return 0;
    v3 = (float *)v9;
    *(_BYTE *)(this + 17544) = 1;
  }
  v10 = *(float **)(this + 17236);
  v2 = v10[37] - *v4;
  if ( v10[5] * (v10[39] - *(float *)(this + 13544)) + v10[3] * v2 < 0.0 )
  {
    v2 = *(float *)(*(_DWORD *)(this + 17240) + 72);
    v3 = *(float **)(this + 17236);
    if ( v2 < v10[18] )
      ++*(_DWORD *)(this + 17496);
LABEL_12:
    *(_BYTE *)(this + 17544) = 1;
  }
  if ( *(_BYTE *)(this + 17544) )
  {
    v11 = this + 17240;
    v55 = *(_DWORD *)(this + 17744);
    v54 = *(_DWORD *)(this + 17240);
    *(_DWORD *)(this + 17488) = *(_DWORD *)(*(_DWORD *)(this + 17236) + 72);
    *(_DWORD *)(this + 17236) = SpatialTreeNearestNeighborSearch(dword_5EA2C0, v4, v54, v55, 1);
    v12 = (_DWORD *)(this + 17240);
    v59 = 19;
    do
    {
      v13 = *(_DWORD *)(this + 17740);
      v14 = *(v12 - 1);
      if ( !v13 || (v15 = *(_DWORD *)(v14 + 276)) == 0 || v13 != *(_DWORD *)(v15 + 300) )
        v15 = *(_DWORD *)(v14 + 272);
      *v12++ = v15;
      --v59;
    }
    while ( v59 );
    v16 = *(_DWORD *)(this + 17744);
    if ( v16 || *(_DWORD *)(*(_DWORD *)v11 + 300) != 1 )
    {
      if ( v16 == 1 && !*(_DWORD *)(*(_DWORD *)v11 + 300) )
        sub_4A46F0(this, 0, 0);
    }
    else
    {
      AICommandMessageQueueDispatcher((int *)this, 14, *(_DWORD *)(this + 17744));
      sub_4A46F0(this, 1, 1);
    }
    v17 = *(_DWORD *)(this + 17236);
    *(_DWORD *)(this + 17744) = *(_DWORD *)(*(_DWORD *)v11 + 300);
    TireForceSolver(*(float *)(v17 + 116), v17 + 120, *(float *)(v17 + 112), 16.0);
    v18 = v2 * *(float *)(this + 17668) + *(float *)(this + 17664);
    if ( v18 > 75.0 )
      v18 = 75.0;
    v19 = *(_DWORD *)(this + 17744);
    if ( v19 == 1 )
      v18 = flt_8ACFB4;
    v20 = *(float *)(this + 17472) / v18;
    *(float *)(this + 17476) = v20;
    if ( v20 > 1.0 )
      *(_DWORD *)(this + 17476) = 1065353216;
    *(float *)(this + 17492) = (double)*(int *)(this + 17496) * flt_5EA3FC + *(float *)(this + 17488);
    if ( *(float *)(this + 17472) >= 15.0 || v19 == 1 )
    {
      if ( *(float *)(this + 17472) >= 30.0 )
      {
        if ( *(float *)(this + 17472) >= 65.0 )
          *(_DWORD *)(this + 17512) = 3;
        else
          *(_DWORD *)(this + 17512) = 2;
      }
      else
      {
        *(_DWORD *)(this + 17512) = 1;
      }
    }
    else
    {
      *(_DWORD *)(this + 17512) = 0;
    }
    v21 = *(_DWORD *)(this + 17236);
    v22 = *(float *)(this + 13544);
    v23 = *(float *)(v21 + 148) - *(float *)(this + 13536);
    v24 = *(float *)(v21 + 156) - v22;
    *(_DWORD *)(this + 17560) = *(_DWORD *)(this + 13536);
    *(float *)(this + 17568) = v22;
    *(float *)(this + 17396) = sqrt(v24 * v24 + v23 * v23);
  }
  else if ( !*(_BYTE *)(this + 16704) )
  {
    return 1;
  }
  v25 = *(_DWORD *)(this + 17512);
  if ( *(_DWORD *)(this + 4 * v25 + 17236) )
  {
    v26 = *(_DWORD *)(this + 17240);
    v27 = v3[37] - *(float *)(this + 13536);
    v28 = *(_DWORD *)(this + 15724);
    v29 = v3[8];
    v30 = v3[10] * (v3[39] - *(float *)(this + 13544));
    *(_DWORD *)(this + 17708) = 1065353216;
    *(_DWORD *)(this + 17704) = 1065353216;
    *(float *)(this + 17448) = -(v30 + v29 * v27);
    v31 = (1.0 - *(float *)(this + 17476)) * 0.15000001 + *(float *)(v26 + 4 * v25 + 188);
    v58 = v31;
    v60 = v31 + *(float *)(this + 13552);
    v32 = *(float *)(this + 13552) - v31;
    if ( v28 != 2 || *(float *)(this + 14724) > 0.001 )
    {
      if ( *(float *)(v26 + 4 * v25 + 188) > 0.02421 )
      {
        v33 = *(float *)(*(_DWORD *)(this + 17252) + 184) - *(float *)(*(_DWORD *)(this + 17236) + 184);
        if ( fabs(v33) >= 3.141592653589793 )
        {
          if ( v33 >= 0.0 )
            v33 = v33 - 6.2831855;
          else
            v33 = v33 + 6.2831855;
        }
        if ( v33 <= 0.0 )
        {
          *(_DWORD *)(this + 17708) = -1082130432;
          v34 = *(float *)(v26 + 184) - *(float *)(v26 + 4 * v25 + 188);
        }
        else
        {
          *(_DWORD *)(this + 17704) = -1082130432;
          v34 = *(float *)(v26 + 184) + *(float *)(v26 + 4 * v25 + 188);
        }
        v56 = v34;
      }
      else
      {
        v56 = *(float *)(v26 + 184);
      }
      if ( *(_DWORD *)(*(_DWORD *)this + 13000) != 1 )
        return 1;
      v35 = v60 - v56;
      if ( fabs(v35) >= 3.141592653589793 )
      {
        if ( v35 >= 0.0 )
          v35 = v35 - 6.2831855;
        else
          v35 = v35 + 6.2831855;
      }
      if ( v35 > v58 && v28 != 2 && *(float *)(this + 14724) > 0.001 )
      {
        v36 = *(float *)(this + 13552) - v56;
        if ( fabs(v36) >= 3.141592653589793 )
        {
          if ( v36 >= 0.0 )
            v36 = v36 - 6.2831855;
          else
            v36 = v36 + 6.2831855;
        }
        if ( v36 <= v58 )
          v60 = v56 + v58;
        else
          v60 = *(float *)(this + 13552);
      }
      v37 = v32 - v56;
      if ( fabs(v37) >= 3.141592653589793 )
      {
        if ( v37 >= 0.0 )
          v37 = v37 - 6.2831855;
        else
          v37 = v37 + 6.2831855;
      }
      if ( v37 < -v58 && v28 != 2 && *(float *)(this + 14724) > 0.001 )
      {
        v38 = v56 - *(float *)(this + 13552);
        if ( fabs(v38) >= 3.141592653589793 )
        {
          if ( v38 >= 0.0 )
            v38 = v38 - 6.2831855;
          else
            v38 = v38 + 6.2831855;
        }
        if ( v38 <= v58 )
          v32 = v56 - v58;
        else
          v32 = *(float *)(this + 13552);
      }
    }
    v39 = *(float **)(this + 4 * v25 + 17236);
    v63 = v39[37];
    v62 = *(float *)(this + 13544);
    v64 = v39[39];
    v40 = -sin(v60);
    v41 = -cos(v60);
    v42 = v39[8];
    v43 = v39[10];
    v61 = *(float *)(this + 13536);
    v44 = 1.0 / sqrt(v43 * v43 + v42 * v42);
    v65 = v44 * v42;
    v66 = v44 * v43;
    if ( v40 == 0.0 )
      *(_DWORD *)(this + 17428) = 0;
    else
      *(float *)(this + 17428) = (v63 * (v41 / v40) + v62 - v61 * (v41 / v40) - v64) / (v66 - v65 * (v41 / v40));
    v67 = -sin(v32);
    v45 = -cos(v32);
    if ( v67 == 0.0 )
      *(_DWORD *)(this + 17432) = 0;
    else
      *(float *)(this + 17432) = (v63 * (v45 / v67) + v62 - v61 * (v45 / v67) - v64) / (v66 - v65 * (v45 / v67));
    v46 = -sin(*(float *)(this + 13552));
    v47 = -cos(*(float *)(this + 13552));
    if ( v46 == 0.0 )
      *(_DWORD *)(this + 17436) = 0;
    else
      *(float *)(this + 17436) = (v63 * (v47 / v46) + v62 - v61 * (v47 / v46) - v64) / (v66 - v65 * (v47 / v46));
    if ( v28 != 2 && *(float *)(this + 14724) > 0.001 )
    {
      v48 = *(_DWORD *)(this + 17236);
      v49 = *(float *)(v48 + 80);
      v57 = *(float *)(v48 + 84);
      v50 = (int *)(this + 17240);
      v51 = 5;
      do
      {
        v52 = *v50;
        if ( *(float *)(*v50 + 84) <= (double)v57 )
          v57 = *(float *)(v52 + 84);
        if ( v49 >= *(float *)(v52 + 80) )
          v49 = *(float *)(v52 + 80);
        ++v50;
        --v51;
      }
      while ( v51 );
      if ( *(float *)(this + 17428) > (double)v57 )
      {
        if ( v57 <= (double)*(float *)(this + 17432) )
          *(_DWORD *)(this + 17428) = *(_DWORD *)(this + 17432);
        else
          *(float *)(this + 17428) = v57;
      }
      v53 = -v49;
      if ( v53 > *(float *)(this + 17432) )
      {
        if ( v53 < *(float *)(this + 17428) )
        {
          *(float *)(this + 17432) = v53;
          *(_BYTE *)(this + 16704) = 0;
          return 1;
        }
        *(_DWORD *)(this + 17432) = *(_DWORD *)(this + 17428);
      }
    }
    *(_BYTE *)(this + 16704) = 0;
  }
  return 1;
}
