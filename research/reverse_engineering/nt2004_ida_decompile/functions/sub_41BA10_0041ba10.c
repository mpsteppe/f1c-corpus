void __stdcall sub_41BA10(int a1, int a2)
{
  int v2; // eax
  int v3; // ecx

  if ( dword_7688A0 )
  {
    if ( flt_7678BC != 0.0 )
    {
      if ( byte_6292D8 )
      {
        if ( sub_4633A0(&unk_764D70) != 1 && *(_BYTE *)(dword_75AACC + 17412) != 1 )
        {
          if ( (unsigned __int8)sub_42DBA0(&unk_62BF64) )
          {
            if ( dword_75AACC )
            {
              if ( !*(_DWORD *)(dword_75AACC + 20892) )
              {
                v2 = *(_DWORD *)(dword_75AACC + 20896);
                if ( (!v2 || v2 == 4) && dword_7D5DA4 != 2 )
                {
                  v3 = *(_DWORD *)(dword_75AACC + 20848);
                  if ( dword_7D74B8 - v3 > 0 )
                  {
                    switch ( a1 )
                    {
                      case 0:
                        if ( a2 )
                          sub_419480(2);
                        break;
                      case 1:
                        sub_419480(8);
                        break;
                      case 6:
                        if ( v3 + 1 < dword_7D74B8 )
                          sub_419480(4);
                        break;
                      case 7:
                        if ( a2 != 7 )
                          sub_419480(32);
                        break;
                      default:
                        return;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}
