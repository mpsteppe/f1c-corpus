_DWORD *__thiscall std::basic_streambuf<unsigned short>::gbump(int this, int a2)
{
  _DWORD *result; // eax

  **(_DWORD **)(this + 44) -= a2;
  result = *(_DWORD **)(this + 28);
  *result += 2 * a2;
  return result;
}
