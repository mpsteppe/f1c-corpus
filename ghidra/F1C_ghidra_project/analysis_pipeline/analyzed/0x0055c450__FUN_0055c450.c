// Function: FUN_0055c450 @ 0055c450
// Size (bytes): 477


void FUN_0055c450(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (0x28 < param_1) {
    if (param_1 < 0x33545845) {
      if (param_1 == 0x33545844) {
        if (param_2 != (undefined4 *)0x0) {
          *param_2 = 1;
        }
        if (param_3 == (undefined4 *)0x0) {
          return;
        }
        *param_3 = 0xb;
        return;
      }
      if (param_1 == 0x29) goto LAB_0055c580;
      if (param_1 == 0x31545844) {
        if (param_2 != (undefined4 *)0x0) {
          *param_2 = 1;
        }
        if (param_3 == (undefined4 *)0x0) {
          return;
        }
        *param_3 = 9;
        return;
      }
      if (param_1 == 0x32545844) {
        if (param_2 != (undefined4 *)0x0) {
          *param_2 = 1;
        }
        if (param_3 == (undefined4 *)0x0) {
          return;
        }
        *param_3 = 10;
        return;
      }
    }
    else {
      if (param_1 == 0x34545844) {
        if (param_2 != (undefined4 *)0x0) {
          *param_2 = 1;
        }
        if (param_3 == (undefined4 *)0x0) {
          return;
        }
        *param_3 = 0xc;
        return;
      }
      if (param_1 == 0x35545844) {
        if (param_2 != (undefined4 *)0x0) {
          *param_2 = 1;
        }
        if (param_3 == (undefined4 *)0x0) {
          return;
        }
        *param_3 = 0xd;
        return;
      }
    }
switchD_0055c46f_default:
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = 0;
    }
    if (param_3 == (undefined4 *)0x0) {
      return;
    }
    *param_3 = 0;
    return;
  }
  if (param_1 == 0x28) {
LAB_0055c580:
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = 8;
    }
    if (param_3 == (undefined4 *)0x0) {
      return;
    }
    *param_3 = 4;
    return;
  }
  switch(param_1) {
  case 0x14:
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = 0x18;
    }
    goto LAB_0055c4b7;
  case 0x15:
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = 0x20;
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = 8;
      return;
    }
    break;
  case 0x16:
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = 0x20;
    }
LAB_0055c4b7:
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = 7;
      return;
    }
    break;
  case 0x17:
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = 0x10;
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = 6;
      return;
    }
    break;
  case 0x18:
  case 0x19:
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = 0x10;
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = 5;
      return;
    }
    break;
  default:
    goto switchD_0055c46f_default;
  }
  return;
}


