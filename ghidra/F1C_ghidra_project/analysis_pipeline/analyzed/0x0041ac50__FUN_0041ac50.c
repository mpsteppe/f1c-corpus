// Function: FUN_0041ac50 @ 0041ac50
// Size (bytes): 269


void FUN_0041ac50(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined1 local_20 [32];
  
  if ((((DAT_007d0308 != 0) && (DAT_007cf3c8 != DAT_0059e440)) && (param_1 != 0)) &&
     ((((DAT_007c56a8 != 8 && (DAT_007c56a4 == 7)) &&
       ((FUN_004144d0(), DAT_007c54e8 == 0 || (DAT_007c54e8 != param_1)))) &&
      (*(int *)(param_1 + 0x4064) == 0)))) {
    if (param_2 == 0) {
      uVar1 = 0xd0;
    }
    else if (param_2 == 2) {
      switch(*(undefined4 *)(param_1 + 0x39fc)) {
      case 0:
      case 1:
        uVar1 = 0xd4;
        break;
      case 2:
        uVar1 = 0xd5;
        break;
      case 3:
        uVar1 = 0xd6;
        break;
      case 4:
        uVar1 = 0xd7;
        break;
      case 5:
        uVar1 = 0xd8;
        break;
      case 6:
        uVar1 = 0xd9;
        break;
      default:
        uVar1 = 0xd3;
      }
    }
    else {
      if (param_2 != 3) {
        return;
      }
      uVar1 = 0xdc;
    }
    FUN_004144f0(uVar1,*(undefined4 *)(param_1 + 0x489c),0xffffffff,0xffffffff,0xffffffff,0xc0000000
                 ,0xc0000000);
    FUN_00418560(local_20);
  }
  return;
}


