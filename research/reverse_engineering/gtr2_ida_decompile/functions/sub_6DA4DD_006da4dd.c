_DWORD *__userpurge sub_6DA4DD@<eax>(int a1@<eax>, _BYTE *a2@<edx>, int a3@<ecx>, int a4)
{
  _DWORD *result; // eax
  int v7; // [esp+10h] [ebp+8h]

  result = (_DWORD *)sub_6DA486(a1);
  result[1451] = 8;
  if ( a4 )
  {
    *(_BYTE *)(result[5] + result[2]) = a3;
    *(_BYTE *)(++result[5] + result[2]) = BYTE1(a3);
    *(_BYTE *)(++result[5] + result[2]) = ~(_BYTE)a3;
    *(_BYTE *)(++result[5] + result[2]) = (unsigned __int16)~(_WORD)a3 >> 8;
    ++result[5];
  }
  if ( a3 )
  {
    do
    {
      v7 = a3;
      *(_BYTE *)(result[5] + result[2]) = *a2;
      ++result[5];
      ++a2;
      --a3;
    }
    while ( v7 != 1 );
  }
  return result;
}
