// Function: FUN_0045c8f0 @ 0045c8f0
// Size (bytes): 301


/* WARNING: Removing unreachable block (ram,0x0045c99d) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0045c8f0(int param_1,uint *param_2,float param_3)

{
  byte bVar1;
  uint uVar2;
  float fVar3;
  uint *puVar4;
  char cVar5;
  uint uVar6;
  
  puVar4 = param_2;
  uVar2 = *param_2;
  uVar6 = uVar2 & 0xff;
  if (uVar6 < 0x68) {
    *(undefined4 *)(param_1 + 0x14 + uVar6 * 4) = 0;
    if (_DAT_0059e450 < *(float *)(param_1 + 0x1b4 + uVar6 * 4)) {
      *(undefined4 *)(param_1 + 0x1124 + uVar6 * 4) = 0xbf800000;
      FUN_0045c7a0(param_3 - (float)param_2[1],
                   param_1 + 0x424 + (uVar6 * 0x10 + (uint)*(byte *)(uVar6 + 0x3bc + param_1)) * 2);
      bVar1 = *(byte *)(uVar6 + 0x354 + param_1);
      if (bVar1 < 0x10) {
        *(byte *)(uVar6 + 0x354 + param_1) = bVar1 + 1;
      }
      *(byte *)(uVar6 + 0x3bc + param_1) = *(char *)(uVar6 + 0x3bc + param_1) + 1U & 0xf;
      *(undefined4 *)(param_1 + 0x1b4 + uVar6 * 4) = 0;
    }
    cVar5 = FUN_0045cbf0(uVar6,&param_2);
    if (cVar5 != '\0') {
      puVar4[1] = (uint)((float)puVar4[1] - (float)param_2);
    }
    fVar3 = (float)_DAT_008afea0;
    if ((float)puVar4[1] <= fVar3) {
      if ((float)puVar4[1] < fVar3 - DAT_007d108c) {
        puVar4[1] = (uint)(fVar3 - DAT_007d108c);
      }
    }
    else {
      puVar4[1] = (uint)fVar3;
    }
  }
  *(uint *)(param_1 + 4) = *(int *)(param_1 + 4) + (uVar2 >> 8 & 0x3ff) + 8;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  return;
}


