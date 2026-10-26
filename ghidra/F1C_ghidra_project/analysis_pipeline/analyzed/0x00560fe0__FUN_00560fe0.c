// Function: FUN_00560fe0 @ 00560fe0
// Size (bytes): 1019


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_00560fe0(int param_1,undefined4 param_2,int param_3)

{
  uint *puVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  float10 fVar6;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar3 = **(int **)(param_1 + 0xc);
  uVar5 = 0;
  iVar4 = FUN_0055c9b0();
  if (iVar4 == 0) {
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(iVar3 + 0x164);
  }
  else if ((*(byte *)(param_1 + 0x24) & 4) == 0) {
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x28) * 0x60 + *(int *)(iVar3 + 0x164);
  }
  else {
    *(int *)(param_1 + 0x10) =
         *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x18) + 0x138) + 0x40) + 0x230) +
                 0x28) * 0x60 + *(int *)(iVar3 + 0x164);
  }
  FUN_00542560(*(undefined4 *)(*(int *)(param_1 + 0x10) + 0x54));
  iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 0x19c);
  if (iVar3 == 0) {
    return 0xfffffffe;
  }
  if ((*(uint *)(iVar3 + 0x18) & 0x40000) == 0) {
    return 0xfffffffe;
  }
  if ((*(byte *)(*(int *)(*(int *)(param_1 + 0x18) + 0x138) + 0x3c) & 2) != 0) {
    uVar5 = 0xfffffffe;
    goto LAB_005613a6;
  }
  if ((*(byte *)(*(int *)(param_1 + 0x18) + 0x14) & 5) == 0) {
    if (*(int *)(param_1 + 0x2c) != 0) {
      FUN_005457c0(0);
      FUN_0055d590(&local_c,&local_8,&local_4);
      fVar6 = (float10)fpatan((float10)*(float *)(*(int *)(param_1 + 0x18) + 0x18) *
                              (float10)_DAT_005b8998,(float10)_DAT_005dd848);
      fVar2 = (float)(ABS(fVar6) + ABS(fVar6));
      if (*(int *)(*(int *)(param_1 + 0x18) + 0x13c) == 0) {
        FUN_00542050(fVar2,fVar2,1);
        fVar2 = *(float *)(*(int *)(param_1 + 0x18) + 0x18);
        fVar2 = fVar2 + fVar2;
        FUN_005423c0(_DAT_005dd848 - fVar2,_DAT_005dd848 + fVar2);
        FUN_0054b420(&local_18,&local_14,&local_10);
      }
      else {
        FUN_00542050(fVar2,fVar2,1);
        fVar2 = *(float *)(*(int *)(param_1 + 0x18) + 0x18);
        fVar2 = fVar2 + fVar2;
        FUN_005423c0(_DAT_005dd848 - fVar2,_DAT_005dd848 + fVar2);
        FUN_0054b950(&local_18,&local_14,&local_10);
      }
      FUN_00541d10(_DAT_005dd848 * local_c - local_18,_DAT_005dd848 * local_8 - local_14,
                   _DAT_005dd848 * local_4 - local_10);
      FUN_00541b70(0xe);
      FUN_00541a70();
      FUN_0055c070(param_1,0x10);
      uVar5 = 0xfffffffe;
      goto LAB_0056136d;
    }
  }
  else if ((*(byte *)(param_1 + 0x24) & 4) == 0) {
    FUN_005457c0(0);
    FUN_0055d590(&local_c,&local_8,&local_4);
    fVar6 = (float10)fpatan((float10)*(float *)(*(int *)(param_1 + 0x18) + 0x18) *
                            (float10)_DAT_005b8998,(float10)_DAT_005dd848);
    fVar2 = (float)(ABS(fVar6) + ABS(fVar6));
    if (*(int *)(*(int *)(param_1 + 0x18) + 0x13c) == 0) {
      FUN_00542050(fVar2,fVar2,1);
      fVar2 = *(float *)(*(int *)(param_1 + 0x18) + 0x18);
      fVar2 = fVar2 + fVar2;
      FUN_005423c0(_DAT_005dd848 - fVar2,_DAT_005dd848 + fVar2);
      FUN_0054b420(&local_18,&local_14,&local_10);
    }
    else {
      FUN_00542050(fVar2,fVar2,1);
      fVar2 = *(float *)(*(int *)(param_1 + 0x18) + 0x18);
      fVar2 = fVar2 + fVar2;
      FUN_005423c0(_DAT_005dd848 - fVar2,_DAT_005dd848 + fVar2);
      FUN_0054b950(&local_18,&local_14,&local_10);
    }
    FUN_00541d10(_DAT_005dd848 * local_c - local_18,_DAT_005dd848 * local_8 - local_14,
                 _DAT_005dd848 * local_4 - local_10);
    FUN_00541b70(0xe);
    FUN_00541a70();
    FUN_0055c070(param_1,0);
LAB_0056136d:
    *(uint *)(param_1 + 0x24) = *(uint *)(param_1 + 0x24) | 8;
  }
  else {
    FUN_0055c070(param_1,0);
  }
  iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 0x19c);
  if ((*(byte *)(iVar3 + 0x18) & 2) != 0) {
    FUN_00540240(iVar3,2,4);
    puVar1 = (uint *)(*(int *)(*(int *)(param_1 + 0xc) + 0x19c) + 0x18);
    *puVar1 = *puVar1 & 0xfffffbff;
  }
LAB_005613a6:
  if (*(int *)(param_1 + 0x2c) != 0) {
    FUN_00560fe0(param_2,1);
  }
  if ((*(int *)(param_1 + 0x34) != 0) && (param_3 != 0)) {
    FUN_00560fe0(param_2,1);
  }
  return uVar5;
}


