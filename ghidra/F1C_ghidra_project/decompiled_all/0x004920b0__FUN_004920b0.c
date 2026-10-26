// Function: FUN_004920b0 @ 004920b0
// Strings:  [Could Not Load MAS file %s (line %d), SOURCE_MAS]


undefined4 __fastcall FUN_004920b0(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined1 local_100 [256];
  
  FUN_00535390(0);
  iVar3 = 0x20;
  iVar2 = FUN_00491fb0();
  while (iVar2 != 0) {
    iVar2 = FUN_005654a0(s_SOURCE_MAS_005cc524,local_100);
    if ((iVar2 != 0) && (cVar1 = FUN_004979f0(local_100), cVar1 == '\0')) {
      FUN_0058815f(&DAT_007cdcf0,s_Could_Not_Load_MAS_file__s__line_005cc4fc,local_100,
                   *(undefined4 *)(param_1 + 0x18c));
      FUN_00493c80(1,&DAT_007cdcf0);
    }
    iVar3 = iVar3 + -1;
    if (iVar3 < 0) break;
    iVar2 = FUN_00491fb0();
  }
  FUN_00535390(0);
  return 0;
}


