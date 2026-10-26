// f1c  0x0041a720  size=415
void __stdcall sub_41A720(int a1, const char *a2)
{
  int v2; // esi
  float v3[8]; // [esp+Ch] [ebp-20h] BYREF

  if ( dword_7D0308 && flt_7CF3C8 != 0.0 )
  {
    if ( *(_DWORD *)(dword_7C54E8 + 18580) == *(_DWORD *)(a1 + 18580) )
    {
      if ( !a2 )
        return;
      if ( !strcmp(aSpeedingInPitl, a2) )
      {
        v2 = 153;
      }
      else if ( !strcmp(aCutTrack, a2) )
      {
        v2 = 151;
      }
      else if ( !strcmp(aJumpedStart, a2) )
      {
        v2 = 155;
      }
      else
      {
        if ( strcmp(aIgnoredBlueFla, a2) )
          return;
        v2 = 154;
        sub_418A20(flt_5EA618, 123);
        sub_418A20(flt_5EA618, 124);
        sub_418A20(flt_5EA618, 125);
      }
LABEL_23:
      sub_4144D0(v3);
      sub_4144F0(v3, v2, *(_DWORD *)(a1 + 18588), -1, -1, -1, -2.0, -2.0);
      sub_418560(flt_5EA618, v3);
      return;
    }
    if ( a2 && dword_7C56A8 != 8 )
    {
      if ( !strcmp(aSpeedingInPitl, a2) )
      {
        v2 = 256;
      }
      else if ( !strcmp(aCutTrack, a2) )
      {
        v2 = 253;
      }
      else if ( !strcmp(aJumpedStart, a2) )
      {
        v2 = 254;
      }
      else
      {
        if ( strcmp(aIgnoredBlueFla, a2) )
          return;
        v2 = 252;
      }
      goto LABEL_23;
    }
  }
}
