int __thiscall sub_6CD143(_DWORD *this, int a2, int a3, int a4, unsigned int a5)
{
  int v5; // eax
  int result; // eax

  v5 = a5;
  if ( a5 > 4 )
    v5 = 4;
  this[6] = -1;
  this[9] = -1;
  *this = a2;
  this[1] = a3;
  this[3] = v5;
  result = 0;
  this[10] = -1;
  this[2] = a4;
  this[4] = 0;
  this[5] = 0;
  this[7] = 0;
  this[8] = 0;
  this[11] = 0;
  this[12] = 0;
  return result;
}
