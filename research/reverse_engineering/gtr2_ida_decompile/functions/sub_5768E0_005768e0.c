int __thiscall sub_5768E0(float *this, float *a2)
{
  double v2; // st7
  int v4; // edi
  int result; // eax
  int v6; // edx
  int v7; // ecx
  double v8; // st7
  double v9; // st7
  float v10; // [esp+4h] [ebp-28h]
  double v11; // [esp+8h] [ebp-24h]
  float v12; // [esp+10h] [ebp-1Ch]
  float v13; // [esp+10h] [ebp-1Ch]
  float v14; // [esp+10h] [ebp-1Ch]
  double v15; // [esp+14h] [ebp-18h] BYREF
  double v16; // [esp+1Ch] [ebp-10h]
  double v17; // [esp+24h] [ebp-8h]

  v2 = a2[2];
  v4 = (int)(this + 672);
  *(float *)&v15 = v2 * a2[15];
  *((float *)&v15 + 1) = v2 * a2[16];
  v11 = v15;
  *(float *)&v16 = v2 * a2[17];
  v12 = *(float *)&v16;
  this[3993] = *(float *)&v15 + this[3993];
  this[3994] = *((float *)&v11 + 1) + this[3994];
  this[3995] = v12 + this[3995];
  sub_569300((_DWORD *)this + 672, this + 3993, (_DWORD *)this + 3996, this + 3984);
  sub_5690C0(v4);
  result = *(_DWORD *)(*(_DWORD *)this + 22468);
  v6 = *((_DWORD *)this + 3701);
  if ( result == *(_DWORD *)(dword_91E084 + 22468) )
  {
    if ( v6 != 2 )
    {
      if ( !(unsigned __int8)sub_4735E0(&dword_B6CBA8) || (result = sub_473630(&dword_B6CBA8), !(_BYTE)result) )
      {
        v15 = *(float *)&v11;
        v16 = *((float *)&v11 + 1);
        v17 = v12;
        return sub_443450(&dbl_B66040, &v15);
      }
      return result;
    }
  }
  else if ( v6 != 2 )
  {
    return result;
  }
  result = sub_473B30();
  if ( result )
  {
    result += 36;
    v13 = *(float *)result;
    v7 = *(_DWORD *)(result + 8);
    LODWORD(v15) = *(_DWORD *)(result + 4);
    v14 = v13 + v10;
    HIDWORD(v15) = v7;
    v8 = *(float *)&v15 + *(float *)&v11;
    *(float *)result = v14;
    *(float *)&v15 = v8;
    v9 = *((float *)&v15 + 1);
    *(_DWORD *)(result + 4) = LODWORD(v15);
    *((float *)&v15 + 1) = v9 + *((float *)&v11 + 1);
    *(_DWORD *)(result + 8) = HIDWORD(v15);
  }
  return result;
}
