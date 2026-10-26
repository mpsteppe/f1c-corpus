// Function: FUN_004f81d0 @ 004f81d0
// Size (bytes): 115


undefined4
FUN_004f81d0(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  char *pcVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  
  uVar5 = 1;
  if ((param_1 != (undefined4 *)0x0) && (param_2 != (undefined4 *)0x0)) {
    pcVar2 = (char *)*param_2;
    if (pcVar2 == (char *)0x0) {
      pcVar2 = &DAT_005ea438;
    }
    iVar4 = -1;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    if (iVar4 == -2) {
      *param_1 = 0;
      return 1;
    }
    if (DAT_008ac4c4 != (int *)0x0) {
      piVar3 = (int *)(**(code **)(*DAT_008ac4c4 + 0x5c))(param_2,param_3,param_4);
      *param_1 = piVar3;
      if (piVar3 != (int *)0x0) {
        iVar4 = (**(code **)(*piVar3 + 0x14))();
        if (iVar4 == 0) {
          uVar5 = 0;
        }
      }
    }
  }
  return uVar5;
}


