int __thiscall sub_60A5E0(void *this, int a2, int a3, int a4)
{
  int result; // eax
  int i; // [esp+14h] [ebp-4h]

  result = 0;
  for ( i = 0; i <= 4; ++i )
  {
    switch ( result )
    {
      case 0:
        (*(void (__thiscall **)(void *, int, int, _DWORD, int, int))(*(_DWORD *)this + 72))(this, a2, a3, 0, 1, a4);
        break;
      case 1:
        (*(void (__thiscall **)(void *, int, int, int, _DWORD, int))(*(_DWORD *)this + 72))(this, a2, a3, 1, 0, a4);
        break;
      case 2:
        (*(void (__thiscall **)(void *, int, int, int, int, int))(*(_DWORD *)this + 72))(this, a2, a3, 2, 1, a4);
        break;
      case 3:
        (*(void (__thiscall **)(void *, int, int, int, _DWORD, int))(*(_DWORD *)this + 72))(this, a2, a3, 3, 0, a4);
        break;
      case 4:
        (*(void (__thiscall **)(void *, int, int, int, _DWORD, int))(*(_DWORD *)this + 72))(this, a2, a3, 4, 0, a4);
        break;
      default:
        break;
    }
    result = i + 1;
  }
  return result;
}
