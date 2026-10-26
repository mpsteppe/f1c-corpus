int __thiscall sub_52A110(_DWORD *this)
{
  int result; // eax
  char *v3; // esi
  int v4; // ebx
  int v5; // ebx
  int v6; // ecx
  int v7; // ebp
  double v8; // st7
  double v9; // st7
  int v10; // ebx
  int j; // esi
  int v12; // eax
  int v13; // ebp
  int v14; // ecx
  int v15; // ebx
  double v16; // st7
  int v17; // ebp
  int v18; // esi
  double v19; // st7
  __int64 v20; // rax
  float v21; // [esp+0h] [ebp-48h]
  float v22; // [esp+4h] [ebp-44h]
  float v23; // [esp+4h] [ebp-44h]
  float v24; // [esp+4h] [ebp-44h]
  float v25; // [esp+8h] [ebp-40h]
  float v26; // [esp+8h] [ebp-40h]
  float v27; // [esp+8h] [ebp-40h]
  char v28; // [esp+1Fh] [ebp-29h]
  int i; // [esp+20h] [ebp-28h]
  int k; // [esp+20h] [ebp-28h]
  float v31; // [esp+24h] [ebp-24h]
  unsigned int v32; // [esp+28h] [ebp-20h]
  float v33; // [esp+28h] [ebp-20h]
  float v34; // [esp+2Ch] [ebp-1Ch]
  float v35; // [esp+30h] [ebp-18h]
  int v36; // [esp+34h] [ebp-14h]
  float v37; // [esp+3Ch] [ebp-Ch] BYREF
  float v38; // [esp+40h] [ebp-8h] BYREF
  float v39; // [esp+44h] [ebp-4h] BYREF

  if ( this[17] == dword_75CBB0 )
  {
    this[17] = -1;
    sub_52A7D0(0);
  }
  result = sub_40C4B0(&dword_6291CC);
  if ( result )
  {
    sub_593DE0(&v37, &v38, &v39);
    if ( *this )
    {
      v25 = *((float *)this + 3) - v39 * flt_767D48;
      v21 = *((float *)this + 1) - v37 * flt_767D48;
      sub_59E050(LODWORD(v21), this[2], LODWORD(v25));
    }
    v3 = (char *)(this + 6);
    v4 = 3;
    do
    {
      if ( *((_DWORD *)v3 - 2) )
      {
        v22 = *(float *)v3 - v38;
        sub_59E050(*((_DWORD *)v3 - 1), LODWORD(v22), *((_DWORD *)v3 + 1));
      }
      v3 += 16;
      --v4;
    }
    while ( v4 );
    if ( flt_7DAAE8 == *((float *)this + 46) )
    {
      v28 = 0;
    }
    else
    {
      v28 = 1;
      *((float *)this + 46) = flt_7DAAE8;
    }
    v5 = 0;
    for ( i = 0; v5 < this[18]; i = v5 )
    {
      v6 = this[28];
      if ( v6 && (*((float *)this + 29) != 0.0 || *((float *)this + 30) != 0.0) )
      {
        v26 = dbl_7DA9C8 * *((float *)this + 30);
        v23 = dbl_7DA9C8 * *((float *)this + 29);
        sub_59EBF0(v6, 0, v23, v26);
      }
      v7 = sub_59EFF0(0);
      if ( v28 && v7 )
      {
        v8 = 1.0 - flt_7DAAE8;
        if ( v8 >= 0.5 )
          v9 = 1.0;
        else
          v9 = v8 + v8;
        v32 = (unsigned int)(__int64)(v9 * 254.0 + 0.5) << 24;
        if ( v32 )
          sub_59ECC0(1, 1, 1, 0);
        else
          sub_59ECC0(0, 0, 1, 0);
        v10 = sub_59CB20(v7);
        for ( j = 0; j < v10; *(_DWORD *)(v12 + 24) |= v32 )
        {
          v12 = sub_59CB40(j);
          *(_BYTE *)(v12 + 27) = 0;
          ++j;
        }
        sub_59E090(0.0, 0.0, 0.0);
        v5 = i;
        *(_DWORD *)(v7 + 20) &= ~0x10000000u;
      }
      ++v5;
    }
    result = this[31];
    v13 = 0;
    for ( k = 0; v13 < result; k = v13 )
    {
      v14 = this[41];
      if ( v14 && (*((float *)this + 42) != 0.0 || *((float *)this + 43) != 0.0) )
      {
        v27 = dbl_7DA9C8 * *((float *)this + 43);
        v24 = dbl_7DA9C8 * *((float *)this + 42);
        sub_59EBF0(v14, 0, v24, v27);
      }
      if ( *((float *)this + 45) > (double)*((float *)this + 44) )
      {
        v34 = 1.0 / (*((float *)this + 45) - *((float *)this + 44));
        v15 = sub_59EFF0(0);
        if ( v28 )
        {
          if ( v15 )
          {
            v16 = flt_7DAAE8;
            if ( byte_767D30 )
            {
              v16 = v16 + v16;
              v31 = v16 - 1.0;
            }
            else
            {
              v31 = flt_7DAAE8;
            }
            v35 = v16 - v31;
            if ( v16 > 0.0 || v31 > 0.0 )
              sub_59ECC0(1, 1, 1, 0);
            else
              sub_59ECC0(0, 0, 1, 0);
            v17 = 0;
            v36 = sub_59CB20(v15);
            if ( v36 > 0 )
            {
              do
              {
                v18 = sub_59CB40(v17);
                v19 = (*(float *)v18 - *((float *)this + 44)) * v34 * v35 + v31;
                v33 = v19;
                if ( v19 <= 1.0 )
                {
                  if ( v33 >= 0.0 )
                    v20 = (__int64)(v33 * 254.0 + 0.5);
                  else
                    LODWORD(v20) = 0;
                }
                else
                {
                  LODWORD(v20) = 254;
                }
                *(_BYTE *)(v18 + 27) = 0;
                ++v17;
                *(_DWORD *)(v18 + 24) |= (_DWORD)v20 << 24;
              }
              while ( v17 < v36 );
            }
            sub_59E090(0.0, 0.0, 0.0);
            v13 = k;
            *(_DWORD *)(v15 + 20) &= ~0x10000000u;
          }
        }
      }
      result = this[31];
      ++v13;
    }
  }
  return result;
}
