int __thiscall sub_543C80(int this, float a2, float *a3, float *a4, float a5, double *a6, int a7, char a8)
{
  int result; // eax
  int v10; // eax
  int v11; // edx
  int v12; // esi
  int v13; // eax
  int v14; // ecx
  float *v15; // esi
  double v16; // st7
  double v17; // st7
  double v18; // st7
  double v19; // st7
  int v20; // [esp+10h] [ebp-40h]
  int v21; // [esp+14h] [ebp-3Ch]
  double v22[6]; // [esp+18h] [ebp-38h] BYREF
  double *v23; // [esp+48h] [ebp-8h]

  result = *(_DWORD *)(this + 96);
  if ( result > 0 )
  {
    result = a7;
    if ( a7 > 0 )
    {
      v20 = a7;
      do
      {
        v10 = *(_DWORD *)(this + 104);
        v11 = *(_DWORD *)(this + 96);
        v21 = v10;
        *(_DWORD *)(this + 104) = v10 + 1;
        if ( v10 + 1 >= v11 )
          *(_DWORD *)(this + 104) = 0;
        v12 = *(_DWORD *)(this + 100);
        v13 = 108 * v10;
        v14 = *(_DWORD *)(v12 + v13 + 4);
        v15 = (float *)(v13 + v12);
        if ( v14 < 0 )
        {
          v15[1] = *(float *)(this + 108);
          *(_DWORD *)(*(_DWORD *)(this + 112) + 4 * (*(_DWORD *)(this + 108))++) = v13 + *(_DWORD *)(this + 100);
          sub_5FCAC0(v21);
        }
        v16 = a2 + v15[7];
        v15[2] = a2;
        v15[3] = v16;
        v15[11] = *a3;
        v15[12] = a3[1];
        v15[13] = a3[2];
        v15[14] = *a4;
        v15[15] = a4[1];
        v15[16] = a4[2];
        v17 = flt_BE08A4[(unsigned __int8)dword_BE08A0++] * 64.0;
        v15[17] = NAN;
        v15[10] = (v17 + 190.0) * a5;
        v18 = *a3;
        v23 = a6;
        v22[0] = v18;
        v22[1] = a3[1];
        v22[2] = a3[2];
        v22[3] = 0.25;
        v22[4] = 9.999999933815813e36;
        a6 = sub_45D210(dbl_B68610, v22, v15 + 21);
        if ( a6 )
        {
          v19 = v22[5];
        }
        else
        {
          v15[21] = 0.0;
          v15[22] = 1.0;
          v15[23] = 0.0;
          v19 = a3[1] - 0.25;
        }
        if ( a8 )
        {
          v15[12] = *(float *)(this + 16) * 0.5 + v19;
          v15[15] = v15[26] * *(float *)(this + 28) * 0.5;
        }
        sub_5FCCB0(*(_DWORD *)v15, *((_DWORD *)v15 + 11), *((_DWORD *)v15 + 12), *((_DWORD *)v15 + 13));
        sub_5FCD10(*(_DWORD *)v15, *(_DWORD *)(this + 12), *(_DWORD *)(this + 16), *(_DWORD *)(this + 20));
        result = sub_5FC760(*(_DWORD *)v15, byte_FFFFFF);
        --v20;
      }
      while ( v20 );
    }
  }
  return result;
}
