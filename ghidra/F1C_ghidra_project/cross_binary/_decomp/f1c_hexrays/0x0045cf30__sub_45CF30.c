// f1c  0x0045cf30  size=22
char __fastcall sub_45CF30(char *a1)
{
  char result; // al

  for ( result = *a1; result; ++a1 )
  {
    if ( result == 92 )
      *a1 = 95;
    result = a1[1];
  }
  return result;
}
