// Function: FUN_0052e1d0 @ 0052e1d0
// Strings:  [D:\Dev\AudioDev\Shared\Engine\Dev\LbMpeg.cpp, CMpegFilePlayer::Open GetHeader() failed 2, CMpegFilePlayer::Open GetHeader() failed 1]


undefined4 __thiscall FUN_0052e1d0(int *param_1,uint param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  if ((char)param_1[0x93b] != '\0') {
    FUN_0052e320();
  }
  *(undefined1 *)(param_1 + 0x93b) = 1;
  param_1[0x929] = (int)param_1 + 0x2533U & 0xffffffc0;
  if (param_2 == 0) {
    iVar1 = (**(code **)(*param_1 + 0xc))();
    if (iVar1 == 0) goto LAB_0052e26a;
    (*(code *)PTR_FUN_005da714)(s_AUDIO_ASSERT_________005da5e0);
    pcVar3 = s_CMpegFilePlayer__Open_GetHeader__005da698;
    uVar2 = 0x6d0;
  }
  else {
    iVar1 = FUN_0052de40(param_2 >> 0x18 | (param_2 & 0xff0000) >> 8 | (param_2 & 0xff00) << 8 |
                         param_2 << 0x18);
    if (iVar1 == 0) {
LAB_0052e26a:
      FUN_0052da10();
      FUN_0052de60();
      FUN_0052e2f0();
      iVar1 = FUN_0052e080(param_1[0x935] + param_3,param_1[0x938],
                           (param_1[0x936] * param_1[0x938] + param_1[0x937]) * param_1[0x935]);
      param_1[0x92c] = param_1[0x923] * iVar1;
      param_1[0x928] = iVar1;
      (**(code **)(*(int *)param_1[0xb4d] + 0xc))(param_1[0xb4e],0);
      *(undefined1 *)(param_1 + 0xb4f) = 1;
      return 0;
    }
    (*(code *)PTR_FUN_005da714)(s_AUDIO_ASSERT_________005da5e0);
    pcVar3 = s_CMpegFilePlayer__Open_GetHeader__005da6c4;
    uVar2 = 0x6c8;
  }
  (*(code *)PTR_FUN_005da714)
            (s__s__d_____s_005da564,s_D__Dev_AudioDev_Shared_Engine_De_005da574,uVar2,pcVar3);
  (*(code *)PTR_FUN_005da718)();
  return 0xffffffff;
}


