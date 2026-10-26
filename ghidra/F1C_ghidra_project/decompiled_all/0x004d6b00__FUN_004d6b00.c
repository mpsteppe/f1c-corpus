// Function: FUN_004d6b00 @ 004d6b00
// Strings:  [TractiveCurve, BrakingCurve, LatCurve, OptimumPressureMult, OptimumPressureBase, OptimumTemp, AIWear, AIPeakSlip]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004d6b00(int param_1)

{
  double *pdVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int local_39c;
  undefined1 local_398 [512];
  undefined4 local_198;
  undefined1 local_194;
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180 [96];
  
  *(undefined4 *)(param_1 + 8) = 0x3f800000;
  *(undefined4 *)(param_1 + 0xc) = 0x3f800000;
  puVar4 = local_180;
  for (iVar3 = 0x60; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *(undefined4 *)(param_1 + 0x10) = 10;
  *(undefined1 *)(param_1 + 0x14) = 0;
  iVar3 = param_1 + 0x18;
  local_198 = 0;
  local_184 = 0;
  local_18c = 0;
  local_188 = 0;
  local_194 = 1;
  iVar2 = FUN_00566cc0(local_180,0x180);
  while (((iVar2 != 0 && (iVar2 = FUN_005651b0(), iVar2 != 1)) && (iVar2 != 4))) {
    if (iVar2 == 0) {
      iVar2 = FUN_005654a0(&DAT_005d4710,local_398);
      if (iVar2 != 0) {
        FUN_00566650(local_398);
      }
      iVar2 = FUN_00565760(s_WetWeather_005d4874,&local_39c,0,0,0);
      if (iVar2 != 0) {
        *(bool *)(param_1 + 0x14) = local_39c != 0;
      }
      iVar2 = FUN_00587c20(local_180,s_FRONT__005d486c);
      if (iVar2 != 0) {
        iVar3 = param_1 + 0x18;
      }
      iVar2 = FUN_00587c20(local_180,s_REAR__005d4864);
      if (iVar2 != 0) {
        iVar3 = param_1 + 0x160;
      }
      FUN_00565aa0(s_DryLatLong_005d4858,iVar3,iVar3 + 8,0,0);
      FUN_00565aa0(s_WetLatLong_005d484c,iVar3 + 0x10,iVar3 + 0x18,0,0);
      FUN_00565aa0(s_Radius_005d4844,iVar3 + 0x20,0,0,0);
      pdVar1 = (double *)(iVar3 + 0x28);
      iVar2 = FUN_00565aa0(s_RadiusRPM_005d4838,pdVar1,0,0,0);
      if (iVar2 != 0) {
        *pdVar1 = *pdVar1 * _DAT_0059ea38;
      }
      FUN_00565aa0(s_Width_005d4830,iVar3 + 0x30,0,0,0);
      FUN_00565aa0(s_SpringBase_005d4824,iVar3 + 0x38,0,0,0);
      FUN_00565aa0(s_SpringkPa_005d4818,iVar3 + 0x40,0,0,0);
      FUN_00565aa0(s_Damper_005d4810,iVar3 + 0x48,0,0,0);
      FUN_00565aa0(s_LoadSens_005d4804,iVar3 + 0x50,iVar3 + 0x58,iVar3 + 0x60,0);
      FUN_00565aa0(s_LatPeak_005d47fc,iVar3 + 0x68,iVar3 + 0x70,iVar3 + 0x78,0);
      FUN_00565aa0(s_LongPeak_005d47f0,iVar3 + 0x80,iVar3 + 0x88,iVar3 + 0x90,0);
      pdVar1 = (double *)(iVar3 + 0x98);
      iVar2 = FUN_00565aa0(s_CamberLatLong_005d47e0,pdVar1,iVar3 + 0xa0,iVar3 + 0xa8,0);
      if (iVar2 != 0) {
        *pdVar1 = *pdVar1 * _DAT_0059eae8;
      }
      FUN_00565aa0(s_RollingResistance_005d47cc,iVar3 + 0xb0,0,0,0);
      FUN_00565aa0(s_Heating_005d47c4,iVar3 + 0xb8,iVar3 + 0xc0,0,0);
      FUN_00565aa0(s_Transfer_005d47b8,iVar3 + 200,iVar3 + 0xd0,iVar3 + 0xd8,0);
      FUN_00565aa0(s_WearRate_005d47ac,iVar3 + 0xe0,0,0,0);
      FUN_00565aa0(s_Softness_005d47a0,iVar3 + 0xe8,0,0,0);
      FUN_00565aa0(s_AISens_005d4798,iVar3 + 0xf0,iVar3 + 0xf8,0,0);
      FUN_00565aa0(s_AIGripMult_005d478c,iVar3 + 0x100,0,0,0);
      FUN_00565aa0(s_AIPeakSlip_005d4780,iVar3 + 0x108,0,0,0);
      FUN_00565aa0(s_AIWear_005d4778,iVar3 + 0x110,0,0,0);
      FUN_00565aa0(s_OptimumTemp_005d476c,iVar3 + 0x118,0,0,0);
      FUN_00565aa0(s_OptimumPressureBase_005d4758,iVar3 + 0x120,0,0,0);
      FUN_00565aa0(s_OptimumPressureMult_005d4744,iVar3 + 0x128,0,0,0);
      iVar2 = FUN_005654a0(s_LatCurve_005d4738,local_398);
      if (iVar2 != 0) {
        FUN_00566650(local_398);
      }
      iVar2 = FUN_005654a0(s_BrakingCurve_005d4728,local_398);
      if (iVar2 != 0) {
        FUN_00566650(local_398);
      }
      iVar2 = FUN_005654a0(s_TractiveCurve_005d4718,local_398);
      if (iVar2 != 0) {
        FUN_00566650(local_398);
      }
    }
    iVar2 = FUN_00566cc0(local_180,0x180);
  }
  *(float *)(param_1 + 8) =
       (float)(((float10)*(double *)(param_1 + 0x168) + (float10)*(double *)(param_1 + 0x160) +
                (float10)*(double *)(param_1 + 0x20) + (float10)*(double *)(param_1 + 0x18)) *
              (float10)_DAT_0059eb50);
  *(float *)(param_1 + 0xc) =
       (float)(((float10)*(double *)(param_1 + 0x178) + (float10)*(double *)(param_1 + 0x170) +
                (float10)*(double *)(param_1 + 0x30) + (float10)*(double *)(param_1 + 0x28)) *
              (float10)_DAT_0059eb50);
  iVar3 = __ftol();
  *(int *)(param_1 + 0x10) = iVar3;
  if (0xf < iVar3) {
    *(undefined4 *)(param_1 + 0x10) = 0xf;
    return;
  }
  if (iVar3 < 7) {
    *(undefined4 *)(param_1 + 0x10) = 7;
  }
  return;
}


