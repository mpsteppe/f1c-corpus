// Function: FUN_004f6bf0 @ 004f6bf0
// Strings:  [MaximumRPM, MinimumRPM]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004f6bf0(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  float local_31c [97];
  undefined4 local_198;
  undefined1 local_194;
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180 [96];
  
  puVar2 = local_180;
  for (iVar1 = 0x60; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  local_198 = 0;
  local_184 = 0;
  local_18c = 0;
  local_188 = 0;
  local_194 = 1;
  if ((-1 < param_3) && (param_3 < 5)) {
    iVar1 = FUN_00566cc0(local_180,0x180);
    while (iVar1 != 0) {
      iVar1 = FUN_005651b0();
      if (iVar1 == 0) {
        iVar1 = FUN_00565870(s_MinimumRPM_005d67ec,local_31c,0,0,0,0,0,0,0);
        if (iVar1 != 0) {
          *(float *)(param_1 + 4 + param_3 * 0xc) = local_31c[0] * (float)_DAT_005ad258;
        }
        iVar1 = FUN_00565870(s_MaximumRPM_005d67e0,local_31c,0,0,0,0,0,0,0);
        if (iVar1 != 0) {
          *(float *)(param_1 + 8 + param_3 * 0xc) = local_31c[0] * (float)_DAT_005ad258;
        }
        iVar1 = FUN_00565870(s__NaturalRPM_005d67d2 + 2,local_31c,0,0,0,0,0,0,0);
        if (iVar1 != 0) {
          if (local_31c[0] < DAT_0059e440 == (local_31c[0] == DAT_0059e440)) {
            *(float *)(param_1 + (param_3 * 3 + 3) * 4) =
                 (float)_DAT_0059e420 / (local_31c[0] * (float)_DAT_005ad258);
          }
          else {
            *(undefined4 *)(param_1 + (param_3 * 3 + 3) * 4) = 0;
          }
        }
      }
      else if (iVar1 == 2) {
        return;
      }
      iVar1 = FUN_00566cc0(local_180,0x180);
    }
  }
  return;
}


