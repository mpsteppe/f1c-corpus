// Function: FUN_00448330 @ 00448330
// Size (bytes): 257


void __thiscall FUN_00448330(int param_1,float param_2)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined1 local_c [4];
  undefined1 local_8 [4];
  undefined1 local_4 [4];
  
  if (DAT_0059e440 < *(float *)(param_1 + 8)) {
    fVar3 = (float10)FUN_0058957a();
    iVar1 = FUN_0054c210();
    iVar2 = 0;
    if (0 < iVar1) {
      do {
        FUN_0054c230(iVar2);
        FUN_00551810(*(undefined4 *)(param_1 + 0xc),(float)fVar3);
        iVar2 = iVar2 + 1;
      } while (iVar2 < iVar1);
    }
  }
  FUN_0054b950(local_c,local_8,local_4);
  uStack_18 = 0;
  uStack_14 = 0;
  uStack_10 = 0;
  if (*(int **)(param_1 + 4) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 4) + 4))(2,local_c,&uStack_18,DAT_007cf2cc,0x3f800000,0);
  }
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 0) {
    *(float *)(param_1 + 0x18) = param_2;
    return;
  }
  if (param_2 == *(float *)(param_1 + 0x18)) {
    FUN_00550620(iVar1,0);
    *(float *)(param_1 + 0x18) = param_2;
    return;
  }
  FUN_005505a0(iVar1,0);
  *(float *)(param_1 + 0x18) = param_2;
  return;
}


