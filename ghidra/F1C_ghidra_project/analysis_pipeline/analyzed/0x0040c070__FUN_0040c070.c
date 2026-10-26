// Function: FUN_0040c070 @ 0040c070
// Size (bytes): 183


undefined4 __fastcall FUN_0040c070(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  float10 fVar5;
  
  uVar3 = 0;
  if (*(char *)(param_1 + 0x24) == '\0') {
    fVar5 = (float10)FUN_0040c780();
    fVar5 = (float10)*(float *)(param_1 + 0x3c) - fVar5;
    *(float *)(param_1 + 0x3c) = (float)fVar5;
    if (fVar5 < (float10)DAT_0059e440 != (fVar5 == (float10)DAT_0059e440)) {
      iVar1 = FUN_0040cd60();
      uVar2 = _rand();
      uVar2 = uVar2 & 0x80000003;
      if ((int)uVar2 < 0) {
        uVar2 = (uVar2 - 1 | 0xfffffffc) + 1;
      }
      switch(uVar2) {
      case 0:
        iVar4 = 0;
        break;
      case 1:
        iVar4 = 3;
        break;
      case 2:
        iVar4 = 4;
        break;
      default:
        iVar4 = 5;
      }
      FUN_0040cde0(iVar4,1);
      if (iVar4 != iVar1) {
        FUN_0040cde0(iVar4,1);
      }
      iVar1 = _rand();
      if (iVar1 % 3 == 0) {
        FUN_0040d290(1);
      }
      uVar3 = 1;
      FUN_0040d360(*(undefined4 *)(param_1 + 0x30),*(undefined4 *)(param_1 + 0x34));
    }
  }
  return uVar3;
}


