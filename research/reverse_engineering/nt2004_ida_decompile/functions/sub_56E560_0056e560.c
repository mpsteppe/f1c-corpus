char __thiscall sub_56E560(HINSTANCE *this)
{
  char result; // al

  result = 0;
  if ( dword_7E0818 )
  {
    DestroyWindow(dword_7E0818);
    UnregisterClassA(lpClassName, this[477]);
    dword_7E0818 = 0;
    return 1;
  }
  return result;
}
