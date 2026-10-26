int __thiscall sub_4E0D00(_DWORD *this, int a2)
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
      DoublyLinkedListNodeMover(result, 0);
      sub_54B4D0(
        *(_DWORD *)(a2 + 4),
        *(_DWORD *)(a2 + 8),
        *(_DWORD *)(a2 + 12),
        *(float *)(a2 + 16),
        *(float *)(a2 + 20),
        *(float *)(a2 + 24));
      *(_BYTE *)(a2 + 64) = 1;
      result = AudioSoundEffectController(this[601]);
      v14 = *(_DWORD *)a2;
      if ( dword_8AB6E4 != 2 )
      {
        v2 = 0;
        if ( unk_5EA5A8 > 0 )
        {
          v3 = (_DWORD *)(unk_5EA5B0 + 208);
          while ( v14 != *v3 )
          {
            ++v2;
            v3 += 202;
            if ( v2 >= unk_5EA5A8 )
              goto LABEL_10;
          }
          v6 = 36 * v2;
          v7 = (int *)(v6 + unk_5EA5AC);
          if ( *(_DWORD *)(unk_5EA5AC + v6) != -1 )
          {
            sub_410AF0(dword_5EA560, v7);
            return ArithmeticComparison_df90(dword_8AB710, v6 + unk_5EA5AC);
          }
          return NestedLoopCall(dword_8AB710, (int)v7);
        }
LABEL_10:
        v4 = 0;
        if ( unk_5EA5B4 > 0 )
        {
          v5 = (_DWORD *)(unk_5EA5BC + 208);
          while ( v14 != *v5 )
          {
            ++v4;
            v5 += 198;
            if ( v4 >= unk_5EA5B4 )
              goto LABEL_19;
          }
          v8 = 36 * v4;
          v9 = *(_DWORD *)(unk_5EA5B8 + 36 * v4);
          v7 = (int *)(unk_5EA5B8 + 36 * v4);
          if ( v9 != -1 )
          {
            sub_410AF0(dword_5EA560, v7);
            return ArithmeticComparison_df90(dword_8AB710, v8 + unk_5EA5B8);
          }
          return NestedLoopCall(dword_8AB710, (int)v7);
        }
LABEL_19:
        result = 0;
        if ( unk_5EA5C0 > 0 )
        {
          for ( i = (_DWORD *)(unk_5EA5C8 + 208); v14 != *i; i += 198 )
          {
            if ( ++result >= unk_5EA5C0 )
              return result;
          }
          v11 = 36 * result;
          v7 = (int *)(unk_5EA5C4 + 36 * result);
          if ( *v7 == -1 )
            return NestedLoopCall(dword_8AB710, (int)v7);
          sub_410AF0(dword_5EA560, v7);
          return ArithmeticComparison_df90(dword_8AB710, v11 + unk_5EA5C4);
        }
      }
    }
  }
  return result;
}

