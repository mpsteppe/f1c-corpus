void __thiscall sub_41FEC0(float *this, float *a2, int a3, char a4)
{
  int v4; // esi
  double v5; // st7
  unsigned __int8 v7; // c0
  unsigned __int8 v8; // c3
  double v9; // st7
  double v10; // st5
  double v11; // st7
  unsigned __int8 v13; // c0
  unsigned __int8 v14; // c3
  double v15; // st7
  float v16; // [esp+0h] [ebp-Ch]
  float v17; // [esp+0h] [ebp-Ch]
  float v18; // [esp+0h] [ebp-Ch]
  float v19; // [esp+8h] [ebp-4h]
  float v20; // [esp+8h] [ebp-4h]

  if ( a4 )
  {
    v4 = *(_DWORD *)this;
    v5 = (*(float *)(*(_DWORD *)this + 15988) - a2[38]) * a2[42]
       + (*(float *)(*(_DWORD *)this + 15996) - a2[40]) * a2[44];
    v16 = a2[42] * v5;
    v19 = a2[44] * v5;
    v9 = sqrt(v19 * v19 + v16 * v16);
    if ( v7 | v8 )
      v9 = -v9;
    this[9] = v9;
    v10 = a2[42] * a2[42] + a2[44] * a2[44];
    if ( v10 == 0.0 )
      this[12] = 0.0;
    else
      this[12] = (*(float *)(v4 + 16012) * a2[42] + *(float *)(v4 + 16020) * a2[44]) / v10;
  }
  else
  {
    v17 = -a2[44];
    v11 = (*(float *)(*(_DWORD *)this + 15996) - a2[40]) * a2[42]
        - (*(float *)(*(_DWORD *)this + 15988) - a2[38]) * a2[44];
    v18 = v17 * v11;
    v20 = a2[42] * v11;
    v15 = sqrt(v20 * v20 + v18 * v18);
    if ( !(v13 | v14) )
      v15 = -v15;
    this[9] = v15;
  }
}
