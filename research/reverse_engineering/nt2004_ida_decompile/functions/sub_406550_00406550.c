int __thiscall sub_406550(_DWORD *this)
{
  int result; // eax
  void *v3; // esi

  *this = &off_5D5534;
  sub_4067B0();
  result = sub_4089C0(this);
  *this = &off_5D5558;
  v3 = (void *)this[1];
  if ( v3 )
    return sub_5BE8AE(v3);
  return result;
}
