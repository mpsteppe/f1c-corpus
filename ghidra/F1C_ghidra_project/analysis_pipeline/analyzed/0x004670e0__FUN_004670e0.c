// Function: FUN_004670e0 @ 004670e0
// Size (bytes): 79


undefined4 __fastcall FUN_004670e0(int param_1)

{
  int iVar1;
  
  switch(*(undefined4 *)(param_1 + 0x334)) {
  case 0xec:
  case 0xed:
  case 0xee:
  case 0xef:
  case 0xf0:
  case 0xf1:
  case 0xf2:
  case 0xf3:
  case 0xf4:
  case 0xf5:
  case 0xf6:
  case 0xf7:
    iVar1 = (**(code **)(*DAT_007cd8c0 + 0x1c))(0xe);
    break;
  default:
    goto switchD_004670fc_caseD_f8;
  case 0x10d:
  case 0x10e:
  case 0x10f:
  case 0x115:
  case 0x116:
  case 0x17d:
  case 0x17e:
  case 0x181:
  case 0x182:
  case 0x184:
  case 0x185:
  case 0x186:
  case 0x187:
  case 0x188:
  case 0x189:
  case 0x18a:
  case 0x18c:
  case 0x18d:
  case 0x18e:
  case 399:
  case 0x19c:
  case 0x19d:
    iVar1 = (**(code **)(*DAT_007cd8c0 + 0x1c))(0xb);
  }
  if (iVar1 != 0) {
    FUN_00477280(param_1);
  }
switchD_004670fc_caseD_f8:
  return 0;
}


