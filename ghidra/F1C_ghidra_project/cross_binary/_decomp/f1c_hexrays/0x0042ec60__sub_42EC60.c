// f1c  0x0042ec60  size=93
int __thiscall sub_42EC60(_DWORD *this)
{
  _DWORD *v1; // eax
  int v2; // esi
  int v3; // edx
  _DWORD *v4; // eax
  int v5; // edx
  int result; // eax

  v1 = this + 49;
  v2 = 4;
  do
  {
    v3 = 11;
    do
    {
      *v1 = v1[1];
      v1 += 16;
      --v3;
    }
    while ( v3 );
    --v2;
  }
  while ( v2 );
  v4 = this + 753;
  v5 = 55;
  do
  {
    *v4 = v4[1];
    v4 += 16;
    --v5;
  }
  while ( v5 );
  result = 1056964608;
  this[1834] = 1056964608;
  this[1835] = 1056964608;
  this[1836] = 1056964608;
  this[1837] = 1056964608;
  *(_BYTE *)this = 1;
  return result;
}
