_DWORD *__thiscall sub_685BBE(_DWORD *this, _DWORD *a2, int a3, int a4)
{
  _DWORD *result; // eax
  int v6; // edx
  _DWORD *v7; // esi
  int v8; // edx
  int v9; // edx
  unsigned int v10; // edi
  int v11; // ebx
  int v12; // edi
  int v13; // ebx
  int v14; // edi
  int v15; // [esp+Ch] [ebp-8h]
  int v16; // [esp+1Ch] [ebp+8h]

  result = a2;
  do
  {
    v6 = this[5];
    if ( *(_DWORD *)(*(_DWORD *)(v6 + 4 * a3) + 56) != -1 )
      a3 = *(_DWORD *)(*(_DWORD *)(v6 + 4 * a3) + 56);
    v7 = *(_DWORD **)(v6 + 4 * a3);
    if ( v7[1] == *result )
    {
      v15 = v7[29];
      if ( result[22] )
      {
        v8 = *(_DWORD *)(result[19] + 4 * v7[29]) + *(_DWORD *)(result[20] + 4 * v7[29]);
        *(_DWORD *)(result[21] + 4 * v8) = v8;
        v9 = 12 * v8;
        *(_DWORD *)(v9 + result[22]) = a4;
        v10 = **(_DWORD **)(this[6] + 4 * a4) & 0xFFF00000;
        if ( v10 == 544210944 || v10 == 545259520 || v10 == 290455552 )
        {
          *(_DWORD *)(v9 + result[22] + 4) = v7[5];
          *(_DWORD *)(v9 + result[22] + 8) = v7[6];
        }
        else
        {
          *(_DWORD *)(v9 + result[22] + 4) = *(_DWORD *)(*(_DWORD *)(this[5]
                                                                   + 4
                                                                   * **(_DWORD **)(*(_DWORD *)(this[6] + 4 * a4) + 16))
                                                       + 20);
          *(_DWORD *)(v9 + result[22] + 8) = *(_DWORD *)(*(_DWORD *)(this[5]
                                                                   + 4
                                                                   * **(_DWORD **)(*(_DWORD *)(this[6] + 4 * a4) + 16))
                                                       + 24);
        }
        v11 = v9 + result[22];
        v12 = *(_DWORD *)(v11 + 4);
        v13 = *(_DWORD *)(v11 + 8);
        while ( v12 != v7[5] )
        {
          v16 = 4 * v12;
          if ( *(char *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(*(_DWORD *)(4 * v12 + this[5]) + 4)) + 5) < 0 )
          {
            *(_DWORD *)(v9 + result[22] + 4) = v12;
            *(_DWORD *)(v9 + result[22] + 8) = v13;
            *(_DWORD *)(v9 + result[22]) = *(_DWORD *)(*(_DWORD *)(v16 + this[5]) + 88);
            if ( v7[22] < *(_DWORD *)(*(_DWORD *)(v16 + this[5]) + 88) )
              v7[22] = *(_DWORD *)(*(_DWORD *)(v16 + this[5]) + 88);
          }
          v14 = *(_DWORD *)(v16 + this[5]);
          v13 = *(_DWORD *)(v14 + 24);
          v12 = *(_DWORD *)(v14 + 20);
        }
      }
      ++*(_DWORD *)(result[19] + 4 * v15);
    }
    a3 = v7[2];
  }
  while ( a3 != -1 );
  return result;
}
