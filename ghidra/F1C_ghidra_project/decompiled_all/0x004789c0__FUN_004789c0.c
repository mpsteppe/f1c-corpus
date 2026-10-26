// Function: FUN_004789c0 @ 004789c0
// Strings:  [DFCarIcon.bmp]


int __fastcall FUN_004789c0(int param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = *(undefined1 **)(param_1 + 0x154);
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = &DAT_005ea438;
  }
  iVar2 = FUN_00497ad0(puVar1,0);
  if (iVar2 == 0) {
    iVar2 = FUN_00497ad0(s_DFCarIcon_bmp_005c6a04,0);
    if (iVar2 == 0) goto LAB_004789ff;
  }
  FUN_00499b80(iVar2);
LAB_004789ff:
  return param_1 + 0x120;
}


