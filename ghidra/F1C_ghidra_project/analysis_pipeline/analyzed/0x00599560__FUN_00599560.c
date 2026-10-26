// Function: FUN_00599560 @ 00599560
// Size (bytes): 133


undefined4 __thiscall FUN_00599560(int param_1,uint param_2,char param_3)

{
  char cVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  
  if (0xfffffffd < param_2) {
    FUN_0059ad49();
  }
  puVar2 = *(undefined1 **)(param_1 + 4);
  if (((puVar2 == (undefined1 *)0x0) || (cVar1 = puVar2[-1], cVar1 == '\0')) || (cVar1 == -1)) {
    if (param_2 != 0) {
      if (param_3 == '\0') {
        if (param_2 <= *(uint *)(param_1 + 0xc)) {
          return 1;
        }
      }
      else {
        if ((*(uint *)(param_1 + 0xc) < 0x20) && (param_2 <= *(uint *)(param_1 + 0xc))) {
          return 1;
        }
        FUN_005993af(1);
      }
      goto LAB_005995d6;
    }
    if (param_3 == '\0') {
      if (puVar2 == (undefined1 *)0x0) {
        return 0;
      }
      *(undefined4 *)(param_1 + 8) = 0;
      *puVar2 = 0;
      return 0;
    }
    uVar3 = 1;
  }
  else {
    if (param_2 != 0) {
LAB_005995d6:
      FUN_0059964a(param_2);
      return 1;
    }
    uVar3 = 0;
    puVar2[-1] = cVar1 + -1;
  }
  FUN_005993af(uVar3);
  return 0;
}


