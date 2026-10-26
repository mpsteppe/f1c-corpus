// Function: FUN_0040da30 @ 0040da30
// Size (bytes): 197


void __fastcall FUN_0040da30(undefined4 *param_1)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  
  *param_1 = 1;
  param_1[0x21] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  if (*(char *)(param_1 + 0x28) != '\0') {
    *(undefined1 *)(param_1[1] + 0x24) = 0;
  }
  *(undefined1 *)(param_1 + 0x28) = 0;
  if (param_1[0x24] != 0) {
    FUN_0040d1b0(param_1[0x24],1);
  }
  iVar1 = param_1[0x25];
  if (-1 < iVar1) {
    DAT_007c54e0 = (&DAT_007c54f0)[iVar1];
    DAT_007c54dc = iVar1;
  }
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0xffffffff;
  FUN_00567f10();
  if (param_1[0x22] == 0) {
    pvVar2 = operator_new(0x30);
    if (pvVar2 == (void *)0x0) {
      uVar3 = 0;
    }
    else {
      uVar3 = FUN_0040d470(param_1);
    }
    param_1[0x22] = uVar3;
  }
  else {
    FUN_0040d490();
  }
  if (param_1[0x22] == 0) {
    *param_1 = 0xffffffff;
  }
  return;
}


