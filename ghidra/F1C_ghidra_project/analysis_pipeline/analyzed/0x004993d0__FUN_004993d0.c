// Function: FUN_004993d0 @ 004993d0
// Size (bytes): 326


undefined4 __fastcall FUN_004993d0(int *param_1)

{
  short *psVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 unaff_EBX;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  short sStack_20;
  short sStack_1e;
  short sStack_14;
  short sStack_12;
  short local_10;
  short sStack_e;
  
  if (param_1[0x13] != 0) {
    iVar2 = *(int *)(param_1[0x13] + 0xc);
    FUN_00491300(*(int *)(param_1[0x14] + 0xc) + param_1[3],*(int *)(param_1[0x14] + 4) + param_1[1]
                 ,*(undefined4 *)(iVar2 + 0x1c),*(undefined4 *)(iVar2 + 0x20));
    FUN_00490920();
    psVar1 = (short *)FUN_00491cf0();
    (**(code **)(*param_1 + 0x2c))(0);
    while (psVar1 != (short *)0x0) {
      FUN_00491300((int)*psVar1,(int)psVar1[1],(int)psVar1[2],(int)psVar1[3]);
      FUN_00491600((int)sStack_14,(int)sStack_12,(int)local_10,(int)sStack_e);
      if ((0 < sStack_20) && (0 < sStack_1e)) {
        iVar2 = (int)(short)unaff_EBX;
        iVar8 = iVar2 - sStack_14;
        iVar5 = (int)(short)((uint)unaff_EBX >> 0x10);
        uVar11 = 0;
        uVar10 = 0;
        iVar9 = iVar5 - sStack_12;
        iVar6 = (int)sStack_20;
        iVar7 = (int)sStack_1e;
        uVar3 = FUN_00495150(iVar2,iVar5,iVar6,iVar7,0,0);
        FUN_00494a30(*(undefined4 *)(param_1[0x13] + 0xc),iVar8,iVar9,uVar3,iVar2,iVar5,iVar6,iVar7,
                     uVar10,uVar11);
      }
      FUN_00490920();
      psVar1 = (short *)FUN_00491d10();
      FUN_004b0170();
    }
    piVar4 = (int *)param_1[0x11];
    while (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 0x44))();
      piVar4 = (int *)FUN_00486320();
    }
    FUN_004b0170();
    return 0;
  }
  return 0xffffffff;
}


