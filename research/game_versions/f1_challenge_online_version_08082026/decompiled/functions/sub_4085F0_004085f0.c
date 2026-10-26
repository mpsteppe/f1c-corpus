int __thiscall sub_4085F0(_DWORD *this, int a2, int a3, int a4)
{
  int result; // eax
  int v5; // esi
  int v6; // eax
  int v7; // edx
  double v8; // st7
  int v9; // eax
  int v10; // edx
  int v11; // edx
  float v12; // [esp+Ch] [ebp-Ch]
  float v13; // [esp+Ch] [ebp-Ch]
  float v14; // [esp+Ch] [ebp-Ch]
  float v15; // [esp+Ch] [ebp-Ch]
  float v16; // [esp+Ch] [ebp-Ch]

  result = this[13];
  switch ( result )
  {
    case 0:
      v5 = this[4];
      goto LABEL_11;
    case 1:
      v5 = this[5];
      goto LABEL_11;
    case 2:
      v5 = this[6];
      goto LABEL_11;
    case 3:
      v5 = this[7];
      goto LABEL_11;
    case 4:
      result = this[8];
      v5 = result + 200 * this[15];
      goto LABEL_11;
    case 5:
      v5 = this[9];
      goto LABEL_11;
    case 6:
      v5 = this[10];
      goto LABEL_11;
    case 7:
      v5 = this[11];
      goto LABEL_11;
    case 8:
      v5 = this[12];
LABEL_11:
      if ( !v5 )
        return result;
      if ( a2 == -1 )
      {
        v12 = sub_4084A0();
        sub_456F70(byte_5EA55C, 1, v12);
      }
      else if ( a2 == 1 )
      {
        v13 = sub_4084A0();
        sub_456F70(byte_5BE870, v6, v13);
      }
      if ( a3 == -1 )
      {
        v8 = sub_4084A0();
        v9 = (unsigned __int8)byte_5EA55C;
      }
      else
      {
        if ( a3 != 1 )
          goto LABEL_21;
        v8 = sub_4084A0();
        v9 = (unsigned __int8)byte_5BE870;
      }
      v14 = v8;
      (*(void (__thiscall **)(int, int, _DWORD, _DWORD))(v7 + 12))(v5, v9, 0, LODWORD(v14));
LABEL_21:
      result = a4;
      if ( a4 == -1 )
      {
        v15 = sub_4084A0();
        return (*(int (__thiscall **)(int, _DWORD, int, _DWORD))(v10 + 16))(
                 v5,
                 (unsigned __int8)byte_5BE870,
                 1,
                 LODWORD(v15));
      }
      else if ( a4 == 1 )
      {
        v16 = sub_4084A0();
        return (*(int (__thiscall **)(int, _DWORD, int, _DWORD))(v11 + 16))(
                 v5,
                 (unsigned __int8)byte_5EA55C,
                 1,
                 LODWORD(v16));
      }
      return result;
    default:
      return result;
  }
}
