// Function: FUN_004bbfc0 @ 004bbfc0
// Size (bytes): 154


void __thiscall FUN_004bbfc0(int *param_1,uint *param_2)

{
  int iVar1;
  
  if ((undefined *)(*param_2 & 0xfc0000) == &DAT_00680000) {
    if (param_1[0xc] == 0) {
      param_1[0xc] = 2;
      if (param_1[0xd] == 0) {
        param_1[0xd] = (int)(char)param_2[2];
      }
      iVar1 = *param_1;
      if (*(char *)(iVar1 + 0x105d) != '\0') {
        *(undefined1 *)(iVar1 + 0x105d) = 0;
        FUN_004e0ed0(*(undefined4 *)(iVar1 + 0x1054));
      }
      FUN_0042af40();
    }
  }
  else {
    if (param_1[0xc] == 2) {
      param_1[0xc] = 0;
    }
    if (*(char *)(*param_1 + 0x105d) != '\x01') {
      *(undefined1 *)(*param_1 + 0x105d) = 1;
      FUN_004e0ed0();
      return;
    }
  }
  return;
}


