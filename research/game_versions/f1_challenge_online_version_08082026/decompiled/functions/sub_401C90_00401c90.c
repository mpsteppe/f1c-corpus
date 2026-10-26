int __userpurge sub_401C90@<eax>(float *a1@<ecx>, double a2@<st0>, int a3)
{
  int v4; // ebp
  int v5; // edi
  int v6; // esi
  float v7; // ecx
  float v8; // eax
  int v9; // esi
  int v10; // edi
  int v11; // esi
  float *i; // edi
  double v13; // st5
  double v14; // st4
  double v15; // st2
  long double v16; // st3
  bool v17; // cc
  int v18; // ecx
  int v19; // edx
  int v20; // esi
  int v21; // edi
  float *j; // esi
  double v23; // st5
  double v24; // st4
  double v25; // st2
  long double v26; // st3
  int v27; // eax
  int v28; // ecx
  int v29; // eax
  int v30; // edi
  int v31; // esi
  int k; // ecx
  float *v33; // edx
  double v34; // st7
  double v35; // st7
  double v36; // st6
  double v37; // st4
  double v38; // st3
  double v39; // st1
  int v40; // esi
  int v41; // edi
  int result; // eax
  int v43; // esi
  int v44; // edi
  float v45; // [esp+10h] [ebp-10h]
  float v46; // [esp+10h] [ebp-10h]
  float v47; // [esp+14h] [ebp-Ch]
  float v48; // [esp+14h] [ebp-Ch]
  int v49; // [esp+18h] [ebp-8h]
  int v50; // [esp+18h] [ebp-8h]
  int v51; // [esp+1Ch] [ebp-4h]
  int v52; // [esp+1Ch] [ebp-4h]
  float v53; // [esp+24h] [ebp+4h]

  sub_401910(a1, a2, a3);
  v4 = 0;
  sub_401340(a1, 0);
  v5 = 0;
  if ( *((int *)a1 + 76) > 0 )
  {
    do
    {
      v6 = *((_DWORD *)a1 + 77);
      v7 = *(float *)(v6 + v4 + 112);
      v8 = *(float *)(v6 + v4 + 116);
      v9 = v4 + v6;
      sub_4E8CE0(v8, v9 + 120, v7, 16.0);
      *(float *)(v9 + 136) = a2;
      ++v5;
      v4 += 316;
    }
    while ( v5 < *((_DWORD *)a1 + 76) );
    v4 = 0;
  }
  v49 = 0;
  if ( *((int *)a1 + 76) > 0 )
  {
    v51 = 0;
    do
    {
      v10 = *((_DWORD *)a1 + 77);
      v11 = *(_DWORD *)(v10 + v4 + 268);
      for ( i = (float *)(v4 + v10); v11; v11 = *(_DWORD *)(v11 + 268) )
      {
        if ( *(float **)(v11 + 272) != i )
          break;
        sub_4E9100(i[34], *(float *)(v11 + 116), v11 + 120, *(float *)(v11 + 112));
        if ( i[34] <= 0.0 )
          break;
        v13 = i[38] - *(float *)(v11 + 152);
        v14 = i[39] - *(float *)(v11 + 156);
        v15 = i[37] - *(float *)(v11 + 148);
        v16 = sqrt(v14 * v14 + v13 * v13 + v15 * v15);
        a2 = a2 * (v16 / i[34]) * 0.5 + i[34];
        v47 = a2;
        if ( a2 <= 0.0 )
          break;
        sub_4E9100(v47, *(float *)(v11 + 116), v11 + 120, *(float *)(v11 + 112));
        v45 = v16;
        a2 = a2 * (v45 / v47) + i[34];
        if ( a2 > *(float *)(v11 + 136) )
          break;
        if ( a2 < 0.0 )
          a2 = 0.0;
        *(float *)(v11 + 136) = a2;
        i = (float *)v11;
      }
      v4 = v51 + 316;
      v17 = ++v49 < *((_DWORD *)a1 + 76);
      v51 += 316;
    }
    while ( v17 );
    v4 = 0;
  }
  v18 = 0;
  if ( *((int *)a1 + 76) > 0 )
  {
    v19 = 0;
    do
    {
      *(_DWORD *)(v19 + *((_DWORD *)a1 + 77) + 140) = *(_DWORD *)(*((_DWORD *)a1 + 77) + v19 + 136);
      ++v18;
      v19 += 316;
    }
    while ( v18 < *((_DWORD *)a1 + 76) );
  }
  v50 = 0;
  if ( *((int *)a1 + 76) > 0 )
  {
    v52 = 0;
    do
    {
      v20 = *((_DWORD *)a1 + 77);
      v21 = *(_DWORD *)(v20 + v4 + 272);
      for ( j = (float *)(v4 + v20); v21; v21 = *(_DWORD *)(v21 + 272) )
      {
        if ( *(float **)(v21 + 268) != j )
          break;
        sub_4E9300(j[35], j[29], (int)(j + 30), j[28]);
        if ( j[35] <= 0.0 )
          break;
        v23 = *(float *)(v21 + 152) - j[38];
        v24 = *(float *)(v21 + 156) - j[39];
        v25 = *(float *)(v21 + 148) - j[37];
        v26 = sqrt(v24 * v24 + v23 * v23 + v25 * v25);
        a2 = a2 * (v26 / j[35]) * 0.5 + j[35];
        v48 = a2;
        if ( a2 <= 0.0 )
          break;
        sub_4E9300(v48, j[29], (int)(j + 30), j[28]);
        v46 = v26;
        a2 = a2 * (v46 / v48) + j[35];
        if ( a2 >= *(float *)(v21 + 140) )
          break;
        if ( a2 < 0.0 )
          a2 = 0.0;
        *(float *)(v21 + 140) = a2;
        j = (float *)v21;
      }
      v4 = v52 + 316;
      v17 = ++v50 < *((_DWORD *)a1 + 76);
      v52 += 316;
    }
    while ( v17 );
  }
  v27 = 0;
  if ( *((int *)a1 + 76) > 0 )
  {
    v28 = 0;
    do
    {
      *(_DWORD *)(*((_DWORD *)a1 + 77) + v28 + 144) = -1082130432;
      ++v27;
      v28 += 316;
    }
    while ( v27 < *((_DWORD *)a1 + 76) );
  }
  v29 = *((_DWORD *)a1 + 76);
  v30 = 0;
  a1[82] = 0.0;
  if ( v29 > 0 )
  {
    v31 = 0;
    do
    {
      for ( k = v31 + *((_DWORD *)a1 + 77); k; k = *(_DWORD *)(k + 272) )
      {
        v33 = *(float **)(k + 268);
        if ( !v33 || *(float *)(k + 144) >= 0.0 )
          break;
        if ( *(float *)(k + 72) >= (double)v33[18] )
        {
          if ( v33[36] < 0.0 )
            break;
          v35 = v33[36];
          *(float *)(k + 144) = v33[36];
          v36 = (v33[35] + *(float *)(k + 140)) * 0.5;
          if ( v36 > 0.0 )
          {
            v37 = *(float *)(k + 152) - v33[38];
            v38 = *(float *)(k + 156) - v33[39];
            v39 = *(float *)(k + 148) - v33[37];
            *(float *)(k + 144) = sqrt(v38 * v38 + v37 * v37 + v39 * v39) / v36 + v35;
          }
          if ( !*(_DWORD *)(k + 300) && *(float *)(k + 144) > (double)a1[82] )
            a1[82] = *(float *)(k + 144);
        }
        else
        {
          v34 = (v33[35] + *(float *)(k + 140)) * 0.5;
          if ( v34 <= 0.0 )
            *(_DWORD *)(k + 144) = 0;
          else
            *(float *)(k + 144) = *(float *)(k + 72) / v34;
        }
      }
      ++v30;
      v31 += 316;
    }
    while ( v30 < *((_DWORD *)a1 + 76) );
  }
  v40 = 0;
  if ( *((int *)a1 + 76) > 0 )
  {
    v53 = 1.0 - (flt_8AFEE8 + flt_8AFEEC) * 0.5;
    v41 = 0;
    do
    {
      sub_4FB260(v53);
      ++v40;
      v41 += 316;
    }
    while ( v40 < *((_DWORD *)a1 + 76) );
  }
  result = *((_DWORD *)a1 + 76);
  v43 = 0;
  if ( result > 0 )
  {
    v44 = 0;
    do
    {
      sub_4FAF60(v44 + *((_DWORD *)a1 + 77));
      result = *((_DWORD *)a1 + 76);
      ++v43;
      v44 += 316;
    }
    while ( v43 < result );
  }
  return result;
}
