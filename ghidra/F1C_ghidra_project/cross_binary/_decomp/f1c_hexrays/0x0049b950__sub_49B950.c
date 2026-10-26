// f1c  0x0049b950  size=76
int sub_49B950()
{
  return (int)(float)(sqrt(
                        *(float *)(dword_7C54E0 + 13560) * *(float *)(dword_7C54E0 + 13560)
                      + *(float *)(dword_7C54E0 + 13564) * *(float *)(dword_7C54E0 + 13564)
                      + *(float *)(dword_7C54E0 + 13568) * *(float *)(dword_7C54E0 + 13568))
                    * 2.2369363);
}
