int __thiscall sub_6951CB(_DWORD *this, _DWORD *a2)
{
  _DWORD *v2; // esi
  int v3; // edi
  int v5; // eax
  int v7; // eax

  v2 = a2;
  v3 = 0;
  if ( !a2 )
    return v3;
  do
  {
    if ( v2[1] != 1 )
      break;
    v5 = sub_6951CB(v2[2]);
    v2 = (_DWORD *)v2[3];
    v3 += v5;
  }
  while ( v2 );
  if ( !v2 )
    return v3;
  switch ( v2[1] )
  {
    case 6:
      v7 = sub_6951CB(v2[6]);
      break;
    case 8:
      v7 = v2[5] * sub_6951CB(v2[4]);
      break;
    case 9:
      v7 = v2[6] * v2[7];
      break;
    case 0xB:
      v7 = sub_6951CB(v2[8]);
      break;
    default:
      sub_694C3A(this, 0, 0, "internal error: unknown node");
      return 0;
  }
  return v3 + v7;
}
