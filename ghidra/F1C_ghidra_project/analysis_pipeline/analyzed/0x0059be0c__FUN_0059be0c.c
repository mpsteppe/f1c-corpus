// Function: FUN_0059be0c @ 0059be0c
// Size (bytes): 241


uint __thiscall FUN_0059be0c(undefined4 param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 local_8;
  
  puVar5 = param_2;
  local_8 = param_1;
  if ((*(byte *)(param_2 + 3) & 0x40) == 0) {
    uVar3 = param_2[4];
    if (uVar3 == 0xffffffff) {
      puVar2 = &DAT_005e7898;
    }
    else {
      puVar2 = (undefined *)((&DAT_008d4920)[(int)uVar3 >> 5] + (uVar3 & 0x1f) * 0x24);
    }
    if ((puVar2[4] & 0x80) != 0) {
      piVar1 = param_2 + 1;
      *piVar1 = *piVar1 + -1;
      uVar6 = 1;
      if (*piVar1 < 0) {
        uVar3 = FUN_0058c255(param_2);
      }
      else {
        uVar3 = (uint)*(byte *)*param_2;
        *param_2 = (byte *)*param_2 + 1;
      }
      if (uVar3 != 0xffffffff) {
        local_8 = CONCAT31(local_8._1_3_,(char)uVar3);
        if ((PTR_DAT_005e69c8[(uVar3 & 0xff) * 2 + 1] & 0x80) != 0) {
          piVar1 = puVar5 + 1;
          *piVar1 = *piVar1 + -1;
          if (*piVar1 < 0) {
            uVar3 = FUN_0058c255(puVar5);
          }
          else {
            uVar3 = (uint)*(byte *)*puVar5;
            *puVar5 = (byte *)*puVar5 + 1;
          }
          if (uVar3 == 0xffffffff) {
            FUN_0059685f((int)(char)local_8,puVar5);
            return 0xffff;
          }
          local_8._0_2_ = CONCAT11((char)uVar3,(char)local_8);
          uVar6 = 2;
        }
        iVar4 = FUN_00596716((int)&param_2 + 2,&local_8,uVar6);
        if (iVar4 != -1) {
          return (uint)param_2 >> 0x10;
        }
        puVar5 = (undefined4 *)FUN_0058afcf();
        *puVar5 = 0x2a;
      }
      return 0xffff;
    }
  }
  piVar1 = param_2 + 1;
  *piVar1 = *piVar1 + -2;
  if (*piVar1 < 0) {
    uVar3 = FUN_0059c30e(param_2);
  }
  else {
    uVar3 = (uint)*(ushort *)*param_2;
    *param_2 = (ushort *)*param_2 + 1;
  }
  return uVar3;
}


