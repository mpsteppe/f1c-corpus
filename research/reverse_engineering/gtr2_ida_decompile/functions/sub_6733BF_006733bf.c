unsigned int __stdcall sub_6733BF(int a1, int a2, int a3, int a4, _DWORD *a5, _DWORD *a6)
{
  int v7; // eax
  _DWORD *v8; // ebx
  unsigned int result; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // ecx
  unsigned int v13; // [esp+18h] [ebp+10h]

  if ( *(_WORD *)(a3 + 10) )
  {
    v7 = *(_DWORD *)(a1 + 8) + *(_DWORD *)(a3 + 12);
    v13 = 0;
    v8 = (_DWORD *)(v7 + 4);
    do
    {
      if ( *v8 )
        sub_6733BF(a1, a2, *v8 + *(_DWORD *)(a1 + 8), a4 * *(unsigned __int16 *)(*v8 + *(_DWORD *)(a1 + 8) + 8), a5, a6);
      result = *(unsigned __int16 *)(a3 + 10);
      ++v13;
      v8 += 2;
    }
    while ( v13 < result );
  }
  else
  {
    if ( *(_WORD *)(a2 + 4) )
    {
      if ( *(_WORD *)a3 == 3 )
      {
        v12 = *(unsigned __int16 *)(a3 + 4);
        v11 = *(unsigned __int16 *)(a3 + 6);
      }
      else
      {
        v12 = *(unsigned __int16 *)(a3 + 6);
        v11 = *(unsigned __int16 *)(a3 + 4);
      }
      v10 = (v12 + 3) >> 2;
    }
    else
    {
      v10 = *(unsigned __int16 *)(a3 + 6);
      v11 = *(unsigned __int16 *)(a3 + 4);
    }
    *a5 += a4 * v11 * v10;
    result = (unsigned int)a6;
    *a6 += a4 * *(unsigned __int16 *)(a3 + 4) * *(unsigned __int16 *)(a3 + 6);
  }
  return result;
}
