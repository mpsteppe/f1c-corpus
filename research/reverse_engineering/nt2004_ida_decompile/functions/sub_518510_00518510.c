_DWORD *__thiscall sub_518510(float *this, float *a2)
{
  double v2; // st7
  int v4; // edi
  _DWORD *result; // eax
  int v6; // edx
  double v7; // st7
  double v8; // st7
  float v9; // [esp+8h] [ebp-24h]
  float v10; // [esp+Ch] [ebp-20h]
  float v11; // [esp+10h] [ebp-1Ch]
  double v12; // [esp+14h] [ebp-18h] BYREF
  double v13; // [esp+1Ch] [ebp-10h]
  double v14; // [esp+24h] [ebp-8h]

  v2 = a2[2];
  v9 = v2 * a2[15];
  v4 = (int)(this + 452);
  v10 = v2 * a2[16];
  v11 = v2 * a2[17];
  this[4380] = v9 + this[4380];
  this[4381] = v10 + this[4381];
  this[4382] = v11 + this[4382];
  sub_50CAA0((_DWORD *)this + 452, this + 4380, (_DWORD *)this + 4383, this + 4371);
  sub_50BCC0(v4);
  result = (_DWORD *)*((_DWORD *)this + 4125);
  if ( result )
  {
    if ( result == (_DWORD *)2 )
    {
      result = (_DWORD *)sub_465CC0(dword_764D70, *(_DWORD *)(*(_DWORD *)this + 25248));
      if ( result )
      {
        result += 9;
        LODWORD(v12) = *result;
        v6 = result[2];
        HIDWORD(v12) = result[1];
        *(float *)&v12 = *(float *)&v12 + v9;
        LODWORD(v13) = v6;
        v7 = *((float *)&v12 + 1) + v10;
        *result = LODWORD(v12);
        *((float *)&v12 + 1) = v7;
        v8 = *(float *)&v13;
        result[1] = HIDWORD(v12);
        *(float *)&v13 = v8 + v11;
        result[2] = LODWORD(v13);
      }
    }
  }
  else
  {
    v12 = v9;
    v13 = v10;
    v14 = v11;
    return (_DWORD *)sub_4419C0(&dbl_75E930, &v12);
  }
  return result;
}
