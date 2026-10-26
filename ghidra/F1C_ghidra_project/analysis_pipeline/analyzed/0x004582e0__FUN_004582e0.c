// Function: FUN_004582e0 @ 004582e0
// Size (bytes): 197


int * __thiscall FUN_004582e0(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int local_8;
  
  iVar5 = 0;
  if ((*param_2 != 0) && (iVar1 = param_2[1], 3 < iVar1)) {
    FUN_00458020();
    param_1[1] = iVar1;
    piVar2 = operator_new(iVar1 * 0x1c + 4);
    if (piVar2 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      *piVar2 = iVar1;
      piVar2 = piVar2 + 1;
    }
    *param_1 = (int)piVar2;
    if (0 < iVar1) {
      local_8 = 0;
      do {
        puVar3 = (undefined4 *)FUN_004582a0(iVar5);
        puVar4 = (undefined4 *)(*param_1 + local_8);
        *puVar4 = *puVar3;
        puVar4[1] = puVar3[1];
        puVar4[2] = puVar3[2];
        puVar4[3] = puVar3[3];
        puVar4[4] = puVar3[4];
        puVar4[5] = puVar3[5];
        puVar4[6] = puVar3[6];
        iVar5 = iVar5 + 1;
        local_8 = local_8 + 0x1c;
      } while (iVar5 < iVar1);
    }
    FUN_00457ee0();
  }
  return param_1;
}


