// Function: FUN_00411840 @ 00411840
// Size (bytes): 355


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00411840(undefined4 *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar4 = 0;
  iVar1 = FUN_004119d0(*param_1);
  if (iVar1 != -1) {
    iVar2 = FUN_00411a00(*param_1,iVar1);
    iVar3 = FUN_00411a50(*param_1);
    if ((-1 < iVar2) && (-1 < iVar3)) {
      if ((DAT_005ea5e0 & 1) == 0) {
        DAT_005ea5e0 = DAT_005ea5e0 | 1;
        DAT_005ea5d0 = 0;
        _DAT_005ea5d4 = 0xffffffff;
        FUN_00566650(&DAT_005ea438);
        _DAT_005ea5d8 = 0xffffffff;
        _DAT_005ea5dc = 0xffffffff;
        FUN_00587b3e(&LAB_004119b0);
      }
      FUN_00566650(&DAT_005ea438);
      _DAT_005ea5d8 = 0xffffffff;
      _DAT_005ea5dc = 0xffffffff;
      iVar2 = FUN_00411b50(iVar3 + iVar2,iVar1,&DAT_005ea5d0,*param_1);
      if (iVar2 == 0) {
        iVar4 = FUN_00411bf0(iVar1,&DAT_005ea5d0,param_1,param_2);
        if (iVar4 == 1) {
          FUN_00414140(param_2);
        }
        uVar5 = (uint)(iVar4 == 1);
        iVar4 = FUN_00411db0(iVar1,&DAT_005ea5d0,param_1,param_2 + uVar5 * 0x14,*param_1);
        if (iVar4 != 1) {
          return 0;
        }
        iVar4 = uVar5 + 1;
        param_2 = param_2 + iVar4 * 0x14;
        iVar1 = FUN_00411e90(iVar1,&DAT_005ea5d0,param_1,param_2);
        if (iVar1 == 1) {
          FUN_00414140(param_2);
          iVar4 = uVar5 + 2;
        }
      }
    }
  }
  return iVar4;
}


