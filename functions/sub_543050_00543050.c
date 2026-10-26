int __thiscall sub_543050(_DWORD *this, const char *a2, int a3)
{
  int v4; // eax
  int v5; // esi
  int v7; // edi
  void *v8; // ebx
  char v9[256]; // [esp+10h] [ebp-100h] BYREF

  v4 = sub_587DB0(a2, aRb);
  v5 = v4;
  if ( v4 )
  {
    sub_587F64(v4, 0, 2);
    v7 = FileSizeQueryWrapper(v5);
    sub_587F64(v5, 0, 0);
    v8 = (void *)OperatorNewNhMallocWrapper(v7);
    ThreadSafeReadWrapper_803f(v8, 1, v7, v5);
    FileCloseWithLock(v5);
    if ( RenderingCompositionSetup(dword_8B78A0, (int)v8, v7, this, a3, 0) )
    {
      return -1;
    }
    else
    {
      FreeWrapper_7bcf(v8);
      return 0;
    }
  }
  else
  {
    StringFormatWithBufferOverflowCheck(v9, "Error opening bitmap file %s", a2);
    sub_53C590(-2, v9);
    return -2;
  }
}
