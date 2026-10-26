int __thiscall sub_5BBB50(_DWORD *this)
{
  closesocket(this[8]);
  this[8] = -1;
  sub_5BBB10(this + 5);
  return sub_5BBB10(this + 2);
}
