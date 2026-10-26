void __thiscall sub_59BEC0(_DWORD *this, unsigned int a2)
{
  int v2; // esi
  int v3; // eax
  int v4; // edx
  int v5; // ebx
  unsigned int *v6; // edx
  unsigned int v7; // ebx

  if ( a2 < 0x10 )
  {
    v2 = 0;
    if ( (int)this[70] > 0 )
    {
      v3 = 0;
      do
      {
        *(_DWORD *)(this[71] + v3 + 60) = a2;
        v4 = this[71];
        v5 = *(_DWORD *)(v4 + v3 + 56);
        v6 = (unsigned int *)(v4 + v3 + 56);
        if ( a2 )
          v7 = v5 | 0x1000;
        else
          v7 = v5 & 0xFFFFEFFF;
        *v6 = v7;
        ++v2;
        v3 += 64;
      }
      while ( v2 < this[70] );
    }
  }
}
