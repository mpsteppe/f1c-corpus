int __thiscall sub_5ED040(_DWORD *this, int a2, int *a3, int a4)
{
  float **v5; // eax
  int *v6; // edi
  unsigned __int16 *v7; // esi
  float *v8; // ebx
  int v9; // eax
  double v10; // st7
  int v11; // eax
  int v12; // edx
  int v13; // eax
  int v14; // edx
  int v15; // ecx
  int v16; // eax
  _BYTE *v17; // ecx
  float *v18; // esi
  int v19; // edi
  double v20; // st7
  double v21; // st7
  long double v22; // st7
  long double v23; // st7
  int v24; // eax
  float v25; // ecx
  float v26; // edx
  float v27; // ecx
  double v28; // st7
  double v29; // st6
  double v30; // st5
  bool v31; // cc
  float v33; // [esp+Ch] [ebp-48h]
  float v34; // [esp+10h] [ebp-44h]
  _DWORD *v35; // [esp+14h] [ebp-40h]
  float v36; // [esp+18h] [ebp-3Ch]
  int v37; // [esp+18h] [ebp-3Ch]
  unsigned __int16 *v38; // [esp+1Ch] [ebp-38h]
  int v39; // [esp+20h] [ebp-34h]
  float *v40; // [esp+24h] [ebp-30h]
  int v41; // [esp+28h] [ebp-2Ch]
  int v42; // [esp+2Ch] [ebp-28h]
  float v43; // [esp+30h] [ebp-24h] BYREF
  float v44; // [esp+34h] [ebp-20h]
  float v45; // [esp+38h] [ebp-1Ch]
  float *v46; // [esp+3Ch] [ebp-18h] BYREF
  int v47; // [esp+40h] [ebp-14h]
  int v48; // [esp+44h] [ebp-10h]
  float v49[3]; // [esp+48h] [ebp-Ch] BYREF

  v39 = 0;
  if ( (int)this[136] > 0 && (v5 = (float **)this[133]) != 0 )
    v40 = *v5;
  else
    v40 = 0;
  v6 = a3;
  v7 = (unsigned __int16 *)a3[93];
  v42 = a3[95];
  v38 = v7;
  v41 = 0;
  if ( a3[92] <= 0 )
    return 0;
  v8 = (float *)(v7 + 2);
  do
  {
    v49[0] = v40[57] - v8[4];
    v49[1] = v40[58] - v8[5];
    v9 = this[113];
    v49[2] = v40[59] - v8[6];
    v10 = *(float *)(v9 + 4) + v8[7];
    v36 = v10 * v10;
    if ( sub_5D7920(v49, v49) <= v36 )
    {
      v11 = *((_DWORD *)v8 + 1);
      v12 = *(unsigned __int16 *)v8;
      if ( (*(_BYTE *)v11 & 8) != 0 )
      {
        v13 = *(_DWORD *)(v11 + 32);
        v46 = (float *)(v13 + 88 * *v7);
        v47 = v13 + 88 * *((unsigned __int16 *)v8 - 1);
        v14 = v13 + 88 * v12;
      }
      else
      {
        v15 = *(_DWORD *)(v11 + 32);
        v46 = (float *)(v15 + (*v7 << 6));
        v47 = v15 + (*((unsigned __int16 *)v8 - 1) << 6);
        v14 = v15 + (v12 << 6);
      }
      v16 = this[113];
      v17 = *(_BYTE **)(v16 + 12);
      v48 = v14;
      v35 = v17;
      v37 = 0;
      if ( *(int *)(v16 + 8) > 0 )
      {
        v18 = (float *)(v17 + 24);
        do
        {
          if ( (*v17 & 0x60) == 0 )
          {
            v19 = v42 + 16 * *((_DWORD *)v8 + 2);
            v33 = sub_5D7920((float *)v19, v46);
            v20 = sub_5D7920((float *)v19, v18 - 2);
            v34 = v20;
            if ( v20 > v33 )
            {
              v21 = sub_5D7920((float *)v19, v18 + 4);
              if ( v21 < v33 )
              {
                v22 = v21 - v34;
                if ( fabs(v22) >= 0.000000001 )
                  v23 = (v33 - v34) / v22;
                else
                  v23 = 0.0;
                v24 = *((__int16 *)v8 + 1);
                v43 = (v18[4] - *(v18 - 2)) * v23 + *(v18 - 2);
                v44 = (v18[5] - *(v18 - 1)) * v23 + *(v18 - 1);
                v45 = (v18[6] - *v18) * v23 + *v18;
                if ( sub_5EC7B0(v24, &v46, &v43) )
                {
                  *v35 = 16;
                  *((_DWORD *)v18 + 9) = a2;
                  *((_DWORD *)v18 + 10) = a3;
                  v18[8] = 0.0;
                  *((_DWORD *)v18 + 7) = this;
                  v18[11] = *(float *)(*((_DWORD *)v8 + 1) + 4);
                  *((_DWORD *)v18 + 13) = v38;
                  v18[14] = 0.0;
                  v25 = v43;
                  *((_DWORD *)v18 + 12) = v37;
                  v26 = v44;
                  v18[19] = v25;
                  v27 = v45;
                  v18[20] = v26;
                  v18[21] = v27;
                  v18[16] = *(float *)v19;
                  v18[17] = *(float *)(v19 + 4);
                  v18[18] = *(float *)(v19 + 8);
                  v28 = v18[4] - v43;
                  v29 = v18[5] - v44;
                  v30 = v18[6] - v45;
                  ++v39;
                  v18[22] = sqrt(v30 * v30 + v29 * v29 + v28 * v28);
                  sub_5FDFA0(v18 + 7);
                }
              }
            }
          }
          v17 = v35 + 29;
          v18 += 29;
          v31 = v37 + 1 < *(_DWORD *)(this[113] + 8);
          v35 += 29;
          ++v37;
        }
        while ( v31 );
        v7 = v38;
        v6 = a3;
      }
    }
    v7 += 18;
    v8 += 9;
    v31 = v41 + 1 < v6[92];
    v38 = v7;
    ++v41;
  }
  while ( v31 );
  return v39;
}
