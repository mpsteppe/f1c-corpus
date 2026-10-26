int __stdcall sub_44AF60(_DWORD *a1, int a2, int a3, int a4)
{
  int result; // eax
  int v5; // edx
  int v6; // ecx
  int v7; // edx

  switch ( a3 )
  {
    case 1:
      result = 0;
      v5 = 1;
      v6 = 2;
      break;
    case 2:
      result = 1;
      v5 = 2;
      v6 = 0;
      break;
    case 3:
      result = 2;
      v5 = 0;
      v6 = 1;
      break;
    default:
      result = a2;
      v5 = a2;
      v6 = a2;
      break;
  }
  if ( a4 )
  {
    *a1 = *(_DWORD *)(*(_DWORD *)(a2 + 4 * v5) + 8 * result);
    a1[1] = *(_DWORD *)(*(_DWORD *)(a2 + 4 * v5) + 8 * result + 4);
    a1[2] = *(_DWORD *)(*(_DWORD *)(a2 + 4 * v5) + 8 * v5);
    a1[3] = *(_DWORD *)(*(_DWORD *)(a2 + 4 * v6) + 8 * v5);
    a1[4] = *(_DWORD *)(*(_DWORD *)(a2 + 4 * v6) + 8 * v6);
    v7 = *(_DWORD *)(*(_DWORD *)(a2 + 4 * v6) + 8 * result + 4);
  }
  else
  {
    *a1 = *(_DWORD *)(*(_DWORD *)(a2 + 4 * result) + 8 * result);
    a1[1] = *(_DWORD *)(*(_DWORD *)(a2 + 4 * result) + 8 * result + 4);
    a1[2] = *(_DWORD *)(*(_DWORD *)(a2 + 4 * result) + 8 * v5);
    a1[3] = *(_DWORD *)(*(_DWORD *)(a2 + 4 * v6) + 8 * result + 4);
    a1[4] = *(_DWORD *)(*(_DWORD *)(a2 + 4 * v6) + 8 * v6);
    v7 = *(_DWORD *)(*(_DWORD *)(a2 + 4 * v6) + 8 * result);
  }
  a1[5] = v7;
  return result;
}
