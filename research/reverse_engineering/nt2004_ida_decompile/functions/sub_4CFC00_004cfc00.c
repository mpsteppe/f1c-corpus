int __thiscall sub_4CFC00(int this, float *a2)
{
  int v3; // esi
  int v4; // edx
  int v5; // eax
  int v6; // edx
  int result; // eax
  float v8; // [esp+10h] [ebp+4h]
  float v9; // [esp+10h] [ebp+4h]
  float v10; // [esp+10h] [ebp+4h]

  if ( *a2 <= 7.9688001 )
  {
    if ( *a2 >= -7.9688001 )
    {
      v8 = *a2 * 32.0;
      v3 = (int)v8;
    }
    else
    {
      LOWORD(v3) = -255;
    }
  }
  else
  {
    LOWORD(v3) = 255;
  }
  if ( a2[1] <= 31.992001 )
  {
    if ( a2[1] >= -31.992001 )
    {
      v9 = a2[1] * 128.0;
      v4 = (int)v9;
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
  if ( a2[2] <= 7.9688001 )
  {
    if ( a2[2] >= -7.9688001 )
    {
      v10 = a2[2] * 32.0;
      v5 = (int)v10;
    }
    else
    {
      v5 = -255;
    }
  }
  else
  {
    v5 = 255;
  }
  v6 = *(_DWORD *)(this + 4) & 0x1FF | (((v3 & 0x1FF) + (((v4 & 0x1FFF) - (v5 << 13)) << 9)) << 9);
  result = v5 >> 1;
  *(_DWORD *)(this + 4) = v6;
  *(_BYTE *)(this + 8) = result;
  return result;
}
