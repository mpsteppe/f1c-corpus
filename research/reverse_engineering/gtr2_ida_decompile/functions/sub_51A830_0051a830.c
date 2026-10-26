int __thiscall sub_51A830(_DWORD *this, float *a2)
{
  __int16 v3; // di
  __int16 v4; // si
  int v5; // eax
  int v6; // ecx
  int v7; // esi
  int result; // eax
  float v9; // [esp+0h] [ebp-14h]
  float v10; // [esp+0h] [ebp-14h]
  float v11; // [esp+0h] [ebp-14h]

  if ( *a2 <= 255.97 )
  {
    if ( *a2 >= -255.97 )
    {
      v9 = *a2 * 32.0;
      v3 = sub_4015C0(v9);
    }
    else
    {
      v3 = -8191;
    }
  }
  else
  {
    v3 = 0x1FFF;
  }
  if ( a2[1] <= 127.97 )
  {
    if ( a2[1] >= -127.97 )
    {
      v10 = a2[1] * 32.0;
      v4 = sub_4015C0(v10);
    }
    else
    {
      v4 = -4095;
    }
  }
  else
  {
    v4 = 4095;
  }
  if ( a2[2] <= 255.97 )
  {
    if ( a2[2] >= -255.97 )
    {
      v11 = a2[2] * 32.0;
      v5 = sub_4015C0(v11);
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
  v6 = (v4 & 0x1FFF) + (v5 << 13);
  v7 = this[1];
  *this = (v3 & 0x3FFF) + (v6 << 14);
  result = ((unsigned __int16)v7 ^ (unsigned __int16)(v5 >> 5)) & 0x1FF;
  this[1] = result ^ v7;
  return result;
}
