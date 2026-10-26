int sub_587B7F()
{
  int result; // eax

  InitCRTFloatConversionFunctionPointers();
  dword_8D3E44 = sub_58BCA6();
  result = TwoArgCallWrapper();
  __asm { fnclex }
  return result;
}
