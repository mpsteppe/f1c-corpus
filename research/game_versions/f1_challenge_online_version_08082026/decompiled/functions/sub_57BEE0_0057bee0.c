SOCKET __thiscall sub_57BEE0(void *this)
{
  (*(void (__thiscall **)(void *))(*(_DWORD *)this + 116))(this);
  return socket(2, 1, 0);
}
