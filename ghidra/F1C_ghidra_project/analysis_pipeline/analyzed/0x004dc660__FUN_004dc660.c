// Function: FUN_004dc660 @ 004dc660
// Size (bytes): 262


void __fastcall
FUN_004dc660(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,float param_7,float param_8,int param_9)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (param_9 == 0) {
    param_9 = DAT_008b8dc8;
  }
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar4 = FUN_0053d1f0(param_1);
    if (iVar4 != 0) {
      uVar1 = *(undefined4 *)(iVar4 + 0x5c);
      uVar2 = *(undefined4 *)(iVar4 + 0x60);
      uVar3 = *(undefined4 *)(iVar4 + 0x48);
      *(float *)(iVar4 + 0x5c) = param_7 * *(float *)(iVar4 + 0x5c);
      *(float *)(iVar4 + 0x60) = param_8 * *(float *)(iVar4 + 0x60);
      FUN_00552fc0(param_5);
      param_3 = __ftol();
      param_4 = __ftol();
      param_8 = 0.0;
      param_7 = 0.0;
      FUN_005531f0(param_2,&param_8,&param_7,0);
      FUN_004dc340(param_8,param_7,param_6,&param_3,&param_4);
      FUN_00553070(param_2,param_3,param_4,param_9);
      *(undefined4 *)(iVar4 + 0x48) = uVar3;
      *(undefined4 *)(iVar4 + 0x5c) = uVar1;
      *(undefined4 *)(iVar4 + 0x60) = uVar2;
    }
  }
  return;
}


