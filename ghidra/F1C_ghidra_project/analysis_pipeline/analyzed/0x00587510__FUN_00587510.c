// Function: FUN_00587510 @ 00587510
// Size (bytes): 101


undefined4 __thiscall FUN_00587510(int *param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  
  if (param_1[1] < (int)param_3) {
    if (*param_1 != 0) {
      FUN_00587bcf(*param_1);
    }
    FUN_005874d0(param_3,param_1);
    param_1[1] = param_3;
  }
  if (((undefined4 *)*param_1 != (undefined4 *)0x0) && (0 < (int)param_3)) {
    puVar2 = (undefined4 *)*param_1;
    for (uVar1 = param_3 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar2 = *param_2;
      param_2 = param_2 + 1;
      puVar2 = puVar2 + 1;
    }
    for (uVar1 = param_3 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
      *(undefined1 *)puVar2 = *(undefined1 *)param_2;
      param_2 = (undefined4 *)((int)param_2 + 1);
      puVar2 = (undefined4 *)((int)puVar2 + 1);
    }
    param_1[2] = param_3;
    return 1;
  }
  param_1[2] = 0;
  return 1;
}


