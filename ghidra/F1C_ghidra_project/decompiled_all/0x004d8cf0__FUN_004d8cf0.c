// Function: FUN_004d8cf0 @ 004d8cf0
// Strings:  [%s%s%s, HUD 512 64.TGA]


undefined4 __thiscall FUN_004d8cf0(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  void *pvVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int *piVar9;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  undefined1 local_80 [128];
  
  uVar7 = 1;
  uVar8 = 0x80000000;
  FUN_004d9030(param_2);
  switch(param_2) {
  case 1:
    piVar9 = &DAT_008ad398;
    local_88 = 768.0;
    local_90 = 256.0;
    break;
  case 2:
    piVar9 = &DAT_008ad39c;
    local_88 = 256.0;
    local_90 = 512.0;
    break;
  case 3:
    piVar9 = &DAT_008ad3a0;
    local_84 = 0.0;
    local_88 = 0.0;
    local_8c = 1280.0;
    local_90 = 160.0;
    uVar8 = 0xffffffff;
    pvVar3 = operator_new(0x60);
    if (pvVar3 == (void *)0x0) {
      DAT_008ad3ac = 0;
    }
    else {
      DAT_008ad3ac = FUN_0054fe10();
    }
    *(uint *)(DAT_008ad3ac + 0x44) = *(uint *)(DAT_008ad3ac + 0x44) | 1;
    puVar6 = DAT_005ec428;
    if (DAT_005ec428 == (undefined1 *)0x0) {
      puVar6 = &DAT_005ea438;
    }
    puVar4 = DAT_005ec3d8;
    if (DAT_005ec3d8 == (undefined1 *)0x0) {
      puVar4 = &DAT_005ea438;
    }
    FUN_0058815f(local_80,s__s_s_s_005c6784,puVar4,puVar6,s_HUD_512_64_TGA_005d4ad8);
    iVar5 = FUN_00550080(local_80,0,&DAT_00800004);
    if (iVar5 != 0) {
      FUN_005502c0();
      iVar5 = DAT_008ad3ac;
      if (DAT_008ad3ac != 0) {
        FUN_00557470();
        FUN_00587bcf(iVar5);
      }
      DAT_008ad3ac = 0;
      uVar8 = 0x80000000;
    }
    goto LAB_004d8e7f;
  case 4:
    piVar9 = &DAT_008ad3a4;
    local_84 = 870.0;
    local_88 = 140.0;
    local_8c = 410.0;
    local_90 = 220.0;
    goto LAB_004d8e7f;
  case 5:
    piVar9 = &DAT_008ad3a8;
    local_88 = 0.0;
    local_90 = 50.0;
    uVar8 = 0xffffffff;
    break;
  default:
    goto switchD_004d8d1f_default;
  }
  local_84 = 0.0;
  local_8c = 1280.0;
LAB_004d8e7f:
  if ((*piVar9 == 0) && (FUN_00553980(piVar9,2,0,0x20,0x40), *piVar9 != 0)) {
    local_84 = local_84 * *(float *)(param_1 + 0xe4);
    local_88 = local_88 * *(float *)(param_1 + 0xe8);
    fVar1 = *(float *)(param_1 + 0xe4);
    fVar2 = *(float *)(param_1 + 0xe8);
    FUN_00553650(0,local_84,local_88,0x3f800000,0,0,uVar8);
    fVar2 = local_90 * fVar2 + local_88;
    FUN_00553650(1,local_84,fVar2,0x3f800000,0,0x3f800000,uVar8);
    local_84 = local_8c * fVar1 + local_84;
    FUN_00553650(2,local_84,fVar2,0x3f800000,0x3f800000,0x3f800000,uVar8);
    FUN_00553650(3,local_84,local_88,0x3f800000,0x3f800000,0,uVar8);
    if (param_2 == 3) {
      FUN_00553620(DAT_008ad3ac);
    }
    uVar7 = 0;
  }
switchD_004d8d1f_default:
  return uVar7;
}


