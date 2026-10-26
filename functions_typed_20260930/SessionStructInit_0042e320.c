char *__thiscall sub_42E320(char *this)
{
  _DWORD *v2; // edx
  int v3; // edi
  int v4; // edx
  _DWORD *v5; // edx
  int v6; // edi
  int v7; // edx
  _BYTE *v8; // eax
  int v9; // ecx

  *((_DWORD *)this + 26) = 0;
  *((_DWORD *)this + 27) = -1;
  v2 = this + 176;
  v3 = 44;
  do
  {
    StructInitializer(v2);
    v2 = (_DWORD *)(v4 + 64);
    --v3;
  }
  while ( v3 );
  v5 = this + 2992;
  v6 = 55;
  do
  {
    StructInitializer(v5);
    v5 = (_DWORD *)(v7 + 64);
    --v6;
  }
  while ( v6 );
  SmallDataStructInit((_DWORD *)this + 1628);
  this[6564] = 1;
  this[6565] = 1;
  *this = 0;
  this[112] = 0;
  this[6536] = 0;
  this[6537] = 0;
  *((_DWORD *)this + 1635) = 0;
  *((_DWORD *)this + 1636) = 0;
  *((_DWORD *)this + 1637) = 0;
  *((_DWORD *)this + 1638) = 0;
  *((_DWORD *)this + 1639) = 0;
  *((_DWORD *)this + 1640) = 0;
  sub_42ED70(this);
  v8 = this + 6950;
  v9 = 3;
  do
  {
    *(v8 - 384) = 0;
    *v8 = 0;
    v8 += 128;
    --v9;
  }
  while ( v9 );
  *((_DWORD *)this + 1834) = 1056964608;
  *((_DWORD *)this + 1835) = 1056964608;
  *((_DWORD *)this + 1836) = 1056964608;
  *((_DWORD *)this + 1837) = 1056964608;
  PenaltyStructInit(this);
  return this;
}

