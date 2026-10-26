// Function: FUN_004212e0 @ 004212e0
// Size (bytes): 150


int __fastcall FUN_004212e0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  undefined1 local_50 [80];
  
  iVar3 = 0;
  if (param_1 != 0) {
    iVar2 = 0;
    FUN_004c2850();
    iVar1 = FUN_004c1370();
    if (0 < iVar1) {
      do {
        uVar5 = 0x50;
        puVar4 = local_50;
        iVar1 = iVar2;
        FUN_004c2850(iVar2,puVar4,0x50);
        FUN_004c13a0(iVar1);
        FUN_004c0a20(puVar4,uVar5);
        iVar1 = FUN_00566810();
        if (iVar1 != 0) {
          iVar1 = iVar2;
          FUN_004c2850(iVar2);
          iVar1 = FUN_004c13a0(iVar1);
          iVar3 = iVar3 + *(int *)(iVar1 + 0x1a0);
        }
        iVar2 = iVar2 + 1;
        FUN_004c2850();
        iVar1 = FUN_004c1370();
      } while (iVar2 < iVar1);
    }
    return iVar3;
  }
  return 0;
}


