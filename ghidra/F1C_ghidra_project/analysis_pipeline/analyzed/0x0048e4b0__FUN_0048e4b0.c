// Function: FUN_0048e4b0 @ 0048e4b0
// Size (bytes): 231


undefined4 __fastcall FUN_0048e4b0(int *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  
  puVar1 = (undefined1 *)param_1[0x2c];
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = &DAT_005ea438;
  }
  puVar4 = (undefined1 *)param_1[0x3f];
  if (puVar4 == (undefined1 *)0x0) {
    puVar4 = &DAT_005ea438;
  }
  iVar2 = FUN_00588410(puVar4,puVar1);
  if (iVar2 != 0) {
    (**(code **)(*param_1 + 0xa0))();
    return 0;
  }
  if ((param_1[0x39] != 0) && ((char)param_1[0x3e] != '\0')) {
    iVar2 = param_1[0x3b];
    iVar6 = param_1[0x3a];
    uVar8 = 0x20;
    uVar3 = FUN_00495150(iVar6,iVar2,0x20);
    iVar2 = FUN_00551cf0(uVar3,iVar6,iVar2,uVar8);
    if (iVar2 == 1) {
      iVar2 = param_1[0x3d];
      iVar6 = param_1[0x3c];
      iVar7 = param_1[0x3b];
      iVar5 = param_1[0x3a];
      *(undefined1 *)(param_1 + 0x3e) = 0;
      FUN_00490920(iVar5,iVar7,iVar6,iVar2);
      FUN_004918d0(iVar5,iVar7,iVar6,iVar2);
    }
    (**(code **)(*param_1 + 0x2c))(1);
    (**(code **)(*param_1 + 0x10))(param_1[0x3b],param_1[0x3d],param_1[0x3a],param_1[0x3c]);
  }
  return 0;
}


