// f1c  0x00534d50  size=276
int __thiscall sub_534D50(int *this)
{
  int v2; // edi
  int v3; // eax
  int v4; // edi
  int result; // eax
  char v6; // bl
  int v7; // edi
  int v8; // edi
  int v9; // edi
  int v11; // edi
  int v12; // ecx
  int v13; // eax

  v2 = 0;
  while ( 1 )
  {
    v3 = sub_534E70(this);
    if ( v3 != dword_5DA780[v2] )
      break;
    if ( (unsigned int)++v2 >= 2 )
    {
      v4 = sub_534E70(this);
      result = sub_534E70(this);
      v6 = result;
      if ( v4 != 8 || (result & 0xE0) != 0 )
      {
        this[14] = -3;
      }
      else
      {
        v7 = 6;
        do
        {
          result = sub_534E70(this);
          --v7;
        }
        while ( v7 );
        if ( (v6 & 4) != 0 )
        {
          v8 = sub_534E70(this);
          result = sub_534E70(this) << 8;
          v9 = result + v8;
          do
          {
            if ( !v9-- )
              break;
            result = sub_534E70(this);
          }
          while ( result != -1 );
        }
        if ( (v6 & 8) != 0 )
        {
          do
            result = sub_534E70(this);
          while ( result && result != -1 );
        }
        if ( (v6 & 0x10) != 0 )
        {
          do
            result = sub_534E70(this);
          while ( result && result != -1 );
        }
        if ( (v6 & 2) != 0 )
        {
          v11 = 2;
          do
          {
            result = sub_534E70(this);
            --v11;
          }
          while ( v11 );
        }
        this[14] = this[15] != 0 ? 0xFFFFFFFD : 0;
      }
      return result;
    }
  }
  if ( v2 )
  {
    v12 = *this - 1;
    ++this[1];
    *this = v12;
  }
  if ( v3 != -1 )
  {
    v13 = *this - 1;
    ++this[1];
    *this = v13;
    this[22] = 1;
  }
  result = this[1] == 0;
  this[14] = result;
  return result;
}
