int __thiscall sub_4A24D0(LPCSTR lpSrcStr)
{
  int result; // eax

  sub_589901(lpSrcStr);
  result = 0;
  if ( strcmp(lpSrcStr, aFrontJackUp) )
  {
    if ( !strcmp(lpSrcStr, aFrontJackDown) )
    {
      return 1;
    }
    else if ( !strcmp(lpSrcStr, aRearJackUp) )
    {
      return 2;
    }
    else if ( !strcmp(lpSrcStr, aRearJackDown) )
    {
      return 3;
    }
    else if ( !strcmp(lpSrcStr, aLollipopDown) )
    {
      return 4;
    }
    else if ( !strcmp(lpSrcStr, aLollipopUp) )
    {
      return 5;
    }
    else if ( !strcmp(lpSrcStr, aFuelIn) )
    {
      return 6;
    }
    else if ( !strcmp(lpSrcStr, aFuelOut) )
    {
      return 7;
    }
    else if ( !strcmp(lpSrcStr, aFrontLeftWheel) )
    {
      return 8;
    }
    else if ( !strcmp(lpSrcStr, aFrontRightWhee) )
    {
      return 9;
    }
    else if ( !strcmp(lpSrcStr, aRearLeftWheel) )
    {
      return 10;
    }
    else if ( !strcmp(lpSrcStr, aRearRightWheel) )
    {
      return 11;
    }
    else if ( !strcmp(lpSrcStr, aRearRightWheel_0) )
    {
      return 12;
    }
    else if ( !strcmp(lpSrcStr, a10secLollipopD) )
    {
      return 13;
    }
    else if ( !strcmp(lpSrcStr, a10secLollipopU) )
    {
      return 14;
    }
    else if ( !strcmp(lpSrcStr, a10secFmanFleft) )
    {
      return 15;
    }
    else if ( !strcmp(lpSrcStr, a10secNman) )
    {
      return 16;
    }
    else if ( !strcmp(lpSrcStr, a10secRman) )
    {
      return 17;
    }
    else if ( !strcmp(lpSrcStr, a10secRman2) )
    {
      return 18;
    }
    else if ( !strcmp(lpSrcStr, a10secSman) )
    {
      return 19;
    }
    else if ( !strcmp(lpSrcStr, a10secSman2) )
    {
      return 20;
    }
    else if ( !strcmp(lpSrcStr, a10secSman3) )
    {
      return 21;
    }
    else if ( !strcmp(lpSrcStr, a10secSman4) )
    {
      return 22;
    }
    else
    {
      return (strcmp(lpSrcStr, a10secStarterre) != 0) + 23;
    }
  }
  return result;
}

