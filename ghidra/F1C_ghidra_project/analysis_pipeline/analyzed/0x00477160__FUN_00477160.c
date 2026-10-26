// Function: FUN_00477160 @ 00477160
// Size (bytes): 93


undefined4 __fastcall FUN_00477160(int param_1)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  
  FUN_0048f300();
  iVar4 = *(int *)(param_1 + 0x170);
  if ((-1 < iVar4) && (iVar4 < *(int *)(param_1 + 0xfc))) {
    piVar1 = *(int **)(param_1 + 0xf0);
    for (; 0 < iVar4; iVar4 = iVar4 + -1) {
      if (piVar1 == (int *)0x0) {
        return 0;
      }
      piVar1 = (int *)piVar1[1];
    }
    if ((((piVar1 != (int *)0x0) && (iVar4 = *piVar1, iVar4 != 0)) &&
        (cVar2 = FUN_004773a0(iVar4), cVar2 != '\0')) && (*(int **)(iVar4 + 0x30) != (int *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x004771b2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar3 = (**(code **)(**(int **)(iVar4 + 0x30) + 0x90))();
      return uVar3;
    }
  }
  return 0;
}


