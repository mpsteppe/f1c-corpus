bool __thiscall sub_4BC340(_DWORD *this)
{
  int v1; // eax
  bool result; // al

  result = dword_7C569C == 5
        && ((v1 = this[12], v1 != 1) && v1 != 3 || dword_7CEF84 && v1 != 3 && dword_7C56A4 == 5)
        && (dword_7C56A8 == 5 || dword_7C56A8 == 6 || dword_7C56A8 == 8);
  return result;
}

