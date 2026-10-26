float *__thiscall sub_404ED0(_DWORD *this, int a2, float *a3, float *a4)
{
  long double v5; // st7
  long double v6; // st6
  long double v7; // st5
  int v8; // eax
  long double v9; // st7
  int v10; // eax
  float *result; // eax
  long double v12; // st5
  long double v13; // st7
  double v14; // st6
  float v15; // [esp+4h] [ebp-18h] BYREF
  float v16; // [esp+8h] [ebp-14h]
  float v17; // [esp+Ch] [ebp-10h]
  float v18; // [esp+18h] [ebp-4h]
  float v19; // [esp+28h] [ebp+Ch]

  sub_51BCE0(&v15);
  if ( a4 )
  {
    v5 = -sin(a4[1]);
    v6 = sin(*a4);
    v7 = a4[1];
  }
  else
  {
    v8 = this[98];
    v9 = sin(*(float *)(v8 + 28 * a2 + 16));
    v10 = 28 * a2 + v8;
    v5 = -v9;
    v6 = sin(*(float *)(v10 + 12));
    v7 = *(float *)(v10 + 16);
  }
  result = a3;
  v18 = -cos(v7);
  v12 = sqrt(v16 * v16 + v17 * v17 + v15 * v15);
  v19 = v12;
  v15 = v12 * v5;
  v13 = v19 * v6;
  v14 = v19 * v18;
  *a3 = *a3 - v15;
  a3[1] = a3[1] - v13;
  a3[2] = a3[2] - v14;
  return result;
}
