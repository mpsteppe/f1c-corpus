
/* WARNING: Removing unreachable block (ram,0x004076be) */

uint __thiscall FUN_00407520(int param_1,int *param_2,int param_3)

{
  bool bVar1;
  uint in_EAX;
  int iVar2;
  void *pvVar3;
  int *piVar4;
  int *piVar5;
  byte bStack_9;
  
  bStack_9 = 0;
  if (param_2 == (int *)0x0) {
    return in_EAX & 0xffffff00;
  }
  bVar1 = false;
  if (*param_2 != 0) {
    FUN_00566650(*param_2);
  }
  if (param_2[1] != 0) {
    FUN_005665b0(param_2[1]);
  }
  piVar4 = *(int **)(param_1 + 0x38);
  *(int **)(param_1 + 0x40) = piVar4;
  if ((piVar4 != (int *)0x0) && (piVar4 = (int *)*piVar4, piVar4 != (int *)0x0)) {
    while (*piVar4 != param_3) {
      if (*(int *)(param_1 + 0x40) != 0) {
        *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(*(int *)(param_1 + 0x40) + 4);
      }
      if ((*(undefined4 **)(param_1 + 0x40) == (undefined4 *)0x0) ||
         (piVar4 = (int *)**(undefined4 **)(param_1 + 0x40), piVar4 == (int *)0x0))
      goto LAB_004075a7;
    }
    bVar1 = true;
  }
LAB_004075a7:
  iVar2 = FUN_00588410(&DAT_005ea438,&DAT_005ea438);
  if ((((iVar2 != 0) && (!bVar1)) && (pvVar3 = operator_new(0x74), pvVar3 != (void *)0x0)) &&
     (piVar4 = (int *)FUN_004053e0(), piVar4 != (int *)0x0)) {
    iVar2 = FUN_00587db0(&DAT_005ea438,&DAT_005be828);
    piVar4[3] = iVar2;
    if (iVar2 != 0) {
      iVar2 = FUN_004080f0(piVar4);
      if (iVar2 == 0) {
        iVar2 = FUN_0059b758(piVar4[3]);
        piVar4[4] = iVar2;
        *piVar4 = param_3;
        FUN_00566650(&DAT_005ea438);
        piVar5 = operator_new(0xc);
        if (piVar5 == (int *)0x0) {
          piVar5 = (int *)0x0;
        }
        else {
          *piVar5 = (int)piVar4;
          piVar5[1] = 0;
          *(undefined1 *)(piVar5 + 2) = 1;
        }
        if (*(int *)(param_1 + 0x38) == 0) {
          *(int **)(param_1 + 0x38) = piVar5;
          *(int **)(param_1 + 0x40) = piVar5;
          *(int **)(param_1 + 0x3c) = piVar5;
          *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + 1;
          bStack_9 = 1;
        }
        else {
          *(int **)(*(int *)(param_1 + 0x3c) + 4) = piVar5;
          *(int **)(param_1 + 0x3c) = piVar5;
          *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + 1;
          bStack_9 = 1;
        }
        goto LAB_004076b5;
      }
      FUN_00587d02(piVar4[3]);
      piVar4[3] = 0;
    }
    FUN_00405410();
    FUN_00587bcf(piVar4);
  }
LAB_004076b5:
  return (uint)bStack_9;
}

