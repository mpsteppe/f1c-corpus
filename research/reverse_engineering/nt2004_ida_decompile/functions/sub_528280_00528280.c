int __thiscall sub_528280(void *this)
{
  int result; // eax

  if ( sub_500F90(&unk_7D7920, 2, aDDevNascar2004_26, 1271) )
    sub_500FE0((int)&unk_7D7920, aEnteredVidmanR);
  sub_42FA50(&dword_75CBA8, 0);
  switch ( dword_75CBB0 )
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
      sub_595470(64, 0);
      sub_595470(128, 1);
      goto LABEL_6;
    case 5:
      sub_595470(64, 1);
      sub_595470(128, 0);
LABEL_6:
      sub_595470(256, 1);
      break;
    case 6:
    case 7:
      sub_595470(64, 1);
      sub_595470(128, 1);
      sub_595470(256, 0);
      if ( dword_75CBB0 == 7
        && dword_7D5DA4 != 2
        && !sub_405BF0(&dword_629124)
        && byte_76617C
        && !sub_463490(dword_764D70) )
      {
        sub_42FA50(&dword_75CBA8, 1);
      }
      break;
    default:
      sub_595470(64, 0);
      sub_595470(128, 0);
      sub_595470(256, 0);
      break;
  }
  if ( (dword_75CBAC & 1) != 0 )
    sub_5279A0(this, 0.0, 1);
  dword_7DA9AC = 0;
  sub_526830(&dword_7DA7C8, dword_7DA7CC);
  result = sub_527950(dword_7DA9A8 != 0);
  dword_7DA9B4 = 0;
  flt_7DA9B0 = 0.0;
  return result;
}
