double __thiscall sub_4A6340(_DWORD **this)
{
  _DWORD *v2; // edi
  _DWORD *v3; // ecx
  _DWORD *v4; // ecx
  int v5; // eax
  _DWORD *v6; // ecx
  double v7; // st7
  int v8; // ebp
  int v9; // edi
  int v10; // edx
  int *v11; // ecx
  int v12; // eax
  int v13; // eax
  _DWORD *v14; // ecx
  float v15; // ecx
  double v16; // st6
  double v17; // st6
  double v18; // st6
  double v19; // st6
  double v20; // st6
  double v21; // st6
  int v22; // edx
  int i; // ecx
  double v24; // st7
  double v25; // st7
  double v26; // st7
  int v27; // ebp
  int v28; // edi
  double v29; // st7
  _DWORD *v30; // ecx
  double v31; // st7
  double v32; // st7
  float v33; // ecx
  double v34; // st7
  double v35; // st7
  double v36; // st7
  _DWORD *v37; // ecx
  int v39; // [esp+0h] [ebp-68h]
  float v40; // [esp+0h] [ebp-68h]
  int v41; // [esp+4h] [ebp-64h]
  float v42; // [esp+14h] [ebp-54h]
  float v43; // [esp+18h] [ebp-50h]
  float v44; // [esp+18h] [ebp-50h]
  float v45[5]; // [esp+1Ch] [ebp-4Ch] BYREF
  float v46; // [esp+30h] [ebp-38h] BYREF
  char v47; // [esp+34h] [ebp-34h]
  float v48[6]; // [esp+38h] [ebp-30h]
  char v49; // [esp+50h] [ebp-18h]
  float v50; // [esp+54h] [ebp-14h]
  int v51; // [esp+58h] [ebp-10h]
  float v52; // [esp+5Ch] [ebp-Ch]
  int v53; // [esp+60h] [ebp-8h]
  float v54; // [esp+64h] [ebp-4h]

  v2 = this + 111;
  v3 = this + 111;
  *v3 = 0;
  v3[1] = 0;
  v3[2] = 0;
  v3[3] = 0;
  v3[4] = 0;
  v4 = *this;
  v42 = 0.0;
  if ( this[11] )
  {
    v5 = sub_4BBF20(v4 + 4109);
    v6 = this[2];
    LODWORD(v45[0]) = v5;
    *v2 = 1;
    v42 = (float)v5;
    if ( v6 )
    {
      v45[0] = (float)v5;
      sub_4A3820(v6, v45);
      sub_4A3560(this[2], (int)this[104]);
    }
  }
  else
  {
    v7 = 0.0;
    if ( !v4[3250] )
    {
      v7 = (*((float *)this + 99) + 25.0 - dbl_8AFEA0) * 0.5;
      if ( v7 >= 0.0 )
      {
        if ( v7 > 4.5 )
          v7 = 4.5;
      }
      else
      {
        v7 = 0.0;
      }
      v8 = v4[4111];
      if ( v4[4112] == 2 )
        ++v8;
      v9 = (int)this[88];
      v10 = 0;
      if ( v9 > 0 )
      {
        v11 = (int *)(this + 89);
        while ( 1 )
        {
          v12 = *v11;
          if ( *v11 >= 0 )
            break;
          ++v10;
          v11 += 2;
          if ( v10 >= v9 )
            goto LABEL_22;
        }
        if ( v8 <= v12 + 1 && v8 < v12 - 1 )
        {
          v13 = v10 + 1;
          if ( v10 + 1 < v9 )
          {
            v14 = &this[2 * v13 + 89];
            do
            {
              *v14 = 0x80000000;
              ++v13;
              v14 += 2;
            }
            while ( v13 < (int)this[88] );
          }
        }
        this[2 * v10 + 89] = (_DWORD *)0x80000000;
      }
    }
LABEL_22:
    v15 = *(float *)this;
    v46 = v7;
    v48[4] = 5.5;
    v48[5] = 1.0;
    v51 = 1065353216;
    v53 = 1056964608;
    v54 = 0.0;
    this[108] = *(_DWORD **)(LODWORD(v15) + 14724);
    v16 = (double)(int)this[27] * *((double *)this + 12) + *((double *)this + 11);
    *((float *)this + 110) = v16;
    v45[0] = v16;
    if ( v16 <= *((float *)this + 108) )
    {
      if ( dword_7C56A4 != 7 )
        sub_4F1890(LODWORD(v45[0]));
      v49 = 0;
    }
    else
    {
      v17 = *((float *)this + 110);
      this[112] = (_DWORD *)1;
      v45[0] = (v17 - *((float *)this + 108)) * 0.083333336;
      v18 = flt_8AAE74[(unsigned __int8)dword_8AAE70++];
      v19 = v18 + v18;
      v43 = v19;
      v20 = v19 + v45[0] + v7 + 1.5;
      if ( v20 > 0.0 )
        v42 = v20;
      v21 = v43 + *((float *)this + 104);
      v49 = 1;
      v50 = v43;
      v52 = v45[0];
      *((float *)this + 109) = v21 + v7 + 1.0;
    }
    if ( this[43] )
    {
      v22 = dword_8AAE70;
      v44 = 0.0;
      for ( i = 0; i < 4; ++i )
      {
        v24 = flt_8AAE74[(unsigned __int8)v22++];
        dword_8AAE70 = v22;
        v25 = v24 * (v24 * v24) + v24 * (v24 * v24);
        v45[i + 1] = v25;
        if ( v44 < v25 )
          v44 = v25;
        v48[i] = v25;
      }
      v26 = v44 + v46 + 6.5;
      if ( v42 < v26 )
        v42 = v26;
      v39 = (int)this[43];
      this[113] = (_DWORD *)1;
      v47 = 1;
      v27 = sub_4A5820(this, v39);
      v28 = 0;
      if ( (int)this[86][4] > 0 )
      {
        while ( v27 != sub_4D7570(v28) )
        {
          if ( ++v28 >= this[86][4] )
            goto LABEL_41;
        }
        sub_4F1A60(v28, 1);
      }
LABEL_41:
      v29 = v44 + *((float *)this + 104);
      this[116] = this[104];
      *((float *)this + 117) = v29 + v46 + 5.5;
    }
    else
    {
      v47 = 0;
    }
    v30 = this[59];
    if ( v30 != this[60] )
    {
      v31 = v46;
      this[114] = (_DWORD *)1;
      v32 = v31 + 8.0;
      if ( v42 < v32 )
        v42 = v32;
      if ( v54 < 8.0 )
        v54 = 8.0;
      this[60] = v30;
      sub_4F1860(27, (double)(int)this[59] * *((double *)this + 28) + *((double *)this + 27));
    }
    if ( this[75] )
    {
      this[115] = (_DWORD *)1;
      if ( dword_83EE60 < 1023 )
      {
        ++dword_83EE60;
        dword_8AAE64 += 432;
      }
      v40 = dbl_8AFEA0;
      sub_4B33B0(6, 0, 0, this[1], LODWORD(v40), 0);
      v33 = *(float *)this;
      v34 = v46 + 8.5;
      if ( (*this)[821] )
      {
        if ( !*(_BYTE *)(LODWORD(v33) + 3348) )
        {
          v45[0] = v46 + 8.0;
          if ( v34 <= v45[0] )
            v34 = v45[0];
        }
      }
      if ( *(_DWORD *)(LODWORD(v33) + 3352) )
      {
        if ( !*(_BYTE *)(LODWORD(v33) + 3416) )
        {
          v45[0] = v46 + 39.0;
          if ( v34 <= v45[0] )
            v34 = v45[0];
        }
      }
      v35 = v34 + flt_8AAE74[(unsigned __int8)dword_8AAE70++];
      if ( v42 < v35 )
        v42 = v35;
      v36 = v35 - v46;
      if ( v54 < v36 )
        v54 = v36;
    }
    v37 = this[2];
    if ( v37 )
    {
      sub_4A35F0(v37, (int)&v46);
      sub_4A3560(this[2], (int)this[104]);
      sub_4A34A0(this[2], 1);
      if ( dword_7CF884 > 0 )
      {
        if ( *((_BYTE *)*this + 4188) )
        {
          v41 = (*this)[1045];
          *((_BYTE *)*this + 4188) = 0;
          sub_4E0ED0(v41);
        }
      }
    }
  }
  if ( (*this)[3250] == 1 && sub_42AEE0(*this) )
    return 0.0;
  else
    return v42;
}
