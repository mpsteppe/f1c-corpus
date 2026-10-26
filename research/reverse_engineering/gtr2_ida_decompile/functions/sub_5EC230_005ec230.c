_DWORD *__thiscall sub_5EC230(void *this, _DWORD *a2, _DWORD *a3, _DWORD *a4)
{
  int v5; // eax
  _DWORD *result; // eax

  v5 = *((_DWORD *)this + 98);
  if ( (*(_BYTE *)v5 & 0x10) != 0 && (*(_DWORD *)this & 0x2000) == 0 )
  {
    sub_5D7810((float *)this + 54, (float *)this + 57, (float *)(v5 + 184));
    *(_DWORD *)this |= 0x2000u;
  }
  if ( a2 )
    *a2 = *((_DWORD *)this + 57);
  if ( a3 )
    *a3 = *((_DWORD *)this + 58);
  result = a4;
  if ( a4 )
    *a4 = *((_DWORD *)this + 59);
  return result;
}
