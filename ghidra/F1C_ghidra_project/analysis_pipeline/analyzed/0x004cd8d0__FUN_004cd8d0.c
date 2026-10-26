// Function: FUN_004cd8d0 @ 004cd8d0
// Size (bytes): 176


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004cd8d0(int param_1,float param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  param_2 = param_2 * _DAT_005acec4;
  if ((int)ROUND(param_2) == 0) {
    if (0 < *(int *)(param_1 + 100)) {
      FUN_004cb5e0();
      return;
    }
  }
  else {
    if ((0 < *(int *)(param_1 + 0x58)) && (*(int *)(param_1 + 100) == 0)) {
      FUN_004024f0();
    }
    iVar2 = (int)ROUND(param_2) * 0x1000000 + 0xffffff;
    iVar3 = 0;
    if (0 < *(int *)(param_1 + 100)) {
      do {
        puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x68) + iVar3 * 4);
        FUN_00558dc0(*puVar1,0,iVar2);
        FUN_00558dc0(*puVar1,1,iVar2);
        FUN_00558dc0(*puVar1,2,iVar2);
        FUN_00558dc0(*puVar1,3,iVar2);
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)(param_1 + 100));
    }
  }
  return;
}


