bool __thiscall sub_566940(int *this, const CHAR *a2, int a3, int a4, char a5)
{
  bool result; // al
  int v7; // eax
  int v8; // eax
  char v9; // cl
  int v10; // eax
  char v11; // cl
  int v12; // eax
  char v13; // cl
  bool v14; // bl
  _DWORD v15[2]; // [esp+8h] [ebp-408h]
  char v16[1024]; // [esp+10h] [ebp-400h] BYREF

  if ( !a5 || (result = sub_5668F0(a2)) )
  {
    this[4] = a3;
    this[3] = a4;
    sub_568620(1024);
    if ( a3 )
    {
      v15[1] = 0;
      v15[0] = dword_5E5170;
      switch ( this[4] )
      {
        case 2:
          v12 = 0;
          do
          {
            v13 = byte_5E5164[v12];
            *((_BYTE *)v15 + v12++) = v13;
          }
          while ( v13 );
          break;
        case 3:
          v10 = 0;
          do
          {
            v11 = byte_5E5168[v10];
            *((_BYTE *)v15 + v10++) = v11;
          }
          while ( v11 );
          break;
        case 4:
          v8 = 0;
          do
          {
            v9 = byte_5E516C[v8];
            *((_BYTE *)v15 + v8++) = v9;
          }
          while ( v9 );
          break;
      }
      if ( this[3] == 1 )
        BYTE1(v15[0]) = 116;
      v7 = sub_534B00();
      *this = v7;
    }
    else
    {
      if ( this[3] )
        v7 = sub_587DB0(v16, &unk_5E5174);
      else
        v7 = sub_587DB0(v16, &unk_5E5178);
      *this = v7;
    }
    v14 = v7 != 0;
    if ( v7 )
    {
      *((_BYTE *)this + 24) = 0;
      sub_566650((int)(this + 1), v16);
    }
    return v14;
  }
  return result;
}
