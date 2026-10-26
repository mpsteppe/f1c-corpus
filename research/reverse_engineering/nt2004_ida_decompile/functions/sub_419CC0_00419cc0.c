void __thiscall sub_419CC0(_DWORD *this)
{
  int v1; // ebp
  int v3; // edi
  int v4; // ecx
  int v5; // ebx
  int v6; // ecx
  double v7; // st7
  int v8; // ecx
  int v9; // edx
  float v10; // [esp+Ch] [ebp-14h]
  int v11; // [esp+10h] [ebp-10h]
  int v12; // [esp+14h] [ebp-Ch]
  int v13; // [esp+1Ch] [ebp-4h]

  v1 = -1;
  v10 = dbl_7DA9D0;
  v11 = -1;
  do
  {
    if ( v1 >= 0 )
    {
      if ( v1 == *(_DWORD *)(dword_75AACC + 25248) )
        goto LABEL_32;
      v3 = dword_75AAD0[v1];
    }
    else
    {
      if ( !(unsigned __int8)sub_42DBA0(&unk_62BF64) )
        goto LABEL_32;
      v3 = dword_75AACC;
    }
    if ( v3 )
    {
      v4 = *(_DWORD *)(v3 + 25248);
      if ( *(float *)&this[v4 + 340] > 0.0 && v10 - *(float *)&this[v4 + 340] > 0.5 && *(_DWORD *)(v3 + 16584) != -1 )
      {
        v5 = this[v4 + 580];
        if ( v5 )
        {
          if ( (unsigned __int8)sub_4EED40(v3)
            || this[*(_DWORD *)(v3 + 25248) + 532] >= this[*(_DWORD *)(v5 + 25248) + 532] )
          {
            v6 = *(_DWORD *)(v3 + 25248);
            v7 = v10 - 3.0;
            if ( v7 > *(float *)&this[v6 + 436] && v7 > *(float *)&this[*(_DWORD *)(v5 + 25248) + 436] && v10 > 3.0 )
            {
              v12 = 1;
              if ( (double)(int)this[v6 + 532] >= 5500.0 )
                v12 = 2;
              if ( (unsigned __int8)sub_4EED40(v3) )
              {
                v13 = *(_DWORD *)(v5 + 25256);
                if ( sub_5196B0(v3 + 84) >= 0.75 || sub_5196E0(v3 + 84) >= 0.025 || *(_DWORD *)dword_766888 )
                {
                  v8 = v12;
                  v9 = 2;
                }
                else
                {
                  v8 = 1;
                  v9 = 4;
                }
                if ( this[*(_DWORD *)(dword_75AACC + 25248) + 52] == *(_DWORD *)(dword_75AACC + 20884) )
                  sub_419330(v8, v13, 64, v9);
                *(float *)&this[*(_DWORD *)(v3 + 25248) + 436] = v10;
                *(float *)&this[*(_DWORD *)(v5 + 25248) + 436] = v10;
              }
            }
            this[*(_DWORD *)(v5 + 25248) + 340] = -1082130432;
            this[*(_DWORD *)(v5 + 25248) + 532] = 0;
            this[*(_DWORD *)(v5 + 25248) + 580] = v3;
            this[*(_DWORD *)(v3 + 25248) + 580] = v5;
          }
          v1 = v11;
        }
        this[*(_DWORD *)(v3 + 25248) + 340] = -1082130432;
        this[*(_DWORD *)(v3 + 25248) + 532] = 0;
      }
    }
LABEL_32:
    v11 = ++v1;
  }
  while ( v1 < 48 );
}
