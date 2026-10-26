DWORD __thiscall sub_5BB8E0(int this)
{
  DWORD result; // eax
  char buf[2048]; // [esp+4h] [ebp-804h] BYREF
  int len; // [esp+804h] [ebp-4h]

  len = 0;
  sub_5BAF50((int)buf, 8, (_DWORD *)(this + 132));
  sendto(*(_DWORD *)this, buf, len, 0, (const struct sockaddr *)(this + 196), 16);
  result = GetTickCount();
  *(_DWORD *)(this + 172) = result;
  return result;
}
