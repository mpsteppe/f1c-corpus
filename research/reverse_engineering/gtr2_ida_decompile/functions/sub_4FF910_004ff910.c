bool __thiscall sub_4FF910(int *this)
{
  int v2; // edi
  int v3; // ecx
  float v4; // eax
  float v5; // edx
  double v6; // st7
  double v7; // st7
  double v8; // st7
  double v9; // st7
  int v10; // eax
  int v12; // eax
  int v13; // ecx
  bool v14; // c0
  int v15; // edi
  double v16; // st7
  char v17; // fps^1
  double v18; // st5
  bool v19; // c0
  char v20; // c2
  bool v21; // c3
  char v22; // ah
  float *v23; // edi
  float v24; // ecx
  float v25; // edx
  float v26; // [esp+0h] [ebp-A8h]
  float v27; // [esp+14h] [ebp-94h]
  float v28; // [esp+18h] [ebp-90h]
  float v29; // [esp+1Ch] [ebp-8Ch]
  float v30; // [esp+20h] [ebp-88h] BYREF
  float v31; // [esp+24h] [ebp-84h]
  float v32; // [esp+28h] [ebp-80h]
  float v33; // [esp+2Ch] [ebp-7Ch]
  float v34; // [esp+30h] [ebp-78h]
  float v35[2]; // [esp+34h] [ebp-74h] BYREF
  float v36; // [esp+3Ch] [ebp-6Ch]
  float v37; // [esp+40h] [ebp-68h]
  float v38; // [esp+48h] [ebp-60h]
  float v39; // [esp+4Ch] [ebp-5Ch]
  float v40; // [esp+54h] [ebp-54h]
  float v41; // [esp+58h] [ebp-50h]
  float v42; // [esp+5Ch] [ebp-4Ch]
  float v43; // [esp+60h] [ebp-48h]
  int v44; // [esp+64h] [ebp-44h]
  _BYTE v45[12]; // [esp+68h] [ebp-40h] BYREF
  float v46; // [esp+74h] [ebp-34h]
  float v47; // [esp+78h] [ebp-30h]
  float v48; // [esp+7Ch] [ebp-2Ch]
  float v49[3]; // [esp+80h] [ebp-28h] BYREF
  _BYTE v50[28]; // [esp+8Ch] [ebp-1Ch] BYREF

  sub_401410();
  v2 = *this + 16;
  sub_577780(v49, v50);
  v30 = v49[0] - v46;
  v27 = v30;
  v3 = *this;
  v31 = v49[1] - v47;
  v28 = v31;
  v32 = v49[2] - v48;
  v29 = v32;
  if ( !*(_DWORD *)(v3 + 14820) )
  {
    v4 = *(float *)(v2 + 15996);
    v5 = *(float *)(v2 + 16004);
    v31 = *(float *)(v2 + 16000);
    v32 = v5;
    v30 = v4;
    sub_614A90(v45, v35);
    v41 = v36;
    v42 = v38;
    v43 = v40;
    v6 = v31 * v31 + v30 * v30 + v32 * v32;
    v34 = v6;
    if ( v6 < 0.040000003 && !dword_91E230 )
    {
      v7 = flt_BE08A4[(unsigned __int8)dword_BE08A0++];
      if ( v7 > 0.64999998 && *(_DWORD *)(*this + 19380) != 1 )
      {
        v8 = v36 * v27 + v28 * v38 + v29 * v40;
        if ( v8 <= 1.5 )
        {
          if ( v8 < -5.0 )
            sub_4EE320(49, *this);
        }
        else
        {
          sub_4EE320(48, *this);
        }
      }
    }
    if ( *(float *)(v2 + 15944) * v41 + *(float *)(v2 + 15968) * v43 + *(float *)(v2 + 15956) * v42 > 0.85000002 )
    {
      v9 = v27 * v27 + v29 * v29 + v28 * v28;
      v33 = v9;
      if ( v9 <= 55000.0 || v33 >= 60000.0 || v34 <= 100.0 )
      {
        if ( v33 > 28750.0 && v33 < 34650.0 && v34 > 275.0 )
          sub_4EE320(50, *this);
      }
      else
      {
        sub_4EE320(61, *this);
      }
      if ( v33 < 4800.0 && v34 > 250.0 )
        sub_4EE320(51, *this);
    }
  }
  if ( !*(_DWORD *)(*this + 14820)
    && (*(_DWORD *)dword_B640C8 == 6
     || !*(_DWORD *)dword_B640C8 && (v10 = this[2]) != 0 && (*(_DWORD *)(v10 + 12) & 0x20) == 0)
    && byte_B72218
    && !byte_B660DC )
  {
    return dword_B68534 == 8;
  }
  if ( v27 * v27 + v29 * v29 + v28 * v28 > 25.0 )
  {
    v12 = *(_DWORD *)(v2 + 17476);
    v13 = 0;
    while ( v12 != v44 )
    {
      v12 = *(_DWORD *)(v12 + 276);
      if ( v12 )
      {
        if ( ++v13 < 15 )
          continue;
      }
      goto LABEL_37;
    }
    *((_BYTE *)this + 749) = 0;
LABEL_37:
    if ( *((_BYTE *)this + 749) )
      return 0;
    sub_614A90(v45, v35);
    v14 = v36 * v27 + v28 * v38 + v29 * v40 < 0.0;
    goto LABEL_39;
  }
  sub_614A90(v45, v35);
  v16 = v36 * v27 + v28 * v38 + v29 * v40;
  if ( v16 > 1.5 )
    return 0;
  if ( v16 < -5.0 )
  {
    sub_41FC00(*this);
    if ( *(_DWORD *)(*this + 14820) || !dword_B6FA0C || this[188] == 4 )
      return 0;
    v15 = off_9034A4;
    if ( dword_82F4A0 < 1023 )
    {
      ++dword_82F4A0;
      off_9034A4 += 848;
    }
    goto LABEL_45;
  }
  if ( fabs(v35[0] * v27 + v39 * v29 + v37 * v28) > 1.5 )
  {
    if ( v16 >= 0.0 || *(_DWORD *)(*this + 14820) || !dword_B6FA0C || this[188] == 4 )
      return 0;
    v15 = off_9034A4;
    if ( dword_82F4A0 < 1023 )
    {
      ++dword_82F4A0;
      off_9034A4 += 848;
    }
LABEL_45:
    v26 = dbl_FB1D18;
    sub_51B2A0(6, 5, 1, this[1], LODWORD(v26), 0);
    *(_BYTE *)(v15 + 8) = 4;
    sub_4FD580();
    return 0;
  }
  v18 = v36 * *(float *)(v2 + 15944) + *(float *)(v2 + 15956) * v38 + *(float *)(v2 + 15968) * v40;
  v19 = v18 < 0.85000002;
  v20 = 0;
  v21 = v18 == 0.85000002;
  v22 = v17;
  v14 = v16 < 0.0;
  if ( !__SETP__(v22 & 5, 0) )
  {
LABEL_39:
    if ( !v14 || *(_DWORD *)(*this + 14820) || !dword_B6FA0C || this[188] == 4 )
      return 0;
    v15 = off_9034A4;
    if ( dword_82F4A0 < 1023 )
    {
      ++dword_82F4A0;
      off_9034A4 += 848;
    }
    goto LABEL_45;
  }
  v23 = (float *)(v2 + 15996);
  v24 = v23[1];
  v25 = v23[2];
  v30 = *v23;
  v31 = v24;
  v32 = v25;
  if ( v16 >= 0.0 )
  {
    if ( sub_401200(&v30) > 0.040000003 )
      return 0;
  }
  else if ( sub_401200(&v30) > 4.0 )
  {
    return 0;
  }
  return 1;
}
