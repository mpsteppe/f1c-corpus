void __thiscall sub_4198A0(float *this, char a2)
{
  int *v2; // edx
  float *v3; // ebp
  int v4; // edi
  int v5; // ebx
  int v6; // esi
  bool v7; // cc
  char *v8; // eax
  int v9; // ecx
  int v10; // eax
  int v11; // esi
  _DWORD *v12; // esi
  int v13; // ebp
  int v14; // ebx
  float v15; // [esp+0h] [ebp-1Ch]
  float *v16; // [esp+4h] [ebp-18h]
  _DWORD *v18; // [esp+Ch] [ebp-10h]
  float v19; // [esp+10h] [ebp-Ch]
  int v20; // [esp+14h] [ebp-8h]
  int v21; // [esp+18h] [ebp-4h]

  if ( dword_75CBB0 == 7 && dword_75CBB4 != 8 )
  {
    v15 = dbl_7DA9D0;
    v21 = 0;
    if ( (int)NumOfElements > 0 )
    {
      v2 = (int *)&unk_6310FC;
      v3 = this + 52;
      v18 = &unk_6310FC;
      v16 = this + 52;
      do
      {
        v19 = v15 + 3.0;
        if ( flt_629D4C > (double)v19 )
          flt_629D4C = v15;
        if ( v3[48] <= 0.0 )
          goto LABEL_57;
        if ( v15 - v3[48] < 2.0 )
          goto LABEL_57;
        v4 = *v2;
        v5 = *(_DWORD *)v3;
        *(_DWORD *)v3 = *v2;
        v3[48] = -1.0;
        v20 = v5;
        if ( (unsigned int)dword_7D7540 > 1 || *(int *)(dword_75AACC + 20848) <= 0 || *((_BYTE *)v2 - 3472) )
          goto LABEL_57;
        if ( !(unsigned __int8)sub_4EED40(v2 - 5221) )
        {
          if ( *v18 == 1 && *(_DWORD *)(dword_75AACC + 20884) != 2 && *(v18 - 1075) != -1 )
            sub_419510(4, v18[1093]);
          goto LABEL_57;
        }
        v6 = *(_DWORD *)(dword_75AACC + 25248);
        if ( v15 - this[v6 + 388] <= 5.5 )
        {
          if ( a2 || sub_4FA870(v5 - 1) != v6 )
          {
            v11 = *(_DWORD *)(dword_75AACC + 25248);
            if ( sub_4FA870(v4 - 1) == v11 )
            {
              v12 = (_DWORD *)((char *)&unk_62BF68 + 25304 * sub_4FA870(v5 - 1));
              if ( v12[4146] != -1 )
              {
                v13 = v12[6314];
                if ( v4 >= v5 )
                {
                  if ( (_DWORD *)LODWORD(this[*(_DWORD *)(dword_75AACC + 25248) + 580]) == v12 )
                  {
                    v14 = dword_75AACC + 84;
                    if ( sub_5196B0(dword_75AACC + 84) < 0.75 && sub_5196E0(v14) < 0.025 )
                    {
                      sub_419330(2, v13, 64, 2);
                      this[*(_DWORD *)(dword_75AACC + 25248) + 436] = dbl_7DA9D0;
                      this[v12[6312] + 436] = dbl_7DA9D0;
                    }
                    v5 = v20;
                  }
                }
                else
                {
                  sub_419330(1, v13, 64, 2);
                  this[*(_DWORD *)(dword_75AACC + 25248) + 436] = dbl_7DA9D0;
                  this[v12[6312] + 436] = dbl_7DA9D0;
                }
                v3 = v16;
              }
            }
          }
        }
        else if ( flt_629D4C <= (double)v15 && dword_75CBB0 == 7 )
        {
          v7 = v4 <= v5;
          if ( v4 >= v5 )
            goto LABEL_43;
          v8 = (char *)&unk_62BF68 + 25304 * sub_4FA870(v4);
          if ( !v8[17412] )
          {
            v9 = 2;
            if ( *((_DWORD *)v8 + 5223) != 2 )
            {
              if ( v4 == 1 )
              {
                v9 = 1;
              }
              else if ( v4 != 2 )
              {
                switch ( v4 )
                {
                  case 3:
                    v9 = 4;
                    break;
                  case 5:
                    v9 = 8;
                    break;
                  case 10:
                    v9 = 16;
                    break;
                  default:
                    v9 = v4 != 20 ? 64 : 32;
                    break;
                }
              }
              v10 = *((_DWORD *)v8 + 6314);
              flt_629D4C = v15 + 3.0;
              *(_DWORD *)v3 = v4;
              sub_419390(v9, v10);
            }
          }
        }
        v7 = v4 <= v5;
LABEL_43:
        if ( !v7 )
        {
          switch ( v4 )
          {
            case 2:
              sub_419450(2, 1, 1, 2);
              break;
            case 3:
              sub_419450(4, 1, 1, 2);
              break;
            case 4:
              sub_419450(8, 1, 1, 2);
              break;
            default:
              if ( v5 <= 5 && v4 > 5 )
                sub_419450(16, 1, 1, 2);
              break;
          }
        }
LABEL_57:
        ++v3;
        v2 = v18 + 6326;
        v7 = ++v21 < (int)NumOfElements;
        v16 = v3;
        v18 += 6326;
      }
      while ( v7 );
    }
  }
}
