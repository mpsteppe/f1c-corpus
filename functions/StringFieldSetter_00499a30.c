int __thiscall sub_499A30(_DWORD *this, int a2, int a3)
{
  int result; // eax

  result = StringCopyWithBufferRealloc(a2);
  this[2] = a3;
  return result;
}
