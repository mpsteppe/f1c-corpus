float *__cdecl sub_513F7A(float *a1, float *a2, int a3, unsigned int a4)
{
  unsigned int v4; // esi
  float *v5; // ebx
  unsigned int v6; // edx
  float *v7; // ecx
  float *v8; // ecx
  double v9; // st7
  int v10; // edx
  float *v11; // eax
  unsigned int v12; // edx
  float *v13; // ecx
  double v14; // st7
  unsigned int v15; // eax
  unsigned int v16; // eax
  double v17; // st7
  double v18; // st6
  float *v19; // eax
  float v20; // eax
  double v21; // st7
  double v22; // st7
  float *result; // eax
  float v24[8]; // [esp+Ch] [ebp-50h] BYREF
  int v25; // [esp+2Ch] [ebp-30h]
  float v26; // [esp+30h] [ebp-2Ch]
  float v27; // [esp+34h] [ebp-28h]
  float v28; // [esp+38h] [ebp-24h]
  unsigned int i; // [esp+3Ch] [ebp-20h]
  _BYTE *v30; // [esp+40h] [ebp-1Ch]
  float v31; // [esp+44h] [ebp-18h]
  float v32; // [esp+48h] [ebp-14h]
  float v33; // [esp+4Ch] [ebp-10h]
  float v34; // [esp+50h] [ebp-Ch]
  float v35; // [esp+54h] [ebp-8h]
  float v36; // [esp+58h] [ebp-4h]

  v4 = a4;
  if ( a4 == 6 )
  {
    v5 = (float *)&unk_5AF5C4;
    v30 = &unk_5AF5AC;
  }
  else
  {
    v5 = (float *)&unk_5AF58C;
    v30 = &unk_5AF56C;
  }
  v6 = 0;
  v36 = 1.0;
  v35 = 0.0;
  if ( a4 == 8 )
  {
    do
    {
      v7 = (float *)(a3 + 4 * v6);
      if ( *v7 < (double)v36 )
        v36 = *v7;
      if ( *v7 > (double)v35 )
        v35 = *v7;
      ++v6;
    }
    while ( v6 < 0x10 );
  }
  else
  {
    do
    {
      v8 = (float *)(a3 + 4 * v6);
      if ( *v8 < (double)v36 && *v8 > 0.0 )
        v36 = *v8;
      if ( *v8 > (double)v35 && *v8 < 1.0 )
        v35 = *v8;
      ++v6;
    }
    while ( v6 < 0x10 );
  }
  v25 = a4 - 1;
  v28 = (float)(a4 - 1);
  sub_513E5D();
  for ( i = 0; i < 8; ++i )
  {
    v9 = v35 - v36;
    if ( v9 < 0.00390625 )
      break;
    v27 = v28 / v9;
    if ( v4 )
    {
      v10 = v30 - (_BYTE *)v5;
      v11 = v5;
      do
      {
        *(float *)((char *)v11 + (char *)v24 - (char *)v5) = v35 * *(float *)((char *)v11 + v10) + v36 * *v11;
        ++v11;
        --v4;
      }
      while ( v4 );
      v4 = a4;
    }
    if ( v4 == 6 )
    {
      v24[6] = 0.0;
      v24[7] = 1.0;
    }
    v12 = 0;
    v34 = 0.0;
    v33 = 0.0;
    v32 = 0.0;
    v31 = 0.0;
    do
    {
      v13 = (float *)(a3 + 4 * v12);
      v14 = (*v13 - v36) * v27;
      if ( v14 > 0.0 )
      {
        if ( v14 < v28 )
        {
          v26 = v14 + 0.5;
          v25 = (int)v26;
          v15 = v25;
        }
        else
        {
          if ( v4 == 6 && (v35 + 1.0) * 0.5 <= *v13 )
            goto LABEL_38;
          v15 = a4 - 1;
        }
      }
      else
      {
        if ( v4 == 6 && v36 * 0.5 >= *v13 )
          goto LABEL_38;
        v15 = 0;
      }
      if ( v15 < v4 )
      {
        v16 = v15;
        v17 = *v13 - v24[v16];
        v34 = v17 * v5[v16] + v34;
        v18 = v5[v16];
        v19 = (float *)&v30[v16 * 4];
        v32 = v18 * v18 + v32;
        v33 = v17 * *v19 + v33;
        v31 = *v19 * *v19 + v31;
      }
LABEL_38:
      ++v12;
    }
    while ( v12 < 0x10 );
    if ( v32 > 0.0 )
      v36 = v36 - v34 / v32;
    if ( v31 > 0.0 )
      v35 = v35 - v33 / v31;
    if ( v36 > (double)v35 )
    {
      v20 = v35;
      v35 = v36;
      v36 = v20;
    }
    if ( v34 * v34 < 0.015625 && v33 * v33 < 0.015625 )
      break;
  }
  if ( v36 >= 0.0 )
  {
    if ( v36 <= 1.0 )
      v21 = v36;
    else
      v21 = 1.0;
  }
  else
  {
    v21 = 0.0;
  }
  *a1 = v21;
  if ( v35 >= 0.0 )
  {
    if ( v35 <= 1.0 )
      v22 = v35;
    else
      v22 = 1.0;
  }
  else
  {
    v22 = 0.0;
  }
  result = a2;
  *a2 = v22;
  return result;
}
