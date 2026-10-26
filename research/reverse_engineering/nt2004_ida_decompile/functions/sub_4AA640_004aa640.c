int __thiscall sub_4AA640(int this)
{
  sub_57A080(this);
  sub_57A080(this + 28);
  sub_57A080(this + 56);
  *(_BYTE *)(this + 84) = 0;
  strcpy((char *)(this + 212), "Log\\osc.information");
  strcpy((char *)(this + 340), "Log\\osc.err");
  *(_DWORD *)(this + 468) = 0;
  *(_DWORD *)(this + 472) = 0;
  *(_DWORD *)(this + 476) = 0;
  *(_DWORD *)(this + 484) = 0;
  *(_BYTE *)(this + 480) = 0;
  *(_BYTE *)(this + 481) = 0;
  *(_BYTE *)(this + 482) = 0;
  return this;
}
