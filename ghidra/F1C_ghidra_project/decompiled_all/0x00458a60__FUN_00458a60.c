// Function: FUN_00458a60 @ 00458a60
// Strings:  [FALSE, FALSE]


undefined4 __thiscall FUN_00458a60(int param_1,undefined4 param_2,uint param_3)

{
  undefined1 *puVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  double dVar8;
  float local_154;
  float local_150;
  float local_14c;
  float local_148;
  undefined4 local_144;
  float local_140;
  float local_13c;
  undefined4 local_138;
  undefined4 local_134;
  float local_130;
  float local_12c;
  undefined4 local_128;
  float local_124;
  float local_120;
  float local_11c;
  float local_118;
  float local_114;
  float local_110;
  float local_10c;
  undefined4 local_108 [65];
  
  local_148 = 0.0;
  local_140 = 0.0;
  local_154 = 0.0;
  local_150 = 0.0;
  local_13c = 0.0;
  local_12c = 0.0;
  local_130 = 0.0;
  local_14c = 0.0;
  local_138 = 0;
  local_144 = 0;
  local_134 = 0;
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
  local_124 = *(float *)(param_1 + 0xc);
  local_120 = *(float *)(param_1 + 0x10);
  local_11c = *(float *)(param_1 + 0x14);
  local_118 = *(float *)(param_1 + 0x90);
  local_114 = *(float *)(param_1 + 0x94);
  local_110 = *(float *)(param_1 + 0x98);
  FUN_00456040(&local_14c,&local_130);
  FUN_004560e0();
  FUN_00456080(&local_12c,&local_13c);
  local_128 = *(undefined4 *)(param_1 + 0x48);
  FUN_004560a0(&local_150,&local_154);
  FUN_004560c0(&local_140,&local_148);
  puVar1 = *(undefined1 **)(param_1 + 4);
  local_10c = *(float *)(param_1 + 0x5c);
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = &DAT_005ea438;
  }
  FUN_00566c30(param_2,s__sTrackingCam__s_005c5b18,local_108,puVar1);
  FUN_00566c30(param_2,&DAT_005c5988,local_108);
  FUN_00566c30(param_2,s__s_Position___f___f___f__005c5a44,local_108,(double)local_124,
               (double)local_120,(double)local_11c);
  FUN_00566c30(param_2,s__s_Orientation___f___f___f__005c5a24,local_108,(double)local_118,
               (double)local_114,(double)local_110);
  FUN_00566c30(param_2,s__s_Fov___f___f__005c5974,local_108,(double)local_14c,(double)local_130);
  pcVar2 = &DAT_005c596c;
  if (*(char *)(param_1 + 0x60) == '\0') {
    pcVar2 = s_FALSE_005c5798;
  }
  FUN_00566c30(param_2,s__s_Clear__s_005c595c,local_108,pcVar2);
  FUN_00566c30(param_2,s__s_Color___d___d___d__005c5944,local_108,local_134,local_144,local_138);
  FUN_00566c30(param_2,s__s_ClipPlanes___f___f__005c5928,local_108,(double)local_12c,
               (double)local_13c);
  FUN_00566c30();
  FUN_00566c30(param_2,s__s_Size___f___f__005c58fc,local_108,(double)local_150,(double)local_154);
  FUN_00566c30(param_2,s__s_Center___f___f__005c58e4,local_108,(double)local_140,(double)local_148);
  dVar8 = (double)local_10c;
  uVar7 = CONCAT44(local_108,s__s_MipmapLODBias___f__005c58cc);
  uVar6 = param_2;
  FUN_00566c30();
  FUN_00566c30(param_2,s__s_Flags1___d__005c58b8,local_108,*(undefined4 *)(param_1 + 0x74),uVar6,
               uVar7,dVar8);
  FUN_00566c30(param_2,s__s_Flags2___d__005c58a4,local_108,*(undefined4 *)(param_1 + 0x78));
  FUN_00566c30(param_2,s__s_ActivationLocation___f___f____005c59fc,local_108,
               (double)*(float *)(param_1 + 0x7c),(double)*(float *)(param_1 + 0x80),
               (double)*(float *)(param_1 + 0x84));
  FUN_00566c30();
  FUN_00566c30();
  FUN_00566c30();
  FUN_00458190(param_2,param_3 + 2);
  FUN_00566c30();
  return 0;
}


