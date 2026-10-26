// Function: FUN_004ff680 @ 004ff680
// Size (bytes): 623


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004ff680(float param_1,undefined4 *param_2,undefined4 *param_3,float param_4)

{
  undefined4 uVar1;
  float fVar2;
  undefined4 *puVar3;
  undefined2 uVar4;
  undefined1 *puVar5;
  undefined2 *puVar6;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  undefined1 local_3c [12];
  float local_30 [2];
  float local_28;
  
  puVar3 = param_2;
  fVar2 = param_1 - (float)param_2[1];
  param_2 = (undefined4 *)-DAT_005ad350;
  if (((float)param_2 <= fVar2) && (param_2 = (undefined4 *)fVar2, DAT_005ad350 < fVar2)) {
    param_2 = (undefined4 *)DAT_005ad350;
  }
  fVar2 = (float)param_2 * _DAT_0059f0c0;
  local_64 = -DAT_005ad354;
  if ((local_64 <= fVar2) && (local_64 = fVar2, DAT_005ad354 < fVar2)) {
    local_64 = DAT_005ad354;
  }
  *param_3 = *puVar3;
  uVar1 = puVar3[0x6b];
  param_3[1] = param_1;
  param_3[0x6b] = uVar1;
  FUN_004b2580(&local_60);
  FUN_004b2800(local_30);
  param_3[2] = (local_30[0] * local_64 + local_60) * (float)param_2 + (float)puVar3[2];
  param_3[3] = (local_64 * param_4 * (float)_DAT_0059ed50 + local_5c) * (float)param_2 +
               (float)puVar3[3];
  param_3[4] = (local_28 * local_64 + local_58) * (float)param_2 + (float)puVar3[4];
  local_48 = (float)(int)*(char *)(puVar3 + 0xb) * _DAT_0059e448 * (float)param_2 * _DAT_0059e8b4;
  local_44 = (float)(int)*(short *)((int)puVar3 + 0x2e) * _DAT_005accb0 * (float)param_2 *
             _DAT_0059e4e8;
  local_40 = (float)(int)*(char *)((int)puVar3 + 0x2d) * _DAT_0059e448 * (float)param_2 *
             _DAT_0059e8b4;
  local_54 = (float)(int)*(short *)(puVar3 + 5) * _DAT_0059e77c;
  local_50 = (float)(int)*(short *)((int)puVar3 + 0x16) * _DAT_0059e77c;
  local_4c = (float)(int)*(short *)(puVar3 + 6) * _DAT_0059e77c;
  FUN_00566e40();
  FUN_00567120(&local_48,local_3c);
  uVar4 = __ftol();
  *(undefined2 *)(param_3 + 5) = uVar4;
  uVar4 = __ftol();
  *(undefined2 *)((int)param_3 + 0x16) = uVar4;
  uVar4 = __ftol();
  *(undefined2 *)(param_3 + 6) = uVar4;
  puVar5 = (undefined1 *)((int)param_3 + 0x1a);
  puVar6 = (undefined2 *)((int)param_3 + 0x1e);
  do {
    *puVar5 = puVar5[(int)puVar3 - (int)param_3];
    *puVar6 = *(undefined2 *)((int)puVar6 + ((int)puVar3 - (int)param_3));
    puVar6 = puVar6 + 1;
    puVar5 = puVar5 + 1;
  } while ((int)(puVar5 + (-0x1a - (int)param_3)) < 4);
  *(undefined4 *)((int)param_3 + 0x26) = *(undefined4 *)((int)puVar3 + 0x26);
  *(undefined4 *)((int)param_3 + 0x2a) = *(undefined4 *)((int)puVar3 + 0x2a);
  *(undefined2 *)((int)param_3 + 0x2e) = *(undefined2 *)((int)puVar3 + 0x2e);
  param_3[0xc] = puVar3[0xc];
  param_3[0xd] = puVar3[0xd];
  uVar1 = puVar3[0xe];
  param_3[0xe] = uVar1;
  return CONCAT31((int3)((uint)uVar1 >> 8),1);
}


