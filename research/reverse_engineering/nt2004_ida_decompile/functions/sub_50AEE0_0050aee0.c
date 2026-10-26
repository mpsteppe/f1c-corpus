int __thiscall sub_50AEE0(_DWORD *this, int a2)
{
  int v2; // eax
  _DWORD *v3; // ecx
  int v4; // eax
  _DWORD *v5; // ecx
  int v6; // edi
  int *v7; // eax
  int v8; // edi
  int v9; // ecx
  _DWORD *i; // ecx
  int v11; // edi
  int result; // eax
  int v14; // [esp+Ch] [ebp+4h]

  result = *(_DWORD *)a2;
  if ( *(_DWORD *)a2 )
  {
    if ( !*(_BYTE *)(a2 + 64) )
    {
      sub_59E690(result, 0);
      sub_59E170(
        *(_DWORD *)(a2 + 4),
        *(_DWORD *)(a2 + 8),
        *(_DWORD *)(a2 + 12),
        *(float *)(a2 + 16),
        *(float *)(a2 + 20),
        *(float *)(a2 + 24));
      *(_BYTE *)(a2 + 64) = 1;
      result = sub_50B4E0(this[717], 1);
      v14 = *(_DWORD *)a2;
      if ( dword_7D5DA4 != 2 )
      {
        v2 = 0;
        if ( unk_629218 > 0 )
        {
          v3 = (_DWORD *)(unk_629220 + 212);
          while ( v14 != *v3 )
          {
            ++v2;
            v3 += 203;
            if ( v2 >= unk_629218 )
              goto LABEL_10;
          }
          v6 = 40 * v2;
          v7 = (int *)(v6 + unk_62921C);
          if ( *(_DWORD *)(unk_62921C + v6) != -1 )
          {
            sub_417BE0(dword_6291D0, v7);
            return sub_4E0780(dword_7D5DD8, v6 + unk_62921C);
          }
          return sub_4E0970(dword_7D5DD8, (int)v7);
        }
LABEL_10:
        v4 = 0;
        if ( unk_629224 > 0 )
        {
          v5 = (_DWORD *)(unk_62922C + 212);
          while ( v14 != *v5 )
          {
            ++v4;
            v5 += 199;
            if ( v4 >= unk_629224 )
              goto LABEL_19;
          }
          v8 = 40 * v4;
          v9 = *(_DWORD *)(unk_629228 + 40 * v4);
          v7 = (int *)(unk_629228 + 40 * v4);
          if ( v9 != -1 )
          {
            sub_417BE0(dword_6291D0, v7);
            return sub_4E0780(dword_7D5DD8, v8 + unk_629228);
          }
          return sub_4E0970(dword_7D5DD8, (int)v7);
        }
LABEL_19:
        result = 0;
        if ( unk_629230 > 0 )
        {
          for ( i = (_DWORD *)(unk_629238 + 212); v14 != *i; i += 199 )
          {
            if ( ++result >= unk_629230 )
              return result;
          }
          v11 = 40 * result;
          v7 = (int *)(unk_629234 + 40 * result);
          if ( *v7 == -1 )
            return sub_4E0970(dword_7D5DD8, (int)v7);
          sub_417BE0(dword_6291D0, v7);
          return sub_4E0780(dword_7D5DD8, v11 + unk_629234);
        }
      }
    }
  }
  return result;
}
