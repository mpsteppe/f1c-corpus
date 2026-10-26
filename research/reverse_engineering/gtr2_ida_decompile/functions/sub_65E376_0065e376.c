char *__thiscall sub_65E376(int this, char *a2, int *a3)
{
  unsigned int v4; // eax
  char *v5; // edi
  char *v7; // esi
  char v8; // cl
  unsigned int v9; // ebx
  int v10; // ecx
  char v11; // al
  int v12; // edi
  char v13; // al
  int v14; // edi
  int v15; // eax

  v4 = *(_DWORD *)(this + 4);
  v5 = a2;
  if ( (unsigned int)a2 >= v4 )
    return 0;
  if ( *a2 != 92 || (*(_BYTE *)(this + 40) & 4) != 0 )
  {
    v15 = *a2;
    v7 = a2 + 1;
LABEL_48:
    *a3 = v15;
    return (char *)(v7 - v5);
  }
  v7 = a2 + 1;
  if ( (unsigned int)(a2 + 1) >= v4 )
    sub_65DD1F(*(_DWORD **)(this + 48), this + 8, 1007, "character continues past end of file");
  v8 = *v7;
  switch ( *v7 )
  {
    case 'a':
      *a3 = 7;
      break;
    case 'b':
      *a3 = 8;
      break;
    case 'f':
      *a3 = 12;
      break;
    case 'n':
      *a3 = 10;
      break;
    case 'r':
      *a3 = 13;
      break;
    case 't':
      *a3 = 9;
      break;
    case 'v':
      *a3 = 11;
      break;
    default:
      if ( v8 >= 48 && v8 <= 55 )
      {
        v9 = *(_DWORD *)(this + 4);
        if ( (unsigned int)(a2 + 4) < v9 )
          v9 = (unsigned int)(a2 + 4);
        v10 = 0;
        while ( (unsigned int)v7 < v9 )
        {
          v11 = *v7;
          if ( *v7 < 48 || v11 > 55 )
            break;
          v10 = v11 + 8 * v10 - 48;
          ++v7;
        }
        *a3 = v10;
        return (char *)(v7 - v5);
      }
      if ( v8 == 120 )
      {
        if ( (unsigned int)(a2 + 2) < *(_DWORD *)(this + 4) && isxdigit(a2[2]) )
        {
          v7 = a2 + 2;
          v12 = 0;
          while ( (unsigned int)v7 < *(_DWORD *)(this + 4) && isxdigit(*v7) )
          {
            v13 = *v7;
            v14 = 16 * v12;
            if ( *v7 < 97 )
            {
              if ( v13 < 65 )
                v12 = v14 + v13 - 48;
              else
                v12 = v14 + v13 - 55;
            }
            else
            {
              v12 = v14 + v13 - 87;
            }
            ++v7;
          }
          *a3 = v12;
          v5 = a2;
          return (char *)(v7 - v5);
        }
        v5 = a2;
      }
      v15 = *v7;
      v7 = a2 + 2;
      goto LABEL_48;
  }
  v7 = a2 + 2;
  return (char *)(v7 - v5);
}
