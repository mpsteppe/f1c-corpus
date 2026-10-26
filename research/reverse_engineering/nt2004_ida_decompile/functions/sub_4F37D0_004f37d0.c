int __thiscall sub_4F37D0(int this)
{
  double v2; // st7
  int result; // eax
  int v4; // ebx
  float *v5; // esi
  double v6; // st7
  double v7; // st7
  double v8; // st6
  double v9; // st7
  double v10; // st6
  int v11; // eax
  float *v12; // ebp
  int j; // ebx
  float v14; // ecx
  float v15; // edx
  double v17; // st7
  unsigned __int8 v18; // c0
  unsigned __int8 v19; // c3
  int v20; // eax
  float *v21; // eax
  float v22; // ecx
  float v23; // edx
  float v24; // eax
  float v25; // [esp+0h] [ebp-9Ch]
  float v26; // [esp+1Ch] [ebp-80h]
  float v27; // [esp+20h] [ebp-7Ch]
  int i; // [esp+24h] [ebp-78h]
  float v29; // [esp+24h] [ebp-78h]
  float v30; // [esp+24h] [ebp-78h]
  int v31; // [esp+28h] [ebp-74h] BYREF
  int v32; // [esp+2Ch] [ebp-70h]
  float v33; // [esp+30h] [ebp-6Ch]
  int v34; // [esp+34h] [ebp-68h]
  int v35; // [esp+38h] [ebp-64h]
  float v36; // [esp+3Ch] [ebp-60h]
  float v37; // [esp+40h] [ebp-5Ch]
  float v38; // [esp+44h] [ebp-58h]
  float v39; // [esp+48h] [ebp-54h] BYREF
  float v40; // [esp+4Ch] [ebp-50h]
  float v41; // [esp+50h] [ebp-4Ch]
  float v42; // [esp+54h] [ebp-48h]
  float v43; // [esp+58h] [ebp-44h] BYREF
  float v44; // [esp+5Ch] [ebp-40h]
  float v45; // [esp+60h] [ebp-3Ch]
  float v46; // [esp+64h] [ebp-38h]
  float v47; // [esp+68h] [ebp-34h]
  float v48[2]; // [esp+6Ch] [ebp-30h] BYREF
  float v49; // [esp+74h] [ebp-28h]
  float v50[2]; // [esp+78h] [ebp-24h] BYREF
  float v51; // [esp+80h] [ebp-1Ch]
  float v52; // [esp+88h] [ebp-14h]
  float v53; // [esp+8Ch] [ebp-10h]
  float v54; // [esp+98h] [ebp-4h]

  if ( dword_7D5DA4 == 2 )
    v2 = sub_4D9E20(&dword_7D5DAC);
  else
    v2 = dbl_7DA9D0;
  result = *(_DWORD *)(this + 108);
  v4 = 0;
  v27 = v2;
  for ( i = 0; v4 < result; i = v4 )
  {
    v5 = *(float **)(*(_DWORD *)(this + 112) + 4 * v4);
    if ( v27 > (double)v5[3] || v27 < (double)v5[2] )
    {
      sub_4F2B40((_DWORD *)this, v5);
      --v4;
    }
    else
    {
      v6 = v27 - v5[2];
      v26 = v6;
      v7 = v6 * v5[14];
      v8 = v26 * v5[15];
      v54 = v26 * v5[16];
      v36 = v7 + v5[11];
      v39 = v36;
      v37 = v8 + v5[12];
      v40 = v37;
      v38 = v54 + v5[13];
      v41 = v38;
      v9 = v26 * v5[26];
      v10 = v9 * *(float *)(this + 24);
      v52 = v9 * *(float *)(this + 28);
      v53 = v9 * *(float *)(this + 32);
      v45 = v10 + *(float *)(this + 12);
      v42 = v45;
      v46 = v52 + *(float *)(this + 16);
      v43 = v46;
      v47 = v53 + *(float *)(this + 20);
      v44 = v47;
      v11 = *((_DWORD *)v5 + 17);
      if ( v11 >= 0 )
      {
        if ( byte_767DE4 )
        {
          v25 = v38 + v36;
          v12 = sub_4F1080(flt_7D6BD0, v25, flt_61139C, &v31);
          for ( j = 0; j < v31; ++j )
          {
            v14 = v12[j];
            v48[0] = *(float *)(LODWORD(v14) + 4664);
            v15 = *(float *)(LODWORD(v14) + 4668);
            v49 = *(float *)(LODWORD(v14) + 4672);
            v48[1] = v15;
            if ( fabs(v48[0] - v39) < flt_611398
              && fabs(v49 - v41) < flt_611398
              && *((_DWORD *)v5 + 17) != *(_DWORD *)(LODWORD(v14) + 4) )
            {
              sub_4F3390(&v39, &v43, v5 + 21, v48);
            }
          }
          v4 = i;
        }
        else
        {
          v21 = (float *)((char *)&unk_62D1F4 + 25304 * v11);
          v22 = *v21;
          v23 = v21[1];
          v24 = v21[2];
          v50[0] = v22;
          v51 = v24;
          v50[1] = v23;
          if ( fabs(v22 - v36) < flt_611398 && fabs(v51 - v38) < flt_611398 )
            sub_4F3390(&v39, &v43, v5 + 21, v50);
        }
      }
      sub_5B0B40(*(_DWORD *)v5, LODWORD(v39), LODWORD(v40), LODWORD(v41));
      sub_5B0B90(*(_DWORD *)v5, LODWORD(v42), LODWORD(v43), LODWORD(v44));
      v17 = v26;
      if ( v18 | v19 )
      {
        if ( v17 <= v5[5] )
        {
          v30 = v26 * v5[8] * v5[10];
          v35 = (int)v30;
          v20 = v35;
        }
        else
        {
          v33 = v5[10];
          v34 = (int)v33;
          v20 = v34;
        }
      }
      else
      {
        v29 = (1.0 - (v17 - v5[6]) * v5[9]) * v5[10];
        v32 = (int)v29;
        v20 = v32;
      }
      sub_5B0C30(*(_DWORD *)v5, *((_DWORD *)v5 + 24) + (v20 << 24));
    }
    result = *(_DWORD *)(this + 108);
    ++v4;
  }
  return result;
}
