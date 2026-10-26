int __thiscall sub_55CDF0(int *this)
{
  int result; // eax

  *this = (*(int (__stdcall **)(int, int, _DWORD **))(*(_DWORD *)this[1088] + 152))(
            this[1088],
            2,
            (_DWORD **)this + 1302);
  *this = (*(int (__stdcall **)(int, int, _DWORD **))(*(_DWORD *)this[1088] + 152))(
            this[1088],
            3,
            (_DWORD **)this + 1318);
  result = (*(int (__stdcall **)(int, _DWORD **))(*(_DWORD *)this[1088] + 164))(this[1088], (_DWORD **)this + 1334);
  *this = result;
  return result;
}

