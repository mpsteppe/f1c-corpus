signed int __fastcall sub_51D750(signed int *a1, int a2, int a3)
{
  signed int v4; // eax
  signed int result; // eax
  int v6; // esi
  int v7; // ebp
  int v8; // ecx
  signed int v9; // eax
  signed int *v10; // ecx
  signed int v11; // eax
  int v12; // edi
  int v13; // edx
  int v14; // esi
  int v15; // eax
  int v16; // edi
  int i; // esi
  int v18; // ecx
  int v19; // [esp+Ch] [ebp-8h]

  sub_5DB6B0(a2);
  v4 = *a1;
  if ( (_BYTE)a3 )
    result = v4 | 0x20;
  else
    result = v4 & 0xFFFFFFDF;
  v6 = a1[136];
  v7 = 0;
  *a1 = result;
  v19 = v6;
  while ( v7 < v6 )
  {
    v8 = v7;
    if ( v7 >= 0 && v7 < a1[136] )
    {
      v9 = a1[133];
      if ( v7 <= 0 )
      {
LABEL_10:
        if ( v9 )
        {
          v10 = *(signed int **)v9;
          goto LABEL_13;
        }
      }
      else
      {
        while ( v9 )
        {
          v9 = *(_DWORD *)(v9 + 4);
          if ( --v8 <= 0 )
            goto LABEL_10;
        }
      }
    }
    v10 = 0;
LABEL_13:
    v11 = *v10;
    if ( (_BYTE)a3 )
      result = v11 | 0x8000000;
    else
      result = v11 & 0xF7FFFFFF;
    v12 = v10[90];
    v13 = 0;
    *v10 = result;
    if ( v12 > 0 )
    {
      v14 = 0;
      do
      {
        v15 = v10[90];
        if ( (_BYTE)a3 )
        {
          if ( v13 >= v15 )
          {
            result = 0;
            MEMORY[2] |= 0xC0u;
          }
          else
          {
            result = v14 + v10[91];
            *(_BYTE *)(result + 2) |= 0xC0u;
          }
        }
        else
        {
          if ( v13 >= v15 )
            result = 0;
          else
            result = v14 + v10[91];
          *(_BYTE *)(result + 2) &= 0x3Fu;
        }
        ++v13;
        v14 += 108;
      }
      while ( v13 < v12 );
      v6 = v19;
    }
    ++v7;
  }
  v16 = a1[160];
  for ( i = 0; i < v16; ++i )
  {
    result = a1[160];
    if ( i < result )
    {
      v18 = i;
      if ( i >= 0 && i < result )
      {
        result = a1[157];
        if ( i <= 0 )
        {
LABEL_36:
          if ( result )
          {
            result = *(_DWORD *)result;
            if ( result )
              result = sub_51D750(a3);
          }
        }
        else
        {
          while ( result )
          {
            result = *(_DWORD *)(result + 4);
            if ( --v18 <= 0 )
              goto LABEL_36;
          }
        }
      }
    }
  }
  return result;
}
