int __thiscall sub_562C50(LPVOID *lpMem)
{
  BatchLoopWithMemoryCleanup(lpMem[1]);
  DestroyAudioArrayFreeElementsThenContainer(lpMem[37]);
  sub_58AA6F(lpMem[2]);
  sub_58AA6F(lpMem);
  return WSACleanupThunk();
}

