int __thiscall sub_4BCB40(char *String)
{
  int result; // eax

  _strupr(String);
  result = 0;
  if ( strcmp(String, aFrontJackUp) )
  {
    if ( !strcmp(String, aFrontJackDown) )
    {
      return 1;
    }
    else if ( !strcmp(String, aRearJackUp) )
    {
      return 2;
    }
    else if ( !strcmp(String, aRearJackDown) )
    {
      return 3;
    }
    else if ( !strcmp(String, aLollipopDown) )
    {
      return 4;
    }
    else if ( !strcmp(String, aLollipopUp) )
    {
      return 5;
    }
    else if ( !strcmp(String, aFuelIn) )
    {
      return 6;
    }
    else if ( !strcmp(String, aFuelOut) )
    {
      return 7;
    }
    else if ( !strcmp(String, aFrontLeftWheel) )
    {
      return 8;
    }
    else if ( !strcmp(String, aFrontRightWhee) )
    {
      return 9;
    }
    else if ( !strcmp(String, aRearLeftWheel) )
    {
      return 10;
    }
    else if ( !strcmp(String, aRearRightWheel) )
    {
      return 11;
    }
    else if ( !strcmp(String, aRearRightWheel_0) )
    {
      return 12;
    }
    else if ( !strcmp(String, a10secLollipopD) )
    {
      return 13;
    }
    else if ( !strcmp(String, a10secLollipopU) )
    {
      return 14;
    }
    else if ( !strcmp(String, a10secFmanFleft) )
    {
      return 15;
    }
    else if ( !strcmp(String, a10secNman) )
    {
      return 16;
    }
    else if ( !strcmp(String, a10secRman) )
    {
      return 17;
    }
    else if ( !strcmp(String, a10secRman2) )
    {
      return 18;
    }
    else if ( !strcmp(String, a10secSman) )
    {
      return 19;
    }
    else if ( !strcmp(String, a10secSman2) )
    {
      return 20;
    }
    else if ( !strcmp(String, a10secSman3) )
    {
      return 21;
    }
    else if ( !strcmp(String, a10secSman4) )
    {
      return 22;
    }
    else
    {
      return (strcmp(String, a10secStarterre) != 0) + 23;
    }
  }
  return result;
}
