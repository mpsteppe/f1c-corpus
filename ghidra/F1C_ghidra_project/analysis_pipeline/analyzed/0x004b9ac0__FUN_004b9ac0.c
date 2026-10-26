// Function: FUN_004b9ac0 @ 004b9ac0
// Size (bytes): 192


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004b9ac0(undefined4 param_1,undefined4 param_2,float param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  float10 fVar4;
  
  if (param_3 == _DAT_005acd04) {
    fVar4 = (float10)FUN_004b8790();
    param_3 = (float)fVar4;
  }
  iVar2 = FUN_004b72a0(param_1,param_3);
  if (iVar2 != 0) {
    cVar1 = FUN_005001d0();
    if (cVar1 != '\0') {
      cVar1 = FUN_005001f0();
      if (cVar1 == '\0') {
        uVar3 = FUN_005000c0(param_3,iVar2 + 0x248,param_2);
        return uVar3;
      }
    }
    cVar1 = FUN_005001d0();
    if (cVar1 == '\0') {
      cVar1 = FUN_005001f0();
      if (cVar1 != '\0') {
        uVar3 = FUN_005000c0(param_3,iVar2 + 0x98,param_2);
        return uVar3;
      }
    }
    uVar3 = FUN_00500210(param_3,param_2);
    return uVar3;
  }
  return 0;
}


