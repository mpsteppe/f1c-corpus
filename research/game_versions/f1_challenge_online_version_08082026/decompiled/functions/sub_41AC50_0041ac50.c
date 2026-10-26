void __stdcall sub_41AC50(_DWORD *a1, int a2)
{
  int v2; // eax
  float v3[8]; // [esp+4h] [ebp-20h] BYREF

  if ( dword_7D0308 )
  {
    if ( flt_7CF3C8 != 0.0 )
    {
      if ( a1 )
      {
        if ( dword_7C56A8 != 8 && dword_7C56A4 == 7 )
        {
          sub_4144D0(v3);
          if ( (!dword_7C54E8 || (_DWORD *)dword_7C54E8 != a1) && !a1[4121] )
          {
            if ( a2 )
            {
              if ( a2 == 2 )
              {
                switch ( a1[3711] )
                {
                  case 0:
                  case 1:
                    v2 = 212;
                    break;
                  case 2:
                    v2 = 213;
                    break;
                  case 3:
                    v2 = 214;
                    break;
                  case 4:
                    v2 = 215;
                    break;
                  case 5:
                    v2 = 216;
                    break;
                  case 6:
                    v2 = 217;
                    break;
                  default:
                    v2 = 211;
                    break;
                }
              }
              else
              {
                if ( a2 != 3 )
                  return;
                v2 = 220;
              }
            }
            else
            {
              v2 = 208;
            }
            sub_4144F0(v3, v2, a1[4647], -1, -1, -1, -2.0, -2.0);
            sub_418560(flt_5EA618, v3);
          }
        }
      }
    }
  }
}
