char __thiscall sub_561720(_DWORD *this, float *a2, float *a3, float *a4, float *a5, float *a6, float *a7)
{
  int v8; // eax
  unsigned int v9; // ecx
  double v12; // st7
  float v13; // eax
  float v14; // eax
  float v15; // eax
  double v16; // st7
  double v17; // st7
  double v18; // st7
  __int16 v19; // [esp+4h] [ebp-44h] BYREF
  unsigned __int16 v20; // [esp+6h] [ebp-42h]
  float v21; // [esp+Ch] [ebp-3Ch]
  float v22; // [esp+10h] [ebp-38h]
  float v23; // [esp+14h] [ebp-34h]
  float v24; // [esp+18h] [ebp-30h]
  float v25; // [esp+1Ch] [ebp-2Ch]
  float v26; // [esp+20h] [ebp-28h]
  float v27; // [esp+4Ch] [ebp+4h]
  float v28; // [esp+4Ch] [ebp+4h]
  float v29; // [esp+4Ch] [ebp+4h]

  if ( !sub_48B730((int)&v19) && !v19 )
  {
    v8 = v20;
    if ( *this == v20 )
    {
      v9 = this[1] + 1;
      this[1] = v9;
      if ( v9 > 0x1E )
      {
        *a2 = 0.0;
        *a3 = 0.0;
        *a4 = 0.0;
        *a5 = 0.0;
        *a6 = 0.0;
        *a7 = 0.0;
        return 1;
      }
    }
    v12 = v22;
    *this = v8;
    this[1] = 0;
    *a2 = v12;
    *a3 = v23;
    *a4 = v21;
    *a5 = v24;
    *a6 = v25;
    *a7 = v26;
    if ( *a2 == 0.0 && *a3 == 0.0 && *a4 == 0.0 && *a5 == 0.0 && *a6 == 0.0 && v26 == 0.0 )
      return 1;
    *a2 = *a2 * 0.010986995;
    *a3 = *a3 * 0.010986995;
    *a4 = *a4 * 0.010986995;
    *a2 = *a2 * 0.017453292;
    *a3 = *a3 * 0.017453292;
    *a4 = *a4 * 0.017453292;
    *a3 = -*a3;
    *a2 = -*a2;
    if ( *a5 != 0.0 )
      *a5 = *a5 * 0.000061038882;
    if ( *a6 != 0.0 )
      *a6 = *a6 * 0.000061038882;
    if ( *a7 != 0.0 )
      *a7 = *a7 * 0.000061038882;
    if ( *a5 >= (double)flt_B74728 )
    {
      if ( *a5 <= (double)flt_B7474C )
        goto LABEL_23;
      v13 = flt_B7474C;
    }
    else
    {
      v13 = flt_B74728;
    }
    *a5 = v13;
LABEL_23:
    if ( *a6 >= (double)flt_B74794 )
    {
      if ( *a6 <= (double)flt_B74770 )
        goto LABEL_28;
      v14 = flt_B74770;
    }
    else
    {
      v14 = flt_B74794;
    }
    *a6 = v14;
LABEL_28:
    if ( *a7 >= (double)flt_B747B8 )
    {
      if ( *a7 <= (double)flt_B747DC )
      {
LABEL_33:
        v27 = flt_B746BC * 3.1415927;
        v16 = flt_B74698 * 3.1415927;
        if ( v16 <= *a3 )
        {
          if ( *a3 > (double)v27 )
            *a3 = v27;
        }
        else
        {
          *a3 = v16;
        }
        v28 = flt_B74650 * 3.1415927;
        v17 = flt_B74674 * 3.1415927;
        if ( v17 <= *a2 )
        {
          if ( *a2 > (double)v28 )
            *a2 = v28;
        }
        else
        {
          *a2 = v17;
        }
        v29 = flt_B74704 * 3.1415927;
        v18 = flt_B746E0 * 3.1415927;
        if ( v18 > *a4 )
        {
          *a4 = v18;
          return 1;
        }
        if ( *a4 > (double)v29 )
          *a4 = v29;
        return 1;
      }
      v15 = flt_B747DC;
    }
    else
    {
      v15 = flt_B747B8;
    }
    *a7 = v15;
    goto LABEL_33;
  }
  return 0;
}
