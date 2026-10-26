// Function: FUN_004674e0 @ 004674e0
// Size (bytes): 402


void __fastcall FUN_004674e0(int param_1)

{
  int iVar1;
  undefined1 local_40 [64];
  
  FUN_00489cb0();
  switch(*(undefined4 *)(param_1 + 0x174)) {
  case 0x1be:
    FUN_00431950(DAT_007c737c,local_40);
    DAT_007c7378 = 0;
    break;
  case 0x1bf:
  case 0x1c0:
  case 0x1c1:
  case 0x1c2:
    if (DAT_007d048c != '\0') {
      FUN_00431aa0(*(undefined4 *)(param_1 + 0x178),local_40,3);
      FUN_00489600(local_40,0,0,0,0);
      return;
    }
    if (*(int *)(param_1 + 0x178) == 1) {
      FUN_0042ec00(local_40);
      FUN_00489600(local_40,0,0,0,0);
    }
    FUN_00431aa0(*(undefined4 *)(param_1 + 0x178),local_40,2);
    FUN_00489600(local_40,0,0,0,0);
    FUN_00431aa0(*(undefined4 *)(param_1 + 0x178),local_40,1);
    FUN_00489600(local_40,0,0,0,0);
    FUN_00431aa0(*(undefined4 *)(param_1 + 0x178),local_40,0);
    break;
  case 0x1c3:
  case 0x1c4:
  case 0x1c5:
  case 0x1c6:
    iVar1 = *(int *)(param_1 + 0x178);
    FUN_00431950(*(undefined4 *)(&DAT_007c7384 + iVar1 * 4),local_40);
    (&DAT_007c7380)[iVar1] = 0;
    FUN_00489600(local_40,0,0,0,0);
    return;
  case 0x1c7:
  case 0x1c8:
  case 0x1c9:
  case 0x1ca:
    FUN_004319e0(*(undefined4 *)(param_1 + 0x178),local_40);
    break;
  default:
    goto switchD_00467506_default;
  }
  FUN_00489600(local_40,0,0,0,0);
switchD_00467506_default:
  return;
}


