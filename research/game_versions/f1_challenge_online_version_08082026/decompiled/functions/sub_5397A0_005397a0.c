int __fastcall sub_5397A0(int a1, _BYTE *a2, int a3, int a4)
{
  _DWORD *v5; // ecx
  int result; // eax
  int v7; // ebx
  int v8; // edi
  int v9; // ebx
  int v10; // edx
  int v11; // edx

  sub_539720(a1);
  *(_DWORD *)((char *)v5 + 5799) = 8;
  result = a3;
  if ( a4 )
  {
    *(_BYTE *)(v5[5] + v5[2]) = a3;
    v7 = v5[2];
    v8 = v5[5] + 1;
    v5[5] = v8;
    *(_BYTE *)(v8 + v7) = BYTE1(a3);
    v9 = v5[2];
    v10 = v5[5] + 1;
    v5[5] = v10;
    *(_BYTE *)(v10 + v9) = ~(_BYTE)a3;
    v11 = v5[5] + 1;
    v5[5] = v11;
    *(_BYTE *)(v11 + v5[2]) = ~BYTE1(a3);
    ++v5[5];
  }
  if ( a3 )
  {
    do
    {
      *(_BYTE *)(v5[5] + v5[2]) = *a2++;
      --result;
      ++v5[5];
    }
    while ( result );
  }
  return result;
}
