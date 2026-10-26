// Function: FUN_0056ecf0 @ 0056ecf0
// Size (bytes): 336


void __fastcall FUN_0056ecf0(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  if ((int *)param_1[0xc] == (int *)0x0) {
    iVar5 = param_1[8];
    iVar3 = 0;
    if (0 < iVar5) {
      do {
        iVar1 = *(int *)(param_1[10] + iVar3 * 4);
        iVar2 = 0;
        if (0 < iVar5) {
          do {
            *(undefined4 *)(iVar1 + iVar2 * 8) = 0;
            *(undefined4 *)(iVar1 + 4 + iVar2 * 8) = 0;
            iVar2 = iVar2 + 1;
          } while (iVar2 < param_1[8]);
        }
        iVar5 = param_1[0xb];
        *(undefined4 *)(iVar5 + iVar3 * 8) = 0;
        *(undefined4 *)(iVar5 + 4 + iVar3 * 8) = 0;
        iVar5 = param_1[8];
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar5);
    }
  }
  else {
    (**(code **)(*(int *)param_1[0xc] + 0x1c))();
  }
  FUN_0056ec00();
  iVar5 = 0;
  if (0 < *param_1) {
    do {
      FUN_0056a240();
      iVar5 = iVar5 + 1;
    } while (iVar5 < *param_1);
  }
  if (0 < param_1[2]) {
    iVar5 = 0;
    do {
      if ((*(byte *)(param_1[3] + 0x2c + iVar5) & 1) != 0) {
        iVar3 = *(int *)(*(int *)(param_1[3] + iVar5 + 8) + 0x30);
        FUN_0056ec70(iVar3);
        FUN_0056ec70(iVar3 + 1);
        FUN_0056ec70(iVar3 + 2);
      }
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x30;
    } while (iVar4 < param_1[2]);
  }
  iVar4 = 0;
  if (0 < param_1[4]) {
    iVar5 = 0;
    do {
      if ((*(byte *)(iVar5 + 0x2c + param_1[5]) & 1) != 0) {
        iVar3 = *(int *)(*(int *)(iVar5 + param_1[5] + 8) + 0x7c);
        FUN_0056ec70(iVar3);
        FUN_0056ec70(iVar3 + 1);
      }
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x30;
    } while (iVar4 < param_1[4]);
  }
  iVar4 = 0;
  if (0 < param_1[6]) {
    iVar5 = 0;
    do {
      if ((*(byte *)(param_1[7] + iVar5 + 0x44) & 1) != 0) {
        FUN_0056ec70(*(undefined4 *)(*(int *)(param_1[7] + iVar5 + 8) + 0x30));
      }
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x48;
    } while (iVar4 < param_1[6]);
  }
  if ((int *)param_1[0xc] != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0056ee3d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)param_1[0xc] + 0x14))();
    return;
  }
  FUN_0056cd70(param_1[10],param_1[0xb],param_1[8]);
  return;
}


