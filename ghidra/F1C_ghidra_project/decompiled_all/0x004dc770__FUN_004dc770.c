// Function: FUN_004dc770 @ 004dc770
// Strings:  [Unable to adjust texture for material: %s, tex0=%s, tex1=%s, tex2=%s, D:\dev\F1_1999_2002\Source\util.cpp]


undefined4 __thiscall
FUN_004dc770(int param_1,char *param_2,char *param_3,char *param_4,undefined4 param_5)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  char local_300;
  undefined4 local_2ff;
  undefined1 local_201;
  char local_200;
  undefined4 local_1ff;
  undefined1 local_101;
  char local_100;
  undefined4 local_ff;
  undefined1 local_1;
  
  if (param_1 != 0) {
    iVar2 = FUN_004dc430();
    if (iVar2 != 0) {
      iVar2 = FUN_00548890(param_1);
      if (iVar2 != 0) {
        if (param_2 != (char *)0x0) {
          iVar2 = FUN_004dc450(param_2,param_5);
          if (iVar2 == 0) {
            return 0;
          }
        }
        if (param_3 != (char *)0x0) {
          iVar2 = FUN_004dc450(param_3,param_5);
          if (iVar2 == 0) {
            return 1;
          }
        }
        if (param_4 != (char *)0x0) {
          iVar2 = FUN_004dc450(param_4,param_5);
          if (iVar2 == 0) {
            return 2;
          }
        }
        local_100 = DAT_005ea438;
        puVar3 = &local_ff;
        for (iVar2 = 0x3f; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar3 = 0;
          puVar3 = puVar3 + 1;
        }
        *(undefined2 *)puVar3 = 0;
        *(undefined1 *)((int)puVar3 + 2) = 0;
        local_200 = DAT_005ea438;
        puVar3 = &local_1ff;
        for (iVar2 = 0x3f; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar3 = 0;
          puVar3 = puVar3 + 1;
        }
        *(undefined2 *)puVar3 = 0;
        *(undefined1 *)((int)puVar3 + 2) = 0;
        local_300 = DAT_005ea438;
        puVar3 = &local_2ff;
        for (iVar2 = 0x3f; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar3 = 0;
          puVar3 = puVar3 + 1;
        }
        *(undefined2 *)puVar3 = 0;
        *(undefined1 *)((int)puVar3 + 2) = 0;
        if (param_2 != (char *)0x0) {
          _strncpy(&local_100,param_2,0xff);
          local_1 = 0;
        }
        if (param_3 != (char *)0x0) {
          _strncpy(&local_200,param_3,0xff);
          local_101 = 0;
        }
        if (param_4 != (char *)0x0) {
          _strncpy(&local_300,param_4,0xff);
          local_201 = 0;
        }
        cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_util__005d4be0,0x109);
        if (cVar1 != '\0') {
          FUN_004d7aa0(&DAT_008ad25c,s_Unable_to_adjust_texture_for_mat_005d4b98,param_1,&local_100,
                       &local_200,&local_300);
        }
        return 0xffffffff;
      }
    }
  }
  return 0xffffffff;
}


