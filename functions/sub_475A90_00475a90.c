int __thiscall sub_475A90(_DWORD *this, _DWORD *a2, _DWORD *a3, _DWORD *a4, _DWORD *a5)
{
  int v6; // eax
  int v7; // edi
  int v8; // esi
  double v9; // st7
  int v10; // edi
  double v11; // st7
  int i; // edi
  double v13; // st7
  int v15; // [esp+Ch] [ebp-74h] BYREF
  int v16; // [esp+10h] [ebp-70h] BYREF
  int v17; // [esp+14h] [ebp-6Ch] BYREF
  int v18; // [esp+18h] [ebp-68h] BYREF
  int v19[2]; // [esp+1Ch] [ebp-64h] BYREF
  int v20; // [esp+24h] [ebp-5Ch]
  int v21; // [esp+28h] [ebp-58h] BYREF
  int v22; // [esp+2Ch] [ebp-54h]
  double v23; // [esp+30h] [ebp-50h] BYREF
  double v24; // [esp+38h] [ebp-48h] BYREF
  double v25[8]; // [esp+40h] [ebp-40h]

  sub_4881F0(this, a2, a3, a4, a5);
  if ( UtilityFunction_7160(this, 0, &v15, &v16) && UtilityFunction_7160(this, 1, &v17, &v18) )
  {
    v24 = 0.0;
    v23 = 0.0;
    v21 = 0;
    v22 = 0;
    v6 = DynamicsJointCount(&byte_7C56C0);
    v7 = v16;
    v19[0] = v18 - v16;
    v8 = v6;
    v20 = CRTFtol(
            ((double)dword_7C6C44 * dbl_7C6C38 + dbl_7C6C30) * 9.549296585513721 * 0.0001 * (double)(v18 - v16)
          + (double)v16);
    if ( byte_7D0474 )
      v9 = 3.6;
    else
      v9 = 2.236936292054402;
    *(float *)v19 = v9;
    HIDWORD(v24) = v7;
    v10 = 0;
    for ( LODWORD(v24) = v15; v10 < v8; v25[v10 - 1] = v11 * *(float *)v19 )
      v11 = TireSuspensionForceComputation((int)&byte_7C56C0, v10++);
    v23 = v24;
    v19[0] = v17 - v15;
    v21 = CRTFtol((double)(v17 - v15) * (v25[0] * 0.01) + (double)v15);
    v22 = v20;
    ConditionalDraw(&v23, &v21);
    for ( i = 1; i < v8; ++i )
    {
      v13 = v25[i] * 0.01;
      v19[0] = v21;
      v20 = v17 - v15;
      v19[1] = v22;
      v21 = CRTFtol(v13 * (double)(v17 - v15) + (double)v15);
      OffsetPositionComputation(v19[0], &v24, &v21, &v23);
      ConditionalDraw(v19, &v23);
      ConditionalDraw(&v23, &v21);
    }
  }
  return 0;
}
