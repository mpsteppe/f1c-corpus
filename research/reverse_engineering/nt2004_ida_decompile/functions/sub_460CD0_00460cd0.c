void __thiscall sub_460CD0(char *this)
{
  int v2; // ebp
  int *v3; // edi
  int v4; // eax
  bool v5; // bl
  int v6; // eax
  int v7; // eax
  int v8; // ebp
  char *v9; // ebx
  int v10; // edi
  int v11; // ecx
  float v12; // [esp+0h] [ebp-160h]
  int v13; // [esp+14h] [ebp-14Ch] BYREF
  int v14; // [esp+18h] [ebp-148h]
  int v15[51]; // [esp+1Ch] [ebp-144h] BYREF
  int v16; // [esp+E8h] [ebp-78h] BYREF
  _BYTE v17[116]; // [esp+ECh] [ebp-74h] BYREF

  if ( (unsigned __int8)sub_462B90(this) )
  {
    sub_46CEE0(&unk_7652D8);
    v2 = 0;
    v3 = dword_630030;
    do
    {
      if ( *v3 != -1 )
        sub_46CFF0(v2);
      v3 += 6326;
      ++v2;
    }
    while ( (int)v3 < (int)dword_75EB88 );
  }
  v4 = *((_DWORD *)this + 1680);
  v5 = v4 == 2 || v4 == 1;
  while ( 1 )
  {
    v13 = 208;
    if ( sub_56A490(v15, &v13, &v16) )
      break;
    *((_DWORD *)this + 164) = 0;
    if ( v5 )
    {
      v6 = sub_462380(v16);
      v15[0] = v6 | v15[0] & 0xFFFFFFC0;
    }
    v12 = dbl_7DA9D0;
    sub_45DE70((_DWORD *)this + 6929, (float *)v15, v12);
    sub_45EC80(this, v15);
  }
  if ( v5 )
  {
    if ( (unsigned __int8)sub_462B90(this) )
    {
      sub_4D1930(&dword_76BC30);
      while ( sub_4D18F0(v15) )
        sub_46D020(v15);
    }
    else
    {
      sub_462BC0(v17);
      v14 = sub_463B50(*(_DWORD *)this);
      v7 = *((_DWORD *)this + 1628);
      v8 = 0;
      v13 = 0;
      if ( v7 > 0 )
      {
        v9 = this + 852;
        do
        {
          if ( (unsigned __int8)sub_462C00(v9 - 100) )
          {
            v10 = *(_DWORD *)&this[4 * *v9 + 6516];
            if ( v10 != v14 )
            {
              sub_4D1930(&dword_76BC30);
              while ( sub_4D18F0(v15) )
              {
                if ( v10 != v16 )
                {
                  sub_463A40(v15, 1, v10, 1000);
                  ++v8;
                }
              }
            }
          }
          v11 = *((_DWORD *)this + 1628);
          v9 += 116;
          ++v13;
        }
        while ( v13 < v11 );
      }
      if ( !dword_7698D8 && *(int *)dword_76986C > 8 && v8 > 0 )
        sub_56A460(0);
      nullsub_6(v17);
    }
  }
}
