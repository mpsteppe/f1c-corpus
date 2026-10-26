int __fastcall sub_5389B0(_WORD *a1, int a2, int a3)
{
  int v3; // esi
  int v4; // ebp
  int v5; // edi
  int v6; // ebx
  int result; // eax
  unsigned __int16 *v8; // edx
  int v9; // eax
  int v10; // [esp+10h] [ebp-4h]
  int v11; // [esp+18h] [ebp+4h]

  v3 = *(unsigned __int16 *)(a2 + 2);
  v4 = 0;
  v10 = -1;
  v5 = 7;
  v6 = 4;
  if ( !(_WORD)v3 )
  {
    v5 = 138;
    v6 = 3;
  }
  result = a3;
  *(_WORD *)(a2 + 4 * a3 + 6) = -1;
  if ( a3 >= 0 )
  {
    v8 = (unsigned __int16 *)(a2 + 6);
    v11 = a3 + 1;
    do
    {
      v9 = v3;
      v3 = *v8;
      if ( ++v4 >= v5 || v9 != v3 )
      {
        if ( v4 >= v6 )
        {
          if ( v9 )
          {
            if ( v9 != v10 )
              ++a1[2 * v9 + 1337];
            ++a1[1369];
          }
          else if ( v4 > 10 )
          {
            ++a1[1373];
          }
          else
          {
            ++a1[1371];
          }
        }
        else
        {
          a1[2 * v9 + 1337] += v4;
        }
        v4 = 0;
        v10 = v9;
        if ( v3 )
        {
          if ( v9 == v3 )
          {
            v5 = 6;
            v6 = 3;
          }
          else
          {
            v5 = 7;
            v6 = 4;
          }
        }
        else
        {
          v5 = 138;
          v6 = 3;
        }
      }
      v8 += 2;
      result = --v11;
    }
    while ( v11 );
  }
  return result;
}
