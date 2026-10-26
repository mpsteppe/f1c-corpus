int sub_42EBB0()
{
  int v0; // edi
  int v1; // esi
  signed int i; // esi
  char v4; // [esp+0h] [ebp-8h]

  if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 2, (int)aDDevNascar2004_3, 1268) )
    sub_500FE0((int)&unk_7D7920, aEnteredDynmanP, v4);
  v0 = 0;
  if ( dword_5FD344 > 0 )
  {
    v1 = 0;
    do
    {
      sub_4EE280((char *)off_5FD348 + v1);
      ++v0;
      v1 += 25304;
    }
    while ( v0 < dword_5FD344 );
  }
  for ( i = 0; i < (int)NumOfElements; ++i )
    sub_4EE280(dword_75AAD0[i]);
  NumOfElements = 0;
  sub_4414C0(&dbl_75E930);
  sub_42DD20();
  return sub_416B70(dword_6291D0);
}
