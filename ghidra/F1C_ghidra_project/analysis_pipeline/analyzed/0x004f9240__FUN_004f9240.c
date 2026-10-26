// Function: FUN_004f9240 @ 004f9240
// Size (bytes): 200


int FUN_004f9240(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  iVar1 = DAT_008afe6c;
  iVar4 = 0;
  iVar3 = FUN_004f9150();
  iVar2 = param_1;
  if (0 < iVar3) {
    do {
      if (iVar4 != 0) {
        iVar3 = iVar4;
        if (iVar4 == iVar1) {
          iVar3 = 0;
        }
        FUN_004f9160(iVar3);
      }
      iVar5 = 0;
      iVar3 = FUN_004f9190();
      if (0 < iVar3) {
        do {
          FUN_004f91b0(iVar5,&param_1,&iStack_c,&iStack_8,&iStack_4);
          if ((((param_1 == iVar2) && (iStack_c == param_2)) && (iStack_8 == param_3)) &&
             (iStack_4 == param_4)) break;
          iVar5 = iVar5 + 1;
          iVar3 = FUN_004f9190();
        } while (iVar5 < iVar3);
      }
      iVar3 = FUN_004f9190();
      if (iVar5 < iVar3) {
        return iVar5;
      }
      iVar4 = iVar4 + 1;
      iVar3 = FUN_004f9150();
    } while (iVar4 < iVar3);
  }
  return -1;
}


