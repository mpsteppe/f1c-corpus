int __thiscall sub_54B570(int this, float *a2, int a3)
{
  int v4; // eax
  float v5; // ecx
  float v6; // edx
  char *v7; // eax
  char *v8; // ecx
  char *v9; // edx
  char *v10; // edi
  long double v11; // st7
  long double v12; // st6
  long double v13; // st5
  long double v14; // st4
  long double v15; // st3
  _DWORD *v16; // edi
  _DWORD *v17; // eax
  int v18; // esi
  _DWORD *v19; // ecx
  int v20; // edx
  float v22; // [esp+4h] [ebp-48h]
  float v23; // [esp+8h] [ebp-44h]
  char v24; // [esp+Ch] [ebp-40h] BYREF
  char v25; // [esp+1Ch] [ebp-30h] BYREF
  char v26; // [esp+2Ch] [ebp-20h] BYREF
  char v27; // [esp+3Ch] [ebp-10h] BYREF
  float v28; // [esp+50h] [ebp+4h]

  if ( (*(_DWORD *)(this + 60) & 0x2100) != 0 )
    BitmaskClear((_DWORD *)this, 64, 0, 0);
  v4 = *(_DWORD *)(this + 60);
  if ( (v4 & 0x40) != 0 )
    return 0;
  if ( a2 )
  {
    if ( (v4 & 0x2000) != 0 )
    {
      *(float *)(this + 48) = 3.1415927 - a2[13];
    }
    else if ( (v4 & 0x100) != 0 )
    {
      *(float *)(this + 48) = 3.1415927 - a2[13];
      *(float *)(this + 44) = -a2[12];
      *(float *)(this + 52) = -a2[14];
    }
  }
  if ( (v4 & 0x20) != 0 )
  {
    v5 = *(float *)(this + 100);
    v6 = *(float *)(this + 96);
    *(_DWORD *)(this + 60) = v4 & 0xFFFFFFDF;
    EulerAngleToRotationMatrix(this + 108, v6, v5, *(float *)(this + 104));
    MultiFieldSetter((_DWORD *)(this + 108), *(_DWORD *)(this + 84), *(_DWORD *)(this + 88), *(_DWORD *)(this + 92));
  }
  if ( (*(_BYTE *)(this + 60) & 1) != 0 )
  {
    v7 = &v24;
    v8 = &v25;
    v9 = &v26;
    v10 = &v27;
  }
  else if ( *(_DWORD *)(this + 64) )
  {
    v7 = (char *)(this + 212);
    v8 = (char *)(this + 228);
    v9 = (char *)(this + 244);
    v10 = (char *)(this + 260);
  }
  else
  {
    v7 = (char *)(this + 276);
    v8 = (char *)(this + 292);
    v9 = (char *)(this + 308);
    v10 = (char *)(this + 324);
  }
  v11 = sin(*(float *)(this + 44));
  v12 = cos(*(float *)(this + 44));
  v13 = sin(*(float *)(this + 48));
  v28 = cos(*(float *)(this + 48));
  v14 = sin(*(float *)(this + 52));
  v15 = cos(*(float *)(this + 52));
  *((_DWORD *)v7 + 3) = 0;
  v23 = v15 * v28;
  v22 = v14 * v28;
  *(float *)v7 = v13 * v11 * v14 + v23;
  *((float *)v7 + 1) = v14 * v12;
  *((float *)v7 + 2) = v22 * v11 - v15 * v13;
  *((_DWORD *)v8 + 3) = 0;
  *(float *)v8 = v13 * v11 * v15 - v22;
  *((float *)v8 + 1) = v15 * v12;
  *((float *)v8 + 2) = v14 * v13 + v23 * v11;
  *((_DWORD *)v9 + 3) = 0;
  *(float *)v9 = v13 * v12;
  *((float *)v9 + 1) = -v11;
  *((float *)v9 + 2) = v28 * v12;
  *(_DWORD *)v10 = *(_DWORD *)(this + 32);
  *((_DWORD *)v10 + 1) = *(_DWORD *)(this + 36);
  *((_DWORD *)v10 + 2) = *(_DWORD *)(this + 40);
  *((_DWORD *)v10 + 3) = 1065353216;
  *(_DWORD *)(this + 60) |= 0x40u;
  TransformationMatrixUpdate(0);
  v16 = (_DWORD *)(this + 340);
  v17 = (_DWORD *)(this + 276);
  v18 = 4;
  do
  {
    v19 = v16;
    v20 = 4;
    do
    {
      *v19 = *v17;
      v19 += 4;
      ++v17;
      --v20;
    }
    while ( v20 );
    ++v16;
    --v18;
  }
  while ( v18 );
  if ( a3 )
    *(_DWORD *)(a3 + 20) &= 0xDFFFFFD7;
  return 1;
}
