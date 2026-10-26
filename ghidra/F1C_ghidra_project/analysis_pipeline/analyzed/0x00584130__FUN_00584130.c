// Function: FUN_00584130 @ 00584130
// Size (bytes): 254


undefined4 __thiscall FUN_00584130(int param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  uVar3 = 0;
  if (param_3 != -1) {
    piVar1 = *(int **)(param_1 + 0x11c);
    *(int **)(param_1 + 0x124) = piVar1;
    if ((piVar1 != (int *)0x0) && (iVar5 = *piVar1, iVar5 != 0)) {
      while ((iVar4 = FUN_00587720(), iVar4 != param_3 && (iVar4 != -1))) {
        if (*(int *)(param_1 + 0x124) != 0) {
          *(undefined4 *)(param_1 + 0x124) = *(undefined4 *)(*(int *)(param_1 + 0x124) + 4);
        }
        if ((*(int **)(param_1 + 0x124) == (int *)0x0) ||
           (iVar5 = **(int **)(param_1 + 0x124), iVar5 == 0)) goto LAB_00584197;
      }
      if (iVar5 != 0) goto LAB_0058420c;
    }
LAB_00584197:
    iVar5 = 0;
    piVar1 = *(int **)(param_1 + 0x10c);
    *(int **)(param_1 + 0x114) = piVar1;
    if (piVar1 != (int *)0x0) {
      iVar5 = *piVar1;
      *(undefined1 *)(piVar1 + 2) = 0;
      cVar2 = FUN_00586670(iVar5,1);
      if (cVar2 == '\0') {
        iVar5 = 0;
      }
    }
    if (iVar5 == 0) {
      FUN_00586320();
      piVar1 = *(int **)(param_1 + 0x10c);
      *(int **)(param_1 + 0x114) = piVar1;
      if (piVar1 != (int *)0x0) {
        iVar5 = *piVar1;
        *(undefined1 *)(piVar1 + 2) = 0;
        cVar2 = FUN_00586670(iVar5,1);
        if (cVar2 == '\0') {
          iVar5 = 0;
        }
      }
    }
    *(int *)(iVar5 + 0x414) = param_1;
    FUN_00586000(iVar5,0);
LAB_0058420c:
    FUN_00587710(param_3);
    FUN_00587730(param_2);
    uVar3 = 1;
  }
  return uVar3;
}


