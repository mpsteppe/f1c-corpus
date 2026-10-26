char __thiscall sub_4F6E40(_DWORD *this, int a2)
{
  _DWORD *v5; // eax
  _DWORD *v6; // ecx
  char *v7; // edx
  int v8; // ebx
  int v9; // ebp
  int i; // ebx
  int v11; // eax
  char result; // al
  int v13; // ecx
  int v14; // [esp+14h] [ebp+4h]

  this[1] = *(_DWORD *)a2;
  this[2] = *(_DWORD *)(a2 + 4);
  this[3] = *(_DWORD *)(a2 + 8);
  this[4] = *(_DWORD *)(a2 + 12);
  v5 = (_DWORD *)(a2 + 28);
  *((float *)this + 5) = dbl_FB1D18 + *(float *)(a2 + 16);
  this[6] = *(_DWORD *)(a2 + 20);
  v6 = this + 9;
  v7 = (char *)this - a2;
  v8 = 5;
  do
  {
    *(_DWORD *)&v7[(_DWORD)v5] = *(v5 - 1);
    *(v6 - 1) = *v5;
    *v6 = v5[1];
    v6[1] = v5[2];
    v6[2] = v5[3];
    v6[3] = v5[4];
    v6[4] = v5[5];
    v5 += 7;
    v6 += 7;
    --v8;
  }
  while ( v8 );
  this[42] = *(_DWORD *)(a2 + 164);
  this[43] = *(_DWORD *)(a2 + 168);
  this[44] = *(_DWORD *)(a2 + 172);
  this[45] = *(_DWORD *)(a2 + 176);
  this[46] = *(_DWORD *)(a2 + 180);
  this[47] = *(_DWORD *)(a2 + 184);
  v9 = 0;
  this[48] = *(_DWORD *)(a2 + 188);
  v14 = 0;
  for ( i = a2 + 196; ; i += 1320 )
  {
    v11 = this[72];
    if ( v11 >= *(_DWORD *)(a2 + 192) )
      v11 = *(_DWORD *)(a2 + 192);
    if ( v14 >= v11 )
      break;
    sub_4F6590((int *)(v9 + this[73]), a2, (int)this, i);
    ++v14;
    v9 += 768;
  }
  result = *(_BYTE *)(a2 + 26596);
  v13 = *this + 2704;
  if ( *(_BYTE *)(*this + 5753) != result )
  {
    *(_BYTE *)(*this + 5753) = result;
    return sub_56AE80(*(_DWORD *)(v13 + 3040), 1);
  }
  return result;
}
