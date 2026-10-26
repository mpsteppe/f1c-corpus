// Function: FUN_004af220 @ 004af220
// Size (bytes): 354


void __fastcall FUN_004af220(int param_1)

{
  switch(*(undefined4 *)(param_1 + 0x1b34)) {
  case 1:
    *(undefined4 *)(param_1 + 0xd98) = 0xc;
    if (*(int *)(param_1 + 0xd98) < *(int *)(param_1 + 0xda0)) {
      *(int *)(param_1 + 0xd98) = *(int *)(param_1 + 0xda0);
      *(undefined4 *)(param_1 + 0x1170) = 0;
    }
    else {
      if (*(int *)(param_1 + 0xda4) < *(int *)(param_1 + 0xd98)) {
        *(int *)(param_1 + 0xd98) = *(int *)(param_1 + 0xda4);
      }
      *(undefined4 *)(param_1 + 0x1170) = 0;
    }
    break;
  case 2:
    *(undefined4 *)(param_1 + 0xd98) = 0xe;
    if (*(int *)(param_1 + 0xd98) < *(int *)(param_1 + 0xda0)) {
      *(int *)(param_1 + 0xd98) = *(int *)(param_1 + 0xda0);
      *(undefined4 *)(param_1 + 0x1170) = 1;
    }
    else {
      if (*(int *)(param_1 + 0xda4) < *(int *)(param_1 + 0xd98)) {
        *(int *)(param_1 + 0xd98) = *(int *)(param_1 + 0xda4);
      }
      *(undefined4 *)(param_1 + 0x1170) = 1;
    }
    break;
  case 3:
    *(undefined4 *)(param_1 + 0xd98) = 0x10;
    if (*(int *)(param_1 + 0xd98) < *(int *)(param_1 + 0xda0)) {
      *(int *)(param_1 + 0xd98) = *(int *)(param_1 + 0xda0);
      *(undefined4 *)(param_1 + 0x1170) = 2;
    }
    else {
      if (*(int *)(param_1 + 0xda4) < *(int *)(param_1 + 0xd98)) {
        *(int *)(param_1 + 0xd98) = *(int *)(param_1 + 0xda4);
      }
      *(undefined4 *)(param_1 + 0x1170) = 2;
    }
    break;
  case 4:
    *(undefined4 *)(param_1 + 0xd98) = 0x10;
    if (*(int *)(param_1 + 0xd98) < *(int *)(param_1 + 0xda0)) {
      *(int *)(param_1 + 0xd98) = *(int *)(param_1 + 0xda0);
    }
    else if (*(int *)(param_1 + 0xda4) < *(int *)(param_1 + 0xd98)) {
      *(int *)(param_1 + 0xd98) = *(int *)(param_1 + 0xda4);
    }
    *(undefined4 *)(param_1 + 0x1170) = 3;
    break;
  default:
    goto switchD_004af231_default;
  }
  if (*(int *)(param_1 + 0x1170) < *(int *)(param_1 + 0x1178)) {
    *(int *)(param_1 + 0x1170) = *(int *)(param_1 + 0x1178);
    return;
  }
  if (*(int *)(param_1 + 0x117c) < *(int *)(param_1 + 0x1170)) {
    *(int *)(param_1 + 0x1170) = *(int *)(param_1 + 0x117c);
  }
switchD_004af231_default:
  return;
}


