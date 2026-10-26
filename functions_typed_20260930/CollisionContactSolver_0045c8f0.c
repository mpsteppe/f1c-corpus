int __thiscall sub_45C8F0(_DWORD *this, float *a2, float a3)
{
  float *v3; // ebx
  unsigned int v4; // esi
  double v6; // st7
  unsigned __int8 v7; // al
  double v8; // st7
  int result; // eax
  float v10; // [esp+0h] [ebp-18h]
  int v11; // [esp+14h] [ebp-4h]

  v3 = a2;
  v4 = (unsigned __int8)*(_DWORD *)a2;
  v11 = ((*(_DWORD *)a2 >> 8) & 0x3FF) + 8;
  if ( v4 < 0x68 )
  {
    v6 = *(float *)&this[v4 + 109];
    this[v4 + 5] = 0;
    if ( v6 > 0.5 )
    {
      this[v4 + 1097] = -1082130432;
      v10 = a3 - v3[1];
      FloatToShortViaFtol(v10, (_WORD *)&this[8 * v4 + 265] + *((unsigned __int8 *)this + v4 + 956));
      v7 = *((_BYTE *)this + v4 + 852);
      if ( v7 < 0x10u )
        *((_BYTE *)this + v4 + 852) = v7 + 1;
      *((_BYTE *)this + v4 + 956) = (*((_BYTE *)this + v4 + 956) + 1) & 0xF;
      this[v4 + 109] = 0;
    }
    if ( (unsigned __int8)ShortArrayLookupAndZeroCheck(v4, &a2) )
      v3[1] = v3[1] - *(float *)&a2;
    if ( v3[1] <= dbl_8AFEA0 )
    {
      v8 = dbl_8AFEA0 - flt_7D108C;
      if ( v3[1] < v8 )
        v3[1] = v8;
    }
    else
    {
      v3[1] = dbl_8AFEA0;
    }
  }
  result = this[2] + 1;
  this[1] += v11;
  this[2] = result;
  return result;
}

