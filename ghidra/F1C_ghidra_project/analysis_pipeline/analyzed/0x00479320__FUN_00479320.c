// Function: FUN_00479320 @ 00479320
// Size (bytes): 201


void __fastcall FUN_00479320(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int local_8;
  int local_4;
  
  FUN_00498880(&local_4,&local_8);
  piVar2 = *(int **)(param_1 + 0x164);
  *(int **)(param_1 + 0x16c) = piVar2;
  if ((piVar2 != (int *)0x0) && (piVar2 = (int *)*piVar2, piVar2 != (int *)0x0)) {
    while( true ) {
      iVar1 = *piVar2 + *(int *)(param_1 + 0xc);
      iVar3 = piVar2[1] + *(int *)(param_1 + 4);
      if ((local_4 < iVar1 + 0x14) &&
         (((iVar1 + -0x14 < local_4 && (local_8 < iVar3 + 0x14)) && (iVar3 + -0x14 < local_8)))) {
        iVar1 = -1;
        if (*(int *)(param_1 + 0x16c) != 0) {
          iVar1 = 0;
          for (iVar3 = *(int *)(param_1 + 0x164);
              (iVar3 != 0 && (iVar3 != *(int *)(param_1 + 0x16c))); iVar3 = *(int *)(iVar3 + 4)) {
            iVar1 = iVar1 + 1;
          }
        }
        *(int *)(param_1 + 0x158) = iVar1;
        return;
      }
      if (*(int *)(param_1 + 0x16c) != 0) {
        *(undefined4 *)(param_1 + 0x16c) = *(undefined4 *)(*(int *)(param_1 + 0x16c) + 4);
      }
      if (*(undefined4 **)(param_1 + 0x16c) == (undefined4 *)0x0) break;
      piVar2 = (int *)**(undefined4 **)(param_1 + 0x16c);
      if (piVar2 == (int *)0x0) {
        return;
      }
    }
  }
  return;
}


