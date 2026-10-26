int __thiscall sub_5BC8F0(int this)
{
  int result; // eax
  void *v3; // ecx

  sub_5BC800((char *)this);
  sub_5BDA60(this);
  result = sub_5BA080();
  v3 = *(void **)(this + 4);
  if ( v3 )
    result = sub_5BE160(v3);
  *(_DWORD *)(this + 4) = 0;
  return result;
}
