// f1c  0x004a0d50  size=62
int __stdcall sub_4A0D50(int a1)
{
  int result; // eax

  if ( sub_587C20(a1, aAltosc) )
    byte_7CE268 = 1;
  result = sub_587C20(a1, aSkipoptions);
  if ( result )
    dword_7CE264 = 2;
  return result;
}
