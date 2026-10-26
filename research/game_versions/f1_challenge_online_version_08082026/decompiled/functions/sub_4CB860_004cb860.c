int __usercall sub_4CB860@<eax>(int a1@<ecx>, double a2@<st0>)
{
  int result; // eax
  int v4; // ebp
  float *v5; // esi
  double v6; // st7
  double v7; // st7
  double v8; // st6
  double v9; // st7
  double v10; // st7
  double v11; // st6
  double v12; // st5
  double v13; // st6
  float v14; // ecx
  int v15; // ecx
  int v16; // ebx
  float v17; // ebp
  int v18; // ecx
  int v19; // edx
  double v21; // st7
  unsigned __int8 v22; // c0
  unsigned __int8 v23; // c3
  int v24; // eax
  float v25; // [esp+0h] [ebp-B4h]
  float v26; // [esp+1Ch] [ebp-98h]
  int v27; // [esp+20h] [ebp-94h] BYREF
  float v28; // [esp+24h] [ebp-90h]
  float v29; // [esp+28h] [ebp-8Ch]
  float v30; // [esp+2Ch] [ebp-88h]
  float v31; // [esp+30h] [ebp-84h]
  float v32; // [esp+34h] [ebp-80h]
  float v33; // [esp+38h] [ebp-7Ch]
  float v34; // [esp+3Ch] [ebp-78h]
  float v35; // [esp+40h] [ebp-74h]
  int i; // [esp+44h] [ebp-70h]
  int v37; // [esp+48h] [ebp-6Ch]
  int v38[2]; // [esp+4Ch] [ebp-68h] BYREF
  float v39; // [esp+54h] [ebp-60h]
  float v40; // [esp+58h] [ebp-5Ch]
  int v41; // [esp+5Ch] [ebp-58h]
  float v42; // [esp+60h] [ebp-54h]
  float v43; // [esp+64h] [ebp-50h]
  int v44; // [esp+68h] [ebp-4Ch]
  float v45; // [esp+6Ch] [ebp-48h]
  float v46; // [esp+70h] [ebp-44h]
  int v47; // [esp+74h] [ebp-40h]
  int v48[2]; // [esp+78h] [ebp-3Ch] BYREF
  float v49; // [esp+80h] [ebp-34h]
  int v50; // [esp+84h] [ebp-30h]
  int v51[2]; // [esp+88h] [ebp-2Ch] BYREF
  float v52; // [esp+90h] [ebp-24h]
  int v53; // [esp+94h] [ebp-20h]
  float v54; // [esp+98h] [ebp-1Ch]
  float v55; // [esp+A0h] [ebp-14h]
  float v56; // [esp+A4h] [ebp-10h]
  float v57; // [esp+B0h] [ebp-4h]

  if ( dword_8AB6E4 == 2 )
    sub_4B9CE0(&dword_8AB6EC);
  else
    a2 = dbl_8AFEA0;
  result = *(_DWORD *)(a1 + 100);
  v4 = 0;
  v31 = a2;
  for ( i = 0; v4 < result; i = v4 )
  {
    v5 = *(float **)(*(_DWORD *)(a1 + 104) + 4 * v4);
    if ( v31 > (double)v5[3] || v31 < (double)v5[2] )
    {
      sub_4CB5A0((_DWORD *)a1, v5);
      --v4;
    }
    else
    {
      v6 = v31 - v5[2];
      v26 = v6;
      v7 = v6 * v5[14];
      v8 = v26 * v5[15];
      v57 = v26 * v5[16];
      *(float *)&v41 = v7 + v5[11];
      v42 = v8 + v5[12];
      v9 = v57 + v5[13];
      v27 = v41;
      v28 = v42;
      v43 = v9;
      v29 = v43;
      v10 = v26 * *(float *)(a1 + 64);
      sub_5881F0(v10);
      v11 = v5[26];
      v12 = v11 * *(float *)(a1 + 36);
      v55 = v11 * *(float *)(a1 + 40);
      v56 = v11 * *(float *)(a1 + 44);
      *(float *)&v44 = v12 + *(float *)(a1 + 24);
      v38[1] = v44;
      v45 = v55 + *(float *)(a1 + 28);
      v39 = v45;
      v13 = v56 + *(float *)(a1 + 32);
      v32 = *(float *)(a1 + 12);
      v46 = v13;
      v40 = v46;
      v14 = *(float *)(a1 + 20);
      v33 = *(float *)(a1 + 16);
      v39 = v45 * v10;
      v40 = v46 * v10;
      v32 = *(float *)&v44 * v10 + v32;
      v33 = v39 + v33;
      v34 = v40 + v14;
      v35 = v33 * 0.5;
      v28 = v42 + v35;
      if ( dword_7CFA28 == 1 )
      {
        v19 = dword_7C54F0[dword_7C54DC] + 1860;
        v51[0] = *(_DWORD *)v19;
        v51[1] = *(_DWORD *)(v19 + 4);
        v52 = *(float *)(v19 + 8);
        if ( fabs(*(float *)v51 - *(float *)&v27) < flt_5D3490 && fabs(v52 - v29) < flt_5D3490 )
          sub_4CBDD0((int)&v27, (int)(v5 + 21), v35, (int)v51);
      }
      else if ( dword_7CFA28 > 1 && dword_7CFA28 <= 3 )
      {
        if ( dword_7C54E0 )
          v15 = *(_DWORD *)(dword_7C54E0 + 18580);
        else
          v15 = 104;
        v37 = 104;
        if ( (dword_7CFA28 & 1) == 0 )
          v37 = v15;
        v25 = v29 + *(float *)&v27;
        v30 = COERCE_FLOAT(sub_4C9C70(flt_8AC4E0, v25, flt_5D3494, v38));
        v16 = 0;
        if ( v38[0] > 0 )
        {
          v17 = v35;
          do
          {
            v18 = *(_DWORD *)(LODWORD(v30) + 4 * v16);
            v48[0] = *(_DWORD *)(v18 + 1848);
            v48[1] = *(_DWORD *)(v18 + 1852);
            v49 = *(float *)(v18 + 1856);
            if ( fabs(*(float *)v48 - *(float *)&v27) < flt_5D3490
              && fabs(v49 - v29) < flt_5D3490
              && v37 != *(_DWORD *)(v18 + 4) )
            {
              sub_4CBDD0((int)&v27, (int)(v5 + 21), v17, (int)v48);
            }
            ++v16;
          }
          while ( v16 < v38[0] );
          v4 = i;
        }
      }
      sub_558C60(*(_DWORD *)v5, v27, LODWORD(v28), LODWORD(v29));
      sub_558CB0(*(_DWORD *)v5, LODWORD(v32), LODWORD(v33), LODWORD(v34));
      v21 = v26;
      if ( v22 | v23 )
      {
        if ( v21 <= v5[5] )
        {
          v30 = v26 * v5[8] * v5[10];
          v50 = (int)v30;
          v24 = v50;
        }
        else
        {
          v54 = v5[10];
          v47 = (int)v54;
          v24 = v47;
        }
      }
      else
      {
        v30 = (1.0 - (v21 - v5[6]) * v5[9]) * v5[10];
        v53 = (int)v30;
        v24 = v53;
      }
      sub_558CF0(*(_DWORD *)v5, (v24 << 24) + 0xFFFFFF);
    }
    result = *(_DWORD *)(a1 + 100);
    ++v4;
  }
  return result;
}
