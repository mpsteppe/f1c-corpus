// Function: FUN_00497890 @ 00497890
// Size (bytes): 163


undefined4 __thiscall FUN_00497890(int param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  
  if (*(int *)(param_1 + 0x18) != 0) {
    FUN_00498fb0();
  }
  piVar4 = *(int **)(param_1 + 4);
  uVar3 = 0;
  *(int **)(param_1 + 0xc) = piVar4;
  if ((piVar4 != (int *)0x0) && (piVar4 = (int *)*piVar4, piVar4 != (int *)0x0)) {
    while( true ) {
      for (iVar2 = FUN_00498e30(); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x48)) {
        if (iVar2 == param_2) {
          if (*(char *)(param_1 + 0x1574) != '\0') {
            FUN_004977e0(param_2,param_3);
          }
          FUN_00495a80(piVar4);
          (**(code **)(*piVar4 + 0x2c))(1);
          FUN_00498f40(iVar2);
          uVar3 = 1;
        }
      }
      if (*(int *)(param_1 + 0xc) == 0) break;
      puVar1 = *(undefined4 **)(*(int *)(param_1 + 0xc) + 4);
      *(undefined4 **)(param_1 + 0xc) = puVar1;
      if ((puVar1 == (undefined4 *)0x0) || (piVar4 = (int *)*puVar1, piVar4 == (int *)0x0)) break;
    }
  }
  if (*(int *)(param_1 + 0x18) != 0) {
    FUN_00498f80();
  }
  return uVar3;
}


