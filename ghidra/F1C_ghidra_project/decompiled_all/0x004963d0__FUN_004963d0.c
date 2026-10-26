// Function: FUN_004963d0 @ 004963d0
// Strings:  [SUVWj]


/* WARNING: Removing unreachable block (ram,0x0049645c) */
/* WARNING: Removing unreachable block (ram,0x00496468) */
/* WARNING: Removing unreachable block (ram,0x00496478) */

undefined4 __fastcall FUN_004963d0(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  FUN_004b0170();
  piVar5 = *(int **)(param_1 + 4);
  while (piVar5 != (int *)0x0) {
    piVar1 = (int *)piVar5[1];
    if (((char)piVar5[3] != '\0') && ((undefined4 *)*piVar5 != (undefined4 *)0x0)) {
      (*(code *)**(undefined4 **)*piVar5)(1);
    }
    FUN_00587bcf(piVar5);
    piVar5 = piVar1;
  }
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  puVar2 = *(undefined4 **)(param_1 + 0x1c);
  while (puVar2 != (undefined4 *)0x0) {
    puVar3 = (undefined4 *)*puVar2;
    puVar2 = (undefined4 *)puVar2[0x23];
    (*(code *)*puVar3)(1);
  }
  *(undefined4 *)(param_1 + 0x1c) = 0;
  iVar6 = *(int *)(param_1 + 0x104);
  while (iVar6 != 0) {
    iVar4 = *(int *)(iVar6 + 0x10);
    FUN_00494fd0(*(undefined4 *)(iVar6 + 0xc));
    *(undefined4 *)(iVar6 + 0xc) = 0;
    FUN_00414370();
    FUN_00587bcf(iVar6);
    iVar6 = iVar4;
  }
  iVar6 = *(int *)(param_1 + 0x10c);
  while (iVar6 != 0) {
    iVar4 = *(int *)(iVar6 + 0x54);
    FUN_00499af0();
    FUN_00587bcf(iVar6);
    iVar6 = iVar4;
  }
  FUN_00494e60();
  if (*(int *)(param_1 + 0xac) != 0) {
    FUN_00494fd0(*(int *)(param_1 + 0xac));
    *(undefined4 *)(param_1 + 0xac) = 0;
  }
  if (*(int *)(param_1 + 0xb0) != 0) {
    FUN_00494fd0(*(int *)(param_1 + 0xb0));
    *(undefined4 *)(param_1 + 0xb0) = 0;
  }
  FUN_0044f5f0();
  piVar5 = *(int **)(param_1 + 0xf0);
  *(int **)(param_1 + 0xf8) = piVar5;
  if ((piVar5 != (int *)0x0) && (iVar6 = *piVar5, iVar6 != 0)) {
    while( true ) {
      FUN_00495010(*(undefined4 *)(iVar6 + 8));
      *(undefined4 *)(iVar6 + 8) = 0;
      if (*(int *)(param_1 + 0xf8) == 0) break;
      piVar5 = *(int **)(*(int *)(param_1 + 0xf8) + 4);
      *(int **)(param_1 + 0xf8) = piVar5;
      if (piVar5 == (int *)0x0) {
        return 0;
      }
      iVar6 = *piVar5;
      if (iVar6 == 0) {
        return 0;
      }
    }
  }
  return 0;
}


