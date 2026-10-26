int __thiscall sub_58C370(_DWORD *this)
{
  _DWORD *v1; // edi
  int v2; // ebx
  _DWORD *v3; // eax
  int v4; // edx
  int result; // eax

  this[59] = 0;
  v1 = this + 3;
  v2 = 2;
  do
  {
    *v1 = 0;
    v3 = v1 + 2;
    v4 = 5;
    do
    {
      *(v3 - 1) = 0;
      *v3 = 0;
      v3[1] = 0;
      v3[2] = 0;
      v3 += 4;
      --v4;
    }
    while ( v4 );
    v1 += 21;
    --v2;
  }
  while ( v2 );
  this[1] = 0;
  *this = -1082130432;
  this[2] = 1065353216;
  this[45] = 1138128720;
  this[48] = 1138128720;
  this[46] = 1146517328;
  this[49] = 1146517328;
  this[47] = 991480299;
  this[50] = 991480299;
  result = 981467136;
  this[51] = 983091691;
  this[52] = 981467136;
  this[53] = 983091691;
  this[54] = 981467136;
  this[55] = 983091691;
  this[56] = 981467136;
  this[57] = 983091691;
  this[58] = 981467136;
  return result;
}
