// f1c  0x0042c3b0  size=138
int sub_42C3B0()
{
  int v0; // esi
  int result; // eax

  if ( (unsigned __int8)sub_4D7A50(2, aDDevF119992002_12, 623) )
    sub_4D7AA0(&unk_8AD25C, aEnteredDynmanR);
  v0 = 0;
  dword_7C5694 = 0;
  dword_7C5698 = 0;
  sub_4333E0(&dword_7C73E8);
  if ( dword_5C329C > 0 )
  {
    do
    {
      sub_4C6D90(1);
      ++v0;
    }
    while ( v0 < dword_5C329C );
  }
  sub_410890(dword_5EA560);
  dword_7C54DC = dword_7C54E4;
  result = dword_7C54F0[dword_7C54E4];
  dword_7C54E0 = result;
  return result;
}
