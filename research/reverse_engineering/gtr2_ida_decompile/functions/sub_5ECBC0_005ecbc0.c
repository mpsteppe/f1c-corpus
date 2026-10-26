int __thiscall sub_5ECBC0(_DWORD *this, int a2, _DWORD *a3, int a4)
{
  int result; // eax
  float **v6; // ecx
  float *v7; // esi
  float *v8; // edi
  float *v9; // ebp
  int v10; // edx
  double v11; // st7
  int v12; // esi
  int v13; // eax
  int v14; // edx
  int v15; // eax
  int v16; // eax
  int v17; // edx
  _BYTE *v18; // ecx
  float *v19; // esi
  double v20; // st7
  float *v21; // ebp
  double v22; // st7
  long double v23; // st6
  __int16 v24; // ax
  long double v25; // st7
  long double v26; // st7
  int v27; // eax
  float v28; // edx
  float v29; // ecx
  float v30; // edx
  float v31; // ecx
  float v32; // edx
  float v33; // ecx
  double v34; // st6
  double v35; // st5
  bool v36; // cc
  unsigned __int16 *v37; // [esp+Ch] [ebp-7Ch]
  float *v38; // [esp+10h] [ebp-78h]
  float v39; // [esp+14h] [ebp-74h]
  float v40; // [esp+18h] [ebp-70h]
  _DWORD *v41; // [esp+1Ch] [ebp-6Ch]
  int v42; // [esp+20h] [ebp-68h]
  int v43; // [esp+24h] [ebp-64h]
  float v44; // [esp+28h] [ebp-60h]
  float v45; // [esp+28h] [ebp-60h]
  int v46; // [esp+2Ch] [ebp-5Ch]
  int v47; // [esp+30h] [ebp-58h]
  float v48; // [esp+34h] [ebp-54h] BYREF
  float v49; // [esp+38h] [ebp-50h]
  float v50; // [esp+3Ch] [ebp-4Ch]
  float v51; // [esp+40h] [ebp-48h] BYREF
  float v52; // [esp+44h] [ebp-44h]
  float v53; // [esp+48h] [ebp-40h]
  float v54; // [esp+4Ch] [ebp-3Ch] BYREF
  float v55; // [esp+50h] [ebp-38h]
  float v56; // [esp+54h] [ebp-34h]
  float *v57[3]; // [esp+58h] [ebp-30h] BYREF
  float v58[3]; // [esp+64h] [ebp-24h] BYREF
  float v59[3]; // [esp+70h] [ebp-18h] BYREF
  float v60[3]; // [esp+7Ch] [ebp-Ch] BYREF

  result = 0;
  v43 = 0;
  if ( (int)this[136] > 0 && (v6 = (float **)this[133]) != 0 )
  {
    v38 = *v6;
    v7 = *v6;
  }
  else
  {
    v7 = 0;
    v38 = 0;
  }
  v47 = a3[95];
  v37 = (unsigned __int16 *)a3[93];
  v46 = 0;
  if ( (int)a3[92] > 0 )
  {
    v8 = (float *)(a3[93] + 4);
    do
    {
      v9 = (float *)(a2 + 184);
      sub_5D7810(v8 + 4, &v54, (float *)(a2 + 184));
      v10 = this[113];
      v54 = v7[57] - v54;
      v55 = v7[58] - v55;
      v56 = v7[59] - v56;
      v11 = *(float *)(v10 + 4) + v8[7];
      v44 = v11 * v11;
      if ( sub_5D7920(&v54, &v54) <= v44 )
      {
        v12 = *((_DWORD *)v8 + 1);
        v13 = *v37;
        v14 = *(_DWORD *)(v12 + 32);
        if ( (*(_BYTE *)v12 & 8) != 0 )
        {
          sub_5D7810((float *)(v14 + 88 * v13), v58, v9);
          sub_5D7810((float *)(*(_DWORD *)(v12 + 32) + 88 * *((unsigned __int16 *)v8 - 1)), v59, v9);
          v15 = 88 * *(unsigned __int16 *)v8;
        }
        else
        {
          sub_5D7810((float *)(v14 + (v13 << 6)), v58, v9);
          sub_5D7810((float *)(*(_DWORD *)(v12 + 32) + (*((unsigned __int16 *)v8 - 1) << 6)), v59, v9);
          v15 = *(unsigned __int16 *)v8 << 6;
        }
        sub_5D7810((float *)(*(_DWORD *)(v12 + 32) + v15), v60, v9);
        v57[1] = v59;
        v16 = this[113];
        v57[0] = v58;
        v17 = *(_DWORD *)(v16 + 8);
        v57[2] = v60;
        v18 = *(_BYTE **)(v16 + 12);
        v41 = v18;
        v42 = 0;
        if ( v17 > 0 )
        {
          v19 = (float *)(v18 + 24);
          while ( 1 )
          {
            if ( (*v18 & 0x60) == 0 )
            {
              sub_5D77B0((float *)(v47 + 16 * *((_DWORD *)v8 + 2)), &v48, (float *)(a2 + 184));
              v39 = sub_5D7920(&v48, v58);
              v20 = sub_5D7920(&v48, v19 - 2);
              v40 = v20;
              if ( v20 > v39 )
              {
                v21 = v19 + 4;
                v22 = sub_5D7920(&v48, v19 + 4);
                if ( v22 < v39 )
                  break;
              }
            }
LABEL_29:
            v18 = v41 + 29;
            v19 += 29;
            v36 = v42 + 1 < *(_DWORD *)(this[113] + 8);
            v41 += 29;
            ++v42;
            if ( !v36 )
              goto LABEL_30;
          }
          v23 = fabs(v48);
          v45 = fabs(v49);
          if ( v23 <= v45 )
          {
            if ( fabs(v50) < v45 )
            {
              v24 = 2;
              if ( v49 <= 0.0 )
                v24 = 3;
              goto LABEL_24;
            }
          }
          else if ( v23 > fabs(v50) )
          {
            v24 = v48 <= 0.0;
LABEL_24:
            v25 = v22 - v40;
            *((_WORD *)v8 + 1) = v24;
            if ( fabs(v25) >= 0.000000001 )
              v26 = (v39 - v40) / v25;
            else
              v26 = 0.0;
            v27 = *((__int16 *)v8 + 1);
            v51 = (*v21 - *(v19 - 2)) * v26 + *(v19 - 2);
            v52 = (v19[5] - *(v19 - 1)) * v26 + *(v19 - 1);
            v53 = (v19[6] - *v19) * v26 + *v19;
            if ( sub_5EC7B0(v27, v57, &v51) )
            {
              *v41 = 16;
              *((_DWORD *)v19 + 9) = a2;
              *((_DWORD *)v19 + 10) = a3;
              v19[8] = 0.0;
              *((_DWORD *)v19 + 7) = this;
              v19[11] = *(float *)(*((_DWORD *)v8 + 1) + 4);
              *((_DWORD *)v19 + 13) = v37;
              *((_DWORD *)v19 + 12) = v42;
              v28 = v52;
              v19[14] = 0.0;
              v29 = v51;
              v19[20] = v28;
              v30 = v48;
              v19[19] = v29;
              v31 = v53;
              v19[16] = v30;
              v32 = v50;
              v19[21] = v31;
              v33 = v49;
              v19[18] = v32;
              v19[17] = v33;
              v34 = v19[5] - v52;
              v35 = v19[6] - v53;
              ++v43;
              v19[22] = sqrt(v35 * v35 + v34 * v34 + (*v21 - v51) * (*v21 - v51));
              sub_5FDFA0(v19 + 7);
            }
            goto LABEL_29;
          }
          v24 = 4;
          if ( v50 <= 0.0 )
            v24 = 5;
          goto LABEL_24;
        }
LABEL_30:
        v7 = v38;
      }
      v37 += 18;
      v8 += 9;
      ++v46;
    }
    while ( v46 < a3[92] );
    return v43;
  }
  return result;
}
