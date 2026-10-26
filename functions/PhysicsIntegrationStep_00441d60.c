double *__thiscall sub_441D60(int this)
{
  int *v2; // edi
  int v3; // ecx
  int v4; // edx
  int v5; // eax
  double v6; // st7
  int v7; // ebx
  int v8; // eax
  double v9; // st7
  double *v10; // eax
  double v11; // st7
  double *v12; // eax
  double v13; // st7
  double *v14; // eax
  double v15; // st7
  int v16; // eax
  double v17; // st7
  double *result; // eax

  v2 = (int *)(this + 5548);
  sub_56EB90(this + 5548);
  sub_4423B0(this);
  sub_442C90(this);
  DamperSpringForceComputationWithAntiRoll(this);
  if ( *(double *)(this + 412) == 0.0 )
    VelocityDampingFromSpeedError(this);
  v3 = 0;
  if ( *v2 > 0 )
  {
    v4 = 0;
    do
    {
      v5 = *(_DWORD *)(this + 5552);
      v6 = *(double *)(v5 + v4 + 172);
      v7 = *(_DWORD *)(v5 + v4 + 308);
      v8 = v4 + v5;
      *(_DWORD *)(v8 + 308) = v7;
      *(_DWORD *)(v8 + 312) = *(_DWORD *)(v8 + 312);
      v9 = v6 * -9.81 + *(double *)(v8 + 316);
      *(_DWORD *)(v8 + 324) = *(_DWORD *)(v8 + 324);
      *(_DWORD *)(v8 + 328) = *(_DWORD *)(v8 + 328);
      *(double *)(v8 + 316) = v9;
      ++v3;
      v4 += 580;
    }
    while ( v3 < *v2 );
  }
  RigidBodyTorqueAccumulation(this);
  RigidBodyConstraintJointSolver(
    (_DWORD *)(this + 492),
    *(_DWORD *)(this + 5616),
    *(_DWORD *)(this + 96),
    *(_DWORD *)(this + 100));
  v10 = *(double **)(this + 5616);
  v11 = *(double *)((char *)v10 + 308);
  v10 = (double *)((char *)v10 + 308);
  *v10 = v11 + *(double *)(this + 236);
  v10[1] = *(double *)(this + 244) + v10[1];
  v10[2] = *(double *)(this + 252) + v10[2];
  v12 = *(double **)(this + 5616);
  v13 = *(double *)((char *)v12 + 332);
  v12 = (double *)((char *)v12 + 332);
  *v12 = v13 + *(double *)(this + 260);
  v12[1] = *(double *)(this + 268) + v12[1];
  v12[2] = *(double *)(this + 276) + v12[2];
  v14 = *(double **)(this + 5616);
  v15 = *(double *)((char *)v14 + 308);
  v14 = (double *)((char *)v14 + 308);
  *v14 = v15 + *(double *)(this + 7940);
  v14[1] = *(double *)(this + 7948) + v14[1];
  v14[2] = *(double *)(this + 7956) + v14[2];
  v16 = *(_DWORD *)(this + 5616);
  v17 = *(double *)(v16 + 332);
  result = (double *)(v16 + 332);
  *result = v17 + *(double *)(this + 7964);
  result[1] = *(double *)(this + 7972) + result[1];
  result[2] = *(double *)(this + 7980) + result[2];
  return result;
}
