// Function: FUN_004336f0 @ 004336f0
// Size (bytes): 384


void __thiscall FUN_004336f0(int *param_1,int param_2)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  char *_Source;
  char local_100 [128];
  undefined1 local_80 [128];
  
  if ((param_2 < 0) || (DAT_005c329c <= param_2)) {
    param_2 = 0;
    iVar3 = DAT_005c329c;
  }
  else {
    iVar3 = param_2 + 1;
  }
  FUN_00433890(local_100,0x80);
  do {
    if (iVar3 <= param_2) {
      return;
    }
    iVar1 = (&DAT_007c54f0)[param_2];
    if (*(int *)(iVar1 + 13000) == 0) {
      FUN_00432df0(&DAT_007ce498);
      FUN_00568540();
      iVar4 = FUN_004339e0(local_80,0x80);
      if (iVar4 == 0) {
        FUN_00566650(local_80);
        cVar2 = FUN_00568b00();
        if (cVar2 == '\0') {
          puVar5 = (undefined1 *)param_1[4];
          if (puVar5 == (undefined1 *)0x0) {
            puVar5 = &DAT_005ea438;
          }
          FUN_00433d60(puVar5);
          goto LAB_004337f2;
        }
      }
      else {
LAB_004337f2:
        FUN_00566650(&DAT_005ea438);
      }
      puVar5 = (undefined1 *)param_1[4];
      if (puVar5 == (undefined1 *)0x0) {
        puVar5 = &DAT_005ea438;
      }
      FUN_00566650(puVar5);
      _Source = (char *)*param_1;
      if (_Source == (char *)0x0) {
        _Source = &DAT_005ea438;
      }
      _strncpy((char *)(iVar1 + 0x4794),_Source,0xff);
      *(undefined1 *)(iVar1 + 0x4893) = 0;
      puVar5 = (undefined1 *)*param_1;
      if (puVar5 == (undefined1 *)0x0) {
        puVar5 = &DAT_005ea438;
      }
      FUN_00433ed0(puVar5,0);
    }
    else {
      _strncpy((char *)(iVar1 + 0x4794),local_100,0xff);
      *(undefined1 *)(iVar1 + 0x4893) = 0;
    }
    param_2 = param_2 + 1;
  } while( true );
}


