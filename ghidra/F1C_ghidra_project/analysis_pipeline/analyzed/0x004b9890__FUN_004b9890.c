// Function: FUN_004b9890 @ 004b9890
// Size (bytes): 358


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004b9890(int *param_1,float param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  float fVar2;
  char cVar3;
  char cVar4;
  undefined4 uVar5;
  float10 fVar6;
  
  cVar3 = DAT_007c56ac;
  if (DAT_007ce254 == '\0') {
    FUN_0042d210(1);
    uVar5 = FUN_0040cd60();
    uVar1 = *(undefined4 *)((&DAT_007c54f0)[DAT_007c54dc] + 0x4894);
    *param_3 = 2;
    *(float *)(*param_1 + 0xf84) = param_2;
    cVar4 = FUN_004b87c0();
    if (cVar4 != '\0') {
      fVar2 = _DAT_0059e5fc;
      if ((_DAT_0059e5fc <= param_2) && (fVar2 = param_2, _DAT_0059e808 < param_2)) {
        fVar2 = _DAT_0059e808;
      }
      FUN_004b9cd0((float)_DAT_008afea0 - fVar2);
      fVar6 = (float10)FUN_004b9ce0();
      *(float *)(*param_1 + 0xf88) = (float)fVar6;
      FUN_0040cde0(5,0);
      do {
        param_2 = (float)FUN_004b8bd0();
        FUN_004c8650(0xbf800000);
        cVar4 = FUN_004b8ae0(&param_2);
      } while (cVar4 != '\0');
      FUN_004b9cd0((float)_DAT_008afea0);
      FUN_0042bbd0(uVar1);
      FUN_0040cde0(uVar5,0);
      FUN_004b8940();
    }
    *param_3 = 1;
    FUN_0042d210(cVar3);
    if (cVar3 != '\0') {
      FUN_004c8d60();
      return;
    }
    FUN_004c8d70();
  }
  return;
}


