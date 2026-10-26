_DWORD *__thiscall sub_5D8BD0(_DWORD *this)
{
  __int16 v2; // [esp+8h] [ebp-4h]

  memset(this + 1, 0, 0x40u);
  this[16] = 1065353216;
  this[11] = 1065353216;
  this[6] = 1065353216;
  this[1] = 1065353216;
  *this = 1;
  *((_WORD *)this + 34) = v2 & 0x300;
  return this;
}
