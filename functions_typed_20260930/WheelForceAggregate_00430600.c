float *__thiscall sub_430600(int this, int a2, float *a3, float *a4)
{
  float *result; // eax
  float v6; // [esp+0h] [ebp-5Ch]
  float v7; // [esp+4h] [ebp-58h]
  float v8; // [esp+4h] [ebp-58h]
  float v9; // [esp+8h] [ebp-54h]
  float v10; // [esp+8h] [ebp-54h]
  float v11; // [esp+8h] [ebp-54h]
  int v12; // [esp+1Ch] [ebp-40h] BYREF
  int v13; // [esp+20h] [ebp-3Ch] BYREF
  int v14; // [esp+24h] [ebp-38h] BYREF
  int v15; // [esp+28h] [ebp-34h] BYREF
  int v16; // [esp+2Ch] [ebp-30h] BYREF
  int v17; // [esp+30h] [ebp-2Ch] BYREF
  int v18; // [esp+34h] [ebp-28h] BYREF
  int v19[3]; // [esp+38h] [ebp-24h] BYREF
  int v20[3]; // [esp+44h] [ebp-18h] BYREF
  int v21[3]; // [esp+50h] [ebp-Ch] BYREF

  v9 = (double)*(int *)(this + 3588) * *(double *)(this + 3576) + *(double *)(this + 3568);
  QuadraticCubicPolynomialEvaluator(v9, (int)&v12, (int)&v18);
  v10 = (double)*(int *)(this + 3652) * *(double *)(this + 3640) + *(double *)(this + 3632);
  QuadraticCubicPolynomialEvaluator(v10, (int)&a2, (int)&v17);
  v7 = (double)*(int *)(this + 4740) * *(double *)(this + 4728) + *(double *)(this + 4720);
  TireForceTorqueComputation(v7, 0.025, (int)v21, (int)&v16);
  v11 = (double)*(int *)(this + 4804) * *(double *)(this + 4792) + *(double *)(this + 4784);
  QuadraticForceModel(v11, (int)v20, (int)&v15);
  v8 = (double)*(int *)(this + 4868) * *(double *)(this + 4856) + *(double *)(this + 4848);
  v6 = (double)*(int *)(this + 4932) * *(double *)(this + 4920) + *(double *)(this + 4912);
  LinearVehicleParameterEvaluation(v6, v8, 0.025, (int)v19, (int)&v14);
  QuadraticForceTorqueCurveEvaluation(0.025, (int)&v13);
  result = a4;
  *a3 = *(float *)&v19[2] + *(float *)&v20[2] + *(float *)&v21[2] + *(float *)&a2 + *(float *)&v12;
  *result = *(float *)&v13 + *(float *)&v14 + *(float *)&v15 + *(float *)&v16 + *(float *)&v17 + *(float *)&v18;
  return result;
}

