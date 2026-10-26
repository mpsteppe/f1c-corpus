int __userpurge sub_401DD0@<eax>(float *a1@<ecx>, double a2@<st0>, int a3)
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

  sub_401A10(a1, a2, a3);
  v4 = 0;
  sub_401360(a1, 0);
  v5 = 0;
  if ( *((int *)a1 + 89) > 0 )
  {
    do
    {
      v6 = *((_DWORD *)a1 + 90);
      v7 = *(float *)(v6 + v4 + 164);
      v8 = *(float *)(v6 + v4 + 168);
      v9 = v4 + v6;
      sub_514590(v8, v9 + 172, v7, 16.0);
      *(float *)(v9 + 184) = a2;
      ++v5;
      v4 += 348;
    }
    while ( v5 < *((_DWORD *)a1 + 89) );
    v4 = 0;
  }
  v49 = 0;
  if ( *((int *)a1 + 89) > 0 )
  {
    v51 = 0;
    do
    {
      v10 = *((_DWORD *)a1 + 90);
      v11 = *(_DWORD *)(v10 + v4 + 292);
      for ( i = (float *)(v4 + v10); v11; v11 = *(_DWORD *)(v11 + 292) )
      {
        if ( *(float **)(v11 + 296) != i )
          break;
        sub_5149B0(i[46], *(float *)(v11 + 168), v11 + 172, *(float *)(v11 + 164));
        if ( i[46] <= 0.0 )
          break;
        v13 = i[50] - *(float *)(v11 + 200);
        v14 = i[51] - *(float *)(v11 + 204);
        v15 = i[49] - *(float *)(v11 + 196);
        v16 = sqrt(v14 * v14 + v13 * v13 + v15 * v15);
        a2 = a2 * (v16 / i[46]) * 0.5 + i[46];
        v47 = a2;
        if ( a2 <= 0.0 )
          break;
        sub_5149B0(v47, *(float *)(v11 + 168), v11 + 172, *(float *)(v11 + 164));
        v45 = v16;
        a2 = a2 * (v45 / v47) + i[46];
        if ( a2 > *(float *)(v11 + 184) )
          break;
        if ( a2 < 0.0 )
          a2 = 0.0;
        *(float *)(v11 + 184) = a2;
        i = (float *)v11;
      }
      v4 = v51 + 348;
      v17 = ++v49 < *((_DWORD *)a1 + 89);
      v51 += 348;
    }
    while ( v17 );
    v4 = 0;
  }
  v18 = 0;
  if ( *((int *)a1 + 89) > 0 )
  {
    v19 = 0;
    do
    {
      *(_DWORD *)(v19 + *((_DWORD *)a1 + 90) + 188) = *(_DWORD *)(*((_DWORD *)a1 + 90) + v19 + 184);
      ++v18;
      v19 += 348;
    }
    while ( v18 < *((_DWORD *)a1 + 89) );
  }
  v50 = 0;
  if ( *((int *)a1 + 89) > 0 )
  {
    v52 = 0;
    do
    {
      v20 = *((_DWORD *)a1 + 90);
      v21 = *(_DWORD *)(v20 + v4 + 296);
      for ( j = (float *)(v4 + v20); v21; v21 = *(_DWORD *)(v21 + 296) )
      {
        if ( *(float **)(v21 + 292) != j )
          break;
        sub_514BB0(j[47], j[42], (int)(j + 43), j[41]);
        if ( j[47] <= 0.0 )
          break;
        v23 = *(float *)(v21 + 200) - j[50];
        v24 = *(float *)(v21 + 204) - j[51];
        v25 = *(float *)(v21 + 196) - j[49];
        v26 = sqrt(v24 * v24 + v23 * v23 + v25 * v25);
        a2 = a2 * (v26 / j[47]) * 0.5 + j[47];
        v48 = a2;
        if ( a2 <= 0.0 )
          break;
        sub_514BB0(v48, j[42], (int)(j + 43), j[41]);
        v46 = v26;
        a2 = a2 * (v46 / v48) + j[47];
        if ( a2 >= *(float *)(v21 + 188) )
          break;
        if ( a2 < 0.0 )
          a2 = 0.0;
        *(float *)(v21 + 188) = a2;
        j = (float *)v21;
      }
      v4 = v52 + 348;
      v17 = ++v50 < *((_DWORD *)a1 + 89);
      v52 += 348;
    }
    while ( v17 );
  }
  v27 = 0;
  if ( *((int *)a1 + 89) > 0 )
  {
    v28 = 0;
    do
    {
      *(_DWORD *)(*((_DWORD *)a1 + 90) + v28 + 192) = -1082130432;
      ++v27;
      v28 += 348;
    }
    while ( v27 < *((_DWORD *)a1 + 89) );
  }
  v29 = *((_DWORD *)a1 + 89);
  v30 = 0;
  a1[95] = 0.0;
  if ( v29 > 0 )
  {
    v31 = 0;
    do
    {
      for ( k = v31 + *((_DWORD *)a1 + 90); k; k = *(_DWORD *)(k + 296) )
      {
        v33 = *(float **)(k + 292);
        if ( !v33 || *(float *)(k + 192) >= 0.0 )
          break;
        if ( *(float *)(k + 116) >= (double)v33[29] )
        {
          if ( v33[48] < 0.0 )
            break;
          v35 = v33[48];
          *(float *)(k + 192) = v33[48];
          v36 = (v33[47] + *(float *)(k + 188)) * 0.5;
          if ( v36 > 0.0 )
          {
            v37 = *(float *)(k + 200) - v33[50];
            v38 = *(float *)(k + 204) - v33[51];
            v39 = *(float *)(k + 196) - v33[49];
            *(float *)(k + 192) = sqrt(v38 * v38 + v37 * v37 + v39 * v39) / v36 + v35;
          }
          if ( !*(_DWORD *)(k + 328) && *(float *)(k + 192) > (double)a1[95] )
            a1[95] = *(float *)(k + 192);
        }
        else
        {
          v34 = (v33[47] + *(float *)(k + 188)) * 0.5;
          if ( v34 <= 0.0 )
            *(_DWORD *)(k + 192) = 0;
          else
            *(float *)(k + 192) = *(float *)(k + 116) / v34;
        }
      }
      ++v30;
      v31 += 348;
    }
    while ( v30 < *((_DWORD *)a1 + 89) );
  }
  v40 = 0;
  if ( *((int *)a1 + 89) > 0 )
  {
    v53 = 1.0 - (flt_7DAB04 + flt_7DAB08) * 0.5;
    v41 = 0;
    do
    {
      sub_528FF0(v53);
      ++v40;
      v41 += 348;
    }
    while ( v40 < *((_DWORD *)a1 + 89) );
  }
  result = *((_DWORD *)a1 + 89);
  v43 = 0;
  if ( result > 0 )
  {
    v44 = 0;
    do
    {
      sub_528C20(v44 + *((_DWORD *)a1 + 90));
      result = *((_DWORD *)a1 + 89);
      ++v43;
      v44 += 348;
    }
    while ( v43 < result );
  }
  return result;
}
