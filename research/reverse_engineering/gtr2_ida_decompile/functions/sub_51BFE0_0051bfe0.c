int __thiscall sub_51BFE0(_DWORD *this, _DWORD *a2)
{
  _DWORD *v2; // eax

  v2 = (_DWORD *)this[217091];
  if ( v2 == (_DWORD *)this[217089] )
  {
    this[217091] = this[217090];
    return 0;
  }
  else
  {
    if ( ((*v2 >> 8) & 0x3FF) + 8 > 0 )
      qmemcpy(a2, v2, ((*v2 >> 8) & 0x3FF) + 8);
    a2[211] = v2[211];
    this[217091] += 848;
    return 1;
  }
}
