// Function: FUN_004b5760 @ 004b5760
// Size (bytes): 131


void __fastcall FUN_004b5760(int param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined1 local_1b0 [4];
  undefined4 local_1ac;
  
  piVar1 = *(int **)(param_1 + 0x20);
  *(int **)(param_1 + 0x28) = piVar1;
  if ((piVar1 != (int *)0x0) && (iVar3 = *piVar1, iVar3 != 0)) {
    while( true ) {
      cVar2 = FUN_005001d0();
      if ((cVar2 != '\0') &&
         ((cVar2 = FUN_005001f0(), cVar2 != '\0' &&
          (cVar2 = FUN_00500210(*(undefined4 *)(param_1 + 0x30),local_1b0), cVar2 != '\0')))) {
        *(undefined4 *)(iVar3 + 0x370) = local_1ac;
        FUN_00410f60(local_1b0);
      }
      if (*(int *)(param_1 + 0x28) == 0) break;
      piVar1 = *(int **)(*(int *)(param_1 + 0x28) + 4);
      *(int **)(param_1 + 0x28) = piVar1;
      if (piVar1 == (int *)0x0) {
        return;
      }
      iVar3 = *piVar1;
      if (iVar3 == 0) {
        return;
      }
    }
  }
  return;
}


