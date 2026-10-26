int __thiscall sub_46CF80(int this, float *a2, float *a3, float a4)
{
  long double v5; // st7
  _DWORD *v6; // edi
  int v7; // ecx
  float *v8; // eax
  float *v9; // eax
  int *v10; // eax
  float v11; // edx
  int v12; // edx
  int v13; // ecx
  int v14; // eax
  _DWORD *v15; // esi
  int result; // eax
  float *v17; // eax
  float v18; // ecx
  double v19; // st7
  double v20; // st7
  double v21; // st6
  float *v22; // esi
  float v23; // [esp+8h] [ebp-30h]
  float v24; // [esp+8h] [ebp-30h]
  float v25; // [esp+Ch] [ebp-2Ch]
  float v26; // [esp+Ch] [ebp-2Ch]
  float v27; // [esp+10h] [ebp-28h]
  float v28; // [esp+10h] [ebp-28h]
  float v29; // [esp+10h] [ebp-28h]
  float v30; // [esp+14h] [ebp-24h]
  float v31; // [esp+14h] [ebp-24h]
  float v32; // [esp+14h] [ebp-24h]
  float v33; // [esp+14h] [ebp-24h]
  float v34; // [esp+18h] [ebp-20h]
  float v35; // [esp+18h] [ebp-20h]
  float v36; // [esp+18h] [ebp-20h]
  float v37; // [esp+18h] [ebp-20h]
  float v38; // [esp+1Ch] [ebp-1Ch]
  float v39; // [esp+1Ch] [ebp-1Ch]
  float v40; // [esp+1Ch] [ebp-1Ch]
  float v41; // [esp+1Ch] [ebp-1Ch]
  float v42; // [esp+20h] [ebp-18h]
  float v43; // [esp+20h] [ebp-18h]
  float v44; // [esp+20h] [ebp-18h]
  float v45; // [esp+24h] [ebp-14h]
  float v46; // [esp+24h] [ebp-14h]
  float v47; // [esp+24h] [ebp-14h]
  float v48; // [esp+28h] [ebp-10h]
  float v49; // [esp+28h] [ebp-10h]
  float v50; // [esp+28h] [ebp-10h]
  float v51; // [esp+2Ch] [ebp-Ch]
  float v52; // [esp+2Ch] [ebp-Ch]
  float v53; // [esp+30h] [ebp-8h]
  float v54; // [esp+30h] [ebp-8h]
  float v55; // [esp+34h] [ebp-4h]
  float v56; // [esp+3Ch] [ebp+4h]
  float v57; // [esp+44h] [ebp+Ch]

  v5 = *(float *)(this + 172);
  v6 = (_DWORD *)(this + 12);
  v48 = *(float *)(this + 20);
  v42 = *(float *)(this + 12);
  v45 = *(float *)(this + 16);
  if ( (*(_BYTE *)(this + 116) & 2) != 0 )
  {
    if ( !*(_BYTE *)(this + 208) )
    {
      v7 = this + 180;
      if ( *(_DWORD *)(this + 180) )
      {
        *(_BYTE *)(this + 208) = 1;
        v8 = (float *)sub_46C1E0((float *)v7, 0.0);
      }
      else
      {
        v8 = 0;
      }
      v30 = *v8 * -1.0;
      v23 = v30;
      v34 = v8[1] * -1.0;
      v25 = v34;
      v57 = *(float *)(this + 188);
      v38 = v8[2] * -1.0;
      v27 = v38;
      if ( *(_DWORD *)v7 )
      {
        *(_BYTE *)(v7 + 28) = 1;
        v9 = (float *)sub_46C1E0((float *)v7, v57);
      }
      else
      {
        v9 = 0;
      }
      v31 = *v9 * -1.0;
      v35 = v9[1] * -1.0;
      v43 = v31;
      v46 = v35;
      v39 = v9[2] * -1.0;
      v49 = v39;
      v32 = v23 - *a2;
      v36 = v25 - a2[1];
      v40 = v27 - a2[2];
      v51 = v43 - *a2;
      v53 = v46 - a2[1];
      v55 = v49 - a2[2];
      if ( v55 * v55 + v53 * v53 + v51 * v51 < v40 * v40 + v36 * v36 + v32 * v32 )
      {
        v11 = *(float *)(this + 188);
        *(_DWORD *)(this + 176) = -1082130432;
        if ( *(_DWORD *)v7 )
        {
          *(_BYTE *)(v7 + 28) = 1;
          v10 = sub_46C1E0((float *)v7, v11);
          goto LABEL_15;
        }
      }
      else
      {
        *(_DWORD *)(this + 176) = 1065353216;
        if ( *(_DWORD *)v7 )
        {
          *(_BYTE *)(v7 + 28) = 1;
          v10 = sub_46C1E0((float *)v7, 0.0);
LABEL_15:
          v12 = v10[1];
          v13 = *v10;
          v14 = v10[2];
          *v6 = v13;
          v15 = (_DWORD *)(this + 36);
          v6[1] = v12;
          *v15 = 0;
          v6[2] = v14;
          result = 0;
          v15[1] = 0;
          v15[2] = 0;
          return result;
        }
      }
      v10 = 0;
      goto LABEL_15;
    }
    v5 = sqrt(*a3 * *a3 + a3[1] * a3[1] + a3[2] * a3[2]) * *(float *)(this + 172);
  }
  v56 = v5 * *(float *)(this + 176) * a4 + *(float *)(this + 192);
  if ( *(_DWORD *)(this + 180) )
  {
    *(_BYTE *)(this + 208) = 1;
    v17 = (float *)sub_46C1E0((float *)(this + 180), v56);
  }
  else
  {
    v17 = 0;
  }
  v52 = *v17;
  v18 = v17[2];
  v54 = v17[1];
  *v6 = *(_DWORD *)v17;
  v6[1] = *((_DWORD *)v17 + 1);
  v6[2] = *((_DWORD *)v17 + 2);
  if ( a4 <= 0.0 )
  {
    v20 = 0.0;
    v28 = 0.0;
    v21 = 0.0;
  }
  else
  {
    v33 = v52 - v42;
    v37 = v54 - v45;
    v41 = v18 - v48;
    v19 = 1.0 / a4;
    v44 = v33 * v19;
    v47 = v37 * v19;
    v50 = v41 * v19;
    v28 = v50;
    v20 = v44;
    v21 = v47;
  }
  v22 = (float *)(this + 36);
  v24 = v20 * -1.0;
  result = LODWORD(v24);
  *v22 = v24;
  v26 = v21 * -1.0;
  v22[1] = v26;
  v29 = v28 * -1.0;
  v22[2] = v29;
  return result;
}
