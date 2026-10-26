char *__cdecl _getcwd(char *DstBuf, int SizeInBytes)
{
  char *v2; // esi

  _lock(12);
  v2 = (char *)_getdcwd_lk(0, (int)DstBuf, SizeInBytes);
  _unlock(12);
  return v2;
}
