int __thiscall sub_51D720(float *this)
{
  bool v2; // zf
  signed int v3; // eax
  double v4; // st7
  double v5; // st7
  double v6; // st7
  float v7; // esi
  float v9; // [esp+4h] [ebp-Ch]
  float v10; // [esp+4h] [ebp-Ch]
  float v11; // [esp+Ch] [ebp-4h]
  float v12; // [esp+Ch] [ebp-4h]

  v11 = sqrt(this[4386] * this[4386] + this[4387] * this[4387] + this[4388] * this[4388])
      * 2.2369363
      * 0.0024999999
      * (sqrt(this[4386] * this[4386] + this[4387] * this[4387] + this[4388] * this[4388])
       * 2.2369363
       * 0.0024999999);
  v3 = rand() & 0x80000001;
  v2 = v3 == 0;
  if ( v3 < 0 )
    v2 = (((_BYTE)v3 - 1) | 0xFFFFFFFE) == -1;
  if ( v2 )
    v4 = 1.0;
  else
    v4 = -1.0;
  v12 = v11 * 0.30000001 * v4;
  v5 = v12 - this[4407] * 0.050000001;
  v9 = v5;
  if ( v5 >= -0.30000001 )
  {
    if ( v9 > 0.30000001 )
      v9 = 0.30000001;
  }
  else
  {
    v9 = -0.30000001;
  }
  if ( dword_7D5DA4 == 2 )
  {
    if ( sub_4DA080(&dword_7D5DAC) == 5 )
      v6 = 0.0;
    else
      v6 = sub_4D9E30(&dword_7D5DAC);
  }
  else
  {
    v6 = dbl_7DA9C8;
  }
  v7 = *this;
  v10 = (v9 + v12 - *(float *)(LODWORD(v7) + 4764)) * v6 * 8.0 + *(float *)(LODWORD(v7) + 4764);
  if ( v10 < -0.30000001 )
    return sub_50ADD0(LODWORD(v7) + 1892, -0.30000001);
  if ( v10 > 0.30000001 )
    v10 = 0.30000001;
  return sub_50ADD0(LODWORD(v7) + 1892, v10);
}
