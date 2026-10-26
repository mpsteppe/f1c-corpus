// f1c  0x00544c50  size=215
int __thiscall sub_544C50(_DWORD *this, int a2)
{
  _DWORD *v2; // edi
  int v3; // ebp
  _DWORD *v4; // ebx
  _DWORD *v5; // esi
  int v6; // ecx
  int v7; // ebp
  int v8; // edi
  int result; // eax
  int v10; // ebp

  v2 = this;
  while ( 1 )
  {
    v3 = a2;
    v4 = v2 + 16;
    if ( (*(_BYTE *)(a2 + 60) & 0x10) == 0 )
      v4 = v2 + 15;
    v5 = *(_DWORD **)(a2 + 516);
    if ( v5 )
    {
      do
      {
        v6 = v2[13] + 1;
        v2[14] += v5[72];
        v2[13] = v6;
        v7 = 0;
        if ( (int)v5[70] > 0 )
        {
          v8 = 0;
          do
          {
            *(_WORD *)(v5[71] + v8 + 2) = 0;
            *(_DWORD *)(v5[71] + v8) |= *(_DWORD *)(v5[71] + v8) << 16;
            sub_5473C0(*(_DWORD *)(v5[71] + v8 + 4));
            *v4 += *(_DWORD *)(v5[71] + v8 + 8);
            ++v7;
            v8 += 64;
          }
          while ( v7 < v5[70] );
          v2 = this;
        }
        v5 = (_DWORD *)v5[4];
      }
      while ( v5 );
      v3 = a2;
    }
    ++v2[25];
    result = *(_DWORD *)(v3 + 68);
    if ( result )
      result = sub_544C50(*(_DWORD *)(v3 + 68));
    v10 = *(_DWORD *)(v3 + 76);
    if ( !v10 )
      break;
    a2 = v10;
  }
  return result;
}
