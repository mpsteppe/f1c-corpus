// Function: FUN_004c28d0 @ 004c28d0
// Size (bytes): 186


void __thiscall FUN_004c28d0(int param_1,undefined4 param_2)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int *piVar4;
  
  iVar1 = FUN_004c2860(param_2);
  if (iVar1 == 0) {
    FUN_004c5690(param_2);
    iVar1 = DAT_008ac48c * 0x18c + DAT_008ac490;
    if (iVar1 != 0) {
      pvVar2 = operator_new(0x18);
      if (pvVar2 == (void *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_004c03a0();
      }
      FUN_00566650(iVar1 + 0x104);
      FUN_00566650(iVar1 + 4);
      if (iVar3 != 0) {
        piVar4 = operator_new(0xc);
        if (piVar4 == (int *)0x0) {
          piVar4 = (int *)0x0;
        }
        else {
          *piVar4 = iVar3;
          piVar4[1] = 0;
          *(undefined1 *)(piVar4 + 2) = 1;
        }
        if (*(int *)(param_1 + 0x10) == 0) {
          *(int **)(param_1 + 0x10) = piVar4;
          *(int **)(param_1 + 0x18) = piVar4;
        }
        else {
          *(int **)(*(int *)(param_1 + 0x14) + 4) = piVar4;
        }
        *(int **)(param_1 + 0x14) = piVar4;
        *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
      }
    }
  }
  FUN_004c2860(param_2);
  return;
}


