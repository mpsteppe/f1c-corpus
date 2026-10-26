// Function: FUN_00478020 @ 00478020
// Strings:  [ProfileIcon_DFT.bmp]


int * __fastcall FUN_00478020(int *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = (undefined1 *)param_1[0x56];
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = &DAT_005ea438;
  }
  iVar2 = FUN_00497ad0(puVar1,0);
  if (iVar2 == 0) {
    iVar2 = FUN_00497ad0(s_ProfileIcon_DFT_bmp_005c66f8,0);
  }
  FUN_00499b80(iVar2);
  if (param_1[0x51] != 0) {
    (**(code **)(*param_1 + 0x3c))(1);
    return param_1 + 0x49;
  }
  (**(code **)(*param_1 + 0x3c))(0);
  return (int *)0x0;
}


