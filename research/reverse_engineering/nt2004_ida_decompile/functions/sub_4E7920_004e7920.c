LPVOID sub_4E7920()
{
  int v0; // eax
  int v1; // esi
  int v2; // ebp
  int v3; // ebx
  int v4; // edi
  LPVOID result; // eax
  int v6; // [esp+4h] [ebp-4DCh]
  int v7; // [esp+8h] [ebp-4D8h]
  int v8; // [esp+Ch] [ebp-4D4h]
  LPVOID v9[2]; // [esp+10h] [ebp-4D0h] BYREF
  LPVOID v10; // [esp+18h] [ebp-4C8h]
  LPVOID v11; // [esp+20h] [ebp-4C0h]
  LPVOID v12; // [esp+28h] [ebp-4B8h]
  LPVOID v13; // [esp+30h] [ebp-4B0h]
  LPVOID v14; // [esp+48h] [ebp-498h]

  sub_4E6480(v9);
  v0 = dword_7D6A58;
  v1 = 0;
  v7 = 0;
  if ( dword_7D6A58 > 0 )
  {
    v2 = 0;
    v6 = 0;
    while ( 1 )
    {
      v3 = v1 + 1;
      v8 = v1 + 1;
      if ( v1 + 1 < v0 )
      {
        v4 = v2 + 1232;
        do
        {
          if ( sub_4E6C90((const char *)(v4 + dword_7D6A5C), dword_7D6A5C + v2) )
          {
            v1 = v3;
            v2 = v4;
          }
          v0 = dword_7D6A58;
          ++v3;
          v4 += 1232;
        }
        while ( v3 < dword_7D6A58 );
        if ( v1 != v7 )
        {
          sub_4E7A70(v6 + dword_7D6A5C);
          sub_4E7A70(1232 * v1 + dword_7D6A5C);
          sub_4E7A70(v9);
          v0 = dword_7D6A58;
        }
        v3 = v8;
      }
      v2 = v6 + 1232;
      v7 = v3;
      v6 += 1232;
      if ( v3 >= v0 )
        break;
      v1 = v3;
    }
  }
  if ( v14 )
    sub_5BE8AE(v14);
  if ( v13 )
    sub_5BE8AE(v13);
  if ( v12 )
    sub_5BE8AE(v12);
  if ( v11 )
    sub_5BE8AE(v11);
  if ( v10 )
    sub_5BE8AE(v10);
  result = v9[0];
  if ( v9[0] )
    return (LPVOID)sub_5BE8AE(v9[0]);
  return result;
}
