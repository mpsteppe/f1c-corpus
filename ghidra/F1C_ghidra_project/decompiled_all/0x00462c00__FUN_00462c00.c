// Function: FUN_00462c00 @ 00462c00
// Strings:  [hostport, D:\dev\F1_1999_2002\Source\NetComm.cpp, Sending Join Request to "%s", %s:%d]


undefined4 __thiscall FUN_00462c00(int *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined1 local_50;
  undefined4 local_4f;
  
  iVar2 = FUN_00563e80();
  if (iVar2 != 0) {
    local_50 = DAT_005ea438;
    puVar4 = &local_4f;
    for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    *(undefined2 *)puVar4 = 0;
    *(undefined1 *)((int)puVar4 + 2) = 0;
    uVar3 = FUN_00564530(0);
    uVar3 = FUN_00564490(uVar3);
    FUN_0058815f(&local_50,s__s__d_005c6214,uVar3);
    if (DAT_007c569c != 5) {
      cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_NetCo_005c5ce4,0x1a01);
      if (cVar1 != '\0') {
        FUN_004d7aa0(&DAT_008ad25c,s_Sending_Join_Request_to___s__005c61f4,&local_50);
      }
    }
    *(undefined4 *)(*param_1 + 0x378) = 0;
    uVar3 = FUN_00462ce0(&local_50,param_3);
    return uVar3;
  }
  return 0;
}


