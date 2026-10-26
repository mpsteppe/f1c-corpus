unsigned __int16 *__userpurge sub_62D0B0@<eax>(unsigned __int16 *result@<eax>, int a2@<ecx>, _WORD *a3)
{
  int v3; // edi
  int v4; // ebp
  int v5; // esi
  int v7; // ecx
  int v8; // edx
  int v9; // ebx
  int v10; // eax
  unsigned __int16 *v11; // [esp+10h] [ebp-4h]

  v3 = result[1];
  v4 = -1;
  v5 = 0;
  v7 = 7;
  v8 = 4;
  if ( !result[1] )
  {
    v7 = 138;
    v8 = 3;
  }
  result[2 * a2 + 3] = -1;
  if ( a2 >= 0 )
  {
    v11 = result + 3;
    v9 = a2 + 1;
    do
    {
      v10 = v3;
      v3 = *v11;
      if ( ++v5 >= v7 || v10 != v3 )
      {
        if ( v5 >= v8 )
        {
          if ( v10 )
          {
            if ( v10 != v4 )
              ++a3[2 * v10 + 1337];
            ++a3[1369];
          }
          else if ( v5 > 10 )
          {
            ++a3[1373];
          }
          else
          {
            ++a3[1371];
          }
        }
        else
        {
          a3[2 * v10 + 1337] += v5;
        }
        v5 = 0;
        v4 = v10;
        if ( v3 )
        {
          if ( v10 == v3 )
          {
            v7 = 6;
            v8 = 3;
          }
          else
          {
            v7 = 7;
            v8 = 4;
          }
        }
        else
        {
          v7 = 138;
          v8 = 3;
        }
      }
      result = v11 + 2;
      --v9;
      v11 += 2;
    }
    while ( v9 );
  }
  return result;
}
