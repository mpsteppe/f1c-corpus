int __thiscall sub_4E5B70(_DWORD *this)
{
  int v2; // eax
  int result; // eax

  v2 = this[6];
  if ( v2 )
  {
    sub_5E7F70(dword_FB1CE0, v2);
    this[6] = 0;
  }
  if ( this[7] )
  {
    sub_5E7F70(dword_FB1CE0, this[7]);
    this[7] = 0;
  }
  if ( this[1] )
  {
    sub_5F0DA0(this[1]);
    this[1] = 0;
  }
  if ( this[2] )
  {
    sub_5F0DA0(this[2]);
    this[2] = 0;
  }
  if ( this[3] )
  {
    sub_5F0DA0(this[3]);
    this[3] = 0;
  }
  sub_4E47D0();
  sub_4E47D0();
  sub_4E47D0();
  sub_4E47D0();
  sub_4E47D0();
  sub_4E47D0();
  result = sub_4E47D0();
  *(_BYTE *)this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  this[4] = 0;
  this[5] = 0;
  this[6] = 0;
  this[7] = 0;
  this[8] = 0;
  this[9] = 0;
  this[10] = 0;
  this[11] = 0;
  this[12] = 0;
  this[13] = 0;
  this[14] = 0;
  this[15] = 0;
  this[16] = 0;
  this[17] = 0;
  this[18] = 0;
  this[19] = 0;
  this[20] = 0;
  this[21] = 0;
  this[22] = 0;
  this[23] = 0;
  this[24] = 0;
  return result;
}
