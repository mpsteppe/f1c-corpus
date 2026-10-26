int __thiscall sub_64FE72(_DWORD *this, int a2)
{
  void *v3; // eax
  void *v4; // ebx
  void *v5; // eax
  int v6; // ecx
  unsigned int v9; // eax
  int v10; // [esp+14h] [ebp+8h]

  v3 = operator new(0x1000u);
  v4 = v3;
  if ( v3 )
  {
    sub_41D1B0((int)v3, 16, 256, (int)sub_681563);
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  v6 = 0;
  this[14] = v5;
  if ( !v5 )
    return -2147024882;
  v9 = 0;
  if ( *(_DWORD *)(a2 + 80) )
  {
    do
    {
      v10 = *(unsigned __int8 *)(v9 + *(_DWORD *)(a2 + 80));
      v9 += 4;
      *(float *)(v6 + this[14]) = (double)v10 * 0.0039215689;
      v6 += 16;
      *(float *)(v6 + this[14] - 12) = (double)*(unsigned __int8 *)(v9 + *(_DWORD *)(a2 + 80) - 3) * 0.0039215689;
      *(float *)(v6 + this[14] - 8) = (double)*(unsigned __int8 *)(v9 + *(_DWORD *)(a2 + 80) - 2) * 0.0039215689;
      *(float *)(v6 + this[14] - 4) = (double)*(unsigned __int8 *)(v9 + *(_DWORD *)(a2 + 80) - 1) * 0.0039215689;
    }
    while ( v9 < 0x400 );
  }
  else
  {
    do
    {
      *(float *)(v9 + this[14] + 12) = 1.0;
      *(float *)(v9 + this[14] + 8) = 1.0;
      *(float *)(v9 + this[14] + 4) = 1.0;
      *(float *)(v9 + this[14]) = 1.0;
      v9 += 16;
    }
    while ( v9 < 0x1000 );
  }
  return 0;
}
