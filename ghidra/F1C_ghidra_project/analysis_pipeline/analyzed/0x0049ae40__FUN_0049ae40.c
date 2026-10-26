// Function: FUN_0049ae40 @ 0049ae40
// Size (bytes): 118


uint FUN_0049ae40(uint param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 *puVar1;
  uint uVar2;
  uint *extraout_ECX;
  
  uVar2 = FUN_0049adb0();
  if (param_1 == uVar2) {
    uVar2 = FUN_0049adc0(param_2,param_3);
    return uVar2;
  }
  if (((int)param_1 < 0) || ((int)extraout_ECX[3] <= (int)param_1)) {
    extraout_ECX[2] = 0;
  }
  else {
    uVar2 = *extraout_ECX;
    extraout_ECX[2] = uVar2;
    for (; 0 < (int)param_1; param_1 = param_1 - 1) {
      uVar2 = 0;
      if (extraout_ECX[2] == 0) break;
      uVar2 = *(uint *)(extraout_ECX[2] + 4);
      extraout_ECX[2] = uVar2;
    }
  }
  if ((int *)extraout_ECX[2] != (int *)0x0) {
    puVar1 = *(undefined2 **)extraout_ECX[2];
    uVar2 = 0;
    if (puVar1 != (undefined2 *)0x0) {
      *puVar1 = (undefined2)param_2;
      puVar1[1] = (undefined2)param_3;
      return CONCAT31((int3)((uint)puVar1 >> 8),1);
    }
  }
  return uVar2 & 0xffffff00;
}


