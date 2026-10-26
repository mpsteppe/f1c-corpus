int __thiscall sub_563E00(LPVOID *this)
{
  void *v3; // eax
  void *v4; // ecx

  if ( *this )
    return 4;
  sub_564860(this[1]);
  v3 = (void *)sub_564810(sub_5640F0);
  v4 = this[37];
  this[1] = v3;
  sub_564740(v4);
  this[37] = (LPVOID)sub_5646D0(4, sub_5645A0, sub_564600, sub_564630);
  this[38] = 0;
  return 0;
}
