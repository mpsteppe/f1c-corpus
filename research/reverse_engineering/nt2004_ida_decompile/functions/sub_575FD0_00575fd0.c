_DWORD *__thiscall sub_575FD0(_DWORD *this)
{
  void *v2; // eax
  DWORD v3; // eax

  v2 = (void *)this[20];
  if ( v2 && ((v3 = WaitForSingleObject(v2, this[21])) == 0 || v3 == 128) )
    return this;
  else
    return 0;
}
