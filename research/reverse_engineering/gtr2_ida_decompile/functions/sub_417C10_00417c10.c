int __fastcall sub_417C10(int a1, float *a2, float *a3)
{
  _DWORD *v5; // esi
  int v6; // eax
  int v7; // ebp
  double v8; // st7
  double v9; // st7
  float *v10; // ecx
  double v11; // st7
  int result; // eax
  double v13; // st7
  int v14; // eax
  int v15; // ebx
  int v16; // esi
  float *v17; // eax
  double v18; // st6
  double v19; // st3
  double v20; // st4
  long double v21; // st7
  float v22; // [esp+14h] [ebp-40h]
  int v23; // [esp+18h] [ebp-3Ch]
  float v24; // [esp+1Ch] [ebp-38h]
  int v25; // [esp+1Ch] [ebp-38h]
  float v26; // [esp+24h] [ebp-30h] BYREF
  float v27; // [esp+28h] [ebp-2Ch]
  float v28; // [esp+2Ch] [ebp-28h]
  float v29; // [esp+30h] [ebp-24h]
  float v30; // [esp+34h] [ebp-20h]
  float v31; // [esp+38h] [ebp-1Ch]
  float v32; // [esp+3Ch] [ebp-18h]
  float v33; // [esp+40h] [ebp-14h]
  float v34; // [esp+44h] [ebp-10h]
  float v35; // [esp+48h] [ebp-Ch]
  float v36; // [esp+4Ch] [ebp-8h]
  float v37; // [esp+50h] [ebp-4h]

  sub_56C0A0(&v26);
  v35 = v26 - v29;
  v32 = v35;
  v36 = v27 - v30;
  v33 = v36;
  v37 = v28 - v31;
  v34 = v37;
  v24 = sqrt(v37 * v37 + v36 * v36 + v35 * v35);
  if ( *(int *)(a1 + 544) > 0 && (v5 = *(_DWORD **)(a1 + 532)) != 0 )
    v6 = sub_5EA5B0(*v5);
  else
    v6 = sub_5EA5B0(0);
  v7 = v6;
  v35 = v29 + v26;
  v32 = v35;
  v36 = v30 + v27;
  v33 = v36;
  v37 = v31 + v28;
  v34 = v37;
  v35 = v35 * 0.5;
  v8 = v36;
  *a2 = v35;
  v36 = v8 * 0.5;
  v9 = v34;
  a2[1] = v36;
  v10 = a3;
  v37 = v9 * 0.5;
  a2[2] = v37;
  v11 = v24 * 0.5;
  result = 0;
  v25 = 0;
  *a3 = v11;
  do
  {
    v13 = (double)(result - 2);
    v14 = 0;
    v23 = 0;
    v32 = v13 * 0.02 * (v26 - v29) + *a2;
    do
    {
      v15 = 0;
      v33 = (double)(v14 - 2) * 0.02 * (v27 - v30) + a2[1];
      do
      {
        v16 = 0;
        v22 = 0.0;
        v34 = (double)(v15 - 2) * 0.02 * (v28 - v31) + a2[2];
        if ( v7 > 0 )
        {
          do
          {
            v17 = (float *)sub_5EB140(v16, 1);
            v18 = v17[1] - v33;
            v19 = v17[2] - v34;
            v20 = (*v17 - v32) * (*v17 - v32) + v18 * v18 + v19 * v19;
            if ( v20 > v22 )
              v22 = v20;
            ++v16;
          }
          while ( v16 < v7 );
          v10 = a3;
        }
        v21 = sqrt(v22);
        if ( v21 < *v10 )
        {
          *a2 = v32;
          a2[1] = v33;
          a2[2] = v34;
          *v10 = v21;
        }
        ++v15;
      }
      while ( v15 < 5 );
      v14 = ++v23;
    }
    while ( v23 < 5 );
    result = ++v25;
  }
  while ( v25 < 5 );
  return result;
}
