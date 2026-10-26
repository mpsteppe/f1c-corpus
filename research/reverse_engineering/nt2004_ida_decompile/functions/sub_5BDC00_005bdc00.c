BOOL __thiscall sub_5BDC00(void *this)
{
  int v1; // eax
  timeval timeout; // [esp+0h] [ebp-10Ch] BYREF
  fd_set readfds; // [esp+8h] [ebp-104h] BYREF

  readfds.fd_array[0] = (SOCKET)this;
  readfds.fd_count = 1;
  timeout.tv_sec = 0;
  timeout.tv_usec = 0;
  v1 = select(64, &readfds, 0, 0, &timeout);
  return v1 != -1 && v1;
}
