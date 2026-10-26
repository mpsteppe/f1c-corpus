// Function: FUN_00479600 @ 00479600
// Size (bytes): 132


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00479600(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined1 uStack_40;
  undefined4 uStack_3f;
  
  pfVar5 = (float *)(**(code **)(*param_1 + 0xb4))();
  if (pfVar5 != (float *)0x0) {
    fVar1 = *pfVar5;
    fVar2 = (float)param_1[0x3d];
    fVar3 = (float)param_1[0x3e];
    fVar4 = (float)param_1[0x3d];
    uStack_40 = DAT_005ea438;
    puVar7 = &uStack_3f;
    for (iVar6 = 0xf; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
    *(undefined2 *)puVar7 = 0;
    *(undefined1 *)((int)puVar7 + 2) = 0;
    FUN_0058815f(&uStack_40,&DAT_005c37cc,
                 (int)ROUND(((fVar1 - fVar2) * _DAT_0059e6f8) / (fVar3 - fVar4)));
    FUN_00566650(&uStack_40);
  }
  return 0;
}


