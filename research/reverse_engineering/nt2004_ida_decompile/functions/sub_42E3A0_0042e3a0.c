int sub_42E3A0()
{
  int v0; // esi
  int v1; // edi
  signed int i; // esi
  int result; // eax
  char v4; // [esp+0h] [ebp-4h]

  if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 2, (int)aDDevNascar2004_3, 921) )
    sub_500FE0((int)&unk_7D7920, aEnteredDynmanR, v4);
  dword_75AB94 = 0;
  dword_75AB98 = 0;
  sub_41F400(flt_62BC28);
  if ( !(unsigned __int8)sub_463490(&unk_764D70) )
    sub_4BF870(0);
  sub_436190(&dword_75E8F0);
  v0 = 0;
  if ( dword_5FD344 > 0 )
  {
    v1 = 0;
    do
    {
      sub_4EE160(COERCE_FLOAT(1));
      ++v0;
      v1 += 25304;
    }
    while ( v0 < dword_5FD344 );
  }
  sub_4BBDC0(dword_75CBB0 == 7);
  for ( i = 0; i < (int)NumOfElements; ++i )
    sub_4EE160(COERCE_FLOAT(1));
  sub_417960(dword_6291D0);
  result = sub_42DB40(dword_75AAC8);
  if ( dword_75ABA0 == 2 )
  {
    result = sub_42F350();
    dword_75ABA0 = 1;
  }
  return result;
}
