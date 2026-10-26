int __thiscall sub_45F710(char *this)
{
  int v2; // ebp
  int *v3; // edi
  int v4; // eax
  bool v5; // bl
  int result; // eax
  int v7; // eax
  int v8; // eax
  int v9; // ebp
  char *v10; // ebx
  int v11; // edi
  int v12; // ecx
  float v13; // [esp+0h] [ebp-258h]
  int v14; // [esp+14h] [ebp-244h] BYREF
  int v15; // [esp+18h] [ebp-240h]
  int v16[107]; // [esp+1Ch] [ebp-23Ch] BYREF
  int v17; // [esp+1C8h] [ebp-90h] BYREF
  _BYTE v18[140]; // [esp+1CCh] [ebp-8Ch] BYREF

  if ( (unsigned __int8)sub_461440(this) )
  {
    sub_4651C0(&unk_7CD2A8);
    v2 = 0;
    v3 = dword_5EF9A0;
    do
    {
      if ( *v3 != -1 )
        sub_4652D0(v2);
      v3 += 4656;
      ++v2;
    }
    while ( (int)v3 < (int)dword_7C87A0 );
  }
  v4 = *((_DWORD *)this + 4081);
  v5 = v4 == 2 || v4 == 1;
  while ( 1 )
  {
    v14 = 432;
    result = sub_57A760(v16, &v14, &v17);
    if ( result )
      break;
    *((_DWORD *)this + 226) = 0;
    if ( v5 )
    {
      v7 = sub_460C30(v17);
      v16[0] = v7 | v16[0] & 0xFFFFFF00;
    }
    v13 = dbl_8AFEA0;
    sub_45C8F0((_DWORD *)this + 26864, (float *)v16, v13);
    sub_45D890(this, (unsigned int *)v16);
  }
  if ( v5 )
  {
    if ( (unsigned __int8)sub_461440(this) )
    {
      sub_4B3B30(&dword_7D2E50);
      for ( result = sub_4B3AF0(v16); result; result = sub_4B3AF0(v16) )
        sub_465300(v16);
    }
    else
    {
      sub_461470(v18);
      v15 = sub_462300(*(_DWORD *)this);
      v8 = *((_DWORD *)this + 3973);
      v9 = 0;
      v14 = 0;
      if ( v8 > 0 )
      {
        v10 = this + 1040;
        do
        {
          if ( (unsigned __int8)sub_4614C0(v10 - 124) )
          {
            v11 = *(_DWORD *)&this[4 * *v10 + 15896];
            if ( v11 != v15 )
            {
              sub_4B3B30(&dword_7D2E50);
              while ( sub_4B3AF0(v16) )
              {
                if ( v11 != v17 )
                {
                  sub_462250(v16, 1, v11, 1000);
                  ++v9;
                }
              }
            }
          }
          v12 = *((_DWORD *)this + 3973);
          v10 += 140;
          ++v14;
        }
        while ( v14 < v12 );
      }
      if ( !dword_7D0F04 && dword_7D0E98 > 8 && v9 > 0 )
        sub_57A730(0);
      return nullsub_3(v18);
    }
  }
  return result;
}
