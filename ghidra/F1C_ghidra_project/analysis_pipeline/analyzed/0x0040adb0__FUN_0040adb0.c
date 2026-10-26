// Function: FUN_0040adb0 @ 0040adb0
// Size (bytes): 640


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0040adb0(int param_1)

{
  int iVar1;
  float fVar2;
  undefined4 unaff_EBX;
  float unaff_EBP;
  undefined4 unaff_ESI;
  int iVar3;
  int *piVar4;
  float unaff_EDI;
  float10 fVar5;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar3 = *(int *)(param_1 + 0x14) * 0xa0;
  piVar4 = (int *)(iVar3 + *(int *)(param_1 + 0xc));
  local_c = *(float *)(iVar3 + 0xc + *(int *)(param_1 + 0xc)) * _DAT_0059e670;
  local_8 = (float)piVar4[4] * _DAT_0059e670;
  local_4 = (float)piVar4[5] * _DAT_0059e670;
  if (*(int *)(param_1 + 4) != 0) {
    if ((*(byte *)(piVar4 + 0x1d) & 4) != 0) {
      iVar3 = 0;
      if (0 < DAT_005c329c) {
        do {
          iVar1 = (&DAT_007c54f0)[iVar3];
          local_18 = *(float *)(iVar1 + 0x744);
          local_14 = *(float *)(iVar1 + 0x748);
          local_10 = *(float *)(iVar1 + 0x74c);
          fVar2 = (local_18 - local_c) * (local_18 - local_c) +
                  (local_14 - local_8) * (local_14 - local_8) +
                  (local_10 - local_4) * (local_10 - local_4);
          if (fVar2 < _DAT_0059e6a8) {
            local_24 = *(float *)(iVar1 + 0x58);
            local_20 = *(float *)(iVar1 + 0x5c);
            local_1c = *(float *)(iVar1 + 0x60);
            if (_DAT_0059e6a4 <
                SQRT(local_24 * local_24 + local_1c * local_1c + local_20 * local_20)) {
              fVar2 = _DAT_0059e43c - fVar2 * _DAT_0059e6a0;
              fVar5 = (float10)FUN_0040c780();
              FUN_00457a00(fVar2,(float)fVar5);
              goto LAB_0040aed4;
            }
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < DAT_005c329c);
      }
      FUN_00457b00(0);
    }
LAB_0040aed4:
    local_18 = *(float *)(DAT_007c54e0 + 0x744);
    local_14 = *(float *)(DAT_007c54e0 + 0x748);
    local_10 = *(float *)(DAT_007c54e0 + 0x74c);
    local_24 = *(float *)(DAT_007c54e0 + 0x704);
    local_20 = *(float *)(DAT_007c54e0 + 0x708);
    local_1c = *(float *)(DAT_007c54e0 + 0x70c);
    local_c = *(float *)(DAT_007c54e0 + 0x58);
    local_8 = *(float *)(DAT_007c54e0 + 0x5c);
    local_4 = *(float *)(DAT_007c54e0 + 0x60);
    iVar3 = *piVar4;
    fVar5 = (float10)FUN_0040c780();
    fVar5 = (float10)FUN_004084a0((float)fVar5);
    (**(code **)(iVar3 + 0x18))(&local_18,&local_24,&local_c,(float)fVar5);
    local_24 = (float)piVar4[5];
    FUN_00541cd0(piVar4[3],piVar4[4],local_24,piVar4[6],piVar4[7],piVar4[8]);
    FUN_00456060(&stack0xffffffbc,&stack0xffffffb8);
    FUN_00456080(&stack0xffffffc4,&stack0xffffffc0);
    FUN_00542050(unaff_EDI * _DAT_0059e65c,unaff_EBP * _DAT_0059e65c,0);
    FUN_005423c0(unaff_EBX,unaff_ESI);
    FUN_00542680(piVar4[0x12]);
  }
  return;
}


