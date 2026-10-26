_DWORD *__thiscall sub_4E3DE0(_DWORD *this)
{
  _DWORD *v2; // edi
  int v3; // ebp

  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  v2 = this + 4;
  v3 = 47;
  do
  {
    sub_4E34F0(v2);
    v2 += 161;
    --v3;
  }
  while ( v3 );
  sub_4E34F0(this + 7571);
  sub_4E34A0(this + 7732);
  this[7741] = 0;
  *((_BYTE *)this + 30976) = 0;
  this[7742] = -1;
  this[7743] = 4;
  return this;
}
