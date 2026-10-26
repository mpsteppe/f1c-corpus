// Function: FUN_00560c10 @ 00560c10
// Size (bytes): 567


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_00560c10(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  undefined4 *puVar4;
  float10 fVar5;
  float *pfVar6;
  float fVar7;
  undefined4 uVar8;
  float local_10c;
  undefined1 local_108 [4];
  float local_104;
  undefined1 local_100 [256];
  
  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x18) + 0x138) + 0x40);
  if ((iVar1 == 0) || (*(int *)(iVar1 + 0x230) == 0)) {
    if ((*(byte *)(param_1 + 0x24) & 1) != 0) goto LAB_00560e11;
    FUN_0058815f(local_100,s_FSHADOWVIEW__3d_005dd84b + 1,*(undefined4 *)(param_1 + 0x28));
    pvVar3 = operator_new(0x1bc);
    if (pvVar3 == (void *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4 = (undefined4 *)FUN_005418b0();
    }
    *(undefined4 **)(param_1 + 0xc) = puVar4;
    *puVar4 = param_2;
    FUN_005418e0(local_100);
    fVar7 = *(float *)(*(int *)(param_1 + 0x18) + 0x18);
  }
  else {
    uVar2 = *(uint *)(param_1 + 0x24);
    *(uint *)(param_1 + 0x24) = uVar2 | 4;
    if ((uVar2 & 1) != 0) goto LAB_00560e11;
    FUN_0058815f(local_100,s_FSHADOWVIEW__3d_005dd84b + 1,*(undefined4 *)(param_1 + 0x28));
    pvVar3 = operator_new(0x1bc);
    if (pvVar3 == (void *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4 = (undefined4 *)FUN_005418b0();
    }
    *(undefined4 **)(param_1 + 0xc) = puVar4;
    *puVar4 = param_2;
    FUN_005418e0(local_100);
    fVar7 = *(float *)(*(int *)(param_1 + 0x18) + 0x18);
  }
  FUN_005423c0(_DAT_005dd848 - (fVar7 + fVar7),_DAT_005dd848 + fVar7 + fVar7);
  FUN_005423e0(0,0,0);
  FUN_005457c0(0);
  pfVar6 = &local_10c;
  FUN_0055d590(pfVar6,local_108,&local_104);
  uVar8 = 0;
  fVar5 = (float10)fpatan(-(float10)local_10c,(float10)local_104);
  fVar7 = (float)fVar5;
  fVar5 = (float10)FUN_00588570(pfVar6,fVar7,0);
  FUN_00541db0((float)fVar5,fVar7,uVar8);
  fVar5 = (float10)fpatan((float10)*(float *)(*(int *)(param_1 + 0x18) + 0x18) *
                          (float10)_DAT_005b8998,(float10)_DAT_005dd848);
  fVar7 = (float)(ABS(fVar5) + ABS(fVar5));
  FUN_00542050(fVar7,fVar7,1);
  FUN_00542200(0,0,(float)DAT_008b8df4,(float)DAT_008b8df4,1);
  pvVar3 = operator_new(0x4c);
  if (pvVar3 == (void *)0x0) {
    uVar8 = 0;
  }
  else {
    uVar8 = FUN_00556220();
  }
  *(undefined4 *)(param_1 + 0x1c) = uVar8;
  FUN_00556260(1);
  pvVar3 = operator_new(8);
  if (pvVar3 == (void *)0x0) {
    uVar8 = 0;
  }
  else {
    uVar8 = FUN_00560b60(0x400);
  }
  *(undefined4 *)(param_1 + 0x20) = uVar8;
  *(uint *)(param_1 + 0x24) = *(uint *)(param_1 + 0x24) | 1;
LAB_00560e11:
  if (*(int *)(param_1 + 0x2c) != 0) {
    FUN_00560c10(param_2,1);
  }
  if ((*(int *)(param_1 + 0x34) != 0) && (param_3 != 0)) {
    FUN_00560c10(param_2,1);
  }
  return 0;
}


