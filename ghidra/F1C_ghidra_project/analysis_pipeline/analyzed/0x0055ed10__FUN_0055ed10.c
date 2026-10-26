// Function: FUN_0055ed10 @ 0055ed10
// Size (bytes): 264


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0055ed10(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 *puVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  float local_c;
  undefined1 local_8 [4];
  undefined1 local_4 [4];
  
  if ((*(byte *)(param_3 + 0x14) & 0x20) == 0) {
    if ((*(byte *)(param_2 + 0x3c) & 0x10) == 0) {
      FUN_0054b950(&local_c,local_8,local_4);
      pfVar4 = &local_c;
    }
    else {
      pfVar4 = (float *)(param_4 + 0x30);
    }
    *(undefined4 *)(param_3 + 0x10c) = 0;
    if ((**(uint **)(param_3 + 0x11c) & 0x100) != 0) {
      puVar1 = *(undefined4 **)(param_1 + 0x128);
      fVar3 = _DAT_0059e43c;
      while ((_DAT_0059e43c = fVar3, puVar1 != (undefined4 *)0x0 && (*(int *)(param_3 + 0x10c) < 8))
            ) {
        if ((((byte)*puVar1 & 0xa0) == 0x80) &&
           (fVar2 = *(float *)(param_3 + 0x18) + (float)puVar1[0x14],
           ((float)puVar1[0x10] - pfVar4[2]) * ((float)puVar1[0x10] - pfVar4[2]) +
           ((float)puVar1[0xf] - pfVar4[1]) * ((float)puVar1[0xf] - pfVar4[1]) +
           ((float)puVar1[0xe] - *pfVar4) * ((float)puVar1[0xe] - *pfVar4) <= fVar2 * fVar2)) {
          *(undefined4 **)(*(int *)(param_3 + 0x10c) * 0x38 + *(int *)(param_3 + 0x110)) = puVar1;
          *(float *)(*(int *)(param_3 + 0x10c) * 0x38 + 0x10 + *(int *)(param_3 + 0x110)) =
               fVar3 / (float)puVar1[0x14];
          *(int *)(param_3 + 0x10c) = *(int *)(param_3 + 0x10c) + 1;
        }
        puVar1 = (undefined4 *)puVar1[0x1b];
        fVar3 = _DAT_0059e43c;
      }
    }
  }
  return;
}


