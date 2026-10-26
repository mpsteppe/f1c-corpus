void __thiscall sub_650286(_DWORD *this, unsigned int a2)
{
  unsigned int v3; // ecx
  int v4; // edi
  float *v5; // eax
  unsigned int v6; // ecx
  float *v7; // eax
  unsigned int v8; // ecx
  int v9; // eax
  float *v10; // esi
  unsigned int v11; // ebx
  float *v12; // esi
  unsigned int v13; // ebx

  v3 = a2 + 16 * this[26];
  if ( this[5] )
  {
    v4 = this[2];
    if ( v4 == 1 || v4 == 4 )
    {
      if ( a2 < v3 )
      {
        v7 = (float *)(a2 + 8);
        v8 = ((v3 - a2 - 1) >> 4) + 1;
        do
        {
          *(v7 - 2) = *(v7 - 2) * *(v7 - 2);
          *(v7 - 1) = *(v7 - 1) * *(v7 - 1);
          *v7 = *v7 * *v7;
          v7 += 4;
          --v8;
        }
        while ( v8 );
      }
    }
    else if ( a2 < v3 )
    {
      v5 = (float *)(a2 + 12);
      v6 = ((v3 - a2 - 1) >> 4) + 1;
      do
      {
        *v5 = *v5 * *v5;
        v5 += 4;
        --v6;
      }
      while ( v6 );
    }
  }
  else
  {
    this[31] = a2;
    v9 = this[2];
    if ( v9 == 1 || v9 == 4 )
    {
      if ( a2 < v3 )
      {
        v12 = (float *)(a2 + 8);
        v13 = ((v3 - a2 - 1) >> 4) + 1;
        do
        {
          *(v12 - 2) = sub_64FB85(*(v12 - 2));
          *(v12 - 1) = sub_64FB85(*(v12 - 1));
          *v12 = sub_64FB85(*v12);
          v12 += 4;
          --v13;
        }
        while ( v13 );
      }
    }
    else if ( a2 < v3 )
    {
      v10 = (float *)(a2 + 12);
      v11 = ((v3 - a2 - 1) >> 4) + 1;
      do
      {
        *v10 = sub_64FB85(*v10);
        v10 += 4;
        --v11;
      }
      while ( v11 );
    }
  }
}
