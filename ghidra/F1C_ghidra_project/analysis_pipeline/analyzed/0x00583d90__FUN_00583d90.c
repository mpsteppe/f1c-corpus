// Function: FUN_00583d90 @ 00583d90
// Size (bytes): 436


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00583d90(int *param_1)

{
  char cVar1;
  int iVar2;
  float10 fVar3;
  float local_b4;
  float local_b0;
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059d063;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_005835f0();
  local_4 = 0;
  FUN_005835f0();
  local_4 = CONCAT31(local_4._1_3_,1);
  local_b0 = 0.0;
  cVar1 = FUN_00583d40();
  while (cVar1 == '\0') {
    fVar3 = (float10)FUN_00583680();
    if ((float10)_DAT_0059ed98 < fVar3) {
      FUN_00583660(0);
      fVar3 = (float10)FUN_00583690();
      local_b4 = (float)fVar3;
      if ((float10)DAT_0059e440 <= fVar3) {
        if (_DAT_0059e5fc < local_b4) {
          local_b4 = 10.0;
        }
      }
      else {
        local_b4 = 0.0;
      }
      FUN_005840d0();
      FUN_00584110(local_b4);
      iVar2 = 0;
      cVar1 = (**(code **)(*param_1 + 0x54))();
      while ((cVar1 != '\0' && (iVar2 = iVar2 + 1, iVar2 < 3))) {
        cVar1 = (**(code **)(*param_1 + 0x54))();
      }
      iVar2 = 0;
      cVar1 = (**(code **)(*param_1 + 0x50))();
      while ((cVar1 != '\0' && (iVar2 = iVar2 + 1, iVar2 < 3))) {
        cVar1 = (**(code **)(*param_1 + 0x50))();
      }
      local_b0 = local_b4 + local_b0;
      if (_DAT_005b8b58 < local_b0) {
        FUN_004b0170();
        FUN_00583f50(local_b0);
        (**(code **)(*param_1 + 0xc))(local_b0);
        local_b0 = 0.0;
      }
    }
    SleepEx(5,1);
    cVar1 = FUN_00583d40();
  }
  local_4 = local_4 & 0xffffff00;
  FUN_00583650();
  local_4 = 0xffffffff;
  FUN_00583650();
  ExceptionList = pvStack_c;
  return 0;
}


