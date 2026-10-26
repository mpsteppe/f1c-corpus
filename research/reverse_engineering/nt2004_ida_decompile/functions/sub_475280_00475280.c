_DWORD *__thiscall sub_475280(_DWORD *this)
{
  _DWORD *result; // eax
  int v3; // edx
  int i; // edi
  int v5; // ecx
  const char *v6; // eax
  char Destination[253]; // [esp+8h] [ebp-100h] BYREF
  __int16 v8; // [esp+105h] [ebp-3h]
  char v9; // [esp+107h] [ebp-1h]

  Destination[0] = byte_629120;
  memset(&Destination[1], 0, 0xFCu);
  v8 = 0;
  v9 = 0;
  result = (_DWORD *)sub_4CE010(Destination, 256);
  v3 = this[74];
  for ( i = 0; i < v3; ++i )
  {
    v5 = i;
    if ( i >= 0 && i < this[74] )
    {
      result = (_DWORD *)this[71];
      if ( i <= 0 )
      {
LABEL_7:
        if ( result )
        {
          result = (_DWORD *)*result;
          if ( result )
          {
            v6 = (const char *)result[16];
            if ( !v6 )
              v6 = &byte_629120;
            result = (_DWORD *)strcmp(v6, Destination);
            if ( !result )
              this[105] = i;
          }
        }
      }
      else
      {
        while ( result )
        {
          result = (_DWORD *)result[1];
          if ( --v5 <= 0 )
            goto LABEL_7;
        }
      }
    }
  }
  return result;
}
