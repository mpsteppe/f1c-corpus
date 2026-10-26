// f1c  0x004058a0  size=47
int __thiscall sub_4058A0(_DWORD *this)
{
  int result; // eax
  void *v3; // esi

  *this = &off_59E490;
  sub_405B00();
  result = sub_407BE0(this);
  *this = &off_59E4B4;
  v3 = (void *)this[1];
  if ( v3 )
    return sub_587BCF(v3);
  return result;
}
