// Function: FUN_00598aa0 @ 00598aa0
// Size (bytes): 74


int * __fastcall FUN_00598aa0(int *param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  if ((*(byte *)((int)param_1 + *(int *)(*param_1 + 4) + 4) & 6) == 0) {
    iVar1 = (**(code **)(**(int **)((int)param_1 + *(int *)(*param_1 + 4) + 0x28) + 0x2c))();
    if (iVar1 == -1) {
      uVar2 = 4;
    }
  }
  if (uVar2 != 0) {
    uVar2 = *(uint *)((int)param_1 + *(int *)(*param_1 + 4) + 4) | uVar2;
    if (*(int *)((int)param_1 + *(int *)(*param_1 + 4) + 0x28) == 0) {
      uVar2 = uVar2 | 4;
    }
    FUN_0059a5fe(uVar2,0);
  }
  return param_1;
}


