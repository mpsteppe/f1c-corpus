int __stdcall sub_6D8820(int *a1)
{
  int *(__stdcall **v1)(int); // edi
  int v2; // eax
  int v3; // eax
  int result; // eax
  int v5; // eax
  int v6; // eax
  bool v7; // zf
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax

  v1 = (int *(__stdcall **)(int))(*(int (__stdcall **)(int *, int, int))a1[1])(a1, 1, 12);
  v2 = a1[10] - 1;
  a1[90] = (int)v1;
  *v1 = (int *(__stdcall *)(int))pfnAPC;
  switch ( v2 )
  {
    case 0:
      if ( a1[9] != 1 )
        goto LABEL_9;
      break;
    case 1:
    case 2:
      if ( a1[9] != 3 )
        goto LABEL_9;
      break;
    case 3:
    case 4:
      if ( a1[9] != 4 )
        goto LABEL_9;
      break;
    default:
      if ( a1[9] < 1 )
      {
LABEL_9:
        v3 = *a1;
        *(_DWORD *)(v3 + 20) = 9;
        (*(void (__stdcall **)(int *))v3)(a1);
      }
      break;
  }
  result = a1[16];
  switch ( result )
  {
    case 1:
      if ( a1[15] != 1 )
      {
        v5 = *a1;
        *(_DWORD *)(v5 + 20) = 10;
        (*(void (__stdcall **)(int *))v5)(a1);
      }
      result = a1[10];
      switch ( result )
      {
        case 1:
          goto LABEL_20;
        case 2:
          *v1 = sub_6D8160;
          v1[1] = (int *(__stdcall *)(int))sub_6D8470;
          break;
        case 6:
        case 7:
          *v1 = sub_6D8160;
          v1[1] = (int *(__stdcall *)(int))sub_6D8510;
          break;
        case 3:
LABEL_20:
          v1[1] = (int *(__stdcall *)(int))sub_6D8710;
          break;
        default:
          goto LABEL_41;
      }
      return result;
    case 2:
      if ( a1[15] != 3 )
      {
        v6 = *a1;
        *(_DWORD *)(v6 + 20) = 10;
        result = (*(int (__stdcall **)(int *))v6)(a1);
      }
      v7 = a1[10] == 2;
      goto LABEL_40;
    case 3:
      if ( a1[15] != 3 )
      {
        v8 = *a1;
        *(_DWORD *)(v8 + 20) = 10;
        (*(void (__stdcall **)(int *))v8)(a1);
      }
      result = a1[10];
      if ( result == 2 )
      {
        *v1 = sub_6D8160;
        v1[1] = (int *(__stdcall *)(int))sub_6D8230;
        return result;
      }
      if ( result == 6 || result == 7 )
      {
        *v1 = sub_6D8160;
        v1[1] = (int *(__stdcall *)(int))sub_6D8350;
        return result;
      }
      v7 = result == 3;
      goto LABEL_40;
    case 4:
      if ( a1[15] != 4 )
      {
        v9 = *a1;
        *(_DWORD *)(v9 + 20) = 10;
        result = (*(int (__stdcall **)(int *))v9)(a1);
      }
      v7 = a1[10] == 4;
      goto LABEL_40;
    case 5:
      if ( a1[15] != 4 )
      {
        v10 = *a1;
        *(_DWORD *)(v10 + 20) = 10;
        (*(void (__stdcall **)(int *))v10)(a1);
      }
      result = a1[10];
      if ( result == 4 )
      {
        *v1 = sub_6D8160;
        v1[1] = (int *(__stdcall *)(int))sub_6D85B0;
      }
      else
      {
        v7 = result == 5;
LABEL_40:
        if ( v7 )
        {
LABEL_45:
          v1[1] = (int *(__stdcall *)(int))sub_6D8780;
        }
        else
        {
LABEL_41:
          v11 = *a1;
          *(_DWORD *)(v11 + 20) = 27;
          return (*(int (__stdcall **)(int *))v11)(a1);
        }
      }
      return result;
    default:
      if ( result != a1[10] || a1[15] != a1[9] )
      {
        v12 = *a1;
        *(_DWORD *)(v12 + 20) = 27;
        result = (*(int (__stdcall **)(int *))v12)(a1);
      }
      goto LABEL_45;
  }
}
