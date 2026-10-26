// Function: FUN_005491d0 @ 005491d0
// Size (bytes): 114


void __fastcall FUN_005491d0(int param_1)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  
  iVar1 = *(int *)(param_1 + 0xf0);
  if (iVar1 == 0) {
    pvVar3 = operator_new(0x38);
    if (pvVar3 == (void *)0x0) {
      *(undefined4 *)(param_1 + 0xf0) = 0;
      return;
    }
    uVar4 = FUN_0055d200();
    *(undefined4 *)(param_1 + 0xf0) = uVar4;
    return;
  }
  for (iVar2 = *(int *)(iVar1 + 0x34); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x34)) {
    iVar1 = iVar2;
  }
  pvVar3 = operator_new(0x38);
  if (pvVar3 == (void *)0x0) {
    *(undefined4 *)(iVar1 + 0x34) = 0;
    return;
  }
  uVar4 = FUN_0055d200();
  *(undefined4 *)(iVar1 + 0x34) = uVar4;
  return;
}


