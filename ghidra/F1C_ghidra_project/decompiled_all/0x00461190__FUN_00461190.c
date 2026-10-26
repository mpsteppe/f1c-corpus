// Function: FUN_00461190 @ 00461190
// Strings:  [D:\dev\F1_1999_2002\Source\NetComm.cpp, *** The server %s %s, closed, opened, opened]


void __thiscall FUN_00461190(int param_1,char param_2)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  char *pcVar5;
  undefined1 local_c0 [64];
  undefined1 local_80 [128];
  
  if (param_2 == '\0') {
    pcVar5 = s_closed_005c6124;
    *(undefined4 *)(param_1 + 0x2c) = 0xbf800000;
    *(undefined1 *)(param_1 + 0x29) = 0;
  }
  else {
    pcVar5 = s_opened_005c612c;
    *(undefined4 *)(param_1 + 0x2c) = DAT_0059f0b4;
  }
  if (DAT_007d0398 != 0) {
    puVar2 = operator_new(8);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
      puVar2[1] = 0xffffffff;
    }
    FUN_004c5920(local_c0,0x3f);
    FUN_0058815f(local_80,s_____The_server__s__s_005c610c,pcVar5,local_c0);
    FUN_00566650(local_80);
    if (puVar2 != (undefined4 *)0x0) {
      puVar3 = operator_new(0xc);
      if (puVar3 == (undefined4 *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        *puVar3 = puVar2;
        puVar3[1] = 0;
        *(undefined1 *)(puVar3 + 2) = 0;
      }
      if (*(int *)(param_1 + 0x1b770) == 0) {
        *(undefined4 **)(param_1 + 0x1b770) = puVar3;
        *(undefined4 **)(param_1 + 0x1b778) = puVar3;
      }
      else {
        *(undefined4 **)(*(int *)(param_1 + 0x1b774) + 4) = puVar3;
      }
      *(undefined4 **)(param_1 + 0x1b774) = puVar3;
      *(int *)(param_1 + 0x1b77c) = *(int *)(param_1 + 0x1b77c) + 1;
    }
    puVar4 = (undefined1 *)*puVar2;
    if (puVar4 == (undefined1 *)0x0) {
      puVar4 = &DAT_005ea438;
    }
    FUN_0045bd10(puVar4,3,0x1020304);
    if (DAT_007c569c != 5) {
      cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_NetCo_005c5ce4,0x1347);
      if (cVar1 != '\0') {
        puVar4 = (undefined1 *)*puVar2;
        if (puVar4 == (undefined1 *)0x0) {
          puVar4 = &DAT_005ea438;
        }
        FUN_004d7aa0(&DAT_008ad25c,puVar4);
      }
    }
  }
  return;
}


