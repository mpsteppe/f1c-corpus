void __thiscall sub_4F3240(char *this, int a2, int a3, int a4)
{
  double *v4; // esi
  double *v5; // ebx
  double *v6; // ebp

  v4 = (double *)&this[24 * a3];
  v5 = v4 + 2;
  v6 = v4 + 1;
  if ( sub_565AA0(a4, v4, v4 + 1, v4 + 2, 0) )
  {
    switch ( a3 )
    {
      case 0:
        if ( *v4 > 0.0 && dword_7C569C != 5 )
        {
          if ( StringSplitLoop(dword_8AD25C, 1, (int)aDDevF119992002_7, 351) )
            DebugLogWrite((int)dword_8AD25C, (int)aXForceAppliedW);
        }
        break;
      case 1:
        if ( *v4 < 0.0 && dword_7C569C != 5 && StringSplitLoop(dword_8AD25C, 1, (int)aDDevF119992002_7, 356) )
          DebugLogWrite((int)dword_8AD25C, (int)aXForceAppliedW_0);
        break;
      case 2:
        if ( *v6 > 0.0 && dword_7C569C != 5 && StringSplitLoop(dword_8AD25C, 1, (int)aDDevF119992002_7, 361) )
          DebugLogWrite((int)dword_8AD25C, (int)aYForceAppliedW);
        break;
      case 3:
        if ( *v6 < 0.0 && dword_7C569C != 5 && StringSplitLoop(dword_8AD25C, 1, (int)aDDevF119992002_7, 366) )
          DebugLogWrite((int)dword_8AD25C, (int)aYForceAppliedW_0);
        break;
      case 4:
        if ( *v5 > 0.0 && dword_7C569C != 5 && StringSplitLoop(dword_8AD25C, 1, (int)aDDevF119992002_7, 371) )
          DebugLogWrite((int)dword_8AD25C, (int)aZForceAppliedW);
        break;
      case 5:
        if ( *v5 < 0.0 && dword_7C569C != 5 && StringSplitLoop(dword_8AD25C, 1, (int)aDDevF119992002_7, 376) )
          DebugLogWrite((int)dword_8AD25C, (int)aZForceAppliedW_0);
        break;
      default:
        return;
    }
  }
}
