int __thiscall sub_4AF220(_DWORD *this)
{
  int result; // eax
  int v2; // eax
  int v3; // esi
  int v4; // edx
  int v5; // eax
  int v6; // esi
  int v7; // edx
  int v8; // eax
  int v9; // esi
  int v10; // edx
  int v11; // eax
  int v12; // esi
  int v13; // edx
  int v14; // edx
  int v15; // esi

  result = this[1741] - 1;
  switch ( this[1741] )
  {
    case 1:
      v2 = this[872];
      v3 = this[873];
      this[870] = 12;
      v4 = this[870];
      if ( v4 >= v2 )
      {
        if ( v4 > v3 )
          this[870] = v3;
        this[1116] = 0;
      }
      else
      {
        this[870] = v2;
        this[1116] = 0;
      }
      goto LABEL_22;
    case 2:
      v5 = this[872];
      v6 = this[873];
      this[870] = 14;
      v7 = this[870];
      if ( v7 >= v5 )
      {
        if ( v7 > v6 )
          this[870] = v6;
        this[1116] = 1;
      }
      else
      {
        this[870] = v5;
        this[1116] = 1;
      }
      goto LABEL_22;
    case 3:
      v8 = this[872];
      v9 = this[873];
      this[870] = 16;
      v10 = this[870];
      if ( v10 >= v8 )
      {
        if ( v10 > v9 )
          this[870] = v9;
        this[1116] = 2;
      }
      else
      {
        this[870] = v8;
        this[1116] = 2;
      }
      goto LABEL_22;
    case 4:
      v11 = this[872];
      v12 = this[873];
      this[870] = 16;
      v13 = this[870];
      if ( v13 >= v11 )
      {
        if ( v13 > v12 )
          this[870] = v12;
      }
      else
      {
        this[870] = v11;
      }
      this[1116] = 3;
LABEL_22:
      v14 = this[1116];
      result = this[1118];
      v15 = this[1119];
      if ( v14 >= result )
      {
        if ( v14 > v15 )
          this[1116] = v15;
      }
      else
      {
        this[1116] = result;
      }
      break;
    default:
      return result;
  }
  return result;
}
