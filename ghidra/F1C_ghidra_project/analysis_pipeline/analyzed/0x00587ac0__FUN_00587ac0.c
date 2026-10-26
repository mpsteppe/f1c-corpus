// Function: FUN_00587ac0 @ 00587ac0
// Size (bytes): 126


undefined4 FUN_00587ac0(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  
  FUN_00589d6b();
  uVar1 = FUN_0058bb68(DAT_008d5a54);
  if (uVar1 < (uint)((int)DAT_008d5a50 + (4 - DAT_008d5a54))) {
    iVar2 = FUN_0058bb68(DAT_008d5a54);
    iVar2 = FUN_0058b5d4(DAT_008d5a54,iVar2 + 0x10);
    if (iVar2 == 0) {
      param_1 = 0;
      goto LAB_00587b35;
    }
    DAT_008d5a50 = (undefined4 *)(iVar2 + ((int)DAT_008d5a50 - DAT_008d5a54 >> 2) * 4);
    DAT_008d5a54 = iVar2;
  }
  *DAT_008d5a50 = param_1;
  DAT_008d5a50 = DAT_008d5a50 + 1;
LAB_00587b35:
  FUN_00589d74();
  return param_1;
}


