// Function: FUN_00568a60 @ 00568a60
// Size (bytes): 160


undefined4 __fastcall FUN_00568a60(undefined4 param_1,byte param_2,uint param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  
  *param_4 = 0;
  iVar1 = FUN_00587db0(param_1,&DAT_005be828);
  if (iVar1 != 0) {
    if (param_2 == 0) {
      param_2 = 1;
    }
    *param_4 = 0;
    FUN_00587f64(iVar1,0,0);
    param_3 = param_3 & 0xff;
    iVar2 = FUN_00589fcc(iVar1);
    if (iVar2 != -1) {
      do {
        iVar2 = iVar2 * param_3;
        param_3 = (int)(param_3 + 1) % (int)(uint)param_2;
        *param_4 = *param_4 + iVar2;
        iVar2 = FUN_00589fcc(iVar1);
      } while (iVar2 != -1);
    }
    FUN_00587d02(iVar1);
    return 1;
  }
  return 0;
}


