unsigned int __thiscall sub_5A91A0(unsigned int *this, int a2)
{
  unsigned int v2; // ebp
  unsigned int v3; // esi
  unsigned int v4; // eax
  unsigned int v5; // ebx
  unsigned int v6; // edi
  unsigned int v7; // esi
  int v8; // eax
  unsigned int v9; // edi
  bool v10; // zf
  int v11; // eax
  int v12; // eax
  int v13; // eax
  unsigned int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int result; // eax
  unsigned int v18; // edx

  v2 = this[5];
  v3 = a2 + this[3];
  v4 = this[2];
  this[3] = v3;
  v5 = v3;
  v6 = this[1];
  v7 = v4 - v2 - v3;
  this[4] = v7;
  if ( v6 )
    v8 = v4 / v6;
  else
    v8 = 0;
  v9 = *this;
  v10 = *this == 0;
  this[8] = v8;
  if ( v10 )
    v11 = 0;
  else
    v11 = v5 / v9;
  this[7] = v11;
  if ( v9 )
    v12 = v2 / v9;
  else
    v12 = 0;
  this[10] = v12;
  if ( v9 )
    v13 = v7 / v9;
  else
    v13 = 0;
  this[9] = v13;
  v14 = this[3];
  if ( v14 <= this[12] )
    v14 = this[12];
  this[12] = v14;
  v15 = this[2];
  if ( v15 <= this[11] )
    v15 = this[11];
  this[11] = v15;
  v16 = this[13];
  if ( v9 > v16 )
    v16 = v9;
  this[13] = v16;
  result = this[1];
  v18 = this[14];
  if ( result <= v18 )
    this[14] = v18;
  else
    this[14] = result;
  return result;
}
