// Function: FUN_004c81a0 @ 004c81a0
// Size (bytes): 78


void __fastcall FUN_004c81a0(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar1 = *(int **)(param_1 + 0xc);
  if (piVar1 != (int *)0x0) {
    piVar2 = (int *)*piVar1;
    piVar1[2] = (int)piVar2;
    if ((piVar2 != (int *)0x0) && (iVar3 = *piVar2, iVar3 != 0)) {
      while (*(int *)(iVar3 + 4) != DAT_008acfcc) {
        iVar3 = *(int *)(param_1 + 0xc);
        if (*(int *)(iVar3 + 8) != 0) {
          *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(*(int *)(iVar3 + 8) + 4);
        }
        if (*(int **)(iVar3 + 8) == (int *)0x0) {
          return;
        }
        iVar3 = **(int **)(iVar3 + 8);
        if (iVar3 == 0) {
          return;
        }
      }
      if (*(int *)(iVar3 + 4) != 0) {
        *(undefined4 *)(iVar3 + 0x18) = 0;
      }
    }
  }
  return;
}


