float *__stdcall sub_67CE20(float *a1, float *a2, int a3, unsigned int a4)
{
  unsigned int v4; // esi
  float *v5; // ebx
  unsigned int v6; // edx
  float *v7; // ecx
  float *v8; // ecx
  float v9; // eax
  double v10; // st7
  int v11; // edx
  float *v12; // eax
  unsigned int v13; // edx
  float *v14; // ecx
  double v15; // st7
  unsigned int v16; // eax
  unsigned int v17; // eax
  double v18; // st7
  double v19; // st6
  float *v20; // eax
  float v21; // eax
  double v22; // st7
  double v23; // st7
  float *result; // eax
  float v25[9]; // [esp+Ch] [ebp-54h] BYREF
  int v26; // [esp+30h] [ebp-30h]
  float v27; // [esp+34h] [ebp-2Ch]
  float v28; // [esp+38h] [ebp-28h]
  float v29; // [esp+3Ch] [ebp-24h]
  unsigned int v30; // [esp+40h] [ebp-20h]
  _BYTE *v31; // [esp+44h] [ebp-1Ch]
  int v32; // [esp+48h] [ebp-18h]
  float v33; // [esp+4Ch] [ebp-14h]
  float v34; // [esp+50h] [ebp-10h]
  float v35; // [esp+54h] [ebp-Ch]
  float v36; // [esp+58h] [ebp-8h]
  float v37; // [esp+5Ch] [ebp-4h]

  v4 = a4;
  if ( a4 == 6 )
  {
    v5 = (float *)&unk_73CD2C;
    v31 = &unk_73CD14;
  }
  else
  {
    v5 = (float *)&unk_73CCF4;
    v31 = &unk_73CCD4;
  }
  v6 = 0;
  v37 = 1.0;
  v36 = 0.0;
  if ( a4 == 8 )
  {
    do
    {
      v7 = (float *)(a3 + 4 * v6);
      if ( *v7 < (double)v37 )
        v37 = *v7;
      if ( *v7 > (double)v36 )
        v36 = *v7;
      ++v6;
    }
    while ( v6 < 0x10 );
  }
  else
  {
    do
    {
      v8 = (float *)(a3 + 4 * v6);
      if ( *v8 < (double)v37 && *v8 > 0.0 )
        v37 = *v8;
      if ( *v8 > (double)v36 && *v8 < 1.0 )
        v36 = *v8;
      ++v6;
    }
    while ( v6 < 0x10 );
    if ( v37 == v36 )
      v36 = 1.0;
  }
  v29 = (float)(a4 - 1);
  v32 = v30 | 0xC00;
  v9 = *(float *)&v30;
  v30 = 0;
  v25[8] = v9;
  do
  {
    v10 = v36 - v37;
    if ( v10 < 0.00390625 )
      break;
    v28 = v29 / v10;
    if ( v4 )
    {
      v11 = v31 - (_BYTE *)v5;
      v12 = v5;
      do
      {
        *(float *)((char *)v12 + (char *)v25 - (char *)v5) = v36 * *(float *)((char *)v12 + v11) + v37 * *v12;
        ++v12;
        --v4;
      }
      while ( v4 );
      v4 = a4;
    }
    if ( v4 == 6 )
    {
      v25[6] = 0.0;
      v25[7] = 1.0;
    }
    v13 = 0;
    v35 = 0.0;
    v34 = 0.0;
    v33 = 0.0;
    *(float *)&v32 = 0.0;
    do
    {
      v14 = (float *)(a3 + 4 * v13);
      v15 = (*v14 - v37) * v28;
      if ( v15 > 0.0 )
      {
        if ( v15 < v29 )
        {
          v27 = v15 + 0.5;
          v26 = (int)v27;
          v16 = v26;
        }
        else
        {
          if ( v4 == 6 && (v36 + 1.0) * 0.5 <= *v14 )
            goto LABEL_40;
          v16 = a4 - 1;
        }
      }
      else
      {
        if ( v4 == 6 && v37 * 0.5 >= *v14 )
          goto LABEL_40;
        v16 = 0;
      }
      if ( v16 < v4 )
      {
        v17 = v16;
        v18 = *v14 - v25[v17];
        v35 = v18 * v5[v17] + v35;
        v19 = v5[v17];
        v20 = (float *)&v31[v17 * 4];
        v33 = v19 * v19 + v33;
        v34 = v18 * *v20 + v34;
        *(float *)&v32 = *v20 * *v20 + *(float *)&v32;
      }
LABEL_40:
      ++v13;
    }
    while ( v13 < 0x10 );
    if ( v33 > 0.0 )
      v37 = v37 - v35 / v33;
    if ( *(float *)&v32 > 0.0 )
      v36 = v36 - v34 / *(float *)&v32;
    if ( v37 > (double)v36 )
    {
      v21 = v36;
      v36 = v37;
      v37 = v21;
    }
    if ( v35 * v35 < 0.015625 && v34 * v34 < 0.015625 )
      break;
    ++v30;
  }
  while ( v30 < 8 );
  if ( v37 >= 0.0 )
  {
    if ( v37 <= 1.0 )
      v22 = v37;
    else
      v22 = 1.0;
  }
  else
  {
    v22 = 0.0;
  }
  *a1 = v22;
  if ( v36 >= 0.0 )
  {
    if ( v36 <= 1.0 )
      v23 = v36;
    else
      v23 = 1.0;
  }
  else
  {
    v23 = 0.0;
  }
  result = a2;
  *a2 = v23;
  return result;
}
