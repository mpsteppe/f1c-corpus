int __thiscall sub_4FA640(void *this)
{
  if ( sub_4D7A50(dword_8AD25C, 2, (int)aDDevF119992002_26, 1136) )
    sub_4D7AA0((int)dword_8AD25C, (int)aEnteredVidmanR);
  sub_42D210(&dword_7C569C, 0);
  switch ( dword_7C56A4 )
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
      sub_54A200(64, 0);
      sub_54A200(128, 1);
      goto LABEL_6;
    case 5:
      sub_54A200(64, 1);
      sub_54A200(128, 0);
LABEL_6:
      sub_54A200(256, 1);
      break;
    case 6:
    case 7:
      sub_54A200(64, 1);
      sub_54A200(128, 1);
      sub_54A200(256, 0);
      if ( dword_7C56A4 == 7
        && dword_8AB6E4 != 2
        && !sub_404F10(&dword_5EA43C)
        && byte_7CE254
        && !sub_461DB0(dword_7CD25C) )
      {
        sub_42D210(&dword_7C569C, 1);
      }
      break;
    default:
      sub_54A200(64, 0);
      sub_54A200(128, 0);
      sub_54A200(256, 0);
      break;
  }
  sub_4F9FC0(this, 0.0);
  dbl_8AFEA8 = 0.0;
  dword_8AFE84 = 0;
  sub_4F8F10(&dword_8AFCA8, dword_8AFCAC);
  return sub_4F9F70(0);
}
