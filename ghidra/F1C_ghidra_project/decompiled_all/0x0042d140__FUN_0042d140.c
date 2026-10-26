// Function: FUN_0042d140 @ 0042d140
// Strings:  [Begin Formation Lap, Begin Formation Lap]


void __thiscall FUN_0042d140(int param_1,int param_2)

{
  char *pcVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0xc) != param_2) {
    *(int *)(param_1 + 0xc) = param_2;
    if (((param_2 != 0) && (param_2 != 1)) && (param_2 != 2)) {
      FUN_004d2e20();
    }
    if (DAT_007c569c == 5) {
      switch(*(undefined4 *)(param_1 + 0xc)) {
      case 3:
        if (DAT_007cec78 != '\0') {
          iVar2 = FUN_00423a00(s_Begin_Formation_Lap_005c35b4,&DAT_005ec4cc);
          if (iVar2 != 0) {
            iVar2 = 0;
            do {
              pcVar1 = s_Begin_Formation_Lap_005c35b4 + iVar2;
              (&DAT_005ec4cc)[iVar2] = *pcVar1;
              iVar2 = iVar2 + 1;
            } while (*pcVar1 != '\0');
          }
          FUN_0045bd10(&DAT_005ec4cc,3,0x1020304);
        }
      case 0:
      case 2:
      case 4:
        iVar2 = 0;
        if (0 < DAT_005c329c) {
          do {
            FUN_004c6b60(0);
            iVar2 = iVar2 + 1;
          } while (iVar2 < DAT_005c329c);
        }
      }
    }
  }
  return;
}


