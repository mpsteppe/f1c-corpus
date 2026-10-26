char __thiscall sub_4A5FA0(int *this)
{
  float *v2; // edi
  double v3; // st7
  bool v5; // c0
  unsigned __int8 v6; // c2
  double v7; // st7
  bool v9; // zf
  char v10; // fps^1
  double v11; // st5
  bool v12; // c0
  char v13; // c2
  bool v14; // c3
  char v15; // ah
  float *v16; // edi
  unsigned __int8 v18; // c0
  unsigned __int8 v19; // c2
  double v20; // st7
  float v21; // [esp+8h] [ebp-6Ch]
  float v22; // [esp+Ch] [ebp-68h]
  float v23; // [esp+10h] [ebp-64h]
  float v24[3]; // [esp+20h] [ebp-54h] BYREF
  float v25[3]; // [esp+2Ch] [ebp-48h] BYREF
  _DWORD v26[3]; // [esp+38h] [ebp-3Ch] BYREF
  _BYTE v27[12]; // [esp+44h] [ebp-30h] BYREF
  float v28[2]; // [esp+50h] [ebp-24h] BYREF
  float v29; // [esp+58h] [ebp-1Ch]
  float v30; // [esp+5Ch] [ebp-18h]
  float v31; // [esp+64h] [ebp-10h]
  float v32; // [esp+68h] [ebp-Ch]
  float v33; // [esp+70h] [ebp-4h]

  ArrayOfStructIndexedFieldCopy(dword_5EA2C0, *(_DWORD *)(*this + 18596), v25, v26);
  v2 = (float *)(*this + 12);
  F_3DTransformWithMatrixMultiplication(v24, v27);
  v21 = v24[0] - v25[0];
  v22 = v24[1] - v25[1];
  v3 = v24[2] - v25[2];
  v23 = v3;
  if ( v3 * v23 + v22 * v22 + v21 * v21 > 25.0 )
  {
    EulerToRotationMatrix(v26, v28);
    goto LABEL_11;
  }
  EulerToRotationMatrix(v26, v28);
  v7 = v33 * v23 + v31 * v22 + v29 * v21;
  if ( v7 > 1.5 )
    return 0;
  if ( v7 < -5.0 )
  {
    SessionCleanupFlagClear(*this);
    v9 = *(_DWORD *)(*this + 13000) == 0;
    goto LABEL_13;
  }
  if ( fabs(v32 * v23 + v30 * v22 + v28[0] * v21) > 1.5 )
  {
    if ( v7 < 0.0 )
    {
      v9 = *(_DWORD *)(*this + 13000) == 0;
      goto LABEL_13;
    }
    return 0;
  }
  v11 = v33 * v2[3380] + v2[3377] * v31 + v2[3374] * v29;
  v12 = v11 < 0.85000002;
  v13 = 0;
  v14 = v11 == 0.85000002;
  v15 = v10;
  v5 = v7 < 0.0;
  v6 = 0;
  if ( !__SETP__(v15 & 5, 0) )
  {
LABEL_11:
    if ( v5 | v6 )
    {
      v9 = *(_DWORD *)(*this + 13000) == 0;
LABEL_13:
      if ( v9 )
      {
        if ( dword_7CE7A8 )
          StateChangeNotify((int)this, 4);
      }
      return 0;
    }
    return 0;
  }
  v16 = v2 + 3387;
  v20 = v16[1] * v16[1] + v16[2] * v16[2] + *v16 * *v16;
  if ( v18 | v19 )
  {
    if ( v20 > 4.0 )
      return 0;
  }
  else if ( v20 > 0.040000003 )
  {
    return 0;
  }
  return 1;
}
