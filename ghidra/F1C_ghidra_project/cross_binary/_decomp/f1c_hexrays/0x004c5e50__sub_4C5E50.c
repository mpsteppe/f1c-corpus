// f1c  0x004c5e50  size=372
int __thiscall sub_4C5E50(_DWORD *this, _DWORD *a2, int a3)
{
  int v4; // ebx
  int result; // eax
  int i; // esi
  _DWORD *v7; // eax
  _DWORD *v8; // esi
  int v9; // eax
  int v10; // ecx
  int v11; // [esp+8h] [ebp-10Ch]
  int v12; // [esp+Ch] [ebp-108h]
  int v13; // [esp+10h] [ebp-104h]
  _BYTE v14[253]; // [esp+14h] [ebp-100h] BYREF
  __int16 v15; // [esp+111h] [ebp-3h]
  char v16; // [esp+113h] [ebp-1h]

  v4 = 0;
  result = 0;
  v11 = 0;
  if ( *a2 )
  {
    if ( a3 > 0 )
    {
      v13 = dword_8AC488;
      if ( dword_8AC488 > 0 )
      {
        v12 = 0;
        do
        {
          if ( !sub_4C4CB0(this, v4) )
          {
            if ( v12 + dword_8AC490 )
            {
              v14[0] = byte_5EA438[0];
              memset(&v14[1], 0, 0xFCu);
              v15 = 0;
              v16 = 0;
              if ( !sub_4C58A0((int)v14, 256, (int)aFilterProperti, v12 + dword_8AC490 + 260) )
              {
                for ( i = 0; i < a3; ++i )
                {
                  if ( !sub_566810(v14, a2[i]) )
                    break;
                }
                if ( i == a3 )
                {
                  v7 = (_DWORD *)sub_587C03(16);
                  if ( v7 )
                  {
                    v8 = sub_4C5C80(v7, v4, (int)v14);
                    if ( v8 )
                    {
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
                      ++v11;
                    }
                  }
                }
              }
            }
          }
          ++v4;
          v12 += 396;
        }
        while ( v4 < v13 );
        return v11;
      }
    }
  }
  return result;
}
