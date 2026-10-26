char __thiscall sub_459440(int this, float *a2, int a3, float a4, int a5, float a6)
{
  char v7; // bl
  double v8; // st7
  int v9; // ecx
  int v10; // eax
  double v11; // st7
  long double v12; // st7
  float *v13; // ecx
  int v14; // edx
  int v15; // ecx
  int v16; // edx
  int v17; // eax
  _DWORD *v18; // esi
  int v20; // ecx
  double v21; // st7
  double v22; // st7
  double v23; // st6
  double v24; // st5
  double v25; // st4
  long double v26; // st7
  float v27; // [esp+8h] [ebp-38h]
  float v28; // [esp+Ch] [ebp-34h]
  float v29; // [esp+10h] [ebp-30h]
  float v30; // [esp+14h] [ebp-2Ch]
  float v31; // [esp+18h] [ebp-28h]
  int v32; // [esp+28h] [ebp-18h] BYREF
  float v33; // [esp+2Ch] [ebp-14h]
  float v34; // [esp+30h] [ebp-10h]
  int v35; // [esp+34h] [ebp-Ch]
  int v36; // [esp+38h] [ebp-8h]
  int v37; // [esp+3Ch] [ebp-4h]

  if ( *(_DWORD *)(this + 120) && (unsigned __int8)sub_45A5A0() )
  {
    v7 = 1;
    v27 = *(float *)(this + 128) * *(float *)(this + 124) * a6;
    if ( (*(_DWORD *)(this + 140) & 0x10) != 0 )
    {
      v8 = sub_45A590(*(_DWORD *)(this + 120));
      v9 = *(_DWORD *)(this + 120);
      a6 = *(float *)(this + 132) / v8;
      v10 = sub_45A5C0(v9);
      v28 = sub_45A5D0(v10 - 3);
      v11 = v28 / sub_45A590(*(_DWORD *)(this + 120));
      if ( a6 > v11 )
      {
        if ( a6 > 0.94999999 )
          a6 = 0.94999999;
        v27 = (1.0 - (a6 - v11) / (0.94999999 - v11) * 0.94999999) * v27;
      }
    }
    if ( (*(_DWORD *)(this + 140) & 2) != 0 )
      v12 = sqrt(
              *(float *)LODWORD(a4) * *(float *)LODWORD(a4)
            + *(float *)(LODWORD(a4) + 4) * *(float *)(LODWORD(a4) + 4)
            + *(float *)(LODWORD(a4) + 8) * *(float *)(LODWORD(a4) + 8))
          * v27;
    else
      v12 = v27;
    v20 = *(_DWORD *)(this + 120);
    *(float *)(this + 132) = v12 + *(float *)(this + 132);
    v21 = sub_45A590(v20);
    if ( *(float *)(this + 132) >= 0.0 )
    {
      if ( v21 < *(float *)(this + 132) )
        *(float *)(this + 132) = v21;
    }
    else
    {
      *(_DWORD *)(this + 132) = 0;
    }
    sub_45A580(*(float *)(this + 132), (int)&v32);
    v13 = (float *)(this + 148);
    *(float *)(this + 148) = *(float *)&v32;
    *(float *)(this + 152) = v33;
    *(float *)(this + 156) = v34;
    *(_DWORD *)(this + 160) = v35;
    *(_DWORD *)(this + 164) = v36;
    *(_DWORD *)(this + 168) = v37;
  }
  else
  {
    v13 = (float *)(this + 148);
    *(_DWORD *)(this + 148) = *(_DWORD *)(this + 20);
    v14 = *(_DWORD *)(this + 28);
    *(_DWORD *)(this + 152) = *(_DWORD *)(this + 24);
    v7 = 0;
    *(_DWORD *)(this + 156) = v14;
  }
  if ( *(float *)(this + 136) > 0.0 || v7 )
  {
    if ( *(float *)(this + 136) > 0.0 )
    {
      v29 = *a2 - *v13;
      v30 = a2[1] - v13[1];
      v31 = a2[2] - v13[2];
      v22 = v30 * 0.0;
      v23 = v22 - v31;
      v24 = v31 * 0.0 - v29 * 0.0;
      v25 = v29 - v22;
      *(float *)&v32 = v24 * v31 - v25 * v30;
      v33 = v25 * v29 - v23 * v31;
      v34 = v23 * v30 - v24 * v29;
      sub_5795E0(this + 160);
      if ( (*(_BYTE *)(this + 140) & 1) != 0 )
      {
        sub_4598F0(&a4, &a6);
        v26 = 35.0 / sqrt(v31 * v31 + v30 * v30 + v29 * v29);
        if ( v26 >= 0.1 )
        {
          if ( v26 > 1.0 )
            v26 = 1.0;
        }
        else
        {
          v26 = 0.1;
        }
        a4 = a4 * v26;
        a6 = v26 * a6;
        sub_4599E0(&a4, &a6);
      }
    }
    return 1;
  }
  else
  {
    v15 = *(_DWORD *)(this + 32);
    v16 = *(_DWORD *)(this + 36);
    v17 = *(_DWORD *)(this + 40);
    v18 = (_DWORD *)(this + 160);
    *v18 = v15;
    v18[1] = v16;
    v18[2] = v17;
    return 1;
  }
}
