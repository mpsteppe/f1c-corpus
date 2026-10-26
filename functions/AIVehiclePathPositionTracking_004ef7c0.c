_DWORD *__thiscall sub_4EF7C0(int this, float *a2, _DWORD *a3)
{
  float *v4; // ebx
  _DWORD *v5; // ecx
  double v6; // st7
  double v7; // st6
  double v8; // st7
  double v9; // st6
  double v10; // st5
  float *v11; // ecx
  _DWORD *result; // eax
  double v13; // [esp+Ch] [ebp-30h] BYREF
  double v14; // [esp+14h] [ebp-28h]
  double v15; // [esp+1Ch] [ebp-20h]
  double v16[3]; // [esp+24h] [ebp-18h] BYREF

  v4 = (float *)(this + 13536);
  v5 = (_DWORD *)(this + 13536);
  *v5 = *a3;
  v5[1] = a3[1];
  v5[2] = a3[2];
  EulerToRotationMatrix(v5, this + 13488);
  RideHeightDelta((float *)this, (int)&v13);
  v6 = *(float *)&v14 * *(float *)(this + 13496)
     + *((float *)&v13 + 1) * *(float *)(this + 13492)
     + *(float *)&v13 * *(float *)(this + 13488);
  v7 = *(float *)&v14 * *(float *)(this + 13508)
     + *((float *)&v13 + 1) * *(float *)(this + 13504)
     + *(float *)&v13 * *(float *)(this + 13500);
  *(float *)&v14 = *(float *)&v14 * *(float *)(this + 13520)
                 + *((float *)&v13 + 1) * *(float *)(this + 13516)
                 + *(float *)&v13 * *(float *)(this + 13512);
  *(float *)&v13 = v6 + *(float *)(this + 13524);
  v8 = v7 + *(float *)(this + 13528);
  v9 = *(float *)&v14 + *(float *)(this + 13532);
  *(float *)&v13 = *a2 - *(float *)&v13;
  *((float *)&v13 + 1) = a2[1] - v8;
  v10 = a2[2] - v9;
  *(float *)(this + 13524) = *(float *)&v13 + *(float *)(this + 13524);
  *(float *)(this + 13528) = *((float *)&v13 + 1) + *(float *)(this + 13528);
  *(float *)(this + 13532) = v10 + *(float *)(this + 13532);
  *(_DWORD *)(this + 15004) = 0;
  F_3x3MatrixTransformWithTranslation(v11);
  result = *(_DWORD **)(this + 12988);
  if ( !result )
  {
    v16[0] = *(float *)(this + 13524);
    v16[1] = *(float *)(this + 13528);
    v16[2] = *(float *)(this + 13532);
    v13 = *v4;
    v14 = *(float *)(this + 13540);
    v15 = *(float *)(this + 13544);
    return RigidBodyConstraintSolve((int)&dbl_7C7428, v16, (int)&v13);
  }
  return result;
}
