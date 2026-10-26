int __thiscall sub_482230(_DWORD *this)
{
  int result; // eax
  int i; // edi
  int v4; // ecx
  int *v5; // eax
  int v6; // eax
  const char *v7; // eax
  int v8; // ecx
  int v9; // eax
  char Destination[253]; // [esp+8h] [ebp-100h] BYREF
  __int16 v11; // [esp+105h] [ebp-3h]
  char v12; // [esp+107h] [ebp-1h]

  Destination[0] = byte_629120;
  memset(&Destination[1], 0, 0xFCu);
  v11 = 0;
  v12 = 0;
  sub_4CE010(Destination, 256);
  result = this[220];
  for ( i = 0; i < result; ++i )
  {
    v4 = i;
    if ( i >= 0 && i < this[220] )
    {
      v5 = (int *)this[217];
      if ( i <= 0 )
      {
LABEL_7:
        if ( v5 )
        {
          v6 = *v5;
          if ( v6 )
          {
            v7 = *(const char **)(v6 + 64);
            if ( !v7 )
              v7 = &byte_629120;
            if ( !strcmp(v7, Destination) )
            {
              this[216] = i;
              v8 = i;
              if ( i >= this[220] )
              {
                this[219] = 0;
              }
              else
              {
                this[219] = this[217];
                if ( i > 0 )
                {
                  do
                  {
                    v9 = this[219];
                    if ( !v9 )
                      break;
                    --v8;
                    this[219] = *(_DWORD *)(v9 + 4);
                  }
                  while ( v8 > 0 );
                }
              }
              sub_482200();
            }
          }
        }
      }
      else
      {
        while ( v5 )
        {
          v5 = (int *)v5[1];
          if ( --v4 <= 0 )
            goto LABEL_7;
        }
      }
    }
    result = this[220];
  }
  return result;
}
