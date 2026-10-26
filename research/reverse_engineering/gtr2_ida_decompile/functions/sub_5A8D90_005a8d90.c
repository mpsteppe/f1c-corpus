int __thiscall sub_5A8D90(_DWORD *this, char a2)
{
  int v3; // ecx
  int v4; // eax
  _DWORD *v5; // ebx
  unsigned int v6; // edx
  signed int j; // eax
  char v8; // cl
  int v10; // [esp+1Ch] [ebp-94h]
  int v11; // [esp+20h] [ebp-90h]
  int i; // [esp+24h] [ebp-8Ch]
  _BYTE v13[132]; // [esp+28h] [ebp-88h] BYREF
  int v14; // [esp+ACh] [ebp-4h]

  v14 = dword_912B08;
  sub_5A8D20();
  sub_5A8D20();
  sub_5A8D20();
  sub_5A8D20();
  sub_5A8D20();
  sub_5A8D20();
  sub_5A8D20();
  sub_5A8D20();
  sub_5A8D20();
  sub_5A8D20();
  sub_5A8D20();
  sub_5A8D20();
  sub_5A8D20();
  sub_5A8D20();
  sub_5A8D20();
  sub_5A8D20();
  sub_5A8D20();
  sub_5A8D20();
  sub_5A8D20();
  if ( *this )
  {
    if ( a2 )
    {
      sub_5A8D20();
      sub_5A8D20();
      v3 = this[18];
      v4 = 0;
      v11 = 0;
      v10 = v3;
      for ( i = 0; v4 < v3; i = v4 )
      {
        v5 = *(_DWORD **)(*(_DWORD *)(this[15] + 4 * v4) + 4);
        if ( v5 )
        {
          do
          {
            memset(v13, 0, 0x80u);
            ++v11;
            v6 = v5[3];
            if ( v6 >= 0x7F )
              v6 = 127;
            for ( j = 0; j < (int)v6; ++j )
            {
              v8 = *(_BYTE *)(j + v5[2]);
              if ( v8 < 16 )
                v8 = 46;
              v13[j] = v8;
            }
            sub_5A8D20();
            v5 = (_DWORD *)v5[1];
          }
          while ( v5 );
          v4 = i;
          v3 = v10;
        }
        ++v4;
      }
    }
  }
  return sub_5A8D20();
}
