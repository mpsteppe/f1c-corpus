// Function: FUN_005972bd @ 005972bd
// Size (bytes): 70


undefined4 FUN_005972bd(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = (int *)*param_1;
  if (((*piVar1 == -0x1f928c9d) && (piVar1[4] == 3)) && (piVar1[5] == 0x19930520)) {
    uVar2 = FUN_00593c9c();
    return uVar2;
  }
  if ((DAT_008d41e4 != (code *)0x0) && (iVar3 = FUN_00597359(DAT_008d41e4), iVar3 != 0)) {
    uVar2 = (*DAT_008d41e4)(param_1);
    return uVar2;
  }
  return 0;
}


