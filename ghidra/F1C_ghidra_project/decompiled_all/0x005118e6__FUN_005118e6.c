// Function: FUN_005118e6 @ 005118e6
// Strings:  [zlib version error, zlib memory error, Unknown zlib error, 1.1.3, Incompatible libpng version in application and library]


int FUN_005118e6(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  
  iVar1 = FUN_00517e43(1);
  if (iVar1 == 0) {
    return 0;
  }
  iVar2 = __setjmp3(iVar1,0);
  if (iVar2 != 0) {
    FUN_00517ec8(iVar1,*(undefined4 *)(iVar1 + 0x9c));
    FUN_00517e85(iVar1);
    return 0;
  }
  FUN_0051184f(iVar1,param_2,param_3,param_4);
  if ((param_1 == (char *)0x0) || (*param_1 != '1')) {
    FUN_00511869(iVar1,"Incompatible libpng version in application and library");
  }
  *(undefined4 *)(iVar1 + 0xa0) = 0x2000;
  uVar3 = FUN_00517e92(iVar1,0x2000);
  *(undefined4 *)(iVar1 + 0x9c) = uVar3;
  *(code **)(iVar1 + 0x84) = FUN_00513c80;
  *(code **)(iVar1 + 0x88) = thunk_FUN_00517ec8;
  *(int *)(iVar1 + 0x8c) = iVar1;
  iVar2 = FUN_00517ac5(iVar1 + 100,"1.1.3",0x38);
  if (iVar2 == -6) {
    pcVar4 = "zlib version error";
  }
  else if ((iVar2 == -4) || (iVar2 == -2)) {
    pcVar4 = "zlib memory error";
  }
  else {
    if (iVar2 == 0) goto LAB_005119c5;
    pcVar4 = "Unknown zlib error";
  }
  FUN_00511869(iVar1,pcVar4);
LAB_005119c5:
  *(undefined4 *)(iVar1 + 0x70) = *(undefined4 *)(iVar1 + 0x9c);
  *(undefined4 *)(iVar1 + 0x74) = *(undefined4 *)(iVar1 + 0xa0);
  FUN_00513bf9(iVar1,0,0);
  return iVar1;
}


