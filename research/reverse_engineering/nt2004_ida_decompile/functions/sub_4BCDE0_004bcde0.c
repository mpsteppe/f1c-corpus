int __stdcall sub_4BCDE0(char *a1, const char *a2)
{
  __int16 v2; // dx
  char *v3; // edi
  char *v4; // edi
  __int16 v5; // cx
  __int16 v6; // ax
  char *v7; // edi
  int result; // eax
  char v9[61]; // [esp+8h] [ebp-40h] BYREF
  __int16 v10; // [esp+45h] [ebp-3h]
  char v11; // [esp+47h] [ebp-1h]

  v9[0] = byte_629120;
  memset(&v9[1], 0, 0x3Cu);
  v10 = 0;
  v11 = 0;
  strcpy(v9, a2);
  switch ( dword_767BEC )
  {
    case 0:
      v6 = word_609D28;
      v7 = &v9[strlen(v9)];
      *(_DWORD *)v7 = dword_609D24;
      *((_WORD *)v7 + 2) = v6;
      break;
    case 1:
      v4 = &v9[strlen(v9) + 1];
      v5 = word_609D30;
      *(_DWORD *)--v4 = dword_609D2C;
      *((_WORD *)v4 + 2) = v5;
      break;
    case 2:
    case 3:
      v2 = word_609D38;
      v3 = &v9[strlen(v9)];
      *(_DWORD *)v3 = dword_609D34;
      *((_WORD *)v3 + 2) = v2;
      break;
    default:
      break;
  }
  result = 0;
  strcat(a1, v9);
  return result;
}
