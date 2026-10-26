int __thiscall sub_42D140(_DWORD *this, unsigned int a2)
{
  int result; // eax
  int v4; // eax
  char v5; // cl
  int i; // esi

  result = a2;
  if ( this[3] != a2 )
  {
    this[3] = a2;
    if ( a2 > 2 )
      result = sub_4D2E20(&unk_8ACEE0);
    if ( dword_7C569C == 5 )
    {
      switch ( this[3] )
      {
        case 0:
        case 2:
        case 4:
          goto LABEL_11;
        case 3:
          if ( byte_7CEC78 )
          {
            if ( sub_423A00(byte_5EC4C0, aBeginFormation, byte_5EC4CC) )
            {
              v4 = 0;
              do
              {
                v5 = aBeginFormation[v4];
                byte_5EC4CC[v4++] = v5;
              }
              while ( v5 );
            }
            sub_45BD10(byte_5EC4CC, 3, 16909060);
          }
LABEL_11:
          result = dword_5C329C;
          for ( i = 0; i < dword_5C329C; ++i )
          {
            sub_4C6B60(0);
            result = dword_5C329C;
          }
          break;
        default:
          return result;
      }
    }
  }
  return result;
}
