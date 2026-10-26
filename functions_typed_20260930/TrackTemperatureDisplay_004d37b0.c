int __thiscall sub_4D37B0(_DWORD *this)
{
  int *v2; // esi
  _DWORD *v3; // ecx
  int v5; // [esp+8h] [ebp-Ch]
  int v6; // [esp+Ch] [ebp-8h] BYREF
  int v7; // [esp+10h] [ebp-4h] BYREF

  FlagPropertyGetter(&v6, 2048);
  FlagPropertyGetter(&v7, 2048);
  v2 = (int *)((char *)&stru_5EC6D8 + 18624 * v6);
  if ( v7 != -11 )
  {
    AICommandMessageQueueDispatcher(v2, 5, 0);
    PitExitUnderRed((_BYTE *)v2 + 13004);
    if ( v2 == (int *)dword_7C54E8 )
    {
      pfnAPC(0);
      StateResetOnCondition(&dword_5EA510);
    }
    goto LABEL_11;
  }
  AICommandMessageQueueDispatcher(v2, 4, 0);
  PitEnterUnderRed((_BYTE *)v2 + 13004);
  if ( v2 == (int *)dword_7C54E8 )
    pfnAPC(1u);
  if ( fabs(dbl_8AFEA0 - flt_8AC4B0) <= 3.0 )
  {
LABEL_11:
    BufferEntryClear(this[5]);
    return 0;
  }
  if ( dword_83EE60 >= 1023 )
  {
    v3 = (_DWORD *)dword_8AAE64;
  }
  else
  {
    ++dword_83EE60;
    v3 = (_DWORD *)dword_8AAE64;
    dword_8AAE64 += 432;
  }
  *(float *)&v5 = dbl_8AFEA0;
  ProgressBarEventEncode(v3, 3, 7, 0, v2[4645], v5, 0);
  flt_8AC4B0 = dbl_8AFEA0;
  BufferEntryClear(this[5]);
  return 0;
}

