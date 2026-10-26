_DWORD *__thiscall sub_59E780(_DWORD *this)
{
  *(_WORD *)this = 2;
  this[1] = htonl(0);
  *((_WORD *)this + 1) = htons(0);
  *((_WORD *)this + 8) = 2;
  this[5] = htonl(0);
  *((_WORD *)this + 9) = htons(0);
  this[526] = 0;
  *((_WORD *)this + 1054) = 0;
  this[33296] = 0;
  *((_WORD *)this + 66594) = 0;
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  this[4] = 0;
  this[5] = 0;
  this[6] = 0;
  this[7] = 0;
  this[9] = 0;
  *((_BYTE *)this + 40) = 0;
  this[11] = 0;
  this[12] = 0;
  *((_WORD *)this + 26) = 0;
  this[8] = -1;
  return this;
}
