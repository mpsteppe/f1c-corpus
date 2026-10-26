int __thiscall sub_4CFA90(int *this, float *a2)
{
  int v3; // esi
  int v4; // edx
  int v5; // eax
  int v6; // edi
  unsigned int v7; // edx
  int result; // eax
  float v9; // [esp+10h] [ebp+4h]
  float v10; // [esp+10h] [ebp+4h]
  float v11; // [esp+10h] [ebp+4h]

  if ( *a2 <= 255.97 )
  {
    if ( *a2 >= -255.97 )
    {
      v9 = *a2 * 32.0;
      v3 = (int)v9;
    }
    else
    {
      LOWORD(v3) = -8191;
    }
  }
  else
  {
    LOWORD(v3) = 0x1FFF;
  }
  if ( a2[1] <= 127.97 )
  {
    if ( a2[1] >= -127.97 )
    {
      v10 = a2[1] * 32.0;
      v4 = (int)v10;
    }
    else
    {
      LOWORD(v4) = -4095;
    }
  }
  else
  {
    LOWORD(v4) = 4095;
  }
  if ( a2[2] <= 255.97 )
  {
    if ( a2[2] >= -255.97 )
    {
      v11 = a2[2] * 32.0;
      v5 = (int)v11;
    }
    else
    {
      v5 = -8191;
    }
  }
  else
  {
    v5 = 0x1FFF;
  }
  v6 = (v3 & 0x3FFF) + (((v4 & 0x1FFF) + (v5 << 13)) << 14);
  v7 = this[1] & 0xFFFFFE00;
  *this = v6;
  result = v7 | (v5 >> 5) & 0x1FF;
  this[1] = result;
  return result;
}
