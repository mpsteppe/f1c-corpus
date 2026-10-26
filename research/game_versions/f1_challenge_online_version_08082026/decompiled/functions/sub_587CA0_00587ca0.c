_BYTE *__cdecl sub_587CA0(_BYTE *a1, int a2, _DWORD *a3)
{
  _BYTE *v3; // ebx
  _BYTE *v4; // edi
  int v7; // eax

  v3 = a1;
  v4 = a1;
  if ( a2 <= 0 )
    return 0;
  sub_58C1B1(a3);
  do
  {
    if ( !--a2 )
      break;
    if ( --a3[1] < 0 )
      v7 = sub_58C255(a3);
    else
      v7 = *(unsigned __int8 *)(*a3)++;
    if ( v7 == -1 )
    {
      if ( v4 == a1 )
      {
        v3 = 0;
        goto LABEL_14;
      }
      break;
    }
    *v4++ = v7;
  }
  while ( (_BYTE)v7 != 10 );
  *v4 = 0;
LABEL_14:
  sub_58C203(a3);
  return v3;
}
