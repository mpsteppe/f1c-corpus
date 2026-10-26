int __thiscall sub_4BD290(_DWORD *this)
{
  _DWORD *v2; // edi
  _DWORD *v3; // ebp
  int v4; // ebx
  int result; // eax
  int i; // edi
  LPVOID *v7; // ebp
  char v8; // al

  *this = 0;
  this[1] = 0;
  v2 = this + 2;
  v3 = this + 17;
  v4 = 14;
  do
  {
    result = sub_578600(&byte_629120);
    *v2++ = 1092616192;
    v3 += 2;
    --v4;
  }
  while ( v4 );
  this[16] = 0;
  this[45] = 0;
  for ( i = this[46]; i; result = sub_5BE8AE(v7) )
  {
    v7 = (LPVOID *)i;
    v8 = *(_BYTE *)(i + 8);
    i = *(_DWORD *)(i + 4);
    if ( v8 && *v7 )
      sub_5BE8AE(*v7);
  }
  this[46] = 0;
  this[47] = 0;
  this[48] = 0;
  this[49] = 0;
  this[51] = 0;
  this[52] = 0;
  this[53] = 0;
  this[54] = 0;
  this[55] = 0;
  this[50] = -1;
  return result;
}
