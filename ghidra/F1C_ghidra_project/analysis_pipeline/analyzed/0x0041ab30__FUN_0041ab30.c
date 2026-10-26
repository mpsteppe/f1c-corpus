// Function: FUN_0041ab30 @ 0041ab30
// Size (bytes): 265


void __thiscall FUN_0041ab30(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 local_20 [32];
  
  if (DAT_007d0308 == 0) {
    return;
  }
  if (DAT_007cf3c8 == DAT_0059e440) {
    return;
  }
  if (DAT_007c56a8 == 8) {
    return;
  }
  *(undefined4 *)(param_1 + 0xa44 + param_2 * 4) = 2;
  FUN_004144d0();
  iVar3 = 0;
  piVar1 = (int *)(param_1 + 0xa44);
  iVar2 = 4;
  do {
    if (*piVar1 == 2) {
      iVar3 = iVar3 + 1;
    }
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  if (iVar3 < 3) {
    switch(param_2) {
    case 0:
      uVar4 = 0x5e;
      break;
    case 1:
      uVar4 = 0x60;
      break;
    case 2:
      uVar4 = 0x62;
      break;
    case 3:
      uVar4 = 100;
      break;
    default:
      goto switchD_0041abbc_default;
    }
  }
  else {
    uVar4 = 0x68;
  }
  FUN_004144f0(uVar4,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
switchD_0041abbc_default:
  FUN_00418560(local_20);
  return;
}


