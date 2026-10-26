// Function: FUN_0046ee60 @ 0046ee60
// Size (bytes): 84


void FUN_0046ee60(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  FUN_00489cb0();
  FUN_00489600(&DAT_005beb48,0,0,0,0);
  iVar1 = FUN_00432810();
  iVar3 = 0;
  if (0 < iVar1) {
    do {
      uVar2 = FUN_00432820(iVar3);
      FUN_00489600(uVar2,0,0,0,0);
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  return;
}


