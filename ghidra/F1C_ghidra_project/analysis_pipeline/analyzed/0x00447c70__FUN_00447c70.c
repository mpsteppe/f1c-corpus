// Function: FUN_00447c70 @ 00447c70
// Size (bytes): 134


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00447c70(int param_1,char param_2,char param_3)

{
  uint uVar1;
  uint uVar2;
  
  if (((*(char *)(param_1 + 0x1c58) != param_2) &&
      (*(char *)(param_1 + 0x1c58) = param_2, *(int *)(param_1 + 0x1f00) != 0)) && (param_3 == '\0')
     ) {
    uVar2 = DAT_008aae70 & 0xff;
    uVar1 = DAT_008aae70 + 1;
    DAT_008aae70 = DAT_008aae70 + 2;
    FUN_004f87c0(0x28,2,_DAT_0059e43c -
                        *(float *)(&DAT_008aae74 + (uVar1 & 0xff) * 4) * _DAT_0059e868,
                 *(float *)(&DAT_008ab274 + uVar2 * 4) * _DAT_0059e84c + _DAT_0059e43c);
  }
  return;
}


