// f1c  0x0057b910  size=62
u_short __thiscall sub_57B910(_DWORD *this)
{
  u_short result; // ax

  *(_WORD *)this = 2;
  this[1] = htonl(0);
  *((_WORD *)this + 1) = htons(0);
  *((_WORD *)this + 8) = 2;
  this[5] = htonl(0);
  result = htons(0);
  *((_WORD *)this + 9) = result;
  return result;
}
