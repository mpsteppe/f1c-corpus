int __stdcall sub_677730(int *a1)
{
  int v1; // ecx
  int v2; // edi
  int result; // eax
  int v4; // eax

  v1 = a1[5];
  v2 = 0;
  switch ( v1 )
  {
    case 200:
      (*(void (__stdcall **)(int *))(a1[110] + 4))(a1);
      (*(void (__stdcall **)(int *))(a1[6] + 8))(a1);
      a1[5] = 201;
      goto LABEL_3;
    case 201:
LABEL_3:
      v2 = (*(int (__stdcall **)(int *))a1[110])(a1);
      if ( v2 != 1 )
        goto LABEL_8;
      sub_6775C0(a1);
      result = 1;
      a1[5] = 202;
      break;
    case 202:
      return 1;
    case 203:
    case 204:
    case 205:
    case 206:
    case 207:
    case 208:
    case 210:
      return (*(int (__stdcall **)(int *))a1[110])(a1);
    default:
      v4 = *a1;
      *(_DWORD *)(v4 + 20) = 20;
      *(_DWORD *)(v4 + 24) = v1;
      (*(void (__stdcall **)(int *))v4)(a1);
LABEL_8:
      result = v2;
      break;
  }
  return result;
}
