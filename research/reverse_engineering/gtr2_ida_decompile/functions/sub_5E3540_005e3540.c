int __fastcall sub_5E3540(int a1)
{
  _DWORD *v1; // edi
  int v2; // esi
  int v3; // eax
  int i; // ebx
  int v5; // eax
  int v6; // edx
  int v7; // ecx
  bool v8; // cc
  int v10; // [esp+0h] [ebp-Ch]
  int v11; // [esp+4h] [ebp-8h]
  int v12; // [esp+8h] [ebp-4h]

  v11 = a1;
  if ( *(char *)a1 < 0 )
  {
    v12 = 0;
    if ( *(int *)(a1 + 360) > 0 )
    {
      v10 = 0;
      while ( 1 )
      {
        v1 = (_DWORD *)(v10 + *(_DWORD *)(a1 + 364));
        v2 = sub_5E8220(99);
        v3 = sub_5E82A0(99);
        for ( i = v2 + v3; v2 < i; ++v2 )
        {
          v5 = sub_5E80D0(v2);
          if ( *(int *)(v5 + 4) > 1 && (*v1 & 0x300000) == 0 )
          {
            v6 = *(_DWORD *)(v5 + 80);
            v7 = v1[23];
            if ( v7 < v6 && (*(_BYTE *)(v5 + 2) & 1) != 0 )
            {
              switch ( *(_DWORD *)(v5 + 84) & 0xFFFF000F )
              {
                case 1u:
                  if ( ++v7 >= v6 )
                    v7 = v6 - v7;
                  break;
                case 2u:
                  if ( v7 < v6 - 1 )
                    ++v7;
                  if ( v7 >= v6 )
                    v7 = v6 - 1;
                  break;
                case 3u:
                  if ( v7 == v6 - 1 )
                    v7 = -v7;
                  ++v7;
                  break;
                case 4u:
                  if ( ++v7 >= v6 )
                  {
                    sub_5DB320(*(unsigned int **)(v11 + 392), 0, 0, 0);
                    v7 = -1;
                  }
                  break;
                default:
                  break;
              }
              v1[23] = v7;
            }
          }
        }
        v8 = ++v12 < *(_DWORD *)(v11 + 360);
        v10 += 108;
        if ( !v8 )
          break;
        a1 = v11;
      }
    }
  }
  return 0;
}
