// Function: FUN_00406250 @ 00406250
// Size (bytes): 96


void __fastcall FUN_00406250(undefined4 *param_1)

{
  int *piVar1;
  BOOL BVar2;
  int iVar3;
  undefined4 *puVar4;
  
  *param_1 = &PTR_FUN_0059e4ec;
  FUN_004064c0();
  FUN_00407c90(param_1);
  if (*(char *)(param_1 + 0x16) != '\0') {
    BVar2 = CloseHandle((HANDLE)param_1[0x14]);
    if (BVar2 != 0) {
      param_1[0x14] = 0;
    }
  }
  puVar4 = param_1 + 0x13;
  iVar3 = 3;
  do {
    piVar1 = puVar4 + -5;
    puVar4 = puVar4 + -5;
    if (*piVar1 != 0) {
      FUN_00587bcf(*piVar1);
    }
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *param_1 = &PTR_LAB_0059e50c;
  return;
}


