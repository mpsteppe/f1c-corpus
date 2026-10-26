_DWORD *__thiscall sub_59A428(int this, int a2)
{
  _DWORD *result; // eax

  **(_DWORD **)(this + 48) -= a2;
  result = *(_DWORD **)(this + 32);
  *result += 2 * a2;
  return result;
}
