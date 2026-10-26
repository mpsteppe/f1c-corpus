// f1c  0x0049ba50  size=56
bool sub_49BA50()
{
  bool result; // al

  result = 0;
  if ( dword_7D0B64 > 0 )
    return (double)dword_7D0B64 * 0.050000001 > *(float *)(dword_7C54E0 + 14732) * *(float *)(dword_7C54E0 + 14724);
  return result;
}
