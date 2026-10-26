int __thiscall sub_5A2740(_DWORD *this)
{
  _DWORD *v2; // edx
  _DWORD *v3; // edi
  int v4; // ebp
  int *v5; // esi
  int v6; // eax
  _DWORD *i; // [esp+4h] [ebp-8h]
  int v9; // [esp+8h] [ebp-4h]

  for ( i = (_DWORD *)this[129]; i; i = (_DWORD *)v2[4] )
  {
    v2 = i;
    if ( (i[5] & 0x80000) != 0 && i[70] )
    {
      v3 = (_DWORD *)(i[71] + 4);
      v9 = i[70];
      do
      {
        v4 = 0;
        if ( *(int *)(*v3 + 172) > 0 )
        {
          v5 = (int *)(*(_DWORD *)(*v3 + 176) + 80);
          do
          {
            if ( *(v5 - 2) > 1 && (*(_BYTE *)(v5 - 4) & 4) != 0 )
            {
              v6 = v3[12];
              switch ( v5[1] & 0xFFFF000F )
              {
                case 1u:
                  if ( ++v6 >= *v5 )
                    v6 = *v5 - v6;
                  break;
                case 2u:
                  if ( v6 < *v5 - 1 )
                    ++v6;
                  if ( v6 >= *v5 )
                    v6 = *v5 - 1;
                  break;
                case 3u:
                  if ( v6 == *v5 - 1 )
                    v6 = -v6;
                  ++v6;
                  break;
                case 4u:
                  if ( ++v6 >= *v5 )
                  {
                    sub_59ECC0(this, 0, 0, 1, 0);
                    v6 = -1;
                  }
                  break;
                default:
                  break;
              }
              v3[12] = v6;
            }
            v5 += 37;
            ++v4;
          }
          while ( v4 < *(_DWORD *)(*v3 + 172) );
          v2 = i;
        }
        v3 += 16;
        --v9;
      }
      while ( v9 );
    }
  }
  return 0;
}
