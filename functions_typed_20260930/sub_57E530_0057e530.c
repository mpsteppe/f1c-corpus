char __thiscall sub_57E530(HINSTANCE *this)
{
  char result; // al

  result = 0;
  if ( dword_8D3E28 )
  {
    DestroyWindow(dword_8D3E28);
    UnregisterClassA(lpClassName, this[477]);
    dword_8D3E28 = 0;
    return 1;
  }
  return result;
}

