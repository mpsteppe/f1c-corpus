// Function: FUN_00457f90 @ 00457f90
// Size (bytes): 133


undefined4 __thiscall FUN_00457f90(int *param_1,undefined4 *param_2,int param_3)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  
  uVar1 = 1;
  if ((param_2 != (undefined4 *)0x0) && (3 < param_3)) {
    FUN_00458020();
    param_1[1] = param_3;
    piVar2 = operator_new(param_3 * 0x1c + 4);
    if (piVar2 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      *piVar2 = param_3;
      piVar2 = piVar2 + 1;
    }
    *param_1 = (int)piVar2;
    iVar4 = 0;
    if (0 < param_1[1]) {
      iVar3 = 0;
      do {
        puVar5 = (undefined4 *)(*param_1 + iVar3);
        *puVar5 = *param_2;
        puVar5[1] = param_2[1];
        puVar5[2] = param_2[2];
        iVar4 = iVar4 + 1;
        param_2 = param_2 + 3;
        iVar3 = iVar3 + 0x1c;
      } while (iVar4 < param_1[1]);
    }
    FUN_00457ee0();
    uVar1 = 0;
  }
  return uVar1;
}


