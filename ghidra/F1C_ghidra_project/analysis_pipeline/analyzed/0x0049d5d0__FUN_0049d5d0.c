// Function: FUN_0049d5d0 @ 0049d5d0
// Size (bytes): 219


void __thiscall FUN_0049d5d0(int param_1,undefined4 param_2)

{
  switch(DAT_007ce048) {
  case 0:
  case 1:
  case 3:
  case 4:
    if (((*(int *)(param_1 + 0x14) != 0) && (*(int *)(param_1 + 0x18) != 0)) &&
       (*(int *)(param_1 + 8) != 0)) {
      FUN_005432f0(0,0,*(undefined4 *)(*(int *)(param_1 + 0x14) + 0x54),0,0,0x3f800000,0x3f800000,0,
                   0);
      if ((char)param_2 == '\0') {
        switch(DAT_007ce048) {
        case 0:
          switch(DAT_007c56a4) {
          case 0:
          case 1:
          case 2:
          case 3:
          case 4:
          case 5:
            FUN_0049d8b0();
            return;
          case 6:
            FUN_0049da60();
            return;
          case 7:
            FUN_0049d700();
            return;
          }
          break;
        case 1:
          FUN_0049e3e0();
          return;
        case 3:
          if (*(int *)(param_1 + 0xc) != 0) {
            FUN_0049e170();
            return;
          }
          break;
        case 4:
          FUN_0049db80();
          return;
        }
      }
    }
    break;
  case 2:
    FUN_0049de40(param_2);
  }
  return;
}


