// f1c  0x0049b900  size=76
int sub_49B900()
{
  return (int)(float)(sqrt(
                        *(float *)(dword_7C54E0 + 13560) * *(float *)(dword_7C54E0 + 13560)
                      + *(float *)(dword_7C54E0 + 13564) * *(float *)(dword_7C54E0 + 13564)
                      + *(float *)(dword_7C54E0 + 13568) * *(float *)(dword_7C54E0 + 13568))
                    * 3.5999999);
}
