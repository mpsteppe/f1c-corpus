int __thiscall sub_411330(_DWORD *this, int a2, float *a3, int a4, int a5, float *a6)
{
  int v6; // eax
  int v7; // esi
  int result; // eax

  if ( a2 == 3 )
  {
    v6 = dword_5ECF0C[4656 * a4 + 74 * a5];
    v7 = this[19] + 36 * (a5 + 4 * a4);
    *(float *)(*(_DWORD *)(v7 + 32) + 28) = flt_7D0AD4 + *a6;
  }
  else if ( a2 == 4 )
  {
    v7 = this[22] + 36 * (a5 + 2 * a4);
    if ( a5 )
      v6 = dword_5ED3F0[4656 * a4];
    else
      v6 = dword_5ED3AC[4656 * a4];
    *(float *)(*(_DWORD *)(v7 + 32) + 28) = flt_7D0AD4 + *a6;
  }
  else
  {
    v6 = a5;
    if ( a2 == 5 )
    {
      v6 = dword_5ED434[4656 * a4 + 17 * a5];
      v7 = this[25] + 36 * (a5 + 8 * a4);
      *(float *)(*(_DWORD *)(v7 + 32) + 28) = flt_7D0AD4 + *a6;
    }
    else
    {
      v7 = a5;
    }
  }
  ShortComputation_e770((_DWORD *)v7, v6, 1);
  SwitchBasedFloatProcessing((_DWORD *)v7, a3);
  result = PhysicsStateVectorConversion((_DWORD *)v7, a6);
  *(_BYTE *)(v7 + 10) = 1;
  return result;
}
