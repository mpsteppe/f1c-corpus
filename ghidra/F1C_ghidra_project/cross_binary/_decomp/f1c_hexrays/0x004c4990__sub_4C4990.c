// f1c  0x004c4990  size=271
int __thiscall sub_4C4990(_DWORD *this, _DWORD *a2, int a3)
{
  int result; // eax
  int v5; // edi
  int v6; // ebx
  int v7; // esi
  int v8; // edi
  int *v9; // esi
  int v10; // eax
  int v11; // ecx
  int v12; // [esp+Ch] [ebp-Ch]
  int v13; // [esp+10h] [ebp-8h]
  int v14; // [esp+14h] [ebp-4h]

  result = 0;
  v13 = 0;
  if ( *a2 )
  {
    v5 = a3;
    if ( a3 > 0 )
    {
      v6 = 0;
      v14 = dword_8AC390;
      if ( dword_8AC390 > 0 )
      {
        v12 = 0;
        do
        {
          if ( !(unsigned __int8)sub_4C4CB0(v6) && dword_8AC394 + v12 )
          {
            v7 = 0;
            if ( v5 > 0 )
            {
              v8 = dword_8AC394 + v12 + 444;
              do
              {
                if ( !sub_566810(v8, a2[v7]) )
                  break;
                ++v7;
              }
              while ( v7 < a3 );
              v5 = a3;
            }
            if ( v7 == v5 )
            {
              v9 = (int *)sub_587C03(4);
              *v9 = v6;
              v10 = sub_587C03(12);
              if ( v10 )
              {
                *(_DWORD *)v10 = v9;
                *(_DWORD *)(v10 + 4) = 0;
                *(_BYTE *)(v10 + 8) = 1;
              }
              else
              {
                v10 = 0;
              }
              if ( this[2] )
              {
                *(_DWORD *)(this[3] + 4) = v10;
              }
              else
              {
                this[2] = v10;
                this[4] = v10;
              }
              v11 = this[5];
              this[3] = v10;
              this[5] = v11 + 1;
              ++v13;
            }
          }
          ++v6;
          v12 += 1060;
        }
        while ( v6 < v14 );
        return v13;
      }
    }
  }
  return result;
}
