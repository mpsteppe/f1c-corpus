// Function: FUN_004199e0 @ 004199e0
// Size (bytes): 554


void FUN_004199e0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 local_24 [4];
  undefined1 local_20 [32];
  
  iVar4 = param_1;
  if ((((DAT_007d0308 != 0) && (DAT_007cf3c8 != DAT_0059e440)) && (DAT_007c56a8 != 8)) &&
     (((0 < DAT_007c56a4 && (4 < DAT_007c56a4)) &&
      ((DAT_007c56a4 == 7 && (*(int *)(DAT_007c54e8 + 0x4894) == *(int *)(param_1 + 0x4894))))))) {
    FUN_004144d0();
    FUN_004144f0(0x29,*(undefined4 *)(iVar4 + 0x4060),0xffffffff,0xffffffff,0xffffffff,0xc0000000,
                 0xc0000000);
    FUN_00418560(local_20);
    iVar1 = *(int *)(iVar4 + 0x40d0);
    if ((iVar1 != 0) && (iVar2 = FUN_0049b6d0(iVar1,iVar4,local_24,&param_1), iVar2 == 0)) {
      if (param_1 < 1) {
        uVar3 = __ftol();
      }
      else {
        uVar3 = 9999;
      }
      FUN_004144f0(1,*(undefined4 *)(iVar1 + 0x489c),*(undefined4 *)(iVar1 + 0x4060),uVar3,
                   0xffffffff,0xc0000000,0xc0000000);
      FUN_00418560(local_20);
    }
    iVar1 = *(int *)(iVar4 + 0x40d4);
    if (((iVar1 != 0) && (*(int *)(iVar1 + 0x4064) != 2)) &&
       (iVar4 = FUN_0049b6d0(iVar4,iVar1,local_24,&param_1), iVar4 == 0)) {
      if (param_1 < 1) {
        uVar3 = __ftol();
      }
      else {
        uVar3 = 9999;
      }
      FUN_004144f0(2,*(undefined4 *)(iVar1 + 0x489c),*(undefined4 *)(iVar1 + 0x4060),uVar3,
                   0xffffffff,0xc0000000,0xc0000000);
      FUN_00418560(local_20);
    }
    iVar4 = DAT_008acf8c - *(int *)(DAT_007c54e0 + 0x403c);
    switch(iVar4) {
    case 1:
      FUN_004144f0(0x111,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
      FUN_00418560(local_20);
      break;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 0xb:
    case 0xc:
    case 0xf:
    case 0x14:
    case 0x19:
    case 0x1e:
    case 0x23:
    case 0x28:
    case 0x32:
      FUN_004144f0(0x110,iVar4,0xffffffff,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
      FUN_00418560(local_20);
      return;
    }
  }
  return;
}


