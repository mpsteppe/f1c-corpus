char *__cdecl _strdate(char *Buffer)
{
  int v1; // edx
  int wMonth; // eax
  int wDay; // edi
  int v4; // eax
  _SYSTEMTIME SystemTime; // [esp+Ch] [ebp-14h] BYREF
  int v7; // [esp+1Ch] [ebp-4h]

  GetLocalTime(&SystemTime);
  v1 = SystemTime.wYear % 100;
  wMonth = SystemTime.wMonth;
  wDay = SystemTime.wDay;
  Buffer[5] = 47;
  Buffer[2] = 47;
  Buffer[8] = 0;
  v7 = v1;
  *Buffer = wMonth / 10 + 48;
  Buffer[1] = wMonth % 10 + 48;
  Buffer[3] = wDay / 10 + 48;
  v4 = v7;
  Buffer[4] = wDay % 10 + 48;
  Buffer[6] = v4 / 10 + 48;
  Buffer[7] = v4 % 10 + 48;
  return Buffer;
}
