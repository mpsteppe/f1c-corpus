// Function: FUN_004b71e0 @ 004b71e0
// Size (bytes): 180


void __fastcall FUN_004b71e0(int param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  int iVar3;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  FUN_004b5f60();
  FUN_004b5e50();
  piVar2 = *(int **)(param_1 + 0x6c0);
  while (piVar2 != (int *)0x0) {
    piVar1 = (int *)piVar2[1];
    if (((char)piVar2[3] != '\0') && (iVar3 = *piVar2, iVar3 != 0)) {
      if (*(int *)(iVar3 + 4) != 0) {
        FUN_00587bcf(*(int *)(iVar3 + 4));
      }
      FUN_00587bcf(iVar3);
    }
    FUN_00587bcf(piVar2);
    piVar2 = piVar1;
  }
  *(undefined4 *)(param_1 + 0x6c0) = 0;
  *(undefined4 *)(param_1 + 0x6c4) = 0;
  *(undefined4 *)(param_1 + 0x6c8) = 0;
  *(undefined4 *)(param_1 + 0x6cc) = 0;
  FUN_004b52a0();
  *(undefined4 *)(param_1 + 0xf38) = 0;
  *(undefined4 *)(param_1 + 0xf3c) = 0;
  *(undefined1 *)(param_1 + 0x6d0) = 0;
  *(undefined4 *)(param_1 + 0x9b8) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x9bc) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xf8c) = 5;
  FUN_004b6130(unaff_EBX);
  switch(*(undefined4 *)(param_1 + 0x9a4)) {
  case 0:
    *(undefined4 *)(param_1 + 0x9b4) = 0x10;
    break;
  case 1:
    *(undefined4 *)(param_1 + 0x9b4) = 0x18;
    break;
  case 2:
    *(undefined4 *)(param_1 + 0x9b4) = 0x20;
    break;
  case 3:
    *(undefined4 *)(param_1 + 0x9b4) = 0x30;
    break;
  case 4:
    *(undefined4 *)(param_1 + 0x9b4) = 0x60;
    break;
  default:
    goto LAB_004b6115;
  }
  iVar3 = *(int *)(param_1 + 0x9b4);
  piVar2 = operator_new(iVar3 * 0xb0 + 4);
  if (piVar2 != (int *)0x0) {
    *piVar2 = iVar3;
    if (-1 < iVar3 + -1) {
      do {
        FUN_004b46b0(unaff_EDI,unaff_ESI,unaff_EBP);
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    *(int **)(param_1 + 0x9b0) = piVar2 + 1;
    return;
  }
  *(undefined4 *)(param_1 + 0x9b0) = 0;
LAB_004b6115:
  return;
}


