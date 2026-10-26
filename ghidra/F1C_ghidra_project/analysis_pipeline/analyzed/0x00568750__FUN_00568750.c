// Function: FUN_00568750 @ 00568750
// Size (bytes): 50


undefined1 __fastcall FUN_00568750(char param_1)

{
  int iVar1;
  
  iVar1 = FUN_00589c1b((int)param_1);
  if (iVar1 != 0) {
switchD_00568774_caseD_22:
    return 1;
  }
  switch((int)param_1) {
  case 0x20:
  case 0x21:
  case 0x23:
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x2f:
  case 0x3a:
  case 0x3b:
  case 0x3d:
  case 0x40:
  case 0x5b:
  case 0x5c:
  case 0x5d:
  case 0x5e:
  case 0x5f:
  case 0x60:
  case 0x7b:
  case 0x7d:
  case 0x7e:
    goto switchD_00568774_caseD_22;
  default:
    return 0;
  }
}


