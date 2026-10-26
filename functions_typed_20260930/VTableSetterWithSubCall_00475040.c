int __thiscall VTableSetterWithSubCall(LPVOID *this)
{
  *this = &off_5A42C0;
  return InitWithVTableCleanup(this);
}

