_DWORD *__thiscall sub_582110(_DWORD *this)
{
  _DWORD *result; // eax

  *(_WORD *)this = 2;
  this[1] = htonl(0);
  *((_WORD *)this + 1) = htons(0);
  *((_WORD *)this + 8) = 2;
  this[5] = htonl(0);
  *((_WORD *)this + 9) = htons(0);
  RingBufferHeadTailReset((_WORD *)this + 27);
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  this[4] = 0;
  this[5] = 0;
  result = this;
  this[6] = 0;
  this[7] = 0;
  this[8] = -1;
  this[9] = 0;
  *((_BYTE *)this + 40) = 0;
  this[11] = 0;
  this[12] = 0;
  *((_WORD *)this + 26) = 0;
  return result;
}

