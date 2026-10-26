// Function: FUN_00495980 @ 00495980
// Size (bytes): 160


int * __fastcall FUN_00495980(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  undefined8 uVar6;
  
  uVar1 = *(undefined4 *)(param_1 + 0x60);
  uVar2 = *(undefined4 *)(param_1 + 0x5c);
  uVar6 = FUN_00495970();
  if ((int)uVar6 != 0) {
    piVar5 = (int *)0x0;
    piVar3 = (int *)FUN_00498f60();
    while (piVar3 != (int *)0x0) {
      iVar4 = (**(code **)(*piVar3 + 0x30))(uVar2,uVar1);
      if (iVar4 != 0) {
        piVar5 = piVar3;
      }
      piVar3 = (int *)FUN_00486320();
    }
    iVar4 = FUN_00498e40();
    if ((iVar4 != 0) && (piVar5 == (int *)0x0)) {
      iVar4 = FUN_00498e40();
      piVar3 = *(int **)(iVar4 + 0x44);
      while (piVar3 != (int *)0x0) {
        iVar4 = (**(code **)(*piVar3 + 0x30))(uVar2,uVar1);
        if (iVar4 != 0) {
          piVar5 = piVar3;
        }
        piVar3 = (int *)FUN_00486320();
      }
    }
    return piVar5;
  }
  return (int *)((ulonglong)uVar6 >> 0x20);
}


