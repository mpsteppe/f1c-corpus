_DWORD *__thiscall sub_4F2430(_DWORD *this)
{
  _DWORD *v2; // edi
  int v3; // ebx
  _DWORD *v4; // edi
  int v5; // ebx
  _DWORD *v6; // edx
  _DWORD *v7; // ecx
  int v8; // edi

  sub_40E6A0(this + 12);
  sub_40E6A0(this + 24);
  v2 = this + 34;
  v3 = 4;
  do
  {
    sub_40E6A0(v2);
    v2 += 7;
    --v3;
  }
  while ( v3 );
  v4 = this + 102;
  v5 = 8;
  do
  {
    sub_40E6A0(v4);
    v4 += 7;
    --v5;
  }
  while ( v5 );
  *this = 0;
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
  this[19] = 0;
  this[20] = 0;
  this[21] = 0;
  this[22] = 0;
  this[23] = 0;
  this[31] = 0;
  this[32] = 0;
  this[33] = 0;
  v6 = this + 70;
  v7 = this + 80;
  v8 = 8;
  do
  {
    *(v6 - 8) = 0;
    *v6 = 0;
    *(v7 - 2) = 0;
    *(v7 - 1) = 0;
    *v7 = 0;
    ++v6;
    v7 += 3;
    --v8;
  }
  while ( v8 );
  return this;
}
