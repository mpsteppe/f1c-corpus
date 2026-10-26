// Function: FUN_00464290 @ 00464290
// Strings:  [D:\dev\F1_1999_2002\Source\NetComm.cpp, Entering "SynchronizeWithServer()"]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00464290(int *param_1)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  
  iVar3 = *param_1;
  if (*(int *)(iVar3 + 0x3fc4) == 0) {
    return;
  }
  if (*(char *)(iVar3 + 0x28) == '\0') {
    *(undefined1 *)(iVar3 + 0x28) = 1;
    iVar3 = 0;
    do {
      thunk_FUN_00500170();
      iVar3 = iVar3 + 0x368;
    } while (iVar3 < 0x16240);
  }
  else {
    FUN_00460c60();
    FUN_00460cb0(1);
    if (*(int *)(*param_1 + 0x3fc4) == 3) {
      if ((DAT_007c569c != 5) &&
         (cVar2 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_NetCo_005c5ce4,0x1ec5), cVar2 != '\0')
         ) {
        FUN_004d7aa0(&DAT_008ad25c,s_Entering__SynchronizeWithServer__005c6634);
      }
      FUN_0045f390();
    }
  }
  uVar1 = _DAT_0059f0a0;
  iVar3 = *param_1;
  if ((*(int *)(iVar3 + 0x3fc4) == 2) || (*(int *)(iVar3 + 0x3fc4) == 1)) {
    if ((DAT_007c56a4 == 7) || ((DAT_007d105c != '\0' && (DAT_007c56a4 == 5)))) {
      FUN_0057a570(0);
    }
    else {
      FUN_0057a570(1);
    }
  }
  else {
    *(undefined1 *)(iVar3 + 0x14) = 1;
    *(undefined4 *)(iVar3 + 0x10) = uVar1;
    *(undefined4 *)(*param_1 + 0x390) = DAT_0059f0b8;
  }
  *(undefined4 *)(*param_1 + 0x388) = 0;
  *(undefined4 *)(*param_1 + 0x380) = 0;
  FUN_0045c8b0(1);
  FUN_0045d4c0();
  return;
}


