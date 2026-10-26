void __thiscall sub_5ED990(_DWORD *this, int a2)
{
  int v2; // esi
  _DWORD *v3; // eax
  int v4; // edx
  _DWORD *v5; // eax

  v2 = this[113];
  if ( v2 )
  {
    if ( a2 == 0x8000000 )
    {
      v3 = *(_DWORD **)(v2 + 12);
      v4 = 0;
      if ( *(int *)(v2 + 8) > 0 )
      {
        do
        {
          *v3 &= ~0x10u;
          v3[16] = 0;
          v3 += 29;
          ++v4;
        }
        while ( v4 < *(_DWORD *)(this[113] + 8) );
      }
    }
    else
    {
      v5 = (_DWORD *)(*(_DWORD *)(v2 + 12) + 116 * a2);
      *v5 &= ~0x10u;
      v5[16] = 0;
    }
  }
}
