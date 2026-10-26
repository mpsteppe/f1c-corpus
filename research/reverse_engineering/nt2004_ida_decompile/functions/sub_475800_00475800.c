int __thiscall sub_475800(_DWORD *this)
{
  char *v2; // eax
  int result; // eax
  int i; // ebx
  int v5; // ecx
  int *v6; // eax
  int v7; // eax
  int v8; // esi
  int v9; // ecx
  int v10; // esi
  int v11; // edx
  char String2[509]; // [esp+10h] [ebp-400h] BYREF
  __int16 v13; // [esp+20Dh] [ebp-203h]
  char v14; // [esp+20Fh] [ebp-201h]
  char String1[509]; // [esp+210h] [ebp-200h] BYREF
  __int16 v16; // [esp+40Dh] [ebp-3h]
  char v17; // [esp+40Fh] [ebp-1h]

  String2[0] = byte_629120;
  memset(&String2[1], 0, 0x1FCu);
  v13 = 0;
  v14 = 0;
  v2 = dword_766594;
  if ( !dword_766594 )
    v2 = &byte_629120;
  sub_4E8E50(String2, 511, aTrackname_0, v2);
  result = this[74];
  for ( i = 0; i < result; ++i )
  {
    v5 = i;
    if ( i >= 0 && i < this[74] )
    {
      v6 = (int *)this[71];
      if ( i <= 0 )
      {
LABEL_9:
        if ( v6 )
        {
          v7 = *v6;
          if ( v7 )
          {
            v8 = *(_DWORD *)(v7 + 84);
            if ( v8 )
            {
              String1[0] = byte_629120;
              memset(&String1[1], 0, 0x1FCu);
              v16 = 0;
              v17 = 0;
              sub_4E8E50(String1, 511, aTrackname_0, (char *)(v8 + 260));
              if ( !_strcmpi(String1, String2) )
              {
                this[105] = i;
                result = *(unsigned __int8 *)(v8 + 392);
                if ( !(_BYTE)result )
                {
                  result = 36 * *(_DWORD *)dword_7689CC;
                  if ( dword_767454[9 * *(_DWORD *)dword_7689CC] == 4 )
                  {
                    v9 = dword_76745C[9 * *(_DWORD *)dword_7689CC];
                    v10 = dword_767460[9 * *(_DWORD *)dword_7689CC];
                    dword_767454[9 * *(_DWORD *)dword_7689CC] = 0;
                    v11 = *(int *)((char *)dword_767454 + result);
                    if ( v11 >= v9 )
                    {
                      if ( v11 > v10 )
                        *(int *)((char *)dword_767454 + result) = v10;
                    }
                    else
                    {
                      *(int *)((char *)dword_767454 + result) = v9;
                    }
                  }
                }
                return result;
              }
            }
          }
        }
      }
      else
      {
        while ( v6 )
        {
          v6 = (int *)v6[1];
          if ( --v5 <= 0 )
            goto LABEL_9;
        }
      }
    }
    result = this[74];
  }
  return result;
}
