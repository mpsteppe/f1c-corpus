int __thiscall sub_458190(_DWORD *this, int a2, signed int a3)
{
  signed int v3; // eax
  int v5; // ebx
  int v6; // edi
  int v7; // ebx
  _BYTE v9[256]; // [esp+30h] [ebp-100h] BYREF

  v3 = 0;
  if ( a3 > 0 )
  {
    memset(v9, 0x20u, a3);
    v3 = a3;
  }
  v9[v3] = 0;
  if ( !*this || (int)this[1] < 4 )
    return 1;
  v5 = a2;
  sub_566C30(a2, aSS_0);
  sub_566C30(a2, aS_0);
  v6 = 0;
  if ( (int)this[1] > 0 )
  {
    v7 = 0;
    do
    {
      sub_566C30(a2, aSControlpointF);
      ++v6;
      v7 += 28;
    }
    while ( v6 < this[1] );
    v5 = a2;
  }
  sub_566C30(v5, aS_1);
  return 0;
}
