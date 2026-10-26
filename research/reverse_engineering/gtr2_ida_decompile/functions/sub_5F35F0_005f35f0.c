int *__thiscall sub_5F35F0(_DWORD *this, int *a2, int a3)
{
  int *v3; // edi
  int v5; // esi
  int v6; // eax
  int v7; // eax

  v3 = a2;
  if ( (*(_BYTE *)a2 & 0x10) == 0 || !sub_5E7150(a2, 0) )
    return 0;
  switch ( a3 )
  {
    case 0:
      v5 = 0;
      break;
    case 1:
      v5 = 1;
      break;
    case 2:
      v5 = 2;
      break;
    case 3:
      v5 = 3;
      break;
    case 4:
      v5 = 4;
      break;
    case 5:
      v5 = 5;
      break;
    default:
      v5 = (int)a2;
      break;
  }
  v6 = sub_5E7150(v3, 0);
  v7 = (*(int (__stdcall **)(int, int, _DWORD, int **))(*(_DWORD *)v6 + 72))(v6, v5, 0, &a2);
  this[2] = v7;
  if ( !v7 )
    return a2;
  else
    return 0;
}
