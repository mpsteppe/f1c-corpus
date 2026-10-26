// Function: FUN_004b4760 @ 004b4760
// Size (bytes): 59


undefined4 FUN_004b4760(int param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  
  if (((param_1 == 0) && ((*param_2 & 0xfc0000) == 0)) && (uVar1 = *param_2 & 0xff, uVar1 < 0x68)) {
    iVar2 = FUN_004b4840(0,uVar1,&param_1);
    if (iVar2 != 0) {
      return 1;
    }
  }
  return 0;
}


