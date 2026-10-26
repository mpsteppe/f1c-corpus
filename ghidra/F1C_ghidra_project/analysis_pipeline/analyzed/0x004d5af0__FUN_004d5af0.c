// Function: FUN_004d5af0 @ 004d5af0
// Size (bytes): 235


void FUN_004d5af0(uint param_1)

{
  int iVar1;
  int iVar2;
  int local_4;
  
  iVar1 = FUN_00587db0(param_1,&DAT_005be828);
  local_4 = 0;
  if (iVar1 == 0) {
    FUN_004d5be0(&local_4,4);
    return;
  }
  while (iVar2 = FUN_00589fcc(iVar1), iVar2 != -1) {
    local_4 = local_4 + 1;
  }
  FUN_004d5be0(&local_4,4);
  FUN_00587f64(iVar1,0,0);
  while (iVar2 = FUN_00589fcc(iVar1), iVar2 != -1) {
    param_1 = CONCAT31(param_1._1_3_,(char)iVar2) ^ 0x5c;
    FUN_004d5be0(&param_1,1);
    iVar2 = FUN_00589fcc(iVar1);
    if (iVar2 == -1) break;
    param_1 = CONCAT31(param_1._1_3_,(char)iVar2) ^ 0xb4;
    FUN_004d5be0(&param_1,1);
    iVar2 = FUN_00589fcc(iVar1);
    if (iVar2 == -1) break;
    param_1 = CONCAT31(param_1._1_3_,(char)iVar2) ^ 0x12;
    FUN_004d5be0(&param_1,1);
  }
  FUN_00587d02(iVar1);
  return;
}


