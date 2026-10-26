// Function: FUN_004c13c0 @ 004c13c0
// Size (bytes): 143


int FUN_004c13c0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_24;
  undefined1 local_20 [32];
  
  local_24 = 0;
  if (param_1 != 0) {
    iVar1 = FUN_004c1370();
    iVar4 = 0;
    if (0 < iVar1 + 1) {
      do {
        if (iVar4 == 0) {
          iVar2 = FUN_004c1390();
        }
        else {
          iVar2 = FUN_004c13a0(iVar4 + -1);
        }
        if (iVar2 != 0) {
          FUN_004c0a20(local_20,0x20);
          iVar3 = FUN_00566810();
          if (iVar3 != 0) {
            local_24 = local_24 + *(int *)(iVar2 + 0x198);
          }
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar1 + 1);
      return local_24;
    }
  }
  return 0;
}


