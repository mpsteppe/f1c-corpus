HANDLE sub_487190()
{
  DWORD ThreadId; // [esp+0h] [ebp-4h] BYREF

  ThreadId = 0;
  return CreateThread(0, 0, sub_486CB0, 0, 0, &ThreadId);
}
