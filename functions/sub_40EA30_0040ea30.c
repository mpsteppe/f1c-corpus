char __thiscall sub_40EA30(int this, __int16 a2, int a3, int a4)
{
  double v5; // st7
  _DWORD *v6; // eax
  float v8; // [esp+8h] [ebp-48h] BYREF
  float v9; // [esp+Ch] [ebp-44h]
  float v10; // [esp+10h] [ebp-40h]
  float v11; // [esp+14h] [ebp-3Ch]
  float v12; // [esp+18h] [ebp-38h]
  float v13; // [esp+1Ch] [ebp-34h]
  double v14; // [esp+20h] [ebp-30h]
  double v15; // [esp+30h] [ebp-20h]
  int v16[2]; // [esp+38h] [ebp-18h] BYREF
  double v17; // [esp+40h] [ebp-10h]
  double v18; // [esp+48h] [ebp-8h]

  *(_DWORD *)(this + 32) = a3;
  *(_WORD *)(this + 8) = a2;
  *(_DWORD *)(this + 28) = 2;
  BoundingBoxComputation(&v8);
  v15 = v10 - v13;
  v14 = (v8 - v11) * (v8 - v11);
  v5 = (v9 - v12) * (v9 - v12);
  *(double *)v16 = (v15 * v15 + v5) * 0.4166666666666666;
  v17 = (v15 * v15 + v14) * 0.4166666666666666;
  v18 = (v5 + v14) * 0.4166666666666666;
  CollisionInvMassStore(5.0, (int)v16);
  F_6FieldBulkSetter(0, 1083179008, 1717986918, 1078355558, 1610612736, 1072064102);
  v6 = *(_DWORD **)(this + 32);
  v6[16] = 1202590843;
  v6[17] = 1064598241;
  v6[18] = 1202590843;
  v6[19] = 1064598241;
  if ( a4 )
    LOBYTE(v6) = ShortComputation_e770((_DWORD *)this, a4, 0);
  return (char)v6;
}
