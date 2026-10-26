// f1c  0x004c4aa0  size=264
int __thiscall sub_4C4AA0(_DWORD *this, _DWORD *a2, int a3)
{
  int v4; // ebx
  int result; // eax
  int v6; // esi
  int v7; // edi
  int *v8; // esi
  int v9; // eax
  int v10; // ecx
  int v11; // [esp+8h] [ebp-Ch]
  int v12; // [esp+Ch] [ebp-8h]
  int v13; // [esp+10h] [ebp-4h]

  v4 = 0;
  result = 0;
  v12 = 0;
  if ( *a2 )
  {
    if ( a3 > 0 )
    {
      v13 = dword_8AC390;
      if ( dword_8AC390 > 0 )
      {
        v11 = 0;
        do
        {
          if ( !(unsigned __int8)sub_4C4CB0(v4) && dword_8AC394 + v11 )
          {
            v6 = 0;
            v7 = dword_8AC394 + v11 + 444;
            while ( !sub_566810(v7, a2[v6]) )
            {
              if ( ++v6 >= a3 )
                goto LABEL_19;
            }
            v8 = (int *)sub_587C03(4);
            *v8 = v4;
            v9 = sub_587C03(12);
            if ( v9 )
            {
              *(_DWORD *)v9 = v8;
              *(_DWORD *)(v9 + 4) = 0;
              *(_BYTE *)(v9 + 8) = 1;
            }
            else
            {
              v9 = 0;
            }
            if ( this[2] )
            {
              *(_DWORD *)(this[3] + 4) = v9;
            }
            else
            {
              this[2] = v9;
              this[4] = v9;
            }
            v10 = this[5];
            this[3] = v9;
            this[5] = v10 + 1;
            ++v12;
          }
LABEL_19:
          ++v4;
          v11 += 1060;
        }
        while ( v4 < v13 );
        return v12;
      }
    }
  }
  return result;
}
