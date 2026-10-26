int __thiscall sub_5503A0(_DWORD *this)
{
  _DWORD *v2; // edx
  int *v3; // edi
  int v4; // eax
  int v5; // ebp
  int *v6; // esi
  int v7; // eax
  int v8; // ecx
  _DWORD *i; // [esp+4h] [ebp-8h]
  int v11; // [esp+8h] [ebp-4h]

  for ( i = (_DWORD *)this[129]; i; i = (_DWORD *)v2[4] )
  {
    v2 = i;
    if ( (i[5] & 0x80000) != 0 && i[70] )
    {
      v3 = (int *)(i[71] + 52);
      v11 = i[70];
      do
      {
        v4 = *(v3 - 12);
        v5 = 0;
        if ( *(int *)(v4 + 164) > 0 )
        {
          v6 = (int *)(*(_DWORD *)(v4 + 168) + 80);
          do
          {
            if ( *(v6 - 2) > 1 )
            {
              v7 = *v3;
              v8 = *v6;
              if ( *v3 < *v6 && (*(_BYTE *)(v6 - 4) & 4) != 0 )
              {
                switch ( v6[1] & 0xFFFF000F )
                {
                  case 1u:
                    if ( ++v7 >= v8 )
                      v7 = v8 - v7;
                    break;
                  case 2u:
                    if ( v7 < v8 - 1 )
                      ++v7;
                    if ( v7 >= v8 )
                      v7 = v8 - 1;
                    break;
                  case 3u:
                    if ( v7 == v8 - 1 )
                      v7 = -v7;
                    ++v7;
                    break;
                  case 4u:
                    if ( ++v7 >= v8 )
                    {
                      FlagFieldBitManipulation(this, 0, 0, 1, 0);
                      v7 = -1;
                    }
                    break;
                  default:
                    break;
                }
                *v3 = v7;
              }
            }
            v6 += 37;
            ++v5;
          }
          while ( v5 < *(_DWORD *)(*(v3 - 12) + 164) );
          v2 = i;
        }
        v3 += 16;
        --v11;
      }
      while ( v11 );
    }
  }
  return 0;
}
