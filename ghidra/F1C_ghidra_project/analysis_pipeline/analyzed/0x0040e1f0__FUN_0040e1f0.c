// Function: FUN_0040e1f0 @ 0040e1f0
// Size (bytes): 178


void __fastcall FUN_0040e1f0(undefined4 param_1,float *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float *pfVar4;
  int iVar5;
  int local_c;
  
  iVar1 = FUN_0054c210();
  local_c = 0;
  if (0 < iVar1) {
    do {
      iVar2 = FUN_0054c230(local_c);
      iVar3 = FUN_0054e100();
      iVar5 = 0;
      if (0 < iVar3) {
        do {
          pfVar4 = (float *)FUN_0054e120(iVar5);
          iVar5 = iVar5 + 1;
          *pfVar4 = *pfVar4 - *param_2;
          pfVar4[1] = pfVar4[1] - param_2[1];
          pfVar4[2] = pfVar4[2] - param_2[2];
        } while (iVar5 < iVar3);
      }
      *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) & 0xfeffffdf;
      FUN_0054d520(1);
      FUN_0054e270();
      FUN_0054d080(0);
      local_c = local_c + 1;
    } while (local_c < iVar1);
  }
  return;
}


