void __stdcall sub_5BB260(unsigned __int8 *a1, int a2)
{
  _BYTE *v3; // edx
  unsigned __int8 *v4; // eax
  int v5; // esi
  unsigned __int8 v6; // cl
  _BYTE *v7; // eax
  int v8; // esi
  int v9; // esi
  _BYTE *v10; // eax
  unsigned __int8 *v11; // [esp+10h] [ebp-10h]
  unsigned __int8 v12; // [esp+28h] [ebp+8h]
  unsigned __int8 v13; // [esp+28h] [ebp+8h]

  v3 = 0;
  v11 = 0;
  if ( a2 >= 3 )
  {
    v4 = a1 + 1;
    v12 = *a1;
    v5 = a2 - 1;
    if ( *a1 && *a1 != 0xFF )
    {
      v11 = a1 + 1;
      v4 += v12;
      v5 -= v12;
    }
    if ( v5 >= 2 )
    {
      v6 = *v4;
      v7 = v4 + 1;
      v8 = v5 - 1;
      if ( v6 && v6 != 0xFF )
      {
        v3 = v7;
        v7 += v6;
        v8 -= v6;
      }
      if ( v8 >= 1 )
      {
        v9 = v8 - 1;
        v13 = *v7;
        if ( !*v7 || *v7 == 0xFF )
        {
          v10 = 0;
        }
        else
        {
          v10 = v7 + 1;
          v9 -= v13;
        }
        if ( v9 >= 0 )
          sub_5BB340(*a1, v11, v6, v3, v13, v10);
      }
    }
  }
}
