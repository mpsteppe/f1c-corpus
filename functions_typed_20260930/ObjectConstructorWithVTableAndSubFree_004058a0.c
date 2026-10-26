int __thiscall sub_4058A0(_DWORD *this)
{
  int result; // eax
  void *v3; // esi

  *this = &off_59E490;
  AudioResourceRelease();
  result = LinkedListNodeRemovalByKey(this);
  *this = &off_59E4B4;
  v3 = (void *)this[1];
  if ( v3 )
    return FreeWrapper_7bcf(v3);
  return result;
}

