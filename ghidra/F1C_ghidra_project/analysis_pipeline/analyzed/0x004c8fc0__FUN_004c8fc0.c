// Function: FUN_004c8fc0 @ 004c8fc0
// Size (bytes): 60


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_004c8fc0(int *param_1)

{
  float fVar1;
  char cVar2;
  undefined4 uVar3;
  
  fVar1 = (float)param_1[6] - (float)_DAT_008afe98;
  param_1[6] = (int)fVar1;
  if (fVar1 < DAT_0059e440 != (fVar1 == DAT_0059e440)) {
    param_1[6] = param_1[5];
    cVar2 = FUN_004c9000();
    if (cVar2 != '\0') {
                    /* WARNING: Could not recover jumptable at 0x004c8ff4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar3 = (**(code **)(*param_1 + 0xc))();
      return uVar3;
    }
  }
  return 0;
}


