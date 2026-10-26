void __thiscall sub_556D60(void *this, _DWORD *a2, int a3)
{
  int v3; // esi
  _DWORD *v4; // ebp
  int v5; // edi
  _DWORD *v6; // eax
  int v7; // edx
  int v8; // edx
  _DWORD *v9; // edx
  int v10; // [esp+4h] [ebp-4h]

  v10 = 0;
  if ( (a2[5] & 0x2000000) == 0 )
  {
    v3 = a2[71];
    if ( (int)a2[70] > 0 )
    {
      v4 = (_DWORD *)dword_8B8F28;
      while ( 1 )
      {
        v5 = *(_DWORD *)(v3 + 4);
        v6 = 0;
        if ( (*(_DWORD *)(v5 + 156) & 0x120) == 0 )
          break;
        switch ( *(_DWORD *)(v5 + 156) & 0x120 )
        {
          case 32:
            v7 = v4[116];
            goto LABEL_12;
          case 256:
            v7 = v4[110];
            goto LABEL_12;
          case 288:
            v7 = v4[114];
            goto LABEL_12;
        }
LABEL_13:
        v8 = v6[130];
        if ( v8 < v6[129] )
        {
          v9 = (_DWORD *)(v6[131] + 16 * v8);
          *v9 = this;
          v9[1] = a2;
          v9[2] = v3;
          v9[3] = *(_DWORD *)(v3 + 4);
          ++v6[130];
          v4 = (_DWORD *)dword_8B8F28;
        }
        if ( (a2[5] & 0x1000000) == 0 )
        {
          *(_DWORD *)(v3 + 56) &= ~0x200u;
          v4 = (_DWORD *)dword_8B8F28;
        }
        if ( (a2[5] & 0x20) == 0 )
        {
          *(_DWORD *)(v3 + 56) &= ~0x100u;
          v4 = (_DWORD *)dword_8B8F28;
        }
        v3 += 64;
        if ( ++v10 >= a2[70] )
          goto LABEL_20;
      }
      v7 = v4[112];
LABEL_12:
      v6 = (_DWORD *)(v7 + 528 * *(_DWORD *)(v5 + 160));
      goto LABEL_13;
    }
LABEL_20:
    a2[5] |= 0x1000020u;
  }
}

