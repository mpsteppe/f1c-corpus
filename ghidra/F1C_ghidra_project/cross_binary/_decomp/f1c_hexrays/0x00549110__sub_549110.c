// f1c  0x00549110  size=85
int __stdcall sub_549110(_DWORD *a1)
{
  if ( a1[17] )
    sub_549110(a1[17]);
  if ( a1[16] && a1[19] )
    sub_549110(a1[19]);
  if ( sub_54A770(a1) )
    return -1;
  sub_54A710(a1);
  sub_587BCF(a1);
  return 0;
}
