// Function: FUN_0041c4c0 @ 0041c4c0
// Size (bytes): 122


void FUN_0041c4c0(char param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined1 local_20 [32];
  
  if ((DAT_007d0308 != 0) && (DAT_007cf3c8 != DAT_0059e440)) {
    FUN_004144d0();
    iVar1 = FUN_004c2990();
    iVar1 = iVar1 + 2;
    if (param_1 == '\0') {
      uVar7 = 0xc0000000;
      uVar6 = 0xc0000000;
    }
    else {
      uVar7 = 0xbf800000;
      uVar6 = 0;
    }
    uVar5 = 0xffffffff;
    uVar4 = 0xffffffff;
    uVar3 = 0xffffffff;
    uVar2 = thunk_FUN_004201e0(iVar1,0xffffffff,0xffffffff,0xffffffff,uVar6,uVar7);
    FUN_004144f0(uVar2,iVar1,uVar3,uVar4,uVar5,uVar6,uVar7);
    FUN_00418560(local_20);
  }
  return;
}


