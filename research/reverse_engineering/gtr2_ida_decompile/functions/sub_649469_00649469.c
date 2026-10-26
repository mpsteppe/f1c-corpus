int __thiscall sub_649469(_DWORD *this, char *a2, unsigned int a3)
{
  int v5; // ecx
  unsigned int v6; // esi
  unsigned int v7; // eax
  int v8; // eax
  int v9; // edi
  int v10; // ecx
  bool v11; // zf
  unsigned int v12; // esi
  unsigned int v13; // eax
  int v14; // eax
  int v15; // ecx
  int v16; // edx
  void *v17; // eax
  float *v18; // edi
  float *v19; // esi
  float *v20; // eax
  double v21; // st7
  double v22; // st7
  int v23; // ecx
  char v24; // [esp+10h] [ebp-214h] BYREF
  char Buffer[256]; // [esp+110h] [ebp-114h] BYREF
  float v26; // [esp+210h] [ebp-14h] BYREF
  int v27; // [esp+214h] [ebp-10h] BYREF
  int v28; // [esp+218h] [ebp-Ch] BYREF
  int v29; // [esp+21Ch] [ebp-8h]
  int v30; // [esp+220h] [ebp-4h]
  _BYTE *v31; // [esp+22Ch] [ebp+8h]
  _BYTE *v32; // [esp+22Ch] [ebp+8h]
  int i; // [esp+22Ch] [ebp+8h]
  BOOL v34; // [esp+230h] [ebp+Ch]

  if ( a3 <= 3 )
    return -2147467259;
  if ( !memcmp("PF\n", a2, 3u) )
  {
    v29 = 0;
  }
  else
  {
    if ( memcmp("Pf\n", a2, 3u) )
      return -2147467259;
    v29 = 1;
  }
  v5 = (int)(a2 + 3);
  v6 = a3 - 3;
  v7 = 256;
  v31 = a2 + 3;
  if ( a3 - 3 <= 0x100 )
    v7 = a3 - 3;
  v8 = sub_646616(v5, v7);
  v9 = v8;
  if ( !v8 )
    return -2147467259;
  sub_649423(Buffer, v8 + 1, v31);
  if ( sscanf(Buffer, "%u %u%s", &v28, &v27, &v24) != 2 )
    return -2147467259;
  v10 = (int)&v31[v9 + 1];
  v11 = -1 - v9 + v6 == 0;
  v12 = -1 - v9 + v6;
  v32 = (_BYTE *)v10;
  if ( v11 )
    return -2147467259;
  v13 = 256;
  if ( v12 <= 0x100 )
    v13 = v12;
  v14 = sub_646616(v10, v13);
  v30 = v14;
  if ( !v14 )
    return -2147467259;
  sub_649423(Buffer, v14 + 1, v32);
  if ( sscanf(Buffer, "%f%s", &v26, &v24) != 1 )
    return -2147467259;
  v34 = v26 >= 0.0;
  v15 = v28;
  v16 = v27;
  if ( v12 - v30 - 1 < 4 * v27 * v28 * (2 * (unsigned int)(v29 == 0) + 1) )
    return -2147467259;
  this[13] = 0;
  this[12] = 16 * v15;
  this[3] = v15;
  *this = 116;
  this[4] = v16;
  this[5] = 1;
  this[14] = 1;
  v17 = operator new(v16 * 16 * v15);
  this[1] = v17;
  if ( !v17 )
    return -2147024882;
  v18 = (float *)&v32[v30 + 1];
  for ( i = v27 - 1; i >= 0; --i )
  {
    v19 = (float *)(this[1] + 16 * v28 * i);
    v20 = &v19[4 * v28];
    v30 = (int)v20;
    if ( v29 )
    {
      if ( v34 )
      {
        if ( v19 != v20 )
        {
          do
          {
            v21 = sub_646637(COERCE_UNSIGNED_INT(*v18));
            v19[2] = v21;
            ++v18;
            v19[1] = v21;
            *v19 = v21;
            v19 += 4;
            v11 = v19 == (float *)v30;
            *(v19 - 1) = 1.0;
          }
          while ( !v11 );
        }
      }
      else
      {
        while ( v19 != v20 )
        {
          v22 = *v18++;
          v19[2] = v22;
          v19[1] = v22;
          *v19 = v22;
          v19 += 4;
          *(v19 - 1) = 1.0;
        }
      }
    }
    else if ( v34 )
    {
      if ( v19 != v20 )
      {
        do
        {
          *v19 = sub_646637(COERCE_UNSIGNED_INT(*v18));
          v19[1] = sub_646637(COERCE_UNSIGNED_INT(v18[1]));
          v19[2] = sub_646637(COERCE_UNSIGNED_INT(v18[2]));
          v19 += 4;
          v18 += 3;
          v11 = v19 == (float *)v30;
          *(v19 - 1) = 1.0;
        }
        while ( !v11 );
      }
    }
    else
    {
      while ( v19 != v20 )
      {
        *v19 = *v18;
        v19[1] = v18[1];
        v23 = *((_DWORD *)v18 + 2);
        v19[3] = 1.0;
        *((_DWORD *)v19 + 2) = v23;
        v18 += 3;
        v19 += 4;
      }
    }
  }
  return 0;
}
