int __thiscall sub_5EC5A0(_DWORD *this, int a2, int a3)
{
  int result; // eax

  result = sub_5EB140(this, a2, 1);
  *(_DWORD *)(result + 24) = a3;
  *this &= ~0x800u;
  return result;
}
