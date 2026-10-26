int __thiscall VTableSetInitCall(LPVOID *this)
{
  *this = &off_59FCB8;
  return InitWithVTableCleanup(this);
}

