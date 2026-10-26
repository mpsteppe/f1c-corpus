_DWORD *__userpurge sub_62DEC0@<eax>(int a1@<eax>, _BYTE *a2@<edx>, int a3@<ecx>, int a4)
{
  _DWORD *result; // eax
  int v7; // edx
  int v8; // ecx
  int v9; // edx
  int v10; // esi
  int v11; // edx
  int v12; // esi
  int v13; // [esp+10h] [ebp+4h]

  result = (_DWORD *)sub_62DE50(a1);
  *(_DWORD *)((char *)result + 5799) = 8;
  if ( a4 )
  {
    *(_BYTE *)(result[5] + result[2]) = a3;
    v7 = result[2];
    v8 = result[5] + 1;
    result[5] = v8;
    *(_BYTE *)(v8 + v7) = BYTE1(a3);
    v9 = result[2];
    v10 = result[5] + 1;
    result[5] = v10;
    *(_BYTE *)(v10 + v9) = ~(_BYTE)a3;
    v11 = result[2];
    v12 = result[5] + 1;
    result[5] = v12;
    *(_BYTE *)(v12 + v11) = (unsigned __int16)~(_WORD)a3 >> 8;
    ++result[5];
  }
  if ( a3 )
  {
    do
    {
      v13 = a3;
      *(_BYTE *)(result[5] + result[2]) = *a2++;
      --a3;
      ++result[5];
    }
    while ( v13 != 1 );
  }
  return result;
}
