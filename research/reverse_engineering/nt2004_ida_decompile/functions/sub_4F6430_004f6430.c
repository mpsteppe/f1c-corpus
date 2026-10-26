void __thiscall sub_4F6430(_DWORD *this, float *a2, float a3, float *a4, float *a5, int a6)
{
  int v7; // ecx
  double v8; // st7
  double v9; // st6
  double v10; // st7
  double v11; // st7
  double v12; // st7
  double v13; // st7
  double v14; // st7
  int v15; // ecx
  double v16; // st7
  double v17; // st6
  double v18; // st7
  double v19; // st7
  double v20; // st7
  double v21; // st7
  double v22; // st7
  int v23; // ecx
  bool v24; // zf
  signed int v25; // ecx
  double v26; // st7
  double v27; // st6
  double v28; // st7
  double v29; // st7
  double v30; // st7
  double v31; // st7
  double v32; // st7
  int v33; // ecx
  double v34; // st7
  double v35; // st6
  double v36; // st5
  double v37; // st7
  double v38; // st7
  float v39; // [esp+0h] [ebp-60h]
  float v40; // [esp+Ch] [ebp-54h]
  float v41; // [esp+Ch] [ebp-54h]
  float v42; // [esp+Ch] [ebp-54h]
  float v43; // [esp+Ch] [ebp-54h]
  int v44; // [esp+30h] [ebp-30h] BYREF
  float v45; // [esp+34h] [ebp-2Ch]
  float v46; // [esp+38h] [ebp-28h]
  int v47; // [esp+3Ch] [ebp-24h] BYREF
  float v48; // [esp+40h] [ebp-20h]
  float v49; // [esp+44h] [ebp-1Ch]
  int v50; // [esp+48h] [ebp-18h]
  float v51; // [esp+4Ch] [ebp-14h]
  float v52; // [esp+50h] [ebp-10h]
  float v53; // [esp+5Ch] [ebp-4h]

  if ( byte_767DB4 )
  {
    if ( byte_767DE4 )
      a6 = 48;
  }
  else if ( !byte_767DE4 )
  {
    a6 = -1;
  }
  if ( *a2 == 0.0 || !this[8] )
    goto LABEL_14;
  v7 = dword_75AB98;
  if ( dword_767CA0 > 2 || dword_7D5DA4 == 2 || !(dword_75AB98 % 16) )
  {
    if ( fabs(a3 - a2[1]) > 0.15000001 || (v9 = a4[2] - a2[4], v8 = *a4 - a2[2], v9 * v9 + v8 * v8 > 1.0) )
    {
      a2[2] = *a4;
      a2[3] = a4[1];
      a2[4] = a4[2];
      a2[1] = a3;
      v10 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
      v11 = v10 * 0.25 + *a4;
      v45 = a4[1];
      *(float *)&v44 = v11;
      v12 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
      v46 = v12 * 0.25 + a4[2];
      *(float *)&v50 = *a5 * 0.1;
      v13 = a5[1];
      v47 = v50;
      v51 = v13 * 0.1;
      v14 = a5[2];
      v48 = v51;
      v40 = *a2;
      v52 = v14 * 0.1;
      v49 = v52;
      v15 = this[8];
      v48 = v51 + 0.25;
      sub_4F3200(v15, a3, (float *)&v44, (float *)&v47, v40, 0, 0, a6, 0xFFFFFF);
LABEL_14:
      v7 = dword_75AB98;
    }
  }
  if ( a2[5] != 0.0 && this[9] && (dword_767CA0 > 2 || dword_7D5DA4 == 2 || !(v7 % 16)) )
  {
    if ( fabs(a3 - a2[6]) > 0.15000001 || (v17 = a4[2] - a2[9], v16 = *a4 - a2[7], v17 * v17 + v16 * v16 > 1.0) )
    {
      a2[7] = *a4;
      a2[8] = a4[1];
      a2[9] = a4[2];
      a2[6] = a3;
      v18 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
      v19 = v18 * 0.25 + *a4;
      v45 = a4[1];
      *(float *)&v44 = v19;
      v20 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
      v46 = v20 * 0.25 + a4[2];
      *(float *)&v50 = *a5 * 0.1;
      v21 = a5[1];
      v47 = v50;
      v51 = v21 * 0.1;
      v22 = a5[2];
      v48 = v51;
      v41 = a2[5];
      v52 = v22 * 0.1;
      v49 = v52;
      v23 = this[9];
      v48 = v51 + 0.25;
      sub_4F3200(v23, a3, (float *)&v44, (float *)&v47, v41, 0, 0, a6, 0xFFFFFF);
      v7 = dword_75AB98;
    }
  }
  if ( a2[10] != 0.0 && this[10] )
  {
    if ( dword_767CA0 > 1 || dword_7D5DA4 == 2 )
      goto LABEL_36;
    v25 = v7 & 0x8000000F;
    v24 = v25 == 0;
    if ( v25 < 0 )
      v24 = (((_BYTE)v25 - 1) | 0xFFFFFFF0) == -1;
    if ( v24 )
    {
LABEL_36:
      if ( fabs(a3 - a2[11]) > 0.059999999
        || (v27 = a4[2] - a2[14], v26 = *a4 - a2[12], v27 * v27 + v26 * v26 > 0.16000001) )
      {
        a2[12] = *a4;
        a2[13] = a4[1];
        a2[14] = a4[2];
        a2[11] = a3;
        v28 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
        v29 = v28 * 0.15000001 + *a4;
        v45 = a4[1];
        *(float *)&v44 = v29;
        v30 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
        v46 = v30 * 0.15000001 + a4[2];
        *(float *)&v50 = *a5 * 0.1;
        v31 = a5[1];
        v47 = v50;
        v51 = v31 * 0.1;
        v32 = a5[2];
        v48 = v51;
        v42 = a2[10];
        v52 = v32 * 0.1;
        v49 = v52;
        v33 = this[10];
        v48 = v51 + 0.25;
        sub_4F3200(v33, a3, (float *)&v44, (float *)&v47, v42, 0, 0, a6, 0xFFFFFF);
        if ( dword_767CA0 > 2 )
        {
          v34 = *a5;
          v35 = a5[1] * 0.0125;
          v53 = a5[2] * 0.0125;
          *(float *)&v50 = *a4 - v34 * 0.0125;
          v36 = a4[1];
          v44 = v50;
          v51 = v36 - v35;
          v45 = v51;
          v52 = a4[2] - v53;
          v46 = v52;
          v37 = flt_7D4054[(unsigned __int8)dword_7D3C50++] * 0.15000001;
          *(float *)&v44 = v37 + *(float *)&v50;
          v38 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
          v43 = a2[10];
          v46 = v38 * 0.15000001 + v52;
          v39 = a3 - 0.0125;
          sub_4F3200(this[10], v39, (float *)&v44, (float *)&v47, v43, 0, 0, a6, 0xFFFFFF);
        }
      }
    }
  }
}
