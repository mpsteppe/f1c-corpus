void __cdecl __spoils<ecx> sub_5608F6(_WORD *a1, int a2, _WORD *a3, int a4, int a5, int a6, unsigned __int16 a7)
{
  unsigned int v10; // eax
  int v11; // ecx
  __int64 v12; // mm0
  bool v13; // cc
  unsigned int v14; // ecx
  int v15; // eax
  int v16; // edx
  int v17; // [esp+14h] [ebp+Ch]
  int v18; // [esp+1Ch] [ebp+14h]

  dword_5DD804 = a7;
  v10 = 2 * a5;
  v17 = a2 - 2 * a5;
  v18 = a4 - 2 * a5;
  if ( a7 != 0xFFFF || (v10 & 7) != 0 )
  {
    do
    {
      HIWORD(v15) = 0;
      v16 = a5;
      do
      {
        LOWORD(v15) = *a1++;
        if ( v15 != dword_5DD804 )
          *a3 = v15;
        ++a3;
        v13 = v16-- <= 1;
      }
      while ( !v13 );
      a1 = (_WORD *)((char *)a1 + v17);
      a3 = (_WORD *)((char *)a3 + v18);
      v13 = a6-- <= 1;
    }
    while ( !v13 );
  }
  else
  {
    v11 = v10 >> 3;
    do
    {
      do
      {
        v12 = *(_QWORD *)a1;
        a1 += 4;
        *(_QWORD *)a3 = v12;
        a3 += 4;
        v13 = v11-- <= 1;
      }
      while ( !v13 );
      v14 = v10 & 7;
      if ( (v10 & 7) != 0 )
      {
        qmemcpy(a3, a1, v14);
        a1 = (_WORD *)((char *)a1 + v14);
        a3 = (_WORD *)((char *)a3 + v14);
      }
      a1 = (_WORD *)((char *)a1 + v17);
      v11 = v10 >> 3;
      a3 = (_WORD *)((char *)a3 + v18);
      v13 = a6-- <= 1;
    }
    while ( !v13 );
  }
  _m_empty();
}

