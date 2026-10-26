int __thiscall sub_4B21F0(_DWORD *this, float *a2)
{
  int v3; // esi
  int v4; // edx
  int v5; // eax
  unsigned int v6; // edx
  int result; // eax
  float v8; // [esp+10h] [ebp+4h]
  float v9; // [esp+10h] [ebp+4h]
  float v10; // [esp+10h] [ebp+4h]

  if ( *a2 <= 65535.988 )
  {
    if ( *a2 >= -65535.988 )
    {
      v8 = *a2 * 32768.0;
      v3 = (int)v8;
    }
    else
    {
      v3 = -2147483647;
    }
  }
  else
  {
    v3 = 0x7FFFFFFF;
  }
  if ( a2[1] <= 65535.988 )
  {
    if ( a2[1] >= -65535.988 )
    {
      v9 = a2[1] * 32768.0;
      v4 = (int)v9;
    }
    else
    {
      v4 = -2147483647;
    }
  }
  else
  {
    v4 = 0x7FFFFFFF;
  }
  if ( a2[2] <= 65535.988 )
  {
    if ( a2[2] >= -65535.988 )
    {
      v10 = a2[2] * 32768.0;
      v5 = (int)v10;
    }
    else
    {
      v5 = -2147483647;
    }
  }
  else
  {
    v5 = 0x7FFFFFFF;
  }
  *this = ((v4 & 0xFFFFFF00) << 16) + ((v3 >> 8) & 0xFFFFFF);
  v6 = ((v5 & 0xFFFFFF00) << 8) + HIWORD(v4);
  result = v5 >> 24;
  this[1] = v6;
  *((_BYTE *)this + 8) = result;
  return result;
}
