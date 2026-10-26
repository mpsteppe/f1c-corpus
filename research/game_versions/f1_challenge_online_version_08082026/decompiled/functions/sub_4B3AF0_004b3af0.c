int __thiscall sub_4B3AF0(_DWORD *this, _DWORD *a2)
{
  _DWORD *v3; // eax

  v3 = (_DWORD *)this[110595];
  if ( v3 == (_DWORD *)this[110593] )
  {
    this[110595] = this[110594];
    return 0;
  }
  else
  {
    sub_4B3A90(a2, v3);
    this[110595] += 432;
    return 1;
  }
}
