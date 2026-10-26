// Function: FUN_004b68c0 @ 004b68c0
// Size (bytes): 86


int __fastcall FUN_004b68c0(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x9bc);
  if (*(int *)(param_1 + 0x9b8) < iVar3) {
    iVar2 = (*(int *)(param_1 + 0x9b4) - iVar3) + 1 + *(int *)(param_1 + 0x9b8);
  }
  else {
    cVar1 = FUN_004b69f0();
    if (cVar1 != '\0') {
      return 0;
    }
    iVar3 = *(int *)(param_1 + 0x9bc);
    iVar2 = (*(int *)(param_1 + 0x9b8) - iVar3) + 1;
  }
  if (iVar2 == 1) {
    if (*(char *)(iVar3 * 0xb0 + *(int *)(param_1 + 0x9b0)) == '\0') {
      return 0;
    }
    return 1;
  }
  return iVar2;
}


