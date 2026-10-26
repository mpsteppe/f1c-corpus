// Function: FUN_0041afd0 @ 0041afd0
// Size (bytes): 385


void FUN_0041afd0(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 local_20 [32];
  
  if (DAT_007d0308 == 0) {
    return;
  }
  if (DAT_007cf3c8 == DAT_0059e440) {
    return;
  }
  FUN_004144d0();
  if (*(int *)(DAT_007c54e8 + 0x4894) == *(int *)(param_1 + 0x4894)) {
    switch(param_2) {
    case 0:
      uVar2 = 0xffffffff;
      uVar1 = 0x6a;
      break;
    case 1:
      uVar2 = 0xffffffff;
      uVar1 = 0x6b;
      break;
    case 2:
      uVar2 = 0xffffffff;
      uVar1 = 0x6d;
      break;
    case 3:
      uVar2 = 0xffffffff;
      uVar1 = 0x6e;
      break;
    case 4:
      uVar2 = 0xffffffff;
      uVar1 = 0x6c;
      break;
    case 5:
      uVar2 = 0xffffffff;
      uVar1 = 0x6f;
      break;
    default:
      goto switchD_0041b028_default;
    }
  }
  else {
    if (DAT_007c56a8 == 8) goto switchD_0041b028_default;
    switch(param_2) {
    case 0:
    case 1:
    case 2:
    case 3:
      uVar2 = *(undefined4 *)(param_1 + 0x489c);
      uVar1 = 0xdd;
      break;
    case 4:
      uVar2 = *(undefined4 *)(param_1 + 0x489c);
      uVar1 = 0xde;
      break;
    case 5:
      uVar2 = *(undefined4 *)(param_1 + 0x489c);
      uVar1 = 0xdf;
      break;
    default:
      goto switchD_0041b028_default;
    }
  }
  FUN_004144f0(uVar1,uVar2,0xffffffff,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
switchD_0041b028_default:
  FUN_00418560(local_20);
  return;
}


