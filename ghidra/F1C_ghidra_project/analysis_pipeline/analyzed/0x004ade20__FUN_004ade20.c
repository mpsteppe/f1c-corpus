// Function: FUN_004ade20 @ 004ade20
// Size (bytes): 229


void __thiscall FUN_004ade20(int param_1,char param_2)

{
  int iVar1;
  
  if (param_2 == '\0') {
    *(undefined4 *)(param_1 + 0x1aec) = 1;
  }
  else if ((DAT_007cb710 & 1) == 0) {
    if ((DAT_007cbb0c & 1) == 0) {
      FUN_004ae750(1);
    }
    else {
      FUN_004ae750(3);
    }
  }
  else {
    FUN_004ae750(2);
  }
  if (0 < *(int *)(param_1 + 0x1b10)) {
    iVar1 = DAT_005ec4a8 + 1;
    if (4 < iVar1) {
      iVar1 = 4;
    }
    *(int *)(param_1 + 0x1b10) = iVar1;
    if (*(int *)(param_1 + 0x1b10) < *(int *)(param_1 + 0x1b18)) {
      *(int *)(param_1 + 0x1b10) = *(int *)(param_1 + 0x1b18);
    }
    else if (*(int *)(param_1 + 0x1b1c) < *(int *)(param_1 + 0x1b10)) {
      *(int *)(param_1 + 0x1b10) = *(int *)(param_1 + 0x1b1c);
    }
  }
  iVar1 = DAT_008ac48c * 0x18c + DAT_008ac490;
  if (iVar1 != 0) {
    FUN_004c55b0(iVar1 + 0x104);
  }
  FUN_004af3a0();
  FUN_004b0170();
  FUN_004adf10();
  FUN_004ae490();
  FUN_004ae9f0();
  FUN_004af220();
  return;
}


