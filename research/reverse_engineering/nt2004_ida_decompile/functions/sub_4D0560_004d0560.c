int __thiscall sub_4D0560(int this, float *a2)
{
  int v3; // edi
  int v4; // edx
  int v5; // eax
  int v6; // esi
  unsigned __int8 v7; // dl
  int result; // eax
  float v9; // [esp+10h] [ebp+4h]
  float v10; // [esp+10h] [ebp+4h]
  float v11; // [esp+10h] [ebp+4h]

  if ( *a2 <= 255.875 )
  {
    if ( *a2 >= -255.875 )
    {
      v9 = *a2 * 8.0;
      v3 = (int)v9;
    }
    else
    {
      LOWORD(v3) = -2047;
    }
  }
  else
  {
    LOWORD(v3) = 2047;
  }
  if ( a2[1] <= 63.875 )
  {
    if ( a2[1] >= -63.875 )
    {
      v10 = a2[1] * 8.0;
      v4 = (int)v10;
    }
    else
    {
      LOWORD(v4) = -511;
    }
  }
  else
  {
    LOWORD(v4) = 511;
  }
  if ( a2[2] <= 255.875 )
  {
    if ( a2[2] >= -255.875 )
    {
      v11 = a2[2] * 8.0;
      v5 = (int)v11;
    }
    else
    {
      v5 = -2047;
    }
  }
  else
  {
    v5 = 2047;
  }
  v6 = (v4 & 0x3FF) + (v5 << 10);
  v7 = *(_BYTE *)(this + 12);
  *(_DWORD *)(this + 8) = (v3 & 0xFFF) + (v6 << 12);
  result = (v7 ^ (unsigned __int8)(v5 >> 10)) & 3;
  *(_WORD *)(this + 12) ^= result;
  return result;
}
