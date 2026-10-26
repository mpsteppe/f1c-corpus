int __thiscall sub_53C4D0(void *this)
{
  void *v1; // esi
  void *v3; // esi
  void *v4; // esi

  v1 = (void *)dword_8B8F2C;
  if ( dword_8B8F2C )
  {
    EmptyStub_7470(dword_8B8F2C);
    FreeWrapper_7bcf(v1);
    dword_8B8F2C = 0;
  }
  ArrayOfPointersCleanupWithFreeLoop(this);
  ObjectReleaseWithVtableCall(&dword_8B78A0);
  v3 = (void *)dword_8B8F04;
  if ( dword_8B8F04 )
  {
    EmptyStub_7470(dword_8B8F04);
    FreeWrapper_7bcf(v3);
    dword_8B8F04 = 0;
  }
  EmptyStub_0170();
  EmptyStub_0170();
  if ( dword_8B8F18 )
  {
    FreeWrapper_7bcf((LPVOID)dword_8B8F18);
    dword_8B8F18 = 0;
  }
  v4 = (void *)dword_8B8F1C;
  if ( dword_8B8F1C )
  {
    sub_53AD50((void *)dword_8B8F1C);
    FreeWrapper_7bcf(v4);
    dword_8B8F1C = 0;
  }
  if ( dword_8B8F20 )
  {
    FreeWrapper_7bcf((LPVOID)dword_8B8F20);
    dword_8B8F20 = 0;
  }
  return 0;
}

