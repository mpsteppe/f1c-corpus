_DWORD *__thiscall sub_59D740(_DWORD *this)
{
  *(_WORD *)this = 2;
  this[1] = htonl(0);
  *((_WORD *)this + 1) = htons(0);
  *((_WORD *)this + 8) = 2;
  this[5] = htonl(0);
  *((_WORD *)this + 9) = htons(0);
  *(_WORD *)this = 2;
  this[1] = htonl(0);
  *((_WORD *)this + 1) = htons(0);
  *((_WORD *)this + 8) = 2;
  this[5] = htonl(0);
  *((_WORD *)this + 9) = htons(0);
  return this;
}
