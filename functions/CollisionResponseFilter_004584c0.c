_DWORD *__thiscall sub_4584C0(float *this, float a2, int a3, _DWORD *a4, float a5)
{
  float v5; // esi
  float *v7; // edi
  float *v8; // edx
  float *v9; // ecx
  double v10; // st7
  double v11; // st7
  _DWORD *result; // eax
  int v13[4]; // [esp+Ch] [ebp-30h] BYREF
  int v14[4]; // [esp+1Ch] [ebp-20h] BYREF
  _BYTE v15[16]; // [esp+2Ch] [ebp-10h] BYREF

  v5 = a2;
  AngleWrap((float *)LODWORD(a2));
  AngleWrap((float *)(LODWORD(v5) + 4));
  v7 = (float *)a3;
  AngleWrap((float *)a3);
  AngleWrap(v7 + 1);
  *(float *)&a3 = fabs(*(float *)LODWORD(v5) - *v7);
  a2 = fabs(*v8 - *v9);
  AngleNormalization((float *)&a3);
  AngleNormalization(&a2);
  v10 = a2 + *(float *)&a3;
  a2 = v10;
  *(float *)&a3 = v10 * this[41] * a5;
  if ( a2 <= (double)*(float *)&a3 || a2 <= 0.0 )
  {
    result = a4;
    *a4 = *(_DWORD *)LODWORD(v5);
    result[1] = *(_DWORD *)(LODWORD(v5) + 4);
    result[2] = *(_DWORD *)(LODWORD(v5) + 8);
  }
  else
  {
    v11 = *(float *)&a3 / a2;
    a2 = v11;
    if ( v11 > 1.0 )
      a2 = 1.0;
    QuaternionFromEulerAngles(v7, v14);
    QuaternionFromEulerAngles(LODWORD(v5), v13);
    sub_567580((int)v14, (int)v13, a2);
    return (_DWORD *)sub_567010(v15, a4);
  }
  return result;
}
