// f1c  0x0054fae0  size=95
void __thiscall sub_54FAE0(_DWORD *this, int a2)
{
  int v2; // esi
  _DWORD *v3; // eax
  int v4; // edx
  _DWORD *v5; // eax

  v2 = this[120];
  if ( v2 )
  {
    if ( a2 == 0x8000000 )
    {
      v3 = *(_DWORD **)(v2 + 8);
      v4 = 0;
      if ( *(int *)(v2 + 4) > 0 )
      {
        do
        {
          *v3 &= ~1u;
          v3[16] = 0;
          v3 += 29;
          ++v4;
        }
        while ( v4 < *(_DWORD *)(this[120] + 4) );
      }
    }
    else
    {
      v5 = (_DWORD *)(*(_DWORD *)(v2 + 8) + 116 * a2);
      *v5 &= ~1u;
      v5[16] = 0;
    }
  }
}
