// Function: FUN_0054bb40 @ 0054bb40
// Size (bytes): 287


undefined4 __thiscall FUN_0054bb40(int param_1,int param_2)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 local_b0 [32];
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_7c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  
  iVar4 = *(int *)(param_1 + 0x214);
  if (iVar4 == 0) {
    pvVar1 = operator_new(0x28);
    if (pvVar1 == (void *)0x0) {
      iVar2 = 0;
      *(undefined4 *)(param_1 + 0x214) = 0;
    }
    else {
      iVar2 = FUN_005510f0(*(undefined4 *)(param_2 + 0xc));
      *(int *)(param_1 + 0x214) = iVar2;
    }
  }
  else {
    for (iVar2 = *(int *)(iVar4 + 0x24); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x24)) {
      iVar4 = iVar2;
    }
    pvVar1 = operator_new(0x28);
    if (pvVar1 == (void *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_005510f0(*(undefined4 *)(param_2 + 0xc));
    }
    *(int *)(iVar4 + 0x24) = iVar2;
  }
  iVar4 = *(int *)(param_2 + 0xc);
  iVar3 = 0;
  *(int *)(iVar2 + 0x14) = iVar4;
  if (0 < iVar4) {
    iVar4 = 0;
    do {
      *(int *)(iVar4 + *(int *)(iVar2 + 0x18)) = iVar3;
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x88;
    } while (iVar3 < *(int *)(iVar2 + 0x14));
  }
  FUN_00551440();
  *(int *)(iVar2 + 0x1c) = param_2;
  FUN_00557350();
  local_8c = *(undefined4 *)(param_2 + 0xc);
  local_7c = 0x42c80000;
  local_90 = 2;
  local_50 = 0xdfdf1f;
  local_58 = 0x10;
  local_54 = 0;
  if (*(int *)(param_1 + 0x218) == 0) {
    FUN_00559200(param_1 + 0x218,local_b0);
  }
  FUN_004b0170();
  return 0;
}


