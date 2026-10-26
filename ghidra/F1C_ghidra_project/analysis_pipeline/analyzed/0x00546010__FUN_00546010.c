// Function: FUN_00546010 @ 00546010
// Size (bytes): 403


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00546010(int *param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  void *pvVar2;
  
  DAT_008b8ef8 = 0;
  DAT_008b8eec = 0;
  DAT_008b8ee8 = 0;
  if ((DAT_008b8f00 != (code *)0x0) && (iVar1 = FUN_0055b8c0(param_2,&DAT_008b8ee8), iVar1 == 0)) {
    (*DAT_008b8f00)(0);
  }
  _DAT_008b8ef0 = DAT_008b8ee8;
  DAT_008b8eec = DAT_008b8ee8 / 2;
  InterlockedIncrement(&DAT_008b8ef8);
  FUN_00545f50(0);
  pvVar2 = operator_new(0x1f0);
  if (pvVar2 == (void *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_005435d0();
  }
  *param_1 = iVar1;
  FUN_0053c5d0(iVar1);
  *(uint *)(*param_1 + 0xec) = *(uint *)(*param_1 + 0xec) | param_3;
  FUN_0053ac70(2,0);
  iVar1 = FUN_00543a80(param_2);
  if (iVar1 == 0) {
    iVar1 = *(int *)(*param_1 + 0x110);
    DAT_008b8eec = DAT_008b8eec +
                   *(int *)(iVar1 + 0x20) + *(int *)(iVar1 + 0x1c) + *(int *)(iVar1 + 0x18) +
                   *(int *)(iVar1 + 0x14);
    _DAT_008b8ef4 = DAT_008b8eec;
    InterlockedIncrement(&DAT_008b8ef8);
    FUN_00545f50(0);
    iVar1 = FUN_00543fa0();
    if (iVar1 == 0) {
      for (iVar1 = *(int *)(*param_1 + 0x100); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x104)) {
        FUN_00549170();
        FUN_005492b0();
        FUN_00549380();
        FUN_00549440();
        FUN_00549470();
      }
      InterlockedIncrement(&DAT_008b8ef8);
      FUN_00545f50(0);
      FUN_0053ac70(1,0);
      return 0;
    }
    FUN_0053c630(*param_1);
    *param_1 = 0;
    return 0xffffffff;
  }
  FUN_0053c630(*param_1);
  return 0xffffffff;
}


