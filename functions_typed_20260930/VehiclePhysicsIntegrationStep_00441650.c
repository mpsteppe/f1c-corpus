char __thiscall sub_441650(int *this, float a2)
{
  int v2; // edi
  char result; // al
  double i; // st7
  double v5; // st7
  double *v6; // esi
  int v7; // ebx
  double v8; // st7
  int v9; // ecx
  int v10; // ebx
  int v11; // eax
  int v12; // ecx
  double v13; // st7
  double v14; // st7
  double v15; // st6
  double v16; // st7
  int v17; // eax
  double v18; // [esp-Ch] [ebp-104h]
  double v19; // [esp+10h] [ebp-E8h]
  int v20; // [esp+10h] [ebp-E8h]
  double v21; // [esp+18h] [ebp-E0h]
  int v22; // [esp+18h] [ebp-E0h]
  int v24; // [esp+24h] [ebp-D4h]
  double v25; // [esp+28h] [ebp-D0h]
  double v26; // [esp+30h] [ebp-C8h]
  double v27; // [esp+38h] [ebp-C0h]
  double v28; // [esp+40h] [ebp-B8h]
  double v29; // [esp+48h] [ebp-B0h]
  double v30[3]; // [esp+50h] [ebp-A8h] BYREF
  double v31; // [esp+78h] [ebp-80h]
  _BYTE v32[24]; // [esp+80h] [ebp-78h] BYREF
  long double v33; // [esp+A0h] [ebp-58h]
  _BYTE v34[72]; // [esp+B0h] [ebp-48h] BYREF

  v2 = (int)this;
  if ( dbl_5D6D70 == 1.0 || (result = byte_7CE254) == 0 )
  {
    v24 = FPUControlWordMaskExtract(512);
    VehicleMainPhysicsUpdate(v2);
    for ( i = *(double *)(v2 + 104); ; i = v29 - v19 )
    {
      v19 = i;
      v29 = i;
      v25 = *(double *)(v2 + 96);
      PhysicsIntegrationStep(v2);
      v21 = i * 0.5;
      WheelDataCopy((int *)v2, v21);
      v5 = v21 + *(double *)(v2 + 96);
      *(double *)(v2 + 96) = v5;
      PhysicsIntegrationStep(v2);
      PhysicsStepFrame((int *)v2, v19);
      if ( v5 < 1.0 )
      {
        if ( dword_7CE958 && v19 != *(double *)(v2 + 104) )
          v5 = v5 * (*(double *)(v2 + 104) / v19);
        if ( v5 < 1.0 )
        {
          if ( v5 <= 0.5 )
            v19 = v5 * 0.999 * v19;
          else
            v19 = v21;
          if ( v19 < 0.000003814697265625 )
            v19 = 0.000003814697265625;
          StateAccumulateDelta((_DWORD *)v2);
          WheelDataCopy((int *)v2, v19 * 0.5);
          *(double *)(v2 + 96) = v19 * 0.5 + v25;
          PhysicsIntegrationStep(v2);
          PhysicsStepFrame((int *)v2, v19);
        }
      }
      if ( v29 <= v19 )
        break;
      *(double *)(v2 + 96) = v25 + v19;
    }
    *(double *)(v2 + 5720) = *(double *)(v2 + 2116) + *(double *)(v2 + 992);
    *(double *)(v2 + 96) = a2;
    EngineStressSimulation(v2);
    v6 = (double *)(v2 + 824);
    v7 = 4;
    do
    {
      v8 = *v6;
      InterruptDispatch(v8);
      *v6 = v8;
      VehicleDynamicsForceAccumulatorIntegration((int)v6 - 172, *(double *)(v2 + 104));
      v6 = (double *)((char *)v6 + 1124);
      --v7;
    }
    while ( v7 );
    PhysicsCollisionDamageDNFDetection(v2 + 652, *(double *)(v2 + 104), *(_DWORD *)(v2 + 1004));
    PhysicsCollisionDamageDNFDetection(v2 + 1776, *(double *)(v2 + 104), *(_DWORD *)(v2 + 2128));
    v18 = *(double *)(v2 + 104);
    if ( *(_DWORD *)(v2 + 5148) )
    {
      PhysicsCollisionDamageDNFDetection(v2 + 2900, v18, *(_DWORD *)(v2 + 5148));
      v9 = *(_DWORD *)(v2 + 5148);
    }
    else
    {
      PhysicsCollisionDamageDNFDetection(v2 + 2900, v18, *(_DWORD *)(v2 + 3252));
      v9 = *(_DWORD *)(v2 + 4376);
    }
    PhysicsCollisionDamageDNFDetection(v2 + 4024, *(double *)(v2 + 104), v9);
    v10 = v2 + 784;
    v22 = 4;
    do
    {
      v11 = *(_DWORD *)(v10 + 220);
      if ( v11 )
      {
        if ( !*(_BYTE *)(v10 + 320) )
        {
          v26 = *(double *)(v11 + 28);
          v27 = *(double *)(v11 + 52);
          v28 = *(double *)(v11 + 76);
          v12 = *(_DWORD *)(v2 + 5616);
          v13 = v28 * *(double *)(v12 + 76) + v27 * *(double *)(v12 + 52) + v26 * *(double *)(v12 + 28);
          v33 = v28 * *(double *)(v12 + 84) + v27 * *(double *)(v12 + 60) + v26 * *(double *)(v12 + 36);
          if ( v13 < 0.5 || fabs(v33) > 0.7 )
          {
            v14 = *(double *)(v12 + 36) * *(double *)v10
                + *(double *)(v12 + 44) * *(double *)(v10 + 8)
                + *(double *)(v10 - 8) * *(double *)(v12 + 28);
            v15 = *(double *)(v12 + 60) * *(double *)v10
                + *(double *)(v12 + 68) * *(double *)(v10 + 8)
                + *(double *)(v12 + 52) * *(double *)(v10 - 8);
            v31 = *(double *)(v12 + 84) * *(double *)v10
                + *(double *)(v12 + 92) * *(double *)(v10 + 8)
                + *(double *)(v12 + 76) * *(double *)(v10 - 8);
            v30[0] = v14 + *(double *)(v12 + 4);
            v30[1] = v15 + *(double *)(v12 + 12);
            v16 = v31 + *(double *)(v12 + 20);
            qmemcpy(v34, (const void *)(v12 + 28), sizeof(v34));
            v30[2] = v16;
            sub_56BDE0(v10 + 16, 0);
            qmemcpy(v32, (const void *)(this[1404] + 124), sizeof(v32));
            qmemcpy((void *)(*(_DWORD *)(v10 + 220) + 4), v30, 0x18u);
            v17 = *(_DWORD *)(v10 + 220);
            qmemcpy((void *)(v17 + 28), v34, 0x48u);
            v20 = v17;
            F_3x3InertiaTensorTransform(v17);
            qmemcpy((void *)(v20 + 124), v32, 0x18u);
            InertiaTensorWorldSpaceTransform(v20);
            PhysicsSubObjectFree(this);
            v2 = (int)this;
          }
        }
      }
      v10 += 1124;
      result = --v22;
    }
    while ( v22 );
    if ( v24 != 512 )
      return EmptyStub_7780(v24);
  }
  return result;
}

