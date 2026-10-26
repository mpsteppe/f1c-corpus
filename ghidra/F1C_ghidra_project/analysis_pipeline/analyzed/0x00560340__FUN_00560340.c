// Function: FUN_00560340 @ 00560340
// Size (bytes): 208


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00560340(int *param_1)

{
  int iVar1;
  
  if (param_1[0x4f5] == 0) {
    _DAT_008cef7c = 0;
    _DAT_008cef74 = 0;
    DAT_008cef78 = 0x144;
    return 0;
  }
  iVar1 = (**(code **)(*(int *)param_1[0x440] + 300))
                    ((int *)param_1[0x440],&DAT_005dc7a4,&DAT_005dc7b8,&DAT_008cef7c,0x10);
  *param_1 = iVar1;
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  iVar1 = (**(code **)(*(int *)param_1[0x440] + 300))
                    ((int *)param_1[0x440],&DAT_005dd1e0,&DAT_005dd1f8,&DAT_008cef74,0x10);
  *param_1 = iVar1;
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  iVar1 = (**(code **)(*(int *)param_1[0x440] + 300))
                    ((int *)param_1[0x440],&DAT_005dc628,&DAT_005dc640,&DAT_008cef78,0x10);
  *param_1 = iVar1;
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  iVar1 = (**(code **)(*(int *)param_1[0x440] + 200))((int *)param_1[0x440],0x99,1);
  *param_1 = iVar1;
  return 0;
}


