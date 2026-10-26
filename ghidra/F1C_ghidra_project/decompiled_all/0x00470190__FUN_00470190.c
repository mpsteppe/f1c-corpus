// Function: FUN_00470190 @ 00470190
// Strings:  [%i:%06.3f, %s, %s%s%s%s%i]


void FUN_00470190(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 local_124;
  undefined1 local_120 [32];
  undefined1 local_100 [256];
  
  FUN_00489cb0();
  if (0 < DAT_008ac488) {
    iVar2 = 0;
    iVar3 = 0;
    do {
      iVar1 = iVar2 + DAT_008ac490;
      FUN_0058815f(local_120,s__i__06_3f_005c6930,0,0,0);
      FUN_0058815f(local_100,s__s___s_s_s_s_i_005c6e1c,iVar1 + 0x144,iVar1 + 0x104,&DAT_005c692c,
                   local_120,&DAT_005c692c,local_124);
      FUN_00489600(local_100,0,0,0,0);
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x18c;
    } while (iVar3 < DAT_008ac488);
  }
  return;
}


