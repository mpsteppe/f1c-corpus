int __userpurge sub_6D987A@<eax>(int result@<eax>, int a2@<ecx>, _WORD *a3)
{
  int v4; // ecx
  int v5; // edx
  int v6; // ebx
  int v7; // edi
  int i; // esi
  int v9; // [esp-4h] [ebp-18h]
  int v10; // [esp+Ch] [ebp-8h]
  unsigned __int16 *v11; // [esp+10h] [ebp-4h]

  v10 = -1;
  v4 = *(unsigned __int16 *)(result + 2);
  v5 = 7;
  v6 = 0;
  v7 = 4;
  if ( !*(_WORD *)(result + 2) )
  {
    v5 = 138;
    v7 = 3;
  }
  *(_WORD *)(result + 4 * a2 + 6) = -1;
  if ( a2 >= 0 )
  {
    v11 = (unsigned __int16 *)(result + 6);
    for ( i = a2 + 1; i; --i )
    {
      result = v4;
      v4 = *v11;
      if ( ++v6 < v5 && result == v4 )
        goto LABEL_23;
      if ( v6 >= v7 )
      {
        if ( result )
        {
          if ( result != v10 )
            ++a3[2 * result + 1338];
          ++a3[1370];
        }
        else if ( v6 > 10 )
        {
          ++a3[1374];
        }
        else
        {
          ++a3[1372];
        }
      }
      else
      {
        a3[2 * result + 1338] += v6;
      }
      v6 = 0;
      v10 = result;
      if ( v4 )
      {
        if ( result != v4 )
        {
          v5 = 7;
          v9 = 4;
          goto LABEL_22;
        }
        v5 = 6;
      }
      else
      {
        v5 = 138;
      }
      v9 = 3;
LABEL_22:
      v7 = v9;
LABEL_23:
      v11 += 2;
    }
  }
  return result;
}
