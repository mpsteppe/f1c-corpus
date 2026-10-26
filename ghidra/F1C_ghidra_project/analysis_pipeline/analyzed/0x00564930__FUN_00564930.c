// Function: FUN_00564930 @ 00564930
// Size (bytes): 40


void __fastcall FUN_00564930(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 4) + *(int *)(param_1 + 0xc);
  *(int *)(param_1 + 4) = iVar2;
  uVar1 = FUN_0058b5d4(*(undefined4 *)(param_1 + 0x14),*(int *)(param_1 + 8) * iVar2);
  *(undefined4 *)(param_1 + 0x14) = uVar1;
  return;
}


