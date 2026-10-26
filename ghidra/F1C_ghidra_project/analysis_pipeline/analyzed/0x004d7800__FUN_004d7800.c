// Function: FUN_004d7800 @ 004d7800
// Size (bytes): 128


void __fastcall FUN_004d7800(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = 0;
  if (0 < *param_1) {
    do {
      FUN_004d7050();
      iVar3 = iVar3 + 1;
    } while (iVar3 < *param_1);
  }
  iVar3 = param_1[1];
  *param_1 = 0;
  if (iVar3 != 0) {
    iVar2 = *(int *)(iVar3 + -4);
    piVar4 = (int *)(iVar3 + iVar2 * 0x24);
    if (-1 < iVar2 + -1) {
      do {
        FUN_004d7050();
        if (piVar4[-3] != 0) {
          FUN_00587bcf(piVar4[-3]);
        }
        iVar1 = piVar4[-9];
        if (iVar1 != 0) {
          FUN_00587bcf(iVar1);
        }
        iVar2 = iVar2 + -1;
        piVar4 = piVar4 + -9;
      } while (iVar2 != 0);
    }
    FUN_00587bcf(iVar3 + -4);
  }
  param_1[1] = 0;
  return;
}


