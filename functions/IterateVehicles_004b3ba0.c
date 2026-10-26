int sub_4B3BA0()
{
  int result; // eax
  int i; // esi

  result = dword_5C329C;
  for ( i = 0; i < dword_5C329C; ++i )
  {
    TireTemperatureSimStep(dword_7C54F0[i]);
    result = dword_5C329C;
  }
  return result;
}
