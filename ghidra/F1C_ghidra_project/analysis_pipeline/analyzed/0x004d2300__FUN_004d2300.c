// Function: FUN_004d2300 @ 004d2300
// Size (bytes): 200


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004d2300(undefined4 param_1)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  float fVar4;
  
  cVar2 = FUN_00461db0(param_1);
  iVar1 = DAT_008aae64;
  if (cVar2 == '\0') {
    fVar4 = 3.0;
  }
  else {
    if (_DAT_008afea0 < _DAT_005acef0) {
      return;
    }
    fVar4 = 2.5;
  }
  if (DAT_0083ee60 < 0x3ff) {
    DAT_0083ee60 = DAT_0083ee60 + 1;
    DAT_008aae64 = DAT_008aae64 + 0x1b0;
  }
  FUN_004b33b0(4,0x14,8,0xff,(float)_DAT_008afea0,1);
  *(float *)(iVar1 + 8) = (float)_DAT_008afea0 + fVar4;
  uVar3 = DAT_008aae70 & 0xff;
  DAT_008aae70 = DAT_008aae70 + 1;
  *(float *)(iVar1 + 0xc) =
       *(float *)(&DAT_008aae74 + uVar3 * 4) + *(float *)(&DAT_008aae74 + uVar3 * 4) +
       (float)_DAT_008afea0 + fVar4 + (float)_DAT_0059eb08;
  return;
}


