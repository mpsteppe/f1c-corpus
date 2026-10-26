// f1c  0x00424750  size=50
double sub_424750()
{
  if ( dword_7D01A0 >= 95 )
    return 1.0;
  else
    return (double)(dword_7D01A0 - 70) * 0.039999999 * 0.25 + 0.75;
}
