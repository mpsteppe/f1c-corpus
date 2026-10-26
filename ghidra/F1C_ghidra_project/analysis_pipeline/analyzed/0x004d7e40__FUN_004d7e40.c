// Function: FUN_004d7e40 @ 004d7e40
// Size (bytes): 218


void FUN_004d7e40(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5,undefined4 param_6,float param_7,float param_8)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = FUN_004d7fa0(param_6);
  if (iVar3 != 0) {
    uVar1 = *(undefined4 *)(iVar3 + 0x5c);
    uVar2 = *(undefined4 *)(iVar3 + 0x60);
    *(float *)(iVar3 + 0x5c) = param_7 * *(float *)(iVar3 + 0x5c);
    *(float *)(iVar3 + 0x60) = param_8 * *(float *)(iVar3 + 0x60);
    FUN_00552fc0(param_4);
    uVar4 = __ftol();
    param_2 = uVar4;
    param_3 = __ftol();
    if (param_5 == 1) {
      FUN_004d7f60(param_1,uVar4,&param_2,param_6);
      uVar4 = param_2;
    }
    else if (param_5 == 2) {
      FUN_004d7f20(param_1,uVar4,&param_2,param_6);
      uVar4 = param_2;
    }
    FUN_00553070(param_1,uVar4,param_3,DAT_008b8dc8);
    *(undefined4 *)(iVar3 + 0x5c) = uVar1;
    *(undefined4 *)(iVar3 + 0x60) = uVar2;
  }
  return;
}


