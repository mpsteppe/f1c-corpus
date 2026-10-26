// f1c  0x005550c0  size=22
int __thiscall sub_5550C0(int *this)
{
  int result; // eax

  result = (*(int (__stdcall **)(int))(*(_DWORD *)this[1088] + 140))(this[1088]);
  *this = result;
  return result;
}
