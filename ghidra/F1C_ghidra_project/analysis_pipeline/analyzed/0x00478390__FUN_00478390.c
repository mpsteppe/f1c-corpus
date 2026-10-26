// Function: FUN_00478390 @ 00478390
// Size (bytes): 37


void __fastcall FUN_00478390(int param_1)

{
  int iVar1;
  
  if (((*(int *)(param_1 + 0xe0) != 0) && (iVar1 = FUN_0048f590(), iVar1 != 0)) &&
     (PTR_s_ProfileIcon_DFT_bmp_005c6658 = *(undefined **)(iVar1 + 0x30),
     PTR_s_ProfileIcon_DFT_bmp_005c6658 == (undefined *)0x0)) {
    PTR_s_ProfileIcon_DFT_bmp_005c6658 = &DAT_005ea438;
  }
  return;
}


