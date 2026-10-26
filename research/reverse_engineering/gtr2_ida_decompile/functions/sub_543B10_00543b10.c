int __thiscall sub_543B10(int this, float a2, float *a3, float *a4, float a5, int a6, char a7, int a8)
{
  int result; // eax
  float *v10; // esi
  double v11; // st7
  double v12; // st7
  double v13; // st7
  double v14; // st7
  double v15[6]; // [esp+4h] [ebp-38h] BYREF
  int v16; // [esp+34h] [ebp-8h]

  result = *(_DWORD *)(this + 96);
  if ( result > 0 )
  {
    v10 = (float *)sub_5424A0();
    v11 = a2 + v10[7];
    v10[2] = a2;
    v10[3] = v11;
    v10[11] = *a3;
    v10[12] = a3[1];
    v10[13] = a3[2];
    v10[14] = *a4;
    v10[15] = a4[1];
    v10[16] = a4[2];
    v12 = flt_BE08A4[(unsigned __int8)dword_BE08A0++] * 64.0;
    *((_DWORD *)v10 + 17) = a8;
    v10[10] = (v12 + 190.0) * a5;
    v13 = *a3;
    v16 = a6;
    v15[0] = v13;
    v15[1] = a3[1];
    v15[2] = a3[2];
    v15[3] = 0.25;
    v15[4] = 9.999999933815813e36;
    if ( sub_45D210(dbl_B68610, v15, v10 + 21) )
    {
      v14 = v15[5];
    }
    else
    {
      v10[21] = 0.0;
      v10[22] = 1.0;
      v10[23] = 0.0;
      v14 = a3[1] - 0.25;
    }
    if ( a7 )
    {
      v10[12] = *(float *)(this + 16) * 0.5 + v14;
      v10[15] = v10[26] * *(float *)(this + 28) * 0.5;
    }
    sub_5FCCB0(*(_DWORD *)v10, *((_DWORD *)v10 + 11), *((_DWORD *)v10 + 12), *((_DWORD *)v10 + 13));
    sub_5FCD10(*(_DWORD *)v10, *(_DWORD *)(this + 12), *(_DWORD *)(this + 16), *(_DWORD *)(this + 20));
    return sub_5FC760(*(_DWORD *)v10, -1);
  }
  return result;
}
