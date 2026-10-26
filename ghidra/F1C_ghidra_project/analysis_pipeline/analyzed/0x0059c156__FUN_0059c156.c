// Function: FUN_0059c156 @ 0059c156
// Size (bytes): 145


undefined4 FUN_0059c156(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar4 = CONCAT44(param_3,param_2);
  if (((*(uint *)(param_1 + 0xc) & 0x83) == 0) ||
     (((param_4 != 0 && (param_4 != 1)) && (param_4 != 2)))) {
    puVar2 = (undefined4 *)FUN_0058afcf();
    *puVar2 = 0x16;
  }
  else {
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xffffffef;
    if (param_4 == 1) {
      lVar3 = FUN_0058c824(param_1);
      lVar4 = lVar3 + lVar4;
      param_4 = 0;
    }
    FUN_0058a05a(param_1);
    uVar1 = *(uint *)(param_1 + 0xc);
    if ((uVar1 & 0x80) == 0) {
      if ((((uVar1 & 1) != 0) && ((uVar1 & 8) != 0)) && ((uVar1 & 0x400) == 0)) {
        *(undefined4 *)(param_1 + 0x18) = 0x200;
      }
    }
    else {
      *(uint *)(param_1 + 0xc) = uVar1 & 0xfffffffc;
    }
    lVar4 = FUN_00595f11(*(undefined4 *)(param_1 + 0x10),lVar4,param_4);
    if (lVar4 != -1) {
      return 0;
    }
  }
  return 0xffffffff;
}


