// f1c  0x004b2310  size=262
int __thiscall sub_4B2310(_DWORD *this, _DWORD *a2, float *a3)
{
  __int16 v3; // ax
  __int16 v4; // ax
  int result; // eax
  float v6; // [esp+4h] [ebp+4h]
  float v7; // [esp+4h] [ebp+4h]
  float v8; // [esp+4h] [ebp+4h]
  int v9; // [esp+8h] [ebp+8h]

  *this = *a2;
  this[1] = a2[1];
  this[2] = a2[2];
  if ( *a3 <= 15.999512 )
  {
    if ( *a3 >= -15.999512 )
    {
      v6 = *a3 * 2048.0;
      v3 = (int)v6;
    }
    else
    {
      v3 = -32767;
    }
  }
  else
  {
    v3 = 0x7FFF;
  }
  *((_WORD *)this + 6) = v3;
  if ( a3[1] <= 15.999512 )
  {
    if ( a3[1] >= -15.999512 )
    {
      v7 = a3[1] * 2048.0;
      v4 = (int)v7;
    }
    else
    {
      v4 = -32767;
    }
  }
  else
  {
    v4 = 0x7FFF;
  }
  *((_WORD *)this + 7) = v4;
  if ( a3[2] <= 15.999512 )
  {
    if ( a3[2] >= -15.999512 )
    {
      v8 = a3[2] * 2048.0;
      v9 = (int)v8;
      result = (__int16)v9;
      *((_WORD *)this + 8) = v9;
    }
    else
    {
      result = -32767;
      *((_WORD *)this + 8) = -32767;
    }
  }
  else
  {
    result = 0x7FFF;
    *((_WORD *)this + 8) = 0x7FFF;
  }
  return result;
}
