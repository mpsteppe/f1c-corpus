int __stdcall sub_4E31D0(int a1)
{
  int v1; // esi
  int v2; // ebx
  char *v3; // edx
  int v4; // ebp
  int v5; // eax
  int v7; // [esp+Ch] [ebp-204h]
  char Destination[509]; // [esp+10h] [ebp-200h] BYREF
  __int16 v9; // [esp+20Dh] [ebp-3h]
  char v10; // [esp+20Fh] [ebp-1h]

  v1 = 0;
  v7 = 0;
  if ( a1 >= 0 && a1 < dword_7D6A58 )
  {
    v2 = dword_7D6A5C + 1232 * a1;
    if ( v2 )
    {
      if ( sub_57AE50(aSeasonraces) )
      {
        v3 = dword_766594;
        if ( !dword_766594 )
          v3 = &byte_629120;
        if ( sub_57A720(v3) )
        {
          if ( sub_57A720(aPaintschemes) )
          {
            v4 = sub_57A720((char *)(v2 + 246));
            if ( v4 )
            {
              Destination[0] = byte_629120;
              memset(&Destination[1], 0, 0x1FCu);
              v9 = 0;
              v10 = 0;
              if ( *(int *)(v2 + 1228) > 0 )
              {
                while ( 1 )
                {
                  if ( (unsigned __int8)sub_4E7140(v1, Destination, 512) )
                  {
                    v5 = sub_57A6D0(v4);
                    if ( sub_579060(Destination, v5) )
                      break;
                  }
                  if ( ++v1 >= *(_DWORD *)(v2 + 1228) )
                    return 0;
                }
                return v1;
              }
            }
          }
        }
      }
    }
  }
  return v7;
}
