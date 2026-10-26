// Function: FUN_0046ae60 @ 0046ae60
// Size (bytes): 153


void __fastcall FUN_0046ae60(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined1 local_50 [80];
  
  FUN_00489cb0();
  piVar3 = *(int **)(param_1 + 0x44);
  while (piVar3 != (int *)0x0) {
    piVar1 = (int *)piVar3[1];
    if (((char)piVar3[2] != '\0') && (piVar2 = (int *)*piVar3, piVar2 != (int *)0x0)) {
      if (*piVar2 != 0) {
        FUN_00587bcf(*piVar2);
      }
      FUN_00587bcf(piVar2);
    }
    FUN_00587bcf(piVar3);
    piVar3 = piVar1;
  }
  iVar5 = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
  if (0 < DAT_007d1424) {
    do {
      uVar6 = 0xffffffff;
      uVar4 = FUN_00455560(iVar5);
      FUN_00486f30(uVar4,uVar6);
      FUN_0046ad50(iVar5,local_50,1);
      iVar5 = iVar5 + 1;
    } while (iVar5 < DAT_007d1424);
  }
  return;
}


