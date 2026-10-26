int __thiscall sub_50BB30(_DWORD *this)
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

  result = this[2589] - 1;
  switch ( this[2589] )
  {
    case 1:
      v2 = this[1240];
      v3 = this[1241];
      this[1238] = 12;
      v4 = this[1238];
      if ( v4 >= v2 )
      {
        if ( v4 > v3 )
          this[1238] = v3;
        this[1583] = 0;
      }
      else
      {
        this[1238] = v2;
        this[1583] = 0;
      }
      goto LABEL_22;
    case 2:
      v5 = this[1240];
      v6 = this[1241];
      this[1238] = 14;
      v7 = this[1238];
      if ( v7 >= v5 )
      {
        if ( v7 > v6 )
          this[1238] = v6;
        this[1583] = 1;
      }
      else
      {
        this[1238] = v5;
        this[1583] = 1;
      }
      goto LABEL_22;
    case 3:
      v8 = this[1240];
      v9 = this[1241];
      this[1238] = 16;
      v10 = this[1238];
      if ( v10 >= v8 )
      {
        if ( v10 > v9 )
          this[1238] = v9;
        this[1583] = 2;
      }
      else
      {
        this[1238] = v8;
        this[1583] = 2;
      }
      goto LABEL_22;
    case 4:
      v11 = this[1240];
      v12 = this[1241];
      this[1238] = 16;
      v13 = this[1238];
      if ( v13 >= v11 )
      {
        if ( v13 > v12 )
          this[1238] = v12;
      }
      else
      {
        this[1238] = v11;
      }
      this[1583] = 3;
LABEL_22:
      result = off_16C98A4();
      break;
    default:
      return result;
  }
  return result;
}
