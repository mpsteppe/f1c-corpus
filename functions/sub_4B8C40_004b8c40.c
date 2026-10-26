int __thiscall sub_4B8C40(float *this, float a2, char a3)
{
  int v3; // ecx
  int v4; // ecx
  int v6; // ecx
  int v7; // ecx
  int v8; // ecx
  int v9; // ecx
  int v10; // ecx
  int v11; // ecx
  int v12; // ecx
  int v13; // ecx
  float v14; // [esp+0h] [ebp-8h]
  float v15; // [esp+0h] [ebp-8h]
  float v16; // [esp+0h] [ebp-8h]
  float v17; // [esp+0h] [ebp-8h]
  int v18; // [esp+4h] [ebp-4h]
  float v19; // [esp+Ch] [ebp+4h]

  v18 = 1065353216;
  switch ( LODWORD(a2) )
  {
    case 0:
      v19 = FloatGetter(this) - dbl_8AFE90;
      if ( !a3 && v19 < (double)*(float *)(v3 + 3976) )
        v19 = *(float *)(v3 + 3976);
      AngleClampWrap(v3, v19);
      *(_DWORD *)(v4 + 3980) = 4;
      goto LABEL_6;
    case 1:
      v14 = FloatGetter(this);
      AngleClampWrap(v6, v14);
      *(_DWORD *)(v7 + 3980) = 5;
      return ArithmeticComparison_8d60(&byte_8AC494);
    case 2:
      v15 = FloatGetter(this) + dbl_8AFE90;
      AngleClampWrap(v8, v15);
      *(_DWORD *)(v9 + 3980) = 6;
      goto LABEL_6;
    case 3:
      v16 = FloatGetter(this) + dbl_8AFE90 * 0.083333336;
      AngleClampWrap(v10, v16);
      *(_DWORD *)(v11 + 3980) = 6;
      v18 = 1056964608;
      goto LABEL_6;
    case 4:
      v17 = FloatGetter(this) + dbl_8AFE90 * 3.3399999;
      AngleClampWrap(v12, v17);
      *(_DWORD *)(v13 + 3980) = 7;
      v18 = 1070973583;
      goto LABEL_6;
    default:
      if ( LODWORD(a2) == 1 )
        return ArithmeticComparison_8d60(&byte_8AC494);
LABEL_6:
      ShortComputation_8d70(&byte_8AC494);
      return GuardedVirtualCall(v18);
  }
}
