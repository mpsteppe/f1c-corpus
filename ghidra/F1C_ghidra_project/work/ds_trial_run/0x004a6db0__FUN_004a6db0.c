// Function: FUN_004a6db0 @ 004a6db0
// Size (bytes): 158


bool __fastcall FUN_004a6db0(int *param_1)

{
  int iVar1;
  bool bVar2;
  char cVar3;
  
  if ((DAT_007c56a4 == 7) || (DAT_007c56a4 == 0)) {
    iVar1 = *param_1;
    if (((*(int *)(iVar1 + 0x834) == 0) ||
        ((((*(char *)(iVar1 + 0x874) == '\0' || (*(int *)(iVar1 + 0x95c) == 0)) ||
          (*(char *)(iVar1 + 0x99c) == '\0')) ||
         ((*(int *)(iVar1 + 0xa84) == 0 || (*(char *)(iVar1 + 0xac4) == '\0')))))) ||
       ((*(int *)(iVar1 + 0xbac) == 0 || (*(char *)(iVar1 + 0xbec) == '\0')))) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if (((DAT_007ce814 != 0) || (!bVar2)) &&
       ((*(int *)(iVar1 + 0x4064) != 1 && (*(int *)(iVar1 + 0x4064) != 3)))) {
      cVar3 = FUN_004d21d0();
      return cVar3 != '\0';
    }
  }
  return false;
}


