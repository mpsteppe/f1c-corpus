char __thiscall sub_4BC9B0(int *this, char a2, char a3)
{
  float *v4; // ecx
  float *v5; // esi
  double v7; // st7
  int v8; // eax
  char v9; // cl
  int v10; // eax
  char v11; // cl
  float v12; // [esp+Ch] [ebp-78h]
  float v13; // [esp+10h] [ebp-74h]
  float v14; // [esp+14h] [ebp-70h]
  float v15; // [esp+18h] [ebp-6Ch]
  float v16; // [esp+1Ch] [ebp-68h]
  float v17; // [esp+20h] [ebp-64h]
  float v18; // [esp+24h] [ebp-60h]
  float v19; // [esp+28h] [ebp-5Ch]
  float v20; // [esp+2Ch] [ebp-58h]
  float v21[3]; // [esp+30h] [ebp-54h] BYREF
  float v22[3]; // [esp+3Ch] [ebp-48h] BYREF
  _BYTE v23[12]; // [esp+48h] [ebp-3Ch] BYREF
  _BYTE v24[12]; // [esp+54h] [ebp-30h] BYREF
  _BYTE v25[8]; // [esp+60h] [ebp-24h] BYREF
  float v26; // [esp+68h] [ebp-1Ch]
  float v27; // [esp+74h] [ebp-10h]
  float v28; // [esp+80h] [ebp-4h]

  v4 = (float *)*this;
  v5 = v4 + 3;
  v12 = v4[3390] * v4[3390] + v4[3391] * v4[3391] + v4[3392] * v4[3392];
  if ( !a2 && v12 > 1.0 )
    return 0;
  SingleFunctionDispatch_10e0(v4, v22, v23);
  EulerToRotationMatrix(v23, v25);
  v18 = -v26;
  v19 = -v27;
  v20 = -v28;
  F_3DTransformWithMatrixMultiplication(v21, v24);
  v15 = v21[0] - v22[0];
  v16 = v21[1] - v22[1];
  v17 = v21[2] - v22[2];
  v13 = v20 * v17 + v19 * v16 + v15 * v18;
  v14 = -v5[3380] * v20 + -v5[3377] * v19 + -v5[3374] * v18;
  if ( a2 )
  {
    if ( v12 > 1.0 || v17 * v17 + v16 * v16 + v15 * v15 > 5.0625 || v13 > 1.5 || v14 < 0.75 )
    {
      if ( dword_7CEF84 && *((_DWORD *)v5 + 3247) != 1 )
      {
        if ( v17 * v17 + v16 * v16 + v15 * v15 <= 225.0 )
          StopGoPenaltyHandler(this, aJumpedStart, 10);
        else
          DisqualificationHandler(this, aJumpedStart);
        return 0;
      }
      return 0;
    }
    goto LABEL_17;
  }
  v7 = v17 * v17 + v16 * v16 + v15 * v15;
  if ( v7 <= 3.0625 && v13 <= 1.25 && v14 >= 0.85000002 )
  {
LABEL_17:
    if ( a3 )
    {
      if ( BinarySearchInStringTable(byte_5EC4C0, aNotLinedUpProp, byte_5EC4CC) )
      {
        v8 = 0;
        do
        {
          v9 = aNotLinedUpProp[v8];
          byte_5EC4CC[v8++] = v9;
        }
        while ( v9 );
      }
      ShortComputation_bde0((_DWORD **)&dword_7CD204, byte_5EC4CC, 0);
    }
    return 1;
  }
  if ( !a3 || v7 >= 400.0 )
    return 0;
  if ( BinarySearchInStringTable(byte_5EC4C0, aNotLinedUpProp, byte_5EC4CC) )
  {
    v10 = 0;
    do
    {
      v11 = aNotLinedUpProp[v10];
      byte_5EC4CC[v10++] = v11;
    }
    while ( v11 );
  }
  TextLineWrappingAndRendering(&dword_7CD204, (int)byte_5EC4CC, 2, 16909060);
  return 0;
}
