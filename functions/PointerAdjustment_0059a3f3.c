_DWORD *__thiscall sub_59A3F3(int this, int a2)
{
  _DWORD *result; // eax

  **(_DWORD **)(this + 44) -= a2;
  result = *(_DWORD **)(this + 28);
  *result += 2 * a2;
  return result;
}
