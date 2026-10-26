int __stdcall sub_5F32E0(_DWORD *a1)
{
  int v1; // ebx
  int v2; // ecx
  double v3; // st7
  int v4; // esi
  int v5; // edi
  unsigned __int64 v6; // rax
  int v7; // ebp
  int v8; // ecx
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  int v13; // [esp+4h] [ebp-4h]

  v1 = 0;
  if ( !a1 )
    return 0;
  v2 = a1[6];
  switch ( v2 )
  {
    case 3:
    case 5:
    case 6:
      v3 = 2.0;
      break;
    case 4:
      v3 = 1.0;
      break;
    case 7:
      v3 = 3.0;
      break;
    case 8:
    case 14:
      v3 = 4.0;
      break;
    default:
      v3 = 0.0;
      break;
  }
  v4 = a1[1];
  v5 = a1[2];
  if ( (int)a1[5] <= 0 )
    return 0;
  HIDWORD(v6) = v2 - 9;
  v13 = v2 - 9;
  v7 = a1[5];
  do
  {
    switch ( HIDWORD(v6) )
    {
      case 0:
      case 1:
        v8 = 1;
        if ( v4 >> 2 >= 1 )
          v8 = v4 >> 2;
        v9 = v5 >> 2;
        if ( v5 >> 2 < 1 )
          v9 = 1;
        v1 += 8 * v8 * v9;
        break;
      case 2:
      case 3:
      case 4:
        v10 = 1;
        if ( v4 >> 2 >= 1 )
          v10 = v4 >> 2;
        v11 = v5 >> 2;
        if ( v5 >> 2 < 1 )
          v11 = 1;
        LODWORD(v6) = 16 * v10 * v11;
        goto LABEL_22;
      default:
        v6 = (unsigned __int64)((double)(v4 * v5) * v3);
        HIDWORD(v6) = v13;
LABEL_22:
        v1 += v6;
        break;
    }
    v4 >>= 1;
    v5 >>= 1;
    --v7;
  }
  while ( v7 );
  return v1;
}
