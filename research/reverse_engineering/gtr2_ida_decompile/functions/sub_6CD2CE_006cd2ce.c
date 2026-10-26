int __thiscall sub_6CD2CE(_DWORD *this, int a2, int a3)
{
  int result; // eax
  int v4; // edi
  int v5; // edx
  int v6; // ebx
  unsigned int v7; // [esp+10h] [ebp+Ch]

  result = a3;
  if ( (unsigned int)(a3 - a2) >> 1 )
  {
    v4 = 4 * a2;
    result = 4 * a3 - 4;
    v7 = (unsigned int)(a3 - a2) >> 1;
    do
    {
      v5 = this[15];
      v6 = *(_DWORD *)(v4 + v5);
      *(_DWORD *)(v4 + v5) = *(_DWORD *)(result + v5);
      *(_DWORD *)(result + this[15]) = v6;
      v4 += 4;
      result -= 4;
      --v7;
    }
    while ( v7 );
  }
  return result;
}
