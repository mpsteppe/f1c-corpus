// Function: FUN_0046a9c0 @ 0046a9c0
// Size (bytes): 661


void __fastcall FUN_0046a9c0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  piVar4 = (int *)(param_1 + 0x200);
  FUN_0046a980(piVar4);
  iVar3 = *(int *)(param_1 + 500);
  (&DAT_007d1b08)[iVar3 * 7] = *piVar4;
  (&DAT_007d1b0c)[iVar3 * 7] = *(undefined4 *)(param_1 + 0x204);
  if (*piVar4 != 1) {
    return;
  }
  switch(*(undefined4 *)(param_1 + 0x204)) {
  case 1:
    iVar1 = 0;
    iVar3 = 2;
    iVar2 = 0;
    break;
  case 2:
    iVar1 = 0;
    iVar3 = 1;
    iVar2 = 0;
    break;
  case 3:
    iVar3 = 4;
    iVar1 = 0;
    iVar2 = 1;
    break;
  case 4:
    iVar3 = 3;
    iVar1 = 0;
    iVar2 = 1;
    break;
  case 5:
    iVar3 = 6;
    iVar1 = 0;
    iVar2 = 2;
    break;
  case 6:
    iVar3 = 5;
    iVar1 = 0;
    iVar2 = 2;
    break;
  case 7:
    iVar3 = 8;
    iVar1 = 0;
    iVar2 = 3;
    break;
  case 8:
    iVar3 = 7;
    iVar1 = 0;
    iVar2 = 3;
    break;
  case 9:
    iVar3 = 10;
    iVar1 = 0;
    iVar2 = 4;
    break;
  case 10:
    iVar3 = 9;
    iVar1 = 0;
    iVar2 = 4;
    break;
  case 0xb:
    iVar3 = 0xc;
    iVar1 = 0;
    iVar2 = 5;
    break;
  case 0xc:
    iVar3 = 0xb;
    iVar1 = 0;
    iVar2 = 5;
    break;
  default:
    goto switchD_0046aa0c_caseD_d;
  case 0x1e:
    iVar3 = 0x1f;
    iVar1 = 1;
    iVar2 = 0;
    break;
  case 0x1f:
    iVar3 = 0x1e;
    iVar1 = 1;
    iVar2 = 0;
    break;
  case 0x20:
    iVar1 = 1;
    iVar3 = 0x21;
    iVar2 = 1;
    break;
  case 0x21:
    iVar1 = 1;
    iVar3 = 0x20;
    iVar2 = 1;
    break;
  case 0x22:
    iVar3 = 0x23;
    iVar1 = 1;
    iVar2 = 2;
    break;
  case 0x23:
    iVar3 = 0x22;
    iVar1 = 1;
    iVar2 = 2;
    break;
  case 0x24:
    iVar3 = 0x25;
    iVar1 = 1;
    iVar2 = 3;
    break;
  case 0x25:
    iVar3 = 0x24;
    iVar1 = 1;
    iVar2 = 3;
    break;
  case 0x26:
    iVar3 = 0x27;
    iVar1 = 1;
    iVar2 = 4;
    break;
  case 0x27:
    iVar3 = 0x26;
    iVar1 = 1;
    iVar2 = 4;
    break;
  case 0x28:
    iVar3 = 0x29;
    iVar1 = 1;
    iVar2 = 5;
    break;
  case 0x29:
    iVar3 = 0x28;
    iVar1 = 1;
    iVar2 = 5;
    break;
  case 0x66:
    iVar3 = 0x67;
    iVar1 = 0;
    iVar2 = 6;
    break;
  case 0x67:
    iVar3 = 0x66;
    iVar1 = 0;
    iVar2 = 6;
    break;
  case 0x68:
    iVar3 = 0x69;
    iVar1 = 0;
    goto LAB_0046ac1b;
  case 0x69:
    iVar3 = 0x68;
    iVar1 = 0;
    goto LAB_0046ac1b;
  case 0x6a:
    iVar3 = 0x6b;
    iVar1 = 1;
    iVar2 = 6;
    break;
  case 0x6b:
    iVar3 = 0x6a;
    iVar1 = 1;
    iVar2 = 6;
    break;
  case 0x6c:
    iVar3 = 0x6d;
    goto LAB_0046ac16;
  case 0x6d:
    iVar3 = 0x6c;
LAB_0046ac16:
    iVar1 = 1;
LAB_0046ac1b:
    iVar2 = 7;
  }
  piVar4 = &DAT_007d1b0c;
  do {
    if ((piVar4[-1] == 1) && (*piVar4 == iVar3)) {
      (&DAT_007d1490)[(iVar2 + iVar1 * 8) * 0x1b] = 0x3f000000;
    }
    piVar4 = piVar4 + 7;
  } while ((int)piVar4 < 0x7d1fdc);
switchD_0046aa0c_caseD_d:
  return;
}


