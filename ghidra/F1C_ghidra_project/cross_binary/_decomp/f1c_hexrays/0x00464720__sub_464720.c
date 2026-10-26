// f1c  0x00464720  size=19
unsigned __int8 __fastcall sub_464720(unsigned __int8 *a1, unsigned __int8 a2, unsigned __int8 a3)
{
  unsigned __int8 result; // al

  result = *a1;
  if ( *a1 < a2 || (a2 = a3, result > a3) )
    *a1 = a2;
  return result;
}
