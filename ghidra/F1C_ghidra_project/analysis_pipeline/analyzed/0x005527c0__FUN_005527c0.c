// Function: FUN_005527c0 @ 005527c0
// Size (bytes): 229


undefined4 __fastcall FUN_005527c0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((*(uint *)(param_1 + 0x24) & 0x20000) != 0) {
    if (*(int *)(param_1 + 0xc) == 0) {
      puVar1 = operator_new(0x24);
      if (puVar1 == (undefined4 *)0x0) {
        puVar1 = (undefined4 *)0x0;
      }
      else {
        puVar1[5] = 0;
        puVar1[4] = 0;
        puVar1[3] = 0;
        puVar1[2] = 0;
        puVar1[1] = 0;
        *puVar1 = 0;
        puVar1[7] = 0;
        puVar1[6] = 0;
        puVar1[8] = 0;
      }
      *(undefined4 **)(param_1 + 0xc) = puVar1;
    }
    **(undefined4 **)(param_1 + 0xc) = 0x22;
    *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xc) = 0x300;
    *(undefined4 *)(*(int *)(param_1 + 0xc) + 8) = 0x1c;
    *(undefined4 *)(*(int *)(param_1 + 0xc) + 4) = DAT_008cef78;
    iVar2 = FUN_00540df0(*(undefined4 *)(param_1 + 0xc));
    if (iVar2 != 0) {
      return 0xffffffff;
    }
    uVar3 = FUN_00540f00(*(undefined4 *)(param_1 + 0xc),0x60,0,0);
    *(undefined4 *)(param_1 + 0x10) = uVar3;
    iVar2 = 0;
    if (0 < *(int *)(*(int *)(param_1 + 0xc) + 0xc)) {
      do {
        *(undefined4 *)(*(int *)(param_1 + 0x10) + 8) = 0;
        *(undefined4 *)(*(int *)(param_1 + 0x10) + 0xc) = 0x3f800000;
        *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 0x1c;
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(int *)(*(int *)(param_1 + 0xc) + 0xc));
    }
    FUN_00540f90(*(undefined4 *)(param_1 + 0xc));
  }
  return 0;
}


