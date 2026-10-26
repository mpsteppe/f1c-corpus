// Function: FUN_0041c440 @ 0041c440
// Size (bytes): 116


void FUN_0041c440(void)

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
    iVar1 = -1;
    if (DAT_007d0410 == 4) {
      iVar1 = FUN_004c2990();
      iVar1 = iVar1 + 1;
    }
    uVar7 = 0xc0000000;
    uVar6 = 0xc0000000;
    uVar5 = 0xffffffff;
    uVar4 = 0xffffffff;
    uVar3 = 0xffffffff;
    uVar2 = FUN_00420000(iVar1,0xffffffff,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
    FUN_004144f0(uVar2,iVar1,uVar3,uVar4,uVar5,uVar6,uVar7);
    FUN_00418560(local_20);
  }
  return;
}


