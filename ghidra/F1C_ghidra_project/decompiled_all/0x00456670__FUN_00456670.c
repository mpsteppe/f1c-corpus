// Function: FUN_00456670 @ 00456670
// Strings:  [FALSE, FALSE]


undefined4 __thiscall FUN_00456670(int param_1,undefined4 param_2,uint param_3)

{
  undefined1 *puVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  double dVar8;
  float local_13c;
  float local_138;
  float local_134;
  float local_130;
  undefined4 local_12c;
  float local_128;
  float local_124;
  float local_120;
  undefined4 local_11c;
  float local_118;
  undefined4 local_114;
  undefined4 local_110;
  float local_10c;
  undefined4 local_108 [65];
  
  local_128 = 0.0;
  local_120 = 0.0;
  local_138 = 0.0;
  local_130 = 0.0;
  local_124 = 0.0;
  local_13c = 0.0;
  local_118 = 0.0;
  local_134 = 0.0;
  local_11c = 0;
  local_12c = 0;
  local_114 = 0;
  uVar3 = 0;
  if (0 < (int)param_3) {
    puVar5 = local_108;
    for (uVar3 = param_3 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar5 = 0x20202020;
      puVar5 = puVar5 + 1;
    }
    for (uVar4 = param_3 & 3; uVar3 = param_3, uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined1 *)puVar5 = 0x20;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
  }
  *(undefined1 *)((int)local_108 + uVar3) = 0;
  FUN_00456060(&local_134,&local_118);
  FUN_004560e0();
  FUN_00456080(&local_13c,&local_124);
  local_110 = *(undefined4 *)(param_1 + 0x48);
  FUN_004560a0(&local_130,&local_138);
  FUN_004560c0(&local_120,&local_128);
  local_10c = *(float *)(param_1 + 0x5c);
  puVar1 = *(undefined1 **)(param_1 + 4);
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = &DAT_005ea438;
  }
  FUN_00566c30(param_2,s__sLocalCam__s_005c5990,local_108,puVar1);
  FUN_00566c30(param_2,&DAT_005c5988,local_108);
  FUN_00566c30(param_2,s__s_Fov___f___f__005c5974,local_108,(double)local_134,(double)local_118);
  pcVar2 = &DAT_005c596c;
  if (*(char *)(param_1 + 0x60) == '\0') {
    pcVar2 = s_FALSE_005c5798;
  }
  FUN_00566c30(param_2,s__s_Clear__s_005c595c,local_108,pcVar2);
  FUN_00566c30(param_2,s__s_Color___d___d___d__005c5944,local_108,local_114,local_12c,local_11c);
  FUN_00566c30(param_2,s__s_ClipPlanes___f___f__005c5928,local_108,(double)local_13c,
               (double)local_124);
  FUN_00566c30();
  FUN_00566c30(param_2,s__s_Size___f___f__005c58fc,local_108,(double)local_130,(double)local_138);
  FUN_00566c30(param_2,s__s_Center___f___f__005c58e4,local_108,(double)local_120,(double)local_128);
  dVar8 = (double)local_10c;
  uVar7 = CONCAT44(local_108,s__s_MipmapLODBias___f__005c58cc);
  uVar6 = param_2;
  FUN_00566c30();
  FUN_00566c30(param_2,s__s_Flags1___d__005c58b8,local_108,*(undefined4 *)(param_1 + 0x74),uVar6,
               uVar7,dVar8);
  FUN_00566c30(param_2,s__s_Flags2___d__005c58a4,local_108,*(undefined4 *)(param_1 + 0x78));
  FUN_00566c30(param_2,s__s_RadiusLimits___f___f__005c5888,local_108,
               (double)*(float *)(param_1 + 0x80),(double)*(float *)(param_1 + 0x84));
  FUN_00566c30(param_2,s__s_OrientationRate___f___f___f__005c5864,local_108,
               (double)*(float *)(param_1 + 0x88),(double)*(float *)(param_1 + 0x8c),
               (double)*(float *)(param_1 + 0x90));
  FUN_00566c30(param_2,s__s_PositionOffset___f___f___f__005c5840,local_108,
               (double)*(float *)(param_1 + 0x94),(double)*(float *)(param_1 + 0x98),
               (double)*(float *)(param_1 + 0x9c));
  FUN_00566c30(param_2,s__s_OrientationOffset___f___f___f_005c581c,local_108,
               (double)*(float *)(param_1 + 0xa0),(double)*(float *)(param_1 + 0xa4),
               (double)*(float *)(param_1 + 0xa8));
  dVar8 = (double)*(float *)(param_1 + 0xac);
  uVar7 = CONCAT44(local_108,s__s_Radius___f__005c5808);
  uVar6 = param_2;
  FUN_00566c30();
  FUN_00566c30(param_2,&DAT_005c5800,local_108,uVar6,uVar7,dVar8);
  return 0;
}


