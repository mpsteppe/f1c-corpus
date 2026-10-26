// Function: FUN_00489480 @ 00489480
// Size (bytes): 76


void __fastcall FUN_00489480(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 + 0x170);
  if ((-1 < iVar2) && (iVar2 < *(int *)(param_1 + 0x94))) {
    iVar2 = *(int *)(param_1 + 0x94) - iVar2;
    iVar3 = iVar2;
    if (0 < iVar2) {
      do {
        puVar1 = *(undefined4 **)(param_1 + 0x90);
        if (puVar1 != (undefined4 *)0x0) {
          *(undefined4 *)(param_1 + 0x90) = puVar1[0x23];
          (**(code **)*puVar1)(1);
        }
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) - iVar2;
  }
  return;
}


