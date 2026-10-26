// Function: FUN_0045b500 @ 0045b500
// Size (bytes): 128


uint __thiscall FUN_0045b500(int param_1,int param_2)

{
  float fVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  
  uVar3 = *(uint *)(param_1 + 0x31c);
  iVar5 = 0;
  while( true ) {
    uVar2 = uVar3 & 0x80000007;
    if ((int)uVar2 < 0) {
      uVar2 = (uVar2 - 1 | 0xfffffff8) + 1;
    }
    fVar1 = *(float *)(uVar2 * 0x5c + 0x90 + param_1);
    if (fVar1 < DAT_0059e440 != (fVar1 == DAT_0059e440)) break;
    iVar5 = iVar5 + 1;
    uVar3 = uVar3 + 1;
    if (7 < iVar5) {
      uVar3 = 0;
      uVar2 = 1;
      piVar4 = (int *)(param_1 + 0xf0);
      do {
        if (*piVar4 < (int)uVar3) {
          uVar3 = uVar2;
        }
        uVar2 = uVar2 + 1;
        piVar4 = piVar4 + 0x17;
      } while ((int)uVar2 < 8);
      if (*(int *)(uVar3 * 0x5c + 0x94 + param_1) < param_2) {
        uVar3 = 0xffffffff;
      }
      return uVar3;
    }
  }
  return uVar2;
}


