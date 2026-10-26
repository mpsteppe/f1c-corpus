// f1c  0x00563dc0  size=45
int __thiscall sub_563DC0(_DWORD *this)
{
  int v2; // edi
  int v3; // ebx

  v2 = 0;
  if ( (int)this[27] > 0 )
  {
    v3 = 0;
    do
    {
      closesocket(*(_DWORD *)(this[2] + v3));
      ++v2;
      v3 += 28;
    }
    while ( v2 < this[27] );
  }
  return 0;
}
