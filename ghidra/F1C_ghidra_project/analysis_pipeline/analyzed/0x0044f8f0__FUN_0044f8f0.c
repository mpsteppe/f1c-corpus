// Function: FUN_0044f8f0 @ 0044f8f0
// Size (bytes): 335


undefined4 __fastcall FUN_0044f8f0(int param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_54 [84];
  
  piVar1 = *(int **)(param_1 + 0x80);
  *(undefined4 *)(param_1 + 0x3f8) = 0;
  if (piVar1 == (int *)0x0) {
    return 0xffffffff;
  }
  (**(code **)(*piVar1 + 100))(piVar1);
  iVar3 = (**(code **)(**(int **)(param_1 + 0x80) + 0x24))
                    (*(int **)(param_1 + 0x80),0x50,auStack_54);
  if (iVar3 == 0) {
    iVar3 = param_1 + 0x2c8;
    *(undefined4 *)(param_1 + 0x3f8) = 0x187f;
    iVar4 = (**(code **)(**(int **)(param_1 + 0x80) + 0xc))(*(int **)(param_1 + 0x80),iVar3);
    if (iVar4 == 0) {
      uVar2 = *(uint *)(param_1 + 0x2dc);
      if (3 < uVar2) {
        *(uint *)(param_1 + 0x3f8) = *(uint *)(param_1 + 0x3f8) | 0x400;
      }
      if (2 < uVar2) {
        *(uint *)(param_1 + 0x3f8) = *(uint *)(param_1 + 0x3f8) | 0x200;
      }
      if (1 < uVar2) {
        *(uint *)(param_1 + 0x3f8) = *(uint *)(param_1 + 0x3f8) | 0x100;
      }
      if (uVar2 != 0) {
        *(uint *)(param_1 + 0x3f8) = *(uint *)(param_1 + 0x3f8) | 0x80;
      }
      if ((*(byte *)(param_1 + 0x2cc) & 1) != 0) {
        iVar4 = 0;
        do {
          switch(iVar4) {
          case 0:
            iVar3 = 0;
            break;
          case 1:
            iVar3 = 4;
            break;
          case 2:
            iVar3 = 8;
            break;
          case 3:
            iVar3 = 0xc;
            break;
          case 4:
            iVar3 = 0x10;
            break;
          case 5:
            iVar3 = 0x14;
            break;
          case 6:
            iVar3 = 0x18;
            break;
          case 7:
            iVar3 = 0x1c;
          }
          FUN_0044f7f0(iVar3,param_1 + 0x338 + iVar4 * 4,param_1 + 0x358 + iVar4 * 4,
                       param_1 + 0x378 + iVar4 * 4,param_1 + 0x40 + iVar4 * 4,
                       param_1 + 0x60 + iVar4 * 4,param_1 + 0x318 + iVar4 * 4,
                       *(undefined4 *)(param_1 + 0x20 + iVar4 * 4),
                       *(undefined4 *)(param_1 + iVar4 * 4));
          iVar4 = iVar4 + 1;
        } while (iVar4 < 8);
      }
      return 0;
    }
    return 0xffffffff;
  }
  return 0xffffffff;
}


