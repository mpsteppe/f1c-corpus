// f1c  0x005550a0  size=22
int __thiscall sub_5550A0(int *this)
{
  int result; // eax

  result = (*(int (__stdcall **)(int))(*(_DWORD *)this[1088] + 136))(this[1088]);
  *this = result;
  return result;
}
