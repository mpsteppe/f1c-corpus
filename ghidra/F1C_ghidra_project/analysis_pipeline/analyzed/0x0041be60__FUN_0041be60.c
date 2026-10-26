// Function: FUN_0041be60 @ 0041be60
// Size (bytes): 537


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041be60(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 local_20 [32];
  
  if (DAT_007d0308 == 0) {
    return;
  }
  if (DAT_007cf3c8 == DAT_0059e440) {
    return;
  }
  FUN_004144d0();
  uVar1 = FUN_004ff130();
  iVar2 = FUN_004ff1d0();
  switch(uVar1) {
  case 2:
    if (iVar2 != 2) {
      FUN_004144f0(0x200,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
      FUN_00418560(local_20);
      return;
    }
    FUN_004144f0(0x1fa,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
    FUN_00418560(local_20);
    if (_DAT_008afef0 <= _DAT_0059e468) {
      return;
    }
    FUN_004144f0(0x1fb,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
    FUN_00418560(local_20);
    return;
  case 3:
    if ((iVar2 == 3) || (iVar2 == 2)) {
      uVar1 = 0x1fd;
    }
    else {
      uVar1 = 0x200;
    }
    goto LAB_0041c05d;
  case 4:
    if ((iVar2 != 4) && (iVar2 != 5)) {
LAB_0041bfc5:
      FUN_004144f0(0x200,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
      FUN_00418560(local_20);
      return;
    }
    uVar1 = 0x1fe;
    break;
  case 5:
    if ((iVar2 != 4) && (iVar2 != 5)) goto LAB_0041bfc5;
    uVar1 = 0x1ff;
    break;
  default:
    goto switchD_0041beb4_default;
  }
  FUN_004144f0(uVar1,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
  FUN_00418560(local_20);
  if ((float)_DAT_0059e830 < (_DAT_008afee8 + _DAT_008afeec) * _DAT_0059e450) {
    uVar1 = 0x201;
LAB_0041c05d:
    FUN_004144f0(uVar1,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
    FUN_00418560(local_20);
  }
switchD_0041beb4_default:
  return;
}


