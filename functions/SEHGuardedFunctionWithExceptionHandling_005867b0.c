LPVOID __thiscall sub_5867B0(LPVOID *this)
{
  DualPointerFree(this + 5);
  return FreeIfNonNull(this + 2);
}
