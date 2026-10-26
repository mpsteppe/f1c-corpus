// Function: FUN_005991c3 @ 005991c3
// Size (bytes): 111


void __thiscall FUN_005991c3(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_24 [2];
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_c;
  undefined4 local_8;
  
  if (*(int *)(param_1 + 0x50) != 0) {
    iVar1 = FUN_00587f64(*(int *)(param_1 + 0x50),param_3,param_4);
    if (iVar1 == 0) {
      iVar1 = FUN_0058801d(*(undefined4 *)(param_1 + 0x50),&local_c);
      if (iVar1 == 0) {
        local_24[0] = 0;
        local_1c = local_c;
        local_18 = local_8;
        local_14 = *(undefined4 *)(param_1 + 0x40);
        puVar2 = local_24;
        goto LAB_00599225;
      }
    }
  }
  puVar2 = (undefined4 *)FUN_0059942b(0xffffffff);
LAB_00599225:
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_2 = *puVar2;
    puVar2 = puVar2 + 1;
    param_2 = param_2 + 1;
  }
  return;
}


