int sub_4D7AA0(int a1, int a2, ...)
{
  va_list va; // [esp+10h] [ebp+Ch] BYREF

  va_start(va, a2);
  FileWriteWrapperWithLock(*(_DWORD *)(a1 + 4), a2, va);
  return LockCallUnlockWrapper(*(_DWORD *)(a1 + 4));
}

