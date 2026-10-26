_DWORD *__thiscall sub_4F6F20(_DWORD *this)
{
  _DWORD *v2; // edx
  int v3; // edi
  int v4; // edx
  _DWORD *v5; // ecx
  int v6; // edx

  v2 = this + 45;
  v3 = 45;
  do
  {
    StructZeroInit_6f00(v2);
    v2 = (_DWORD *)(v4 + 32);
    --v3;
  }
  while ( v3 );
  StructZeroInit_6bc0(this + 405);
  StructZeroInit_6bc0(this + 422);
  *this = 0;
  *((_BYTE *)this + 4) = 0;
  this[2] = 0;
  this[3] = 0;
  this[4] = 0;
  this[5] = 0;
  this[6] = 0;
  this[7] = 0;
  this[17] = 0;
  this[18] = 0;
  this[19] = 0;
  v5 = this + 22;
  v6 = 4;
  do
  {
    *(v5 - 2) = 0;
    *(v5 - 1) = 0;
    *v5 = 0;
    v5 += 3;
    --v6;
  }
  while ( v6 );
  this[32] = 0;
  this[33] = 0;
  this[34] = 0;
  this[35] = 0;
  this[36] = 0;
  *((_BYTE *)this + 152) = 0;
  this[39] = 0;
  this[40] = 1065353216;
  this[41] = 0;
  this[42] = 0;
  this[43] = 0;
  *((_BYTE *)this + 176) = 0;
  this[421] = 0;
  this[438] = 0;
  this[37] = 0;
  return this;
}

