void __thiscall sub_4B4E70(_DWORD *this, char a2)
{
  int v3; // eax

  switch ( dword_765E70 )
  {
    case 0:
    case 1:
    case 3:
      v3 = this[5];
      if ( v3 )
      {
        if ( this[7] )
        {
          if ( this[2] )
          {
            sub_59FE60(0.0, 0.0, *(_DWORD *)(v3 + 16), 0.0, 0.0, 1.0, 1.0, 0, 0);
            if ( !a2 )
            {
              if ( dword_765E70 )
              {
                if ( dword_765E70 == 3 )
                {
                  if ( this[3] )
                    sub_4B5740(this);
                }
              }
              else
              {
                switch ( dword_75CBB0 )
                {
                  case 0:
                  case 1:
                  case 2:
                  case 3:
                  case 4:
                  case 5:
                    sub_4B5170(this);
                    break;
                  case 6:
                    sub_4B5350(this);
                    break;
                  case 7:
                    sub_4B4F80(this);
                    break;
                  case 8:
                    nullsub_6(this);
                    break;
                  default:
                    return;
                }
              }
            }
          }
        }
      }
      break;
    case 2:
      sub_4B5400(a2);
      break;
    default:
      return;
  }
}
