// Function: FUN_004b3b40 @ 004b3b40
// Size (bytes): 83


void __fastcall FUN_004b3b40(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  if (param_1[0x1b002] != param_1[0x1b001]) {
    do {
      FUN_004b3400();
      iVar2 = param_1[0x1b002];
      param_1[0x1b002] = iVar2 + 0x1b0;
      *param_1 = *param_1 + -1;
    } while (iVar2 + 0x1b0 != param_1[0x1b001]);
  }
  piVar1 = param_1 + 1;
  param_1[0x1b003] = (int)piVar1;
  param_1[0x1b002] = (int)piVar1;
  param_1[0x1b001] = (int)piVar1;
  return;
}


