_DWORD *__thiscall sub_697C19(_DWORD *this, _DWORD *a2)
{
  _DWORD *v3; // eax
  unsigned int v4; // eax
  _DWORD *v5; // eax
  _DWORD *v6; // esi
  _DWORD *v7; // eax
  _DWORD *v8; // eax
  _DWORD *v9; // eax
  _DWORD *v10; // eax
  _DWORD *v11; // eax
  _DWORD *v12; // eax
  int v15; // [esp+18h] [ebp+8h]

  if ( !a2 )
    return 0;
  if ( a2[1] != 15 )
    return 0;
  v3 = (_DWORD *)a2[12];
  if ( !v3 || a2[13] < 4u )
    return 0;
  v4 = *v3 & 0xFFFF0000;
  switch ( v4 )
  {
    case 0x7FFE0000u:
      v15 = 28;
      break;
    case 0x7FFF0000u:
      v15 = 27;
      break;
    case 0xFFFE0000:
      v15 = 26;
      break;
    case 0xFFFF0000:
      v15 = 25;
      break;
    default:
      return 0;
  }
  v5 = (_DWORD *)sub_65B229(80);
  if ( v5 )
    v6 = sub_67F5FE(v5, 0, 0, 0, 0, 1, a2 + 4);
  else
    v6 = 0;
  if ( v6 )
  {
    v7 = (_DWORD *)sub_65B229(36);
    v8 = v7 ? sub_67F2D4(v7, 3, v15, 1, 1, 512) : 0;
    v6[4] = v8;
    if ( v8 )
    {
      v9 = (_DWORD *)sub_65B229(64);
      v10 = v9 ? sub_67F7B5(v9, 5, a2[12], a2[13], a2 + 4) : 0;
      v6[8] = v10;
      if ( v10 )
      {
        v11 = (_DWORD *)sub_65B229(20);
        v12 = v11 ? sub_67ED1B(v11, v6[8], 0, (int)"Value") : 0;
        if ( v12 )
        {
          v6[8] = v12;
          sub_695BDE(this, v6);
          return v6;
        }
      }
    }
  }
  return 0;
}
