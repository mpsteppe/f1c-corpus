// Function: FUN_005511a0 @ 005511a0
// Size (bytes): 107


void __fastcall FUN_005511a0(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    FUN_00557470();
    FUN_00587bcf(iVar1);
  }
  iVar1 = param_1[6];
  *param_1 = 0;
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + -4);
    if (-1 < iVar2 + -1) {
      do {
        FUN_00557470();
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    FUN_00587bcf(iVar1 + -4);
  }
  param_1[6] = 0;
  FUN_004b0170();
  return;
}


