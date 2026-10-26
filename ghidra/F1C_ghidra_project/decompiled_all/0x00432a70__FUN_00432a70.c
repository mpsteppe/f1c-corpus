// Function: FUN_00432a70 @ 00432a70
// Strings:  [Track, Session, Classes]


undefined4 __thiscall FUN_00432a70(int param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 local_418 [640];
  undefined4 local_198;
  undefined1 local_194;
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180 [96];
  
  uVar1 = 1;
  if ((param_2 != (int *)0x0) && (*param_2 != 0)) {
    puVar3 = local_180;
    for (iVar2 = 0x60; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    local_198 = 0;
    local_184 = 0;
    local_18c = 0;
    local_188 = 0;
    local_194 = 1;
    iVar2 = FUN_00566cc0(local_180,0x180);
    while (iVar2 != 0) {
      iVar2 = FUN_005651b0();
      if (iVar2 == 0) {
        iVar2 = FUN_005654a0(PTR_s_Track_005c3f8c,local_418);
        if (iVar2 == 0) {
          iVar2 = FUN_005654a0(PTR_s_Classes_005c3f90,local_418);
          if (iVar2 == 0) {
            iVar2 = FUN_00565520(PTR_s_Session_005c3f94,local_418,0);
            if (iVar2 == 0) {
              iVar2 = FUN_005654a0(PTR_DAT_005c3f98,local_418);
              if (iVar2 != 0) {
                FUN_00566650(local_418);
              }
            }
            else {
              uVar1 = FUN_00587f59(local_418);
              *(undefined4 *)(param_1 + 0x10) = uVar1;
            }
          }
          else {
            FUN_00566650(local_418);
          }
        }
        else {
          FUN_00566650(local_418);
        }
      }
      else if (iVar2 == 1) break;
      iVar2 = FUN_00566cc0(local_180,0x180);
    }
    uVar1 = 0;
  }
  return uVar1;
}


