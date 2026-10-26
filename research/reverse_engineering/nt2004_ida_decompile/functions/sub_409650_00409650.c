void __thiscall sub_409650(float *this)
{
  const char *v2; // eax
  const char *v3; // eax
  const char *v4; // eax
  double v5; // st7
  char v6; // bl
  double v7; // st7
  char v8; // bl
  double v9; // st7
  char v10; // bl
  double v11; // st7
  double v12; // st7
  double v13; // st6
  double v14; // st6
  double v15; // st7
  double v16; // st7
  double v17; // st7
  double v18; // st7
  float v19; // [esp+4h] [ebp-Ch]
  float v20; // [esp+4h] [ebp-Ch]
  float v21; // [esp+4h] [ebp-Ch]
  float v22; // [esp+8h] [ebp-8h]
  float v23; // [esp+8h] [ebp-8h]
  float v24; // [esp+8h] [ebp-8h]
  float v25; // [esp+Ch] [ebp-4h]
  float v26; // [esp+Ch] [ebp-4h]
  float v27; // [esp+Ch] [ebp-4h]

  if ( !*((_DWORD *)this + 4)
    || byte_76617C
    || !dword_768948
    && (v2 = (const char *)((int (*)(void))sub_459B80)(), _strcmpi(v2, aTvcockpit))
    && (v3 = (const char *)sub_459B80(*((_DWORD *)this + 4)), _strcmpi(v3, aNosecam))
    && (v4 = (const char *)sub_459B80(*((_DWORD *)this + 4)), _strcmpi(v4, aCockpit)) )
  {
    this[15] = 0.0;
    this[14] = 0.0;
    this[16] = 0.0;
  }
  else
  {
    v5 = 0.0;
    v19 = 0.0;
    v22 = 0.0;
    if ( byte_769DF4 == 1 )
    {
      if ( dword_763FD0 )
        dword_763890 = sub_526550();
      sub_526400(&dword_763890);
      v22 = (double)dword_763894 * 0.000095873809;
      if ( flt_769E0C != 1.0 )
      {
        if ( v22 >= 0.0 )
        {
          v6 = 0;
        }
        else
        {
          v6 = 1;
          v22 = v22 * -1.0;
        }
        if ( v22 > 3.1415927 )
        {
          do
          {
            v7 = v22 - 3.1415927;
            v22 = v7;
          }
          while ( v7 > 3.1415927 );
        }
        v22 = pow(v22 * 0.31830987, flt_769E0C) * 3.1415927;
        if ( v6 )
          v22 = v22 * -1.0;
      }
      v19 = -((double)dword_763898 * 0.000095873809);
      if ( flt_769E30 != 1.0 )
      {
        if ( v19 >= 0.0 )
        {
          v8 = 0;
        }
        else
        {
          v8 = 1;
          v19 = v19 * -1.0;
        }
        if ( v19 > 3.1415927 )
        {
          do
          {
            v9 = v19 - 3.1415927;
            v19 = v9;
          }
          while ( v9 > 3.1415927 );
        }
        v19 = pow(v19 * 0.31830987, flt_769E30) * 3.1415927;
        if ( v8 )
          v19 = v19 * -1.0;
      }
      v5 = (double)dword_76389C * 0.000095873809;
      v25 = v5;
      if ( flt_769E54 != 1.0 )
      {
        if ( v5 >= 0.0 )
        {
          v10 = 0;
        }
        else
        {
          v5 = v5 * -1.0;
          v10 = 1;
          v25 = v5;
        }
        if ( v5 > 3.1415927 )
        {
          do
            v5 = v5 - 3.1415927;
          while ( v5 > 3.1415927 );
          v25 = v5;
        }
        v5 = pow(v25 * 0.31830987, flt_769E54) * 3.1415927;
        if ( v10 )
          v5 = v5 * -1.0;
      }
    }
    v20 = flt_763B04 - flt_763AD8 + v19;
    v23 = flt_76418C - flt_7641B8 + v22;
    v26 = flt_764210 - flt_7641E4 + v5;
    if ( dword_75AAC4 )
      v11 = *(float *)(dword_75AAC4 + 4716);
    else
      v11 = 0.0;
    v12 = v11 * flt_767F40 + flt_767EF8 * v20;
    v24 = flt_767E8C * v23;
    v21 = flt_767ED4 * v26;
    if ( flt_767E68 == 0.0 )
    {
      this[15] = v12;
      this[14] = v24;
      this[16] = v21;
    }
    else
    {
      v27 = dbl_7DA9C0 * flt_767E68;
      if ( v12 != this[15] )
      {
        if ( v12 <= this[15] )
        {
          v14 = this[15] - v27;
          this[15] = v14;
          if ( v14 < v12 )
            this[15] = v12;
        }
        else
        {
          v13 = v27 + this[15];
          this[15] = v13;
          if ( v13 > v12 )
            this[15] = v12;
        }
      }
      if ( this[14] != v24 )
      {
        if ( this[14] >= (double)v24 )
        {
          v16 = this[14] - v27;
          this[14] = v16;
          if ( v16 < v24 )
            this[14] = v24;
        }
        else
        {
          v15 = v27 + this[14];
          this[14] = v15;
          if ( v15 > v24 )
            this[14] = v24;
        }
      }
      if ( this[16] != v21 )
      {
        if ( this[16] >= (double)v21 )
        {
          v18 = this[16] - v27;
          this[16] = v18;
          if ( v18 < v21 )
            this[16] = v21;
        }
        else
        {
          v17 = v27 + this[16];
          this[16] = v17;
          if ( v17 > v21 )
            this[16] = v21;
        }
      }
    }
  }
}
