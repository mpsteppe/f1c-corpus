// Function: FUN_004a0590 @ 004a0590
// Size (bytes): 133


undefined4 FUN_004a0590(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = DAT_007c56a4;
  uVar2 = 1;
  switch(DAT_007c56a4) {
  case 1:
    uVar2 = 2;
    break;
  case 2:
    uVar2 = 3;
    break;
  case 3:
    uVar2 = 4;
    break;
  case 4:
    uVar2 = 5;
    break;
  case 5:
    uVar2 = 6;
    break;
  case 6:
    uVar2 = 7;
    break;
  default:
    goto switchD_004a05a7_default;
  }
  FUN_0042cf10(uVar2);
  if ((DAT_007d0410 == 4) && (iVar3 = FUN_004c2850(), iVar3 != 0)) {
    if (iVar1 == 7) {
      FUN_004a09a0();
      return 0;
    }
    FUN_004c15a0();
  }
  uVar2 = 0;
switchD_004a05a7_default:
  return uVar2;
}


