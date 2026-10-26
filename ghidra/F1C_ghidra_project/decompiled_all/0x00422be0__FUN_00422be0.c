// Function: FUN_00422be0 @ 00422be0
// Strings:  [Php/\, Ph`/\, PhP/\, PhD/\, Ph8/\, Ph(/\, VERSION=%f]


undefined4 __thiscall FUN_00422be0(undefined4 *param_1,undefined1 *param_2)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  
  if ((param_2 == (undefined1 *)0x0) &&
     (param_2 = (undefined1 *)*param_1, param_2 == (undefined1 *)0x0)) {
    param_2 = &DAT_005ea438;
  }
  FUN_0058ba36(param_2,0x80);
  iVar1 = FUN_00587db0(param_2,&DAT_005c302c);
  if (iVar1 == 0) {
    return 0;
  }
  FUN_005887b1(iVar1,s__COMPONENTS__005c301c);
  puVar2 = (undefined1 *)param_1[2];
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  FUN_005887b1(iVar1,s_SEASONDIR__s_005c300c,puVar2);
  puVar2 = (undefined1 *)param_1[4];
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  FUN_005887b1(iVar1,s_SOUNDDIR__s_005c2ffc,puVar2);
  puVar2 = (undefined1 *)param_1[6];
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  FUN_005887b1(iVar1,s_VEHICLESOUND__s_005c2fe8,puVar2);
  puVar2 = (undefined1 *)param_1[8];
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  FUN_005887b1(iVar1,s_OPTIONSANIM__s_005c2fd8,puVar2);
  puVar2 = (undefined1 *)param_1[10];
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  FUN_005887b1(iVar1,s_OPTIONSFLAGS__s_005c2fc4,puVar2);
  puVar2 = (undefined1 *)param_1[0xc];
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  FUN_005887b1(iVar1,s_OPTIONSSOUNDS__s_005c2fb0,puVar2);
  puVar2 = (undefined1 *)param_1[0xe];
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  FUN_005887b1(iVar1,s_OPTIONSDIR__s_005c2fa0,puVar2);
  puVar2 = (undefined1 *)param_1[0x10];
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  FUN_005887b1(iVar1,s_REPLAYDIR__s_005c2f90,puVar2);
  puVar2 = (undefined1 *)param_1[0x12];
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  FUN_005887b1(iVar1,s_MOVIEDIR__s_005c2f80,puVar2);
  puVar2 = (undefined1 *)param_1[0x14];
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  FUN_005887b1(iVar1,s_TRACKSDIR__s_005c2f70,puVar2);
  puVar2 = (undefined1 *)param_1[0x16];
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  FUN_005887b1(iVar1,s_VEHICLESDIR__s_005c2f60,puVar2);
  puVar2 = (undefined1 *)param_1[0x18];
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  FUN_005887b1(iVar1,s_DRIVERSDIR__s_005c2f50,puVar2);
  puVar2 = (undefined1 *)param_1[0x1a];
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  FUN_005887b1(iVar1,s_LOGDIR__s_005c2f44,puVar2);
  puVar2 = (undefined1 *)param_1[0x1c];
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  FUN_005887b1(iVar1,s_SAVEDIR__s_005c2f38,puVar2);
  puVar2 = (undefined1 *)param_1[0x1e];
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  FUN_005887b1(iVar1,s_MUSICDIR__s_005c2f28,puVar2);
  puVar2 = (undefined1 *)param_1[0x24];
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  FUN_005887b1(iVar1,s_CAMERAEDITORRESOURCEDIR__s_005c2f0c,puVar2);
  uVar3 = FUN_00423060();
  FUN_005887b1(iVar1,s_GRIDSIZE__d_005c2efc,uVar3);
  FUN_005887b1(iVar1,s_CPURATING__d_005c2eec,param_1[0x32]);
  FUN_005887b1(iVar1,s_SYSTEMRAM__d_005c2edc,param_1[0x33]);
  FUN_005887b1(iVar1,s_VIDEORAM__d_005c2ecc,param_1[0x34]);
  FUN_005887b1(iVar1,s_OBJDETAIL__d_005c2ebc,param_1[0x36]);
  FUN_005887b1(iVar1,s_TEXDETAIL__d_005c2eac,param_1[0x37]);
  puVar2 = (undefined1 *)param_1[0x2c];
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  FUN_005887b1(iVar1,s_VIDEOGUID__s_005c2e9c,puVar2);
  FUN_005887b1(iVar1,s_VIDEODRIVER__d_005c2e8c,param_1[0x2e]);
  FUN_005887b1(iVar1,s_VIDEOMODE__d_005c2e7c,param_1[0x2f]);
  FUN_005887b1(iVar1,s_VIDEOREFRESH__d_005c2e68,param_1[0x30]);
  FUN_005887b1(iVar1,s_WINDOWEDMODE__d_005c2e54,*(undefined1 *)(param_1 + 0x35));
  FUN_005887b1(iVar1,s_RUNBENCHMARKS__d_005c2e40,*(undefined1 *)((int)param_1 + 0xd5));
  FUN_005887b1(iVar1,s_FSAA__d_005c2e34,param_1[0x38]);
  FUN_005887b1(iVar1,s_VSYNC__d_005c2e28,*(undefined1 *)((int)param_1 + 0xd6));
  FUN_005887b1(iVar1,s_VBSTRATEGY__d_005c2e18,param_1[0x39]);
  FUN_005887b1(iVar1,s__INSTALL__005c2e0c);
  puVar2 = (undefined1 *)param_1[0x20];
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  FUN_005887b1(iVar1,s_INSTALLFROM__s_005c2dfc,puVar2);
  puVar2 = (undefined1 *)param_1[0x22];
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  FUN_005887b1(iVar1,s_INSTALLTO__s_005c2dec,puVar2);
  FUN_005887b1(iVar1,s__AUTOLAUNCH__005c2ddc);
  FUN_00404d10();
  uVar3 = FUN_00404d00();
  FUN_005887b1(iVar1,s_MODE__s_005c2dd0,uVar3);
  FUN_00404d20();
  uVar3 = __ftol();
  FUN_005887b1(iVar1,s_LAUNCHTIME__d_005c2dc0,uVar3);
  FUN_005887b1(iVar1,s__VERSION__005c2db4);
  FUN_005887b1(iVar1,s_VERSION__f_005c2da8,(double)(float)param_1[0x3a]);
  FUN_00587d02(iVar1);
  return 1;
}


