int __thiscall sub_5B5030(int *this)
{
  int result; // eax

  *this = (*(int (__stdcall **)(int, int, _DWORD **))(*(_DWORD *)this[1112] + 152))(
            this[1112],
            2,
            (_DWORD **)this + 2097);
  *this = (*(int (__stdcall **)(int, int, _DWORD **))(*(_DWORD *)this[1112] + 152))(
            this[1112],
            3,
            (_DWORD **)this + 2113);
  result = (*(int (__stdcall **)(int, _DWORD **))(*(_DWORD *)this[1112] + 164))(this[1112], (_DWORD **)this + 2129);
  *this = result;
  return result;
}
