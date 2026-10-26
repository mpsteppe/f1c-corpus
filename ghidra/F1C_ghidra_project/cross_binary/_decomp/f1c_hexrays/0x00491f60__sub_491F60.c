// f1c  0x00491f60  size=70
int __thiscall sub_491F60(int *this)
{
  int v2; // ecx

  v2 = *this;
  if ( v2 )
    sub_5355A0(v2);
  if ( this[1] )
    sub_587D02(this[1]);
  if ( this[2] )
    sub_587D02(this[2]);
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  return 0;
}
