// Function: FUN_00560050 @ 00560050
// Strings:  [Could not locate bitmap file %s, Error loading bit map %s, Error loading bit map %s, Error loading bit map %s]


undefined4 __thiscall FUN_00560050(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  void *pvVar3;
  void *pvVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  undefined1 local_100 [256];
  
  iVar2 = FUN_00560230(param_3);
  if (iVar2 != 0) {
    FUN_0058815f(local_100,s_Could_not_locate_bitmap_file__s_005dbd94,param_3);
    FUN_0053c590(0xfffffffe,local_100);
    return 0xfffffffe;
  }
  if (DAT_008b8e28 != 0) {
    iVar2 = *(int *)(param_1 + 0x124) * 0x100;
    uVar1 = *(uint *)(iVar2 + 8 + *(int *)(param_1 + 0x128));
    pbVar7 = (byte *)(iVar2 + *(int *)(param_1 + 0x128));
    uVar6 = *(uint *)(pbVar7 + 0xc);
    pvVar3 = operator_new(uVar1);
    pvVar4 = operator_new(uVar6);
    if ((*pbVar7 & 0x10) == 0) {
      uVar6 = FUN_0058803f(pvVar3,1,uVar1,*(undefined4 *)(param_1 + 0x10));
      if (uVar6 != uVar1) goto LAB_0056016f;
    }
    else {
      uVar5 = FUN_0058803f(pvVar4,1,uVar6,*(undefined4 *)(param_1 + 0x10));
      if (uVar5 != uVar6) {
LAB_0056016f:
        FUN_00587bcf(pvVar3);
        FUN_00587bcf(pvVar4);
        FUN_0058815f(local_100,s_Error_loading_bit_map__s_005dc608,pbVar7 + 0x14);
        FUN_0053c590(0xffffffff,local_100);
        return 0xffffffff;
      }
      iVar2 = FUN_0059b260(pvVar4,uVar6);
      if (iVar2 != 0) {
        FUN_00587bcf(pvVar3);
        FUN_00587bcf(pvVar4);
        FUN_0058815f(local_100,s_Error_loading_bit_map__s_005dc608,pbVar7 + 0x14);
        FUN_0053c590(0xffffffff,local_100);
        return 0xffffffff;
      }
    }
    iVar2 = FUN_0053fed0(pvVar3,uVar1,param_2,1,0);
    if (iVar2 != 0) {
      FUN_00587bcf(pvVar3);
      FUN_00587bcf(pvVar4);
      FUN_0058815f(local_100,s_Error_loading_bit_map__s_005dc608,pbVar7 + 0x14);
      FUN_0053c590(0xffffffff,local_100);
      return 0xffffffff;
    }
    FUN_00587bcf(pvVar3);
    FUN_00587bcf(pvVar4);
  }
  return 0;
}


