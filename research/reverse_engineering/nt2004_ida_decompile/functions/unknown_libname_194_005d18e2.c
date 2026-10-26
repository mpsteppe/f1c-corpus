// Microsoft VisualC 2-14/net runtime
_DWORD *__thiscall unknown_libname_194(int this, int a2)
{
  _DWORD *result; // eax

  **(_DWORD **)(this + 48) -= a2;
  result = *(_DWORD **)(this + 32);
  *result += 2 * a2;
  return result;
}
