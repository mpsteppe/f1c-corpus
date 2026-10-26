void __thiscall sub_5D35C0(_DWORD *this, int a2, int a3, int a4)
{
  _DWORD *v4; // edx
  int v5; // ebx
  int v6; // edi
  int v7; // esi
  int v8; // eax
  int v9; // ecx
  int v10; // eax
  int v11; // ebx
  int v12; // edi
  int v13; // edx
  int v14; // eax
  int v15; // esi
  int v16; // eax
  int v17; // [esp+8h] [ebp-10h]
  int v19; // [esp+10h] [ebp-8h]
  int v20; // [esp+14h] [ebp-4h]

  v4 = this;
  v5 = this[1];
  v6 = 0;
  v20 = v5;
  v19 = 0;
  if ( v5 > 0 )
  {
    v7 = a4;
    do
    {
      v8 = v4[3];
      v9 = *(_DWORD *)(v8 + 8 * v6 + 4);
      v10 = *(_DWORD *)(v8 + 8 * v6);
      if ( v9 > 0 )
      {
        v11 = 12 * v10;
        v17 = v9;
        do
        {
          v12 = v11 + v4[6];
          v13 = *(_DWORD *)(v7 + 444);
          v14 = 0;
          if ( v13 <= 0 )
          {
LABEL_10:
            v16 = 0;
          }
          else
          {
            v15 = *(_DWORD *)(v7 + 452);
            while ( *(_DWORD *)(*(_DWORD *)v15 + 400) != *(_DWORD *)(*(_DWORD *)v12 + 400) )
            {
              ++v14;
              v15 += 4;
              if ( v14 >= v13 )
              {
                v7 = a4;
                goto LABEL_10;
              }
            }
            v7 = a4;
            v16 = *(_DWORD *)(*(_DWORD *)(a4 + 452) + 4 * v14);
          }
          v4 = this;
          *(_DWORD *)v12 = v16;
          v11 += 12;
          --v17;
        }
        while ( v17 );
        v5 = v20;
        v6 = v19;
      }
      v19 = ++v6;
    }
    while ( v6 < v5 );
  }
}
