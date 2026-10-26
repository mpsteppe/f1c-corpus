int __cdecl sub_58F2E0(int a1, int a2, int a3)
{
  int v3; // ebx
  int v4; // esi
  int v5; // eax
  _BYTE *v6; // ecx

  v3 = 0;
  v4 = 0;
  v5 = *(unsigned __int8 *)(a1 + 4) >> 2;
  if ( !v5 )
    goto LABEL_5;
  v6 = (_BYTE *)(a2 + 6);
  do
  {
    *v6 = *(v6 - 2);
    v6 += 8;
    --v5;
  }
  while ( v5 );
  do
  {
    v4 = 1;
    if ( a3 && sub_58F360(a1, a2) > a3 || *(_BYTE *)(a1 + 5) && !sub_58F3D0(a2, a1) )
    {
      v4 = 0;
      v3 = sub_58F550(a1, a2);
    }
    if ( v3 )
      break;
LABEL_5:
    ;
  }
  while ( !v4 );
  return v4;
}
