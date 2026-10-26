char *__cdecl _strtime(char *Buffer)
{
  char v1; // al
  char v2; // dl
  int wMinute; // esi
  int wSecond; // edi
  struct _SYSTEMTIME SystemTime; // [esp+Ch] [ebp-10h] BYREF

  GetLocalTime(&SystemTime);
  v1 = SystemTime.wHour / 10;
  v2 = SystemTime.wHour % 10;
  wMinute = SystemTime.wMinute;
  wSecond = SystemTime.wSecond;
  Buffer[5] = 58;
  Buffer[2] = 58;
  Buffer[8] = 0;
  *Buffer = v1 + 48;
  Buffer[1] = v2 + 48;
  Buffer[3] = wMinute / 10 + 48;
  Buffer[4] = wMinute % 10 + 48;
  Buffer[6] = wSecond / 10 + 48;
  Buffer[7] = wSecond % 10 + 48;
  return Buffer;
}
