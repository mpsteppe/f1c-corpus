_DWORD *__thiscall sub_478210(_DWORD *this, char a2, char a3)
{
  sub_49F530();
  this[104] = 0;
  this[105] = 0;
  this[106] = 0;
  this[107] = 0;
  *this = &off_5D70E8;
  sub_4A0640(a2);
  this[158] = 0;
  this[159] = -1;
  if ( a3 )
    this[157] = 0;
  else
    this[157] = 1;
  *((_BYTE *)this + 641) = 0;
  this[156] = 40;
  return this;
}
