// f1c  0x00447d00  size=242
int __thiscall sub_447D00(int this, int a2)
{
  int v3; // ecx
  int v4; // eax
  double v6; // st7
  int v7; // eax
  char v8; // cl
  _BYTE v10[128]; // [esp+18h] [ebp-80h] BYREF

  sub_45BDF0(&unk_7CD204);
  if ( a2 <= 0 )
  {
    if ( a2 < 0 && --*(_DWORD *)(this + 5504) < 0 )
      *(_DWORD *)(this + 5504) = 0;
  }
  else
  {
    v3 = *(_DWORD *)(this + 5504) + 1;
    *(_DWORD *)(this + 5504) = v3;
    v4 = *(_DWORD *)(this + 5500);
    if ( v3 >= v4 )
      *(_DWORD *)(this + 5504) = v4 - 1;
  }
  v6 = (double)*(int *)(this + 5504) * *(double *)(this + 5492) + *(double *)(this + 5484);
  *(double *)(this + 5476) = v6;
  if ( sub_423A00(byte_5EC4C0, aBrakeBias, byte_5EC4CC) )
  {
    v7 = 0;
    do
    {
      v8 = aBrakeBias[v7];
      byte_5EC4CC[v7++] = v8;
    }
    while ( v8 );
  }
  sub_58815F(v10, "%s %4.1f:%4.1f", byte_5EC4CC, 100.0 - v6 * 100.0, v6 * 100.0);
  return sub_45BD10(v10, 3, 16909060);
}
