int __thiscall sub_49B370(_DWORD *this, int a2, int *a3, int a4, int a5, char a6)
{
  int v8; // ebx
  int result; // eax
  int v11; // eax
  int v12; // ebx
  int v13; // esi
  int v14; // edi
  int v15; // [esp+10h] [ebp-2Ch] BYREF
  int v16; // [esp+14h] [ebp-28h] BYREF
  int v17; // [esp+18h] [ebp-24h]
  float v18[8]; // [esp+1Ch] [ebp-20h] BYREF
  int v19; // [esp+44h] [ebp+8h]
  int v20; // [esp+48h] [ebp+Ch]
  int v21; // [esp+48h] [ebp+Ch]
  int v22; // [esp+48h] [ebp+Ch]
  int v23; // [esp+50h] [ebp+14h]

  v16 = 0;
  v15 = 0;
  sub_5531F0(a2, &v16, &v15, 0);
  v8 = CRTFtol((double)v16 * *(float *)(a4 + 92));
  v16 = v8;
  result = CRTFtol((double)v15 * *(float *)(a4 + 96));
  v15 = result;
  if ( v8 > 0 && result > 0 )
  {
    v20 = this[2];
    v11 = *a3;
    v12 = v20 - v8 / 2;
    v18[0] = (float)v20;
    v21 = this[3] - v11;
    v18[1] = (float)(v11 + v15 + 4);
    v18[3] = v18[0];
    v17 = v12;
    v18[4] = (double)v21 * 0.94999999 + (double)(v11 + 4);
    FloatToIntConversionChain(v18, -2002081110);
    v18[0] = (float)(this[2] - 1);
    FloatToIntConversionChain(v18, -2002081110);
    v18[0] = (float)(this[2] - 2);
    FloatToIntConversionChain(v18, -2002081110);
    v18[0] = (float)(this[2] - 3);
    FloatToIntConversionChain(v18, -2002081110);
    v18[0] = (float)(this[2] - 4);
    FloatToIntConversionChain(v18, -2002081110);
    v18[0] = (float)(this[2] - 5);
    FloatToIntConversionChain(v18, -1999844148);
    if ( dword_7CE23C[0] )
    {
      PositionComputationWithAlignment(v12 - 4, *a3 - 4, 1, 0);
      TwoFieldSetterUpdate(v16 + 8, v15 + 8);
      FieldSetterCall_cf20(1728053247);
      ConditionalCall(0);
    }
    v13 = CRTFtol(1.0 / *(float *)(a4 + 92) * (double)v17);
    v22 = CRTFtol(1.0 / *(float *)(a4 + 96) * (double)*a3);
    v19 = *(_DWORD *)(a4 + 72);
    FieldSetterAt0x48(-1);
    sub_553070(a2, v13, v22, dword_8B8DC8);
    FieldSetterAt0x48(v19);
    if ( a6 )
    {
      if ( dword_7CE240 )
      {
        v14 = v15 + 8;
        v23 = RandomColorGenerator(0xFFFFFF, -1, 0.0);
        PositionComputationWithAlignment(v12 + v16 + 5, *a3 - 4, 1, 0);
        TwoFieldSetterUpdate(v14, v14);
        FieldSetterCall_cf20(v23);
        ConditionalCall(0);
      }
    }
    result = v15 + 8;
    *a3 += v15 + 8;
  }
  return result;
}
