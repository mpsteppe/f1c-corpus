// Function: FUN_004d0080 @ 004d0080
// Size (bytes): 143


void __fastcall FUN_004d0080(int *param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1[1] != 0) {
    if ((DAT_008afe88 != 0) && (iVar1 = 0, 0 < *param_1)) {
      iVar2 = 0;
      do {
        if (*(int *)(iVar2 + param_1[1]) != 0) {
          FUN_00545150(*(int *)(iVar2 + param_1[1]));
        }
        iVar1 = iVar1 + 1;
        iVar2 = iVar2 + 0x84;
      } while (iVar1 < *param_1);
    }
    iVar1 = param_1[1];
    if (iVar1 != 0) {
      iVar2 = *(int *)(iVar1 + -4);
      if (-1 < iVar2 + -1) {
        do {
          FUN_004a2220();
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      FUN_00587bcf(iVar1 + -4);
    }
    param_1[1] = 0;
  }
  *param_1 = 0;
  return;
}


