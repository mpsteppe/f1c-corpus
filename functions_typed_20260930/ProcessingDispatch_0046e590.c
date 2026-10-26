int __thiscall ProcessingDispatch(_DWORD *this)
{
  char *v2; // eax

  CleanupWrapper(&dword_7C73E8);
  v2 = UIListIndexedAccessor(this, 0);
  PathRegisterFieldSet(v2, 0x40000000);
  return 0;
}

