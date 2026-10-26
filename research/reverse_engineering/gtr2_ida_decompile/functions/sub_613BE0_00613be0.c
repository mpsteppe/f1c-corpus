int __thiscall sub_613BE0(void *this)
{
  int result; // eax

  (*(void (__thiscall **)(void *))(*(_DWORD *)this + 20))(this);
  sub_615860(WindowName);
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_BYTE *)this + 28) = 0;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 17) = 0;
  *((_BYTE *)this + 64) = 0;
  result = sprintf((char *const)this + 32, "%s", "1.000");
  *((_DWORD *)this + 21) = 0;
  *((_BYTE *)this + 88) = 0;
  return result;
}
