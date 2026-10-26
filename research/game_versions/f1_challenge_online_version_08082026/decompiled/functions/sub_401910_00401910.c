float *__userpurge sub_401910@<eax>(_DWORD *a1@<ecx>, double a2@<st0>, int a3)
{
  float *result; // eax
  int v5; // ecx
  int v6; // edx
  int v7; // eax
  double v8; // st7
  int v9; // esi
  int v10; // ebx
  int v11; // ebp
  float *v12; // esi
  double v13; // rt1
  double v14; // st7
  double v15; // st6
  float *v16; // esi
  bool v17; // cc
  float v18; // [esp+Ch] [ebp-4Ch]
  float v19; // [esp+10h] [ebp-48h]
  float v20; // [esp+14h] [ebp-44h]
  float v21; // [esp+18h] [ebp-40h]
  float v22; // [esp+1Ch] [ebp-3Ch]
  int v23; // [esp+20h] [ebp-38h]
  int v24; // [esp+24h] [ebp-34h]
  float v25; // [esp+28h] [ebp-30h]
  float v26; // [esp+28h] [ebp-30h]
  float v27; // [esp+2Ch] [ebp-2Ch]
  float v28; // [esp+2Ch] [ebp-2Ch]
  float v29; // [esp+30h] [ebp-28h]
  float v30; // [esp+30h] [ebp-28h]
  float v31; // [esp+34h] [ebp-24h]
  float v32; // [esp+38h] [ebp-20h]
  float v33; // [esp+38h] [ebp-20h]
  float v34; // [esp+3Ch] [ebp-1Ch]
  float v35; // [esp+3Ch] [ebp-1Ch]
  float v36; // [esp+48h] [ebp-10h]
  float v37; // [esp+54h] [ebp-4h]

  result = (float *)a1[76];
  v5 = 0;
  if ( (int)result > 0 )
  {
    v6 = 0;
    do
    {
      v7 = a1[77];
      v8 = *(float *)(v7 + v6 + 24);
      result = (float *)(v6 + v7 + 148);
      ++v5;
      v6 += 316;
      v32 = v8 * *(result - 28);
      v34 = v8 * *(result - 27);
      v25 = v8 * *(result - 29) + *(result - 37);
      v27 = v32 + *(result - 36);
      a2 = v34 + *(result - 35);
      *result = v25;
      result[1] = v27;
      v29 = a2;
      result[2] = v29;
    }
    while ( v5 < a1[76] );
  }
  v24 = 0;
  if ( (int)a1[76] > 0 )
  {
    v23 = 0;
    do
    {
      v9 = a1[77];
      v10 = *(_DWORD *)(v9 + v23 + 268);
      v11 = *(_DWORD *)(v9 + v23 + 272);
      v12 = (float *)(v23 + v9);
      if ( v10 && v11 )
      {
        sub_401340(a1, (int)v12);
        sub_4E8CE0(v12[29], (int)(v12 + 30), v12[28], 16.0);
        sub_401340(a1, v10);
        sub_4E8CE0(*(float *)(v10 + 116), v10 + 120, *(float *)(v10 + 112), 16.0);
        sub_401340(a1, v11);
        sub_4E8CE0(*(float *)(v11 + 116), v11 + 120, *(float *)(v11 + 112), 16.0);
        v21 = a2;
        v22 = v12[6];
        v19 = v22 - 0.045000002;
        if ( v22 + 0.050000001 > v19 )
        {
          do
          {
            v36 = v19 * v12[10];
            v13 = v19 * v12[9];
            v26 = v19 * v12[8] + *v12;
            v12[37] = v26;
            v28 = v13 + v12[1];
            v12[38] = v28;
            v14 = v36 + v12[2];
            v30 = v14;
            v12[39] = v30;
            sub_401340(a1, (int)v12);
            sub_4E8CE0(v12[29], (int)(v12 + 30), v12[28], 16.0);
            v20 = v14;
            sub_401340(a1, v10);
            sub_4E8CE0(*(float *)(v10 + 116), v10 + 120, *(float *)(v10 + 112), 16.0);
            v18 = v14;
            sub_401340(a1, v11);
            sub_4E8CE0(*(float *)(v11 + 116), v11 + 120, *(float *)(v11 + 112), 16.0);
            if ( v18 >= v14 )
              v15 = v14;
            else
              v15 = v18;
            if ( v20 >= v15 )
            {
              if ( v18 < v14 )
                v14 = v18;
            }
            else
            {
              v14 = v20;
            }
            if ( v14 > v21 )
            {
              v21 = v14;
              v22 = v19;
            }
            v19 = v19 + 0.0099999998;
          }
          while ( v12[6] + 0.050000001 > v19 );
        }
        v16 = v12 + 37;
        v37 = v22 * *(v16 - 27);
        v31 = v22 * *(v16 - 29) + *(v16 - 37);
        v33 = v22 * *(v16 - 28) + *(v16 - 36);
        a2 = v37 + *(v16 - 35);
        *v16 = v31;
        v16[1] = v33;
        v35 = a2;
        v16[2] = v35;
      }
      result = (float *)(v24 + 1);
      v17 = ++v24 < a1[76];
      v23 += 316;
    }
    while ( v17 );
  }
  return result;
}
