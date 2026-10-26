// Function: FUN_0043ba20 @ 0043ba20
// Size (bytes): 211


void __thiscall FUN_0043ba20(int param_1,double param_2)

{
  double *pdVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  if (*(int *)(param_1 + 0x15c4) < 1) {
    return;
  }
  iVar3 = *(int *)(param_1 + 0x15c8);
  do {
    if ((*(int *)(iVar3 + 4) == *(int *)(param_1 + 0x15f0)) &&
       (*(int *)(iVar3 + 0xc) == *(int *)(param_1 + 0x141c))) {
      pdVar1 = *(double **)(iVar3 + 8);
      iVar2 = *(int *)(iVar3 + 0x10);
LAB_0043ba6d:
      if ((pdVar1 != (double *)0x0) && (iVar2 != 0)) {
        param_2 = param_2 + *(double *)(param_1 + 0x1420);
        pdVar1[1] = param_2;
        iVar4 = *(int *)(param_1 + 0x15f0);
        pdVar1[3] = *pdVar1 * *(double *)(iVar4 + 0x1c) +
                    *(double *)(iVar4 + 0x4c) * pdVar1[2] + param_2 * *(double *)(iVar4 + 0x34);
        pdVar1[4] = *(double *)(iVar4 + 0x54) * pdVar1[2] +
                    *(double *)(iVar4 + 0x24) * *pdVar1 + *(double *)(iVar4 + 0x3c) * pdVar1[1];
        pdVar1[5] = *(double *)(iVar4 + 0x5c) * pdVar1[2] +
                    *(double *)(iVar4 + 0x2c) * *pdVar1 + *(double *)(iVar4 + 0x44) * pdVar1[1];
        FUN_0056d1c0();
        FUN_0056d2d0();
        return;
      }
    }
    else if ((*(int *)(iVar3 + 0xc) == *(int *)(param_1 + 0x15f0)) &&
            (*(int *)(iVar3 + 4) == *(int *)(param_1 + 0x141c))) {
      pdVar1 = *(double **)(iVar3 + 0x10);
      iVar2 = *(int *)(iVar3 + 8);
      goto LAB_0043ba6d;
    }
    iVar4 = iVar4 + 1;
    iVar3 = iVar3 + 0x48;
    if (*(int *)(param_1 + 0x15c4) <= iVar4) {
      return;
    }
  } while( true );
}


