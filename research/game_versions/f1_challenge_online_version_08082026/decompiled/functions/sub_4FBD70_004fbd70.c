int __thiscall sub_4FBD70(_DWORD *this)
{
  char *v2; // esi
  int v3; // ebx
  int v4; // ebx
  int v5; // ecx
  int v6; // ebp
  double v7; // st7
  double v8; // st7
  int v9; // ebx
  int j; // esi
  int v11; // eax
  int result; // eax
  int v13; // ebp
  int v14; // ecx
  int v15; // ebx
  double v16; // st7
  int v17; // ebp
  int v18; // esi
  double v19; // st7
  int v20; // eax
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
  int v32; // [esp+28h] [ebp-20h]
  float v33; // [esp+28h] [ebp-20h]
  float v34; // [esp+2Ch] [ebp-1Ch]
  float v35; // [esp+30h] [ebp-18h]
  int v36; // [esp+34h] [ebp-14h]
  float v37; // [esp+3Ch] [ebp-Ch] BYREF
  float v38; // [esp+40h] [ebp-8h] BYREF
  float v39; // [esp+44h] [ebp-4h] BYREF

  if ( this[17] == dword_7C56A4 )
  {
    this[17] = -1;
    sub_4FC550(0);
  }
  sub_40C910(&dword_5EA510);
  sub_542460(&v37, &v38, &v39);
  if ( *this )
  {
    v25 = *((float *)this + 3) - v39 * flt_7CF950;
    v21 = *((float *)this + 1) - v37 * flt_7CF950;
    sub_54B3B0(LODWORD(v21), this[2], LODWORD(v25));
  }
  v2 = (char *)(this + 6);
  v3 = 3;
  do
  {
    if ( *((_DWORD *)v2 - 2) )
    {
      v22 = *(float *)v2 - v38;
      sub_54B3B0(*((_DWORD *)v2 - 1), LODWORD(v22), *((_DWORD *)v2 + 1));
    }
    v2 += 16;
    --v3;
  }
  while ( v3 );
  if ( flt_8AFEC8 == *((float *)this + 46) )
  {
    v28 = 0;
  }
  else
  {
    v28 = 1;
    *((float *)this + 46) = flt_8AFEC8;
  }
  v4 = 0;
  for ( i = 0; v4 < this[18]; i = v4 )
  {
    v5 = this[28];
    if ( v5 && (*((float *)this + 29) != 0.0 || *((float *)this + 30) != 0.0) )
    {
      v26 = dbl_8AFE98 * *((float *)this + 30);
      v23 = dbl_8AFE98 * *((float *)this + 29);
      sub_54BF60(v5, 0, v23, v26);
    }
    v6 = sub_54C230(0);
    if ( v28 && v6 )
    {
      v7 = 1.0 - flt_8AFEC8;
      if ( v7 >= 0.5 )
        v8 = 1.0;
      else
        v8 = v7 + v7;
      v32 = sub_587BDC(v8 * 254.0 + 0.5) << 24;
      if ( v32 )
        sub_54C030(1, 1, 1, 0);
      else
        sub_54C030(0, 0, 1, 0);
      v9 = sub_54E100(v6);
      for ( j = 0; j < v9; *(_DWORD *)(v11 + 24) |= v32 )
      {
        v11 = sub_54E120(j);
        *(_BYTE *)(v11 + 27) = 0;
        ++j;
      }
      sub_54B3F0(0.0, 0.0, 0.0);
      v4 = i;
      *(_DWORD *)(v6 + 20) &= ~0x10000000u;
    }
    ++v4;
  }
  result = this[31];
  v13 = 0;
  for ( k = 0; v13 < result; k = v13 )
  {
    v14 = this[41];
    if ( v14 && (*((float *)this + 42) != 0.0 || *((float *)this + 43) != 0.0) )
    {
      v27 = dbl_8AFE98 * *((float *)this + 43);
      v24 = dbl_8AFE98 * *((float *)this + 42);
      sub_54BF60(v14, 0, v24, v27);
    }
    if ( *((float *)this + 45) > (double)*((float *)this + 44) )
    {
      v34 = 1.0 / (*((float *)this + 45) - *((float *)this + 44));
      v15 = sub_54C230(0);
      if ( v28 )
      {
        if ( v15 )
        {
          v16 = flt_8AFEC8;
          if ( byte_7CF938 )
          {
            v16 = v16 + v16;
            v31 = v16 - 1.0;
          }
          else
          {
            v31 = flt_8AFEC8;
          }
          v35 = v16 - v31;
          if ( v16 > 0.0 || v31 > 0.0 )
            sub_54C030(1, 1, 1, 0);
          else
            sub_54C030(0, 0, 1, 0);
          v17 = 0;
          v36 = sub_54E100(v15);
          if ( v36 > 0 )
          {
            do
            {
              v18 = sub_54E120(v17);
              v19 = (*(float *)v18 - *((float *)this + 44)) * v34 * v35 + v31;
              v33 = v19;
              if ( v19 <= 1.0 )
              {
                if ( v33 >= 0.0 )
                  v20 = sub_587BDC(v33 * 254.0 + 0.5);
                else
                  v20 = 0;
              }
              else
              {
                v20 = 254;
              }
              *(_BYTE *)(v18 + 27) = 0;
              ++v17;
              *(_DWORD *)(v18 + 24) |= v20 << 24;
            }
            while ( v17 < v36 );
          }
          sub_54B3F0(0.0, 0.0, 0.0);
          v13 = k;
          *(_DWORD *)(v15 + 20) &= ~0x10000000u;
        }
      }
    }
    result = this[31];
    ++v13;
  }
  return result;
}
