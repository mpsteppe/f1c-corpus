// Function: FUN_0053a4d0 @ 0053a4d0
// Strings:  [incomplete literal/length tree, oversubscribed literal/length tree, empty distance tree with lengths, incomplete distance tree, oversubscribed distance tree]


int __thiscall
FUN_0053a4d0(uint param_1,int *param_2,int *param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7,int param_8)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (**(code **)(param_8 + 0x20))(4);
  if (iVar1 == 0) {
    return -4;
  }
  iVar2 = FUN_0053a020(0x101,&DAT_005b8718,&DAT_005b8798,param_4,param_2,param_6,&stack0xfffffff4,
                       iVar1);
  if (iVar2 == 0) {
    if (*param_2 == 0) goto LAB_0053a60d;
    iVar2 = FUN_0053a020(0,&DAT_005b8818,&DAT_005b8890,param_5,param_3,param_6,&stack0xfffffff4,
                         iVar1);
    if (iVar2 == 0) {
      if ((*param_3 != 0) || (param_1 < 0x102)) {
        (**(code **)(param_8 + 0x24))();
        return 0;
      }
LAB_0053a5df:
      *(char **)(param_8 + 0x18) = s_empty_distance_tree_with_lengths_005dbb30;
    }
    else {
      if (iVar2 == -3) {
        *(char **)(param_8 + 0x18) = s_oversubscribed_distance_tree_005dbb70;
        (**(code **)(param_8 + 0x24))();
        return -3;
      }
      if (iVar2 != -5) {
        if (iVar2 == -4) goto LAB_0053a619;
        goto LAB_0053a5df;
      }
      *(char **)(param_8 + 0x18) = s_incomplete_distance_tree_005dbb54;
    }
  }
  else {
    if (iVar2 == -3) {
      *(char **)(param_8 + 0x18) = s_oversubscribed_literal_length_tr_005dbb0c;
      (**(code **)(param_8 + 0x24))();
      return -3;
    }
    if (iVar2 == -4) goto LAB_0053a619;
LAB_0053a60d:
    *(char **)(param_8 + 0x18) = s_incomplete_literal_length_tree_005dbaec;
  }
  iVar2 = -3;
LAB_0053a619:
  (**(code **)(param_8 + 0x24))();
  return iVar2;
}


