// Function: FUN_0052de60 @ 0052de60
// Size (bytes): 167


undefined4 __fastcall FUN_0052de60(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x2484);
  *(undefined4 *)(param_1 + 0x24d4) = 1;
  iVar2 = *(int *)(param_1 + 0x2494) * 0x23280;
  *(int *)(param_1 + 0x24d8) = iVar2 / iVar1;
  *(int *)(param_1 + 0x24dc) = (iVar2 % iVar1) / 100;
  *(int *)(param_1 + 0x24e0) = iVar1 / 100;
  if (*(char *)(param_1 + 0x2490) == '\x01') {
    *(int *)(param_1 + 0x248c) = *(int *)(param_1 + 0x24cc) * 0x300;
  }
  else {
    *(int *)(param_1 + 0x248c) = *(int *)(param_1 + 0x24cc) * 0x900;
  }
  *(undefined1 *)(param_1 + 0x24bc) = 1;
  *(undefined4 *)(param_1 + 0x249c) = *(undefined4 *)(param_1 + 0x248c);
  return 0;
}


