// Function: FUN_00460e90 @ 00460e90
// Strings:  [D:\dev\F1_1999_2002\Source\NetComm.cpp, *** Opening ]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00460e90(int param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  uint local_1b0 [108];
  
  FUN_004b33b0(4,0x26,0,0xff,(float)_DAT_008afea0,1);
  iVar2 = FUN_0057a680();
  *(undefined1 *)(iVar2 + 4) = 1;
  FUN_0057a6a0(local_1b0,(local_1b0[0] >> 8 & 0x3ff) + 8,iVar2,1,1,0xffffffff,0);
  FUN_0057a690(iVar2);
  *(undefined1 *)(param_1 + 0x29) = 1;
  piVar3 = operator_new(8);
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    *piVar3 = 0;
    piVar3[1] = -1;
  }
  FUN_00566650(s_____Opening_005c60e8);
  FUN_004c5920(&stack0xfffffe0c,0x3f);
  FUN_005665b0(&stack0xfffffe0c);
  if (DAT_007c569c != 5) {
    cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_NetCo_005c5ce4,0x12e1);
    if (cVar1 != '\0') {
      puVar4 = (undefined1 *)*piVar3;
      if (puVar4 == (undefined1 *)0x0) {
        puVar4 = &DAT_005ea438;
      }
      FUN_004d7aa0(&DAT_008ad25c,puVar4);
    }
  }
  if (DAT_007d0398 == 0) {
    if (piVar3 != (int *)0x0) {
      if (*piVar3 != 0) {
        FUN_00587bcf(*piVar3);
      }
      FUN_00587bcf(piVar3);
    }
  }
  else if (piVar3 != (int *)0x0) {
    puVar5 = operator_new(0xc);
    if (puVar5 == (undefined4 *)0x0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      *puVar5 = piVar3;
      puVar5[1] = 0;
      *(undefined1 *)(puVar5 + 2) = 0;
    }
    if (*(int *)(param_1 + 0x1b770) == 0) {
      *(undefined4 **)(param_1 + 0x1b770) = puVar5;
      *(undefined4 **)(param_1 + 0x1b778) = puVar5;
    }
    else {
      *(undefined4 **)(*(int *)(param_1 + 0x1b774) + 4) = puVar5;
    }
    *(undefined4 **)(param_1 + 0x1b774) = puVar5;
    *(int *)(param_1 + 0x1b77c) = *(int *)(param_1 + 0x1b77c) + 1;
    return;
  }
  return;
}


