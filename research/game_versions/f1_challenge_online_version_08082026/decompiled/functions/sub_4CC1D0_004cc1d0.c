int __usercall sub_4CC1D0@<eax>(int a1@<ecx>, double a2@<st0>)
{
  int result; // eax
  int v4; // ebx
  float *v5; // esi
  double v6; // st7
  double v7; // st7
  double v8; // st6
  double v9; // st7
  int v10; // eax
  double v11; // st6
  float *v12; // ebp
  int j; // ebx
  float v14; // ecx
  int v15; // edx
  double v17; // st7
  unsigned __int8 v18; // c0
  unsigned __int8 v19; // c3
  int v20; // eax
  char *v21; // eax
  float v22; // ecx
  int v23; // edx
  float v24; // eax
  float v25; // [esp+0h] [ebp-90h]
  float v26; // [esp+4h] [ebp-8Ch]
  float v27; // [esp+4h] [ebp-8Ch]
  float v28; // [esp+1Ch] [ebp-74h]
  float v29; // [esp+20h] [ebp-70h]
  int i; // [esp+24h] [ebp-6Ch]
  float v31; // [esp+24h] [ebp-6Ch]
  float v32; // [esp+24h] [ebp-6Ch]
  int v33; // [esp+28h] [ebp-68h] BYREF
  int v34; // [esp+2Ch] [ebp-64h]
  float v35; // [esp+30h] [ebp-60h]
  int v36; // [esp+34h] [ebp-5Ch]
  int v37; // [esp+38h] [ebp-58h]
  int v38; // [esp+3Ch] [ebp-54h]
  float v39; // [esp+40h] [ebp-50h]
  float v40; // [esp+44h] [ebp-4Ch]
  int v41; // [esp+48h] [ebp-48h] BYREF
  float v42; // [esp+4Ch] [ebp-44h]
  float v43; // [esp+50h] [ebp-40h]
  float v44; // [esp+54h] [ebp-3Ch]
  float v45; // [esp+58h] [ebp-38h]
  float v46; // [esp+5Ch] [ebp-34h]
  int v47[2]; // [esp+60h] [ebp-30h] BYREF
  float v48; // [esp+68h] [ebp-28h]
  int v49[2]; // [esp+6Ch] [ebp-24h] BYREF
  float v50; // [esp+74h] [ebp-1Ch]
  float v51; // [esp+7Ch] [ebp-14h]
  float v52; // [esp+80h] [ebp-10h]
  float v53; // [esp+8Ch] [ebp-4h]

  if ( dword_8AB6E4 == 2 )
    sub_4B9CE0(&dword_8AB6EC);
  else
    a2 = dbl_8AFEA0;
  result = *(_DWORD *)(a1 + 100);
  v4 = 0;
  v29 = a2;
  for ( i = 0; v4 < result; i = v4 )
  {
    v5 = *(float **)(*(_DWORD *)(a1 + 104) + 4 * v4);
    if ( v29 > (double)v5[3] || v29 < (double)v5[2] )
    {
      sub_4CB5A0((_DWORD *)a1, v5);
      --v4;
    }
    else
    {
      v6 = v29 - v5[2];
      v28 = v6;
      v7 = v6 * v5[14];
      v8 = v28 * v5[15];
      v53 = v28 * v5[16];
      *(float *)&v38 = v7 + v5[11];
      v41 = v38;
      v39 = v8 + v5[12];
      v42 = v39;
      v40 = v53 + v5[13];
      v43 = v40;
      v9 = v28 * v5[26];
      v10 = *((_DWORD *)v5 + 17);
      v11 = v9 * *(float *)(a1 + 24);
      v51 = v9 * *(float *)(a1 + 28);
      v52 = v9 * *(float *)(a1 + 32);
      v44 = v11 + *(float *)(a1 + 12);
      v45 = v51 + *(float *)(a1 + 16);
      v46 = v52 + *(float *)(a1 + 20);
      if ( v10 >= 0 )
      {
        if ( byte_7CF9EC )
        {
          v25 = v40 + *(float *)&v38;
          v12 = sub_4C9C70(flt_8AC4E0, v25, flt_5D3494, &v33);
          for ( j = 0; j < v33; ++j )
          {
            v14 = v12[j];
            v47[0] = *(_DWORD *)(LODWORD(v14) + 1848);
            v15 = *(_DWORD *)(LODWORD(v14) + 1852);
            v48 = *(float *)(LODWORD(v14) + 1856);
            v47[1] = v15;
            if ( fabs(*(float *)v47 - *(float *)&v41) < flt_5D3490
              && fabs(v48 - v43) < flt_5D3490
              && *((_DWORD *)v5 + 17) != *(_DWORD *)(LODWORD(v14) + 4) )
            {
              v26 = v45 * 0.5;
              sub_4CBDD0((float *)&v41, v5 + 21, v26, (float *)v47);
            }
          }
          v4 = i;
        }
        else
        {
          v21 = (char *)&unk_5ECE1C + 18624 * v10;
          v22 = *(float *)v21;
          v23 = *((_DWORD *)v21 + 1);
          v24 = *((float *)v21 + 2);
          *(float *)v49 = v22;
          v50 = v24;
          v49[1] = v23;
          if ( fabs(v22 - *(float *)&v38) < flt_5D3490 && fabs(v50 - v40) < flt_5D3490 )
          {
            v27 = v45 * 0.5;
            sub_4CBDD0((float *)&v41, v5 + 21, v27, (float *)v49);
          }
        }
      }
      sub_558C60(*(_DWORD *)v5, v41, LODWORD(v42), LODWORD(v43));
      sub_558CB0(*(_DWORD *)v5, LODWORD(v44), LODWORD(v45), LODWORD(v46));
      v17 = v28;
      if ( v18 | v19 )
      {
        if ( v17 <= v5[5] )
        {
          v32 = v28 * v5[8] * v5[10];
          v37 = (int)v32;
          v20 = v37;
        }
        else
        {
          v35 = v5[10];
          v36 = (int)v35;
          v20 = v36;
        }
      }
      else
      {
        v31 = (1.0 - (v17 - v5[6]) * v5[9]) * v5[10];
        v34 = (int)v31;
        v20 = v34;
      }
      sub_558CF0(*(_DWORD *)v5, (v20 << 24) + 0xFFFFFF);
    }
    result = *(_DWORD *)(a1 + 100);
    ++v4;
  }
  return result;
}
