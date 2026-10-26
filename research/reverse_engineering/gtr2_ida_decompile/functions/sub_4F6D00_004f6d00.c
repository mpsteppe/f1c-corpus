int __thiscall sub_4F6D00(_DWORD *this, int a2)
{
  _DWORD *v4; // eax
  _DWORD *v5; // ecx
  int v6; // ebx
  int result; // eax
  int v8; // ebp
  int v9; // ebx
  int v10; // [esp+14h] [ebp+4h]

  *(_DWORD *)a2 = this[1];
  *(_DWORD *)(a2 + 4) = this[2];
  *(_DWORD *)(a2 + 8) = this[3];
  *(_DWORD *)(a2 + 12) = this[4];
  v4 = this + 8;
  *(float *)(a2 + 16) = *((float *)this + 5) - dbl_FB1D18;
  *(_DWORD *)(a2 + 20) = this[6];
  v5 = (_DWORD *)(a2 + 28);
  v6 = 5;
  do
  {
    *(v5 - 1) = *(v4 - 1);
    *v5 = *v4;
    *(_DWORD *)((char *)v4 + a2 - (_DWORD)this) = v4[1];
    v5[2] = v4[2];
    v5[3] = v4[3];
    v5[4] = v4[4];
    v5[5] = v4[5];
    v5 += 7;
    v4 += 7;
    --v6;
  }
  while ( v6 );
  *(_DWORD *)(a2 + 164) = this[42];
  *(_DWORD *)(a2 + 168) = this[43];
  *(_DWORD *)(a2 + 172) = this[44];
  *(_DWORD *)(a2 + 176) = this[45];
  *(_DWORD *)(a2 + 180) = this[46];
  *(_DWORD *)(a2 + 184) = this[47];
  *(_DWORD *)(a2 + 188) = this[48];
  *(_DWORD *)(a2 + 192) = this[72];
  result = this[72];
  v8 = 0;
  v10 = 0;
  if ( result > 0 )
  {
    v9 = a2 + 196;
    do
    {
      sub_4F5FB0((char *)(v8 + this[73]), v9);
      result = v10 + 1;
      v9 += 1320;
      v8 += 768;
      ++v10;
    }
    while ( v10 < this[72] );
  }
  *(_BYTE *)(a2 + 26596) = *(_BYTE *)(*this + 5753);
  return result;
}
