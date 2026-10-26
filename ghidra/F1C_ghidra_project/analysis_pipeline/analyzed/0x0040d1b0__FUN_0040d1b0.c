// Function: FUN_0040d1b0 @ 0040d1b0
// Size (bytes): 141


uint __thiscall FUN_0040d1b0(int param_1,int param_2,undefined4 param_3)

{
  char cVar1;
  uint in_EAX;
  undefined4 uVar2;
  undefined3 uVar3;
  undefined3 extraout_var;
  undefined4 uVar4;
  
  if (param_2 != 0) {
    cVar1 = FUN_0040a910(param_2,param_3);
    if (cVar1 == '\0') {
      cVar1 = FUN_0040b450(param_2,param_3);
      if (cVar1 == '\0') {
        in_EAX = FUN_0040bcd0(param_2,param_3);
        if ((char)in_EAX == '\0') goto LAB_0040d236;
        uVar2 = *(undefined4 *)(param_1 + 0x20);
      }
      else {
        uVar2 = *(undefined4 *)(param_1 + 0x1c);
      }
    }
    else {
      uVar2 = *(undefined4 *)(param_1 + 0x18);
    }
    FUN_0040cdd0(uVar2);
    uVar4 = 0;
    *(undefined1 *)(param_1 + 0x2c) = 1;
    uVar2 = FUN_0040cd60(0);
    uVar2 = FUN_0040cde0(uVar2,uVar4);
    uVar3 = (undefined3)((uint)uVar2 >> 8);
    if (((char)param_3 != '\0') && (*(int **)(param_1 + 8) != (int *)0x0)) {
      (**(code **)(**(int **)(param_1 + 8) + 0x10))();
      uVar3 = extraout_var;
    }
    return CONCAT31(uVar3,1);
  }
LAB_0040d236:
  return in_EAX & 0xffffff00;
}


