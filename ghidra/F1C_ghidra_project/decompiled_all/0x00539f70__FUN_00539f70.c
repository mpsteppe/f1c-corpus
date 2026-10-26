// Function: FUN_00539f70 @ 00539f70
// Strings:  [incomplete dynamic bit lengths tree, oversubscribed dynamic bit lengths tree]


int __fastcall
FUN_00539f70(undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  undefined4 unaff_retaddr;
  
  iVar1 = (**(code **)(param_5 + 0x20))(4);
  if (iVar1 == 0) {
    return -4;
  }
  iVar1 = FUN_0053a020(0x13,0,0,unaff_retaddr,param_2,param_3,&stack0xfffffff8,iVar1);
  if (iVar1 == -3) {
    *(char **)(param_5 + 0x18) = s_oversubscribed_dynamic_bit_lengt_005dbac4;
    (**(code **)(param_5 + 0x24))();
    return -3;
  }
  if ((iVar1 == -5) || (*param_2 == 0)) {
    *(char **)(param_5 + 0x18) = s_incomplete_dynamic_bit_lengths_t_005dbaa0;
    iVar1 = -3;
  }
  (**(code **)(param_5 + 0x24))();
  return iVar1;
}


