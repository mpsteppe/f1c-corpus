char *__fastcall sub_562830(int a1, const struct sockaddr *a2, char *buf)
{
  char v6[1400]; // [esp+Ch] [ebp-578h] BYREF

  v6[0] = byte_5EA438[0];
  memset(&v6[1], 0, 1399);
  (*(void (__fastcall **)(char *, int, _DWORD))(a1 + 204))(v6, 1400, *(_DWORD *)(a1 + 256));
  return sub_562710((SOCKET *)a1, a2, buf, v6);
}

