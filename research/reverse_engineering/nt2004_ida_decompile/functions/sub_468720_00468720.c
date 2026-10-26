_DWORD *__thiscall sub_468720(_DWORD *this)
{
  _DWORD *v2; // eax
  int v3; // ecx

  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  v2 = this + 4;
  v3 = 48;
  do
  {
    *v2 = 0;
    v2[1] = -1;
    v2 += 2;
    --v3;
  }
  while ( v3 );
  this[103] = 0;
  this[104] = -1;
  sub_57B5D0(this + 107);
  sub_57B5D0(this + 126);
  sub_467CC0(this + 148);
  this[105] = 0;
  sub_57B610(1);
  sub_57B690(this + 107);
  this[145] = 0;
  this[106] = 0;
  sub_57B610(1);
  sub_57B690(this + 126);
  this[100] = 0;
  this[147] = 0;
  return this;
}
