DWORD __fastcall sub_562AC0(int a1, int a2)
{
  DWORD result; // eax
  char buf[256]; // [esp+8h] [ebp-100h] BYREF

  StringFormatWithBufferOverflowCheck(
    buf,
    "\\heartbeat\\%d\\gamename\\%s",
    *(_DWORD *)(a1 + 228),
    (const char *)(a1 + 8));
  if ( a2 )
    StringFormatWithBufferOverflowCheck(&buf[strlen(buf)], "\\statechanged\\%d", a2);
  sendto(*(_DWORD *)(a1 + 4), buf, strlen(buf), 0, (const struct sockaddr *)(a1 + 236), 16);
  result = GetTickCount();
  *(_DWORD *)(a1 + 216) = result;
  return result;
}
