int __fastcall sub_5388D0(int a1, int a2, int a3)
{
  int result; // eax
  __int16 v6; // cx
  __int16 v7; // si
  int i; // esi
  int v9; // edx
  int v10; // ecx
  _WORD v11[2]; // [esp+Ah] [ebp-22h]
  char v12; // [esp+Eh] [ebp-1Eh] BYREF

  result = 1;
  v6 = 0;
  do
  {
    v7 = v6 + *(_WORD *)((char *)&v11[++result] + a3 - (_DWORD)&v12);
    v6 = 2 * v7;
    v11[result] = 2 * v7;
  }
  while ( result <= 15 );
  for ( i = 0; i <= a2; ++i )
  {
    v9 = *(unsigned __int16 *)(a1 + 4 * i + 2);
    if ( (_WORD)v9 )
    {
      v10 = (unsigned __int16)v11[v9 + 1]++;
      result = sub_539670(v10);
      *(_WORD *)(a1 + 4 * i) = result;
    }
  }
  return result;
}

