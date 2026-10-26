double __thiscall sub_530A70(_DWORD *this, int a2, float a3)
{
  int v4; // eax
  double v5; // st7
  float v7; // [esp+8h] [ebp-4h]
  float v8; // [esp+14h] [ebp+8h]
  float v9; // [esp+14h] [ebp+8h]
  float v10; // [esp+14h] [ebp+8h]

  v7 = a3;
  v4 = sub_539670((char *)(a2 + 22084));
  if ( v4 )
    v7 = a3 * *(float *)(v4 + 2700);
  if ( this[216] == 6 )
    v8 = *(float *)(a2 + 20656);
  else
    v8 = *(float *)(a2 + 20652);
  v9 = (double)(rand() % 40) * 0.0099999998 - 0.0099999998 + 1.0 - v8;
  if ( v9 <= 1.0 )
  {
    if ( v9 < 0.0 )
      v9 = 0.0;
  }
  else
  {
    v9 = 1.0;
  }
  v10 = pow(v9, 1.333999991416931);
  v5 = (double)(rand() % 50) * 0.0099999998 + 0.5;
  if ( v5 > 1.0 )
    v5 = 1.0;
  return (v5 * v10 * (v7 * 0.25) - 0.25 + v7) * (*(float *)(a2 + 16084) * 0.000115 + 1.0);
}
