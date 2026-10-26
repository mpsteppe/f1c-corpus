bool __thiscall sub_45CA20(unsigned __int8 *this, unsigned int a2, float *a3, float a4)
{
  bool result; // al
  int v6; // edx
  int v7; // ebx
  double v8; // st7
  double v9; // st7
  float *v10; // edx
  int v11; // eax
  int v12; // edi
  bool v13; // cc
  int v14; // esi
  float v15; // [esp+0h] [ebp-38h]
  float v16; // [esp+14h] [ebp-24h]
  _WORD v17[16]; // [esp+18h] [ebp-20h] BYREF

  if ( dword_5EF9A0[4656 * a2] != 2 )
  {
    *a3 = 0.0;
    return 1;
  }
  v7 = BoundedByteArrayAccessor(this, a2);
  if ( !v7 )
  {
    *a3 = 9.9989996;
    return 0;
  }
  if ( *(float *)&this[4 * v6 + 4388] > 0.0 )
  {
    *a3 = *(float *)&this[4 * v6 + 4388];
    return 1;
  }
  result = v7 == 16;
  if ( LOBYTE(a4) && v7 != 16 )
  {
    *a3 = 9.9989996;
    return result;
  }
  qmemcpy(v17, &this[32 * v6 + 1060], sizeof(v17));
  sub_5890AA(v17, v7, 2, sub_45C760);
  v8 = (double)v7 * 0.33399999;
  if ( v8 < 1.0 )
    v8 = 1.0;
  a4 = COERCE_FLOAT(CRTFtol(v8));
  v9 = 1.0 / (double)SLODWORD(a4);
  v10 = a3;
  v11 = (v7 - LODWORD(a4)) / 2;
  v12 = v11 + LODWORD(a4);
  v13 = v11 < v11 + LODWORD(a4);
  *a3 = 0.0;
  v14 = v11;
  if ( v13 )
  {
    do
    {
      ShortToFloatConversion(v17[v14++], &a4);
      v16 = v9;
      *v10 = a4 * v16 + *v10;
    }
    while ( v14 < v12 );
  }
  if ( v7 == 16 )
  {
    *(float *)&this[4 * a2 + 4388] = *v10;
    if ( flt_7D108C >= (double)*v10 && *v10 >= 0.0 )
    {
      FloatToShortViaFtol(0.0, &this[2 * a2 + 4804]);
      return v7 == 16;
    }
    v15 = flt_7D108C * 0.25 - *v10;
    FloatToShortViaFtol(v15, &this[2 * a2 + 4804]);
  }
  return v7 == 16;
}
