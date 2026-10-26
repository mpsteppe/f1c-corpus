int __thiscall sub_40E1A0(_DWORD *this, int a2, int a3, int a4)
{
  int result; // eax
  int v5; // esi
  int v6; // eax
  int v7; // eax
  float v8; // [esp+Ch] [ebp-8h]
  float v9; // [esp+Ch] [ebp-8h]
  float v10; // [esp+Ch] [ebp-8h]
  float v11; // [esp+Ch] [ebp-8h]

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
      v5 = result + 204 * this[15];
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
        v8 = dbl_FB1D08;
        sub_46DCD0(byte_91BF18, 1, v8);
      }
      else if ( a2 == 1 )
      {
        v9 = dbl_FB1D08;
        sub_46DCD0(byte_757680, 1, v9);
      }
      if ( a3 == -1 )
      {
        v6 = (unsigned __int8)byte_91BF18;
      }
      else
      {
        if ( a3 != 1 )
          goto LABEL_21;
        v6 = (unsigned __int8)byte_757680;
      }
      v10 = dbl_FB1D08;
      (*(void (__thiscall **)(int, int, _DWORD, _DWORD))(*(_DWORD *)v5 + 12))(v5, v6, 0, LODWORD(v10));
LABEL_21:
      result = a4;
      if ( a4 == -1 )
      {
        v7 = (unsigned __int8)byte_757680;
      }
      else
      {
        if ( a4 != 1 )
          return result;
        v7 = (unsigned __int8)byte_91BF18;
      }
      v11 = dbl_FB1D08;
      return (*(int (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v5 + 16))(v5, v7, 1, LODWORD(v11));
    default:
      return result;
  }
}
