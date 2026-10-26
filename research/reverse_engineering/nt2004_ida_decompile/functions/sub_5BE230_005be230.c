int __thiscall sub_5BE230(_DWORD *this)
{
  int v2; // ecx
  void *v3; // edx
  int result; // eax

  v2 = this[3] + this[1];
  v3 = (void *)this[5];
  this[1] = v2;
  result = sub_5C293D(v3, v2 * this[2]);
  this[5] = result;
  return result;
}
